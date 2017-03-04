//
//  weapon_skills.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef weapon_skills_hpp
#define weapon_skills_hpp

#include <vector>

class weapon;

class weapon_skills {
    std::vector<weapon *> weapons;
    std::vector<double> skill;
};

#endif /* weapon_skills_hpp */
