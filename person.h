#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <map>
#include <memory>

#include "license.h"

class Person {
    std::string name;
    unsigned int wealth;
    std::map<std::string, std::unique_ptr<License>> licenses;

public: 
    Person(std::string name, unsigned int wealth=0);
   //virtual ~Person() = default;

    void work(std::string guild);
    //virtual void work(unsigned int) = 0;
    void increase_wealth(unsigned int i);
    std::string get_name() const;
};

#endif