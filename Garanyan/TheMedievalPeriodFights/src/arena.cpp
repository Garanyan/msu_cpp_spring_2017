#include "arena.hpp"

std::unique_ptr<Person> Barrack::getUnit(const std::string & s) {
    std::unique_ptr<Person> tmp(std::move(units.at(s)));
    units.erase(s);
    return tmp;
}

void Barrack::addUnit(std::unique_ptr<Person> c) {
    try {
        units.at(c->get_name());
    } catch (std::out_of_range) {
        units.insert(std::pair<std::string, std::unique_ptr<Person>>
                     (c->get_name(), std::move(c)));
        return;
    }
    throw std::logic_error("Name duplicating occured!");
}

Person & Barrack::operator[](const std::string & s) {
    return *(units.at(s));
}
