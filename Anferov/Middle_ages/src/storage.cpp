//
//  storage.cpp
//  C++ project
//
//  Created by Игорь Анфёров on 11.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include <iostream>
#include "storage.hpp"

std::unique_ptr<character> storage::get_unit(const std::string & s) {
    std::unique_ptr<character> tmp(std::move(units.at(s)));
    units.erase(s);
    return tmp;
}

void storage::add_unit(std::unique_ptr<character> c) {
    try {
        units.at(c->get_name());
    } catch (std::out_of_range) {
        units.insert(std::pair<std::string, std::unique_ptr<character>>
                     (c->get_name(), std::move(c)));
        return;
    }
    throw std::logic_error("Name duplicating occured!");
}

character & storage::operator[](const std::string & s) {
    return *(units.at(s));
}

void storage::clean_from_deadmen() {
    for (auto it = units.cbegin(); it != units.cend();) {
        if (it -> second -> get_health() <= 0) {
            it = units.erase(it);
        } else {
            ++it;
        }
    }
}

size_t storage::get_units_count() {
    return units.size();
}

std::vector<std::string> storage::get_unit_names() const {
    std::vector<std::string> res;
    
    for (auto & p: units) {
        res.push_back(p.second -> get_name());
    }
    
    return res;
}

void storage::save(std::ostream& out) const {
    for (std::string & s: get_unit_names()) {
        out << s << std::endl;
    }
}
