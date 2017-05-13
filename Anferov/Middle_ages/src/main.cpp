#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <future>
#include <condition_variable>
#include "character.hpp"
#include "storage.hpp"
#include "arsenal.hpp"

arsenal a;
barracks b;
stadium s;
stage st;

std::mutex arsenal_mutex;
std::mutex barracks_mutex;
std::mutex stadium_mutex;
std::mutex stage_mutex;

std::mutex cout_mutex;

std::condition_variable enough_units_for_battle;

enum Attributes {
    Normal = 0,
    Bold
};
enum Colours {
    Red = 31,
    Green,
    Yellow,
    Blue,
    Purple,
    Cyan,
    White
};

void colored_output(const std::string s, Colours c, Attributes a = Normal) {
    std::cout << "\x1b["+std::to_string(a)+";"+std::to_string(c)+"m"+s+"\x1b[0m" << std::endl;
}

void dressing_and_going_to_stadium(std::string name, weapon_type weap, armor_type arm) {
    std::unique_lock<std::mutex> lock_barracks(barracks_mutex);
    {
        std::unique_lock<std::mutex> lock_arsenal(arsenal_mutex);
        try {
            b[name].put_on_armor(a.get_armor(arm));
        } catch (std::logic_error) {
        }
        try {
            b[name].take_weapon(a.get_weapon(weap));
        } catch (std::logic_error) {
        }
    }
    std::unique_lock<std::mutex> lock_stadium(stadium_mutex);
    s.add_unit(b.get_unit(name));
    std::unique_lock<std::mutex> lock_cout(cout_mutex);
    colored_output( "🏃🏻  " + name + " got " + s[name].get_weapon_name() + " and " + s[name].get_armor_name() + " and went to stadium.", Purple);
    enough_units_for_battle.notify_one();
}

void hit_sequence(std::string attacker, std::string defender) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(random() % 100));
        std::unique_lock<std::mutex> lock_stage(stage_mutex);
        try {
            if (st[attacker].get_health() > 0 && st[defender].get_health() > 0) {
                st[attacker].attack(st[defender]);
                std::unique_lock<std::mutex> lock_cout(cout_mutex);
                colored_output("   🤺  " + attacker + " attacks " + defender + ". " + defender + "'s health is now " + std::to_string(st[defender].get_health()), Red);
            } else {
                break;
            }
        } catch (std::logic_error) {
            break;
        }
    }
}

void battle(std::string name1, std::string name2) {
    {
        std::unique_lock<std::mutex> lock_cout(cout_mutex);
        colored_output("⚔️  Battle between " + name1 + " and " + name2 + " is starting...", Cyan);
    }
    
    std::thread fighter1(hit_sequence, name1, name2);
    std::thread fighter2(hit_sequence, name2, name1);
    
    fighter1.join();
    fighter2.join();
    
    std::unique_lock<std::mutex> lock_stage(stage_mutex, std::defer_lock);
    std::unique_lock<std::mutex> lock_stadium(stadium_mutex, std::defer_lock);
    
    std::lock(lock_stage, lock_stadium);

    try {
        if (st[name1].get_health() > 0) {
            std::unique_lock<std::mutex> lock_cout(cout_mutex);
            colored_output("🏅  Battle between " + name1 + " and " + name2 + ": the winner is " + name1, Green, Bold);
            s.add_unit(st.get_unit(name1));
        } else {
            std::unique_lock<std::mutex> lock_cout(cout_mutex);
            colored_output("🏅  Battle between " + name1 + " and " + name2 + ": the winner is " + name2, Green, Bold);
            s.add_unit(st.get_unit(name2));
        }
    } catch (std::logic_error) {
        std::unique_lock<std::mutex> lock_cout(cout_mutex);
        colored_output("🏅  Battle between " + name1 + " and " + name2 + ": the winner is " + name2, Green, Bold);
        s.add_unit(st.get_unit(name2));
    }
    st.clean_from_deadmen();

    enough_units_for_battle.notify_one();
}

void fighting() {
    while (true) {
        std::unique_lock<std::mutex> lock_stadium(stadium_mutex);
        while (s.get_units_count() < 2) {
            {
                lock_stadium.unlock();
                std::unique_lock<std::mutex> lock_barracks(barracks_mutex);
                std::unique_lock<std::mutex> lock_stage(stage_mutex);
                lock_stadium.lock();
                if (b.get_units_count() + st.get_units_count() + s.get_units_count() == 1) {
                    colored_output("☠️  Looks like there is nobody to wait...\n🏆  The winner is " + s.get_unit_names()[0], Yellow, Bold);
                    return;
                }
            }
            enough_units_for_battle.wait(lock_stadium);
        }
        
        std::vector<std::string> units = s.get_unit_names();

        std::unique_lock<std::mutex> lock_stage(stage_mutex);
        st.add_unit(s.get_unit(units[0]));
        st.add_unit(s.get_unit(units[1]));

        std::thread(battle, units[0], units[1]).detach();
    }
}

int main() {
    
    for (int i=0; i<4; i++) {
        a.put_weapon(std::unique_ptr<weapon>(new shovel));
        a.put_weapon(std::unique_ptr<weapon>(new sword));
        a.put_weapon(std::unique_ptr<weapon>(new hammer));
        a.put_weapon(std::unique_ptr<weapon>(new bow));
    }
    
    for (int i=0; i<8; i++) {
        a.put_armor(std::unique_ptr<armor>(new chain_armour));
        a.put_armor(std::unique_ptr<armor>(new lat));
    }

    for (int i=0; i<20; i++) {
        b.add_unit(std::unique_ptr<character>(new peasant("Unit"+std::to_string(i))));
    }
    
    std::thread fight_proccess(fighting);
    
    for (int i=0; i<20; i+=4) {
        std::thread u1(dressing_and_going_to_stadium, "Unit"+std::to_string(i+0), SHOVEL, CHAIN_ARMOUR);
        std::thread u2(dressing_and_going_to_stadium, "Unit"+std::to_string(i+1), SWORD, LAT);
        std::thread u3(dressing_and_going_to_stadium, "Unit"+std::to_string(i+2), HAMMER, CHAIN_ARMOUR);
        std::thread u4(dressing_and_going_to_stadium, "Unit"+std::to_string(i+3), BOW, LAT);
        u1.join();
        u2.join();
        u3.join();
        u4.join();
    }
    
    fight_proccess.join();
    
    return 0;
}
