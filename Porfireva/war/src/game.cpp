#include <iostream>
#include "../include/armor.h"
#include "../include/arsenal.h"
#include "../include/weapon.h"
#include "../include/unit.h"
void fight(Unit& one, Unit& two)
{
    int flag = 0;
    while(true)
    {
        flag = one.Attack(two);
        if (flag < 0)
        {
            if(flag == -1)
                std::cout <<"The winner is "<<one.getName() << std::endl;
            else
                std::cout <<"The winner is "<<two.getName() << std::endl;
            break;
        }
        flag = two.Attack(one);
        if (flag<0)
        {
            if(flag == -1)
                std::cout <<"The winner is "<<two.getName() << std::endl;
            else
                std::cout <<"The winner is "<<one.getName() << std::endl;
                
            break;
            
        }
    }
}
int main()
{
    Arsenal a;
    Plowman J("John",a);
    Knight G("Greg",a);
    Plowman("Antony",a);
    fight(G,J);
    

}
