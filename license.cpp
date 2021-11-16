#include "license.h"

License::License(std::string name, unsigned int salary) {
    if(name == "") throw std::runtime_error("Name can't be empty");
    if(!salary) throw std::runtime_error("Salary can't be 0");
}

std::string License::get_guildname() const { return name; }
unsigned int License::get_salary() const { return salary; }
