#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"

License::License(std::string name, unsigned int salary) : name{name}, salary{salary}, counter{0} {
    if(name == "") throw std::runtime_error("Name can't be empty");
    if(!salary) throw std::runtime_error("Salary can't be 0");

    //std::cout << *this; // log
}

std::string License::get_guildname() const { return name; }
unsigned int License::get_salary() const { return salary; }
bool License::valid() const { return counter <= 3; } // sure?
bool License::use() {
  if(!valid()) return false;
  ++counter;
  return true;
}

std::ostream& License::print(std::ostream& o) const {
  return o << "[License for " << name << ", Salary: " << salary << ", Used: " << counter << "]"; 
}

std::ostream& operator<<(std::ostream& o, const License& rop) {
  return rop.print(o);
}