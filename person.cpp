#include "person.h"

Person::Person(std::string, unsigned int wealth) : name{name}, wealth{wealth} {
    if(name == "") throw std::runtime_error("Name empty!");
}

void Person::work(std::string guild) {
    
}