#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <map>
#include <memory>

#include "license.h"

// BASE CLASS PERSON
class Person {
// protected:
    std::string name;
    unsigned int wealth;
    std::map<std::string, std::unique_ptr<License>> licenses;

public: 
    Person(std::string name, unsigned int wealth=0);
    virtual ~Person() = default; // FIXME: watch out, commented out

    void work(std::string guild);
    virtual void work(unsigned int) = 0;
    void increase_wealth(unsigned int i);
    std::string get_name() const;
    bool pay_fee(unsigned int i);
    void receive_license(std::unique_ptr<License> l);
    void transfer_license(std::string l, std::shared_ptr<Person> p);
    bool eligible(std::string l) const;

    virtual std::ostream& print(std::ostream& o) const;
};

std::ostream& operator<<(std::ostream& o, const Person& rop);


// WORKER FROM PERSON
class Worker :public Person {
public:
    Worker(std::string name, unsigned int wealth=0);

    void work(unsigned int i);

    std::ostream& print(std::ostream& o) const;
};

std::ostream& operator<<(std::ostream& o, const Worker& rop);


// SUPERWORKER FROM PERSON
class Superworker :public Person {
private:
    unsigned int fee;

public:
    Superworker(unsigned int fee, std::string name, unsigned int wealth=0);

    void work(unsigned int i);

    std::ostream& print(std::ostream& o) const;
};

std::ostream& operator<<(std::ostream& o, const Superworker& rop);

#endif