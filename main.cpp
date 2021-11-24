#include <iostream>

#include "license.h"
#include "person.h"
#include "guild.h"

using namespace std;

int main() {
  // shared_ptr<Person> Miki = make_shared<Worker>("Mikey", 1000);
  // shared_ptr<Person> Jessica = make_shared<Worker>("Jessica");
  // shared_ptr<Person> Nik = make_shared<Superworker>(10, "Nik der Grosse");

  // shared_ptr<Person> Flo = make_shared<Worker>("Florian");
  // shared_ptr<Person> Nira = make_shared<Superworker>(20, "Nira die Beste");
  
  // vector<shared_ptr<Person>> in_gilde {Miki, Jessica, Nik}; // personen in Gilde

  // Guild Wir = {"Die ksjxjdkdj Lerngruppe", 50, 100, {Miki, Jessica}};
  // Wir.add_member(Nik);
  // Wir.remove_member(Miki->get_name());
  // Wir.add_member(Miki);

  // cout << Wir << endl;

  // Wir.grant_license("Mikey");
  // Miki->work("Die ksjxjdkdj Lerngruppe");
  // Miki->work("Die ksjxjdkdj Lerngruppe");
  // Miki->work("Die ksjxjdkdj Lerngruppe");
  // cout << *Miki << endl;

  /* Testing License */
  try {
    cout << "Test License 1: ";

    License a{"What", 0};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  try {
    cout << "Test License 2: ";

    License a{"", 100};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  {
    cout << "Test License 3: ";

    License a{"Boom", 200};

    bool t1 = a.get_guildname() == "Boom";
    bool t2 = a.get_salary() == 200;

    if(t1 + t2 == 2) cout << "WELL DONE" << endl;
    else cout << "X";
  }

  {
    cout << "Test License 4: ";

    License a{"Boom", 200};

    bool t1 = a.valid();
    bool t2 = a.use();
    bool t3 = a.use();
    bool t4 = a.use();
    bool t5 = a.use();
    bool t6 = a.use();
    bool t7 = a.valid();


    if(t1 && t2 && t3 && t4 && t5 && !t6 && !t7) cout << "WELL DONE" << endl;
    else cout << "X";
  }

  {
    cout << "Test License 5: " << endl;

    License a{"Boom", 200};

    cout << a << endl;
    cout << "[License for Boom, Salary: 200, Used: 0]" << endl;
  }

  cout << endl;

  /* Testing Guild */
  shared_ptr<Person> Miki = make_shared<Worker>("Mikey", 1000);
  shared_ptr<Person> Jessica = make_shared<Worker>("Jessica");
  shared_ptr<Person> Nik = make_shared<Superworker>(10, "Nik der Grosse", 100000);

  shared_ptr<Person> Flo = make_shared<Worker>("Florian");
  shared_ptr<Person> Nira = make_shared<Superworker>(20, "Nira die Beste");
  
  vector<shared_ptr<Person>> GildenVector {Miki, Jessica}; // personen in Gilde
  vector<shared_ptr<Person>> FalscherVector {Miki, Jessica, Miki}; // doppelte Daten

  Guild Wir = {"Die ksjxjdkdj Lerngruppe", 50, 100, GildenVector};

  try {
    cout << "Test Guild 1: ";

    Guild a = {"", 50, 100, GildenVector};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  try {
    cout << "Test Guild 2: ";

    Guild a = {"Boom", 0, 100, GildenVector};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  try {
    cout << "Test Guild 3: ";

    Guild a = {"Boom", 50, 0, GildenVector};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  try {
    cout << "Test Guild 4: ";

    Guild a = {"Boom", 50, 100, FalscherVector};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  {
    cout << "Test Guild 5: ";

    Guild a = {"Boom", 50, 100, GildenVector};
    bool t1 = a.add_member(Nik);
    bool t2 = a.add_member(Nik);
    bool t3 = a.remove_member(Nik->get_name());
    bool t4 = a.remove_member(Nik->get_name());

    if(t1 && !t2 && t3 && !t4) cout << "WELL DONE" << endl;
    else cout << "X";
  }

  try {
    cout << "Test Guild 6: ";

    Guild a = {"Boom", 50000, 100, GildenVector};
    a.grant_license(Miki->get_name());

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  try {
    cout << "Test Guild 7: ";

    Guild a = {"Boom", 50, 100, GildenVector};
    a.grant_license(Nira->get_name());

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  {
    cout << "Test Guild 8: ";

    Guild a = {"Boom", 50, 100, GildenVector};
    bool t1 = a.add_member(Nik);
    bool t2 = a.add_member(Nik);
    bool t3 = a.remove_member(Nik->get_name());
    bool t4 = a.remove_member(Nik->get_name());

    if(t1 && !t2 && t3 && !t4) cout << "WELL DONE" << endl;
    else cout << "X";
  }

  {
    cout << "Test Guild 9: ";

    Guild a = {"Boom", 50, 100, GildenVector};
    bool t1 = a.offer_job(Miki); // true
    a.add_member(Nik);
    a.grant_license(Nik->get_name());
    a.remove_member(Nik->get_name());
    bool t2 = a.offer_job(Nik); // true
    bool t3 = a.offer_job(Nira); // false
    a.offer_job(Nik);
    a.offer_job(Nik);
    a.offer_job(Nik);
    bool t4 = a.offer_job(Nik); // false

    if(t1 && t2 && !t3 && !t4) cout << "WELL DONE" << endl;
    else cout << "X";
  }

  {
    cout << "Test Guild 10: " << endl;

    Guild a = {"Boom", 50, 100, GildenVector};
    a.add_member(Nira);

    cout << a << endl;
    cout << "[Boom, License fee: 50, Job salary: 100, {Jessica, Mikey, Nira die Beste}]" << endl;
  }

  cout << endl;

  /* Testing Person */
  try {
    cout << "Test Person 1: ";

    Worker Selina {"", 100};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  try {
    cout << "Test Person 2: ";

    Superworker Selina {10 ,"", 100};

    cout << "X";
  } catch (const exception& e) { cout << "WELL DONE" << endl; }

  {
    cout << "Test Person 3: ";

    Worker Selina {"Boom", 100};
    Selina.increase_wealth(1000);
    bool t1 = Selina.pay_fee(1100); // true
    bool t2 = Selina.pay_fee(1); // false
    bool t3 = Selina.get_name() == "Boom"; // true

    if(t1 && !t2 && t3) cout << "WELL DONE" << endl;
    else cout << "X";
  }

} 