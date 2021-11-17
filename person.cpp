#include "person.h"

Person::Person(std::string, unsigned int wealth) : name{name}, wealth{wealth} {
    if(name == "") throw std::runtime_error("Name empty!");
}

void Person::work(std::string guild) {
    auto found_at = licenses.find(guild);
    if(found_at != licenses.end())
        if(found_at->second->valid())
            found_at->second->use();
    throw std::runtime_error("No licenses left"); // this should get executed always
}

void Person::increase_wealth(unsigned int i) { ++wealth; }
std::string Person::get_name() const { return name; }

bool Person::pay_fee(unsigned int i) {
    if(wealth <= i) return false;
    else return true;
}

void Person::receive_license(std::unique_ptr<License> l) {
    auto found_at = licenses.find(l->get_guildname());
    if(found_at != licenses.end())
        licenses.erase(found_at);
    licenses //TODO: FIXME: CONTINUE HERE
}