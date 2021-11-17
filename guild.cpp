#include "guild.h"

Guild::Guild(std::string name, unsigned fee, unsigned sal, const std::vector<std::shared_ptr<Person>>& players) :
name{name}, fee{fee}, salary{sal} {
    if(name == "") throw std::runtime_error("Name empty!");
    if(!fee) throw std::runtime_error("Fee zero");
    if(!sal) throw std::runtime_error("Salary zero");

    //TODO: check if person appears multiple times
}

bool Guild::add_member(std::shared_ptr<Person> p) {
    members.insert(std::pair<std::string, std::shared_ptr<Person>>(p->get_name(), p));
}