#include <iostream>

#include "license.h"

int main() {
  License a("Helmut", 500);

  std::cout << a.get_guildname() << std::endl;
  std::cout << a.get_salary() << std::endl;

  std::cout << a;
} 