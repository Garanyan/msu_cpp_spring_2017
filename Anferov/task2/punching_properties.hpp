//
//  punching_properties.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef punching_properties_hpp
#define punching_properties_hpp

#include <vector>

class armor;

class punching_properties
{
    std::vector<armor *> armors;
    std::vector<double> damage;
};

#endif /* punching_properties_hpp */
