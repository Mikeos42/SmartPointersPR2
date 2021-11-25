#include <iostream>

#include "license.h"
#include "person.h"
#include "guild.h"

using namespace std;

int main() {
  Guild Wir{"Unsere Gilde", 1, 1000};
  shared_ptr<Person> Nik = make_shared<Superworker>(100, "Niklas", 500);
  // Superworker Nik{100, "Niklas", 500};

  Wir.add_member(Nik);

  cout << *Nik << endl;
  Wir.offer_job(Nik);
  cout << *Nik << endl;

} 