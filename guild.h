#ifndef GUILD_H
#define GUILD_H

#include <string>
#include <map>
#include <memory>
#include <vector>

#include "person.h"

class Guild{
    std::string name;
    unsigned int fee;
    unsigned int salary;
    std::map<std::string, std::shared_ptr<Person>> members;

public:
    Guild(std::string name, unsigned fee, unsigned sal, const std::vector<std::shared_ptr<Person>>& players = {});
    bool add_member(std::shared_ptr<Person> p);
    bool remove_member(std::string n);
    void grant_license(std::string n);
    bool offer_job(std::shared_ptr<Person> p) const;

    std::ostream& print(std::ostream& o) const;
};

std::ostream& operator<<(std::ostream& o, const Guild& rop);

#endif