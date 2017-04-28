//
//  storage.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 11.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef storage_hpp
#define storage_hpp

#include <string>
#include <memory>
#include <map>
#include <vector>
#include <stdexcept>
#include "character.hpp"

/************************* PARENT *************************/

class storage
{
    std::map<std::string, std::unique_ptr<character>> units;
    
    storage(storage const &) = delete;
    storage & operator= (storage const &) = delete;
    
public:
    storage() = default;
    virtual ~storage() = default;
    std::unique_ptr<character> get_unit(const std::string &);
    void add_unit(std::unique_ptr<character>);
    character & operator[] (const std::string &);
    void clean_from_deadmen();
    size_t get_units_count();
    std::vector<std::string> get_unit_names();
};

/************************ CHILDREN ************************/

class barracks: public storage
{
};

class stadium: public storage
{
};

class stage: public storage
{
};

#endif /* storage_hpp */
