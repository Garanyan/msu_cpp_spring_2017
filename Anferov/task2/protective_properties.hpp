//
//  protective_properties.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef protective_properties_hpp
#define protective_properties_hpp

#include <vector>

class weapon;

class protective_properties {
    std::vector<weapon *> weapons;
    std::vector<double> damage;
};

#endif /* protective_properties_hpp */
