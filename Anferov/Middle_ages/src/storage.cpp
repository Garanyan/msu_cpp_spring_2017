//
//  storage.cpp
//  C++ project
//
//  Created by Игорь Анфёров on 11.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

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
