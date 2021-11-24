#include "guild.h"

Guild::Guild(std::string name, unsigned fee, unsigned sal, const std::vector<std::shared_ptr<Person>>& players) :
name{name}, fee{fee}, salary{sal} {
    if(name == "") throw std::runtime_error("Name empty!");
    if(!fee) throw std::runtime_error("Fee zero");
    if(!sal) throw std::runtime_error("Salary zero");

    std::map<std::string, int> temp;
    for(const auto& p : players)
        if(temp[p->get_name()]++ == 1)
            throw std::runtime_error("Double Players");
        else
            members.insert(std::pair<std::string, std::shared_ptr<Person>>(p->get_name(), p));


    //TODO: check if person appears multiple times
}

bool Guild::add_member(std::shared_ptr<Person> p) {
    auto found_at = members.find(p->get_name());
    if(found_at != members.end()) // if found abort
        return false;

    members.insert(std::pair<std::string, std::shared_ptr<Person>>(p->get_name(), p));
    return true;
}

bool Guild::remove_member(std::string n) {
    auto found_at = members.find(n);
    if(found_at == members.end()) // if not found abort
        return false;

    members.erase(n);
    return true;
}

void Guild::grant_license(std::string n) {
    auto found_at = members.find(n);
    if(found_at == members.end())
        throw std::runtime_error("Not in Guild");
    
    if(!(found_at->second->pay_fee(fee)))
        throw std::runtime_error("Cannot afford");
    
    License l(name, salary);
    found_at->second->receive_license(std::make_unique<License>(l));
}

bool Guild::offer_job(std::shared_ptr<Person> p) const {
    auto in_guild = members.find(p->get_name()) != members.end(); // not found
    auto has_license = p->eligible(name);

    if(!in_guild && !has_license) return false;
    else if(!in_guild && has_license) { p->work(name); return true; } // FIXME: for salary?? 
    else if(in_guild) { p->work(salary * 2); return true; }
}

std::ostream& Guild::print(std::ostream& o) const {
    o << "[" << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
    for(auto it = members.begin(); it != members.end(); ++it) {
        if(it != members.begin()) o << ", " << it->first;
        else o << it->first;
    }
    return o << "}]";
}

std::ostream& operator<<(std::ostream& o, const Guild& rop) {
    return rop.print(o);
}