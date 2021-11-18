#include "person.h"

// BASE CLASS PERSON
Person::Person(std::string, unsigned int wealth) : name{name}, wealth{wealth} {
    if(name == "") throw std::runtime_error("Name empty!");
}

void Person::work(std::string guild) {
    auto found_at = licenses.find(guild);
    if(found_at != licenses.end())
        if(found_at->second->valid())
            found_at->second->use();
    throw std::runtime_error("No licenses left"); // this should get executed always
}

void Person::increase_wealth(unsigned int i) { wealth += i; }
std::string Person::get_name() const { return name; }

bool Person::pay_fee(unsigned int i) {
    if(wealth <= i) return false;
    else return true;
}

void Person::receive_license(std::unique_ptr<License> l) {
    // auto found_at = licenses.find(l->get_guildname());
    // if(found_at != licenses.end())
    //     licenses.erase(found_at);
    // licenses.insert(std::pair<std::string, std::unique_ptr<License>>(l->get_guildname(), std::make_unique<License>(*l)));
    licenses[l->get_guildname()] = std::make_unique<License>(*l);
}

void Person::transfer_license(std::string l, std::shared_ptr<Person> p) {
    auto found_at = licenses.find(l);
    if(found_at == licenses.end())
        throw std::runtime_error("No license l found");
    p->receive_license(std::make_unique<License>(*(found_at->second))); // FIXME: maybe another derefrence
    licenses.erase(found_at);
}

bool Person::eligible(std::string l) const {
    auto found_at = licenses.find(l);
    if(found_at != licenses.end()) // if not end = if found
        return true;
    else 
        return false;
}

std::ostream& Person::print(std::ostream& o) const {
    o << name << ", " << wealth << " Coins, {";
    bool first{true};
    for(auto it = licenses.begin(); it != licenses.end(); ++it) {
        if(it != licenses.begin()) o << ", " << *(it->second);
        else o << *(it->second);
    }
    return o << "}]";
}

std::ostream& operator<<(std::ostream& o, const Person& rop) {
    return rop.print(o);
}


// WORKER FROM PERSON
Worker::Worker(std::string name, unsigned int wealth) : Person(name, wealth) {}

void Worker::work(unsigned int i) { increase_wealth(i); }

std::ostream& Worker::print(std::ostream& o) const {
    o << "[Worker ";
    return Person::print(o);
}


// Superworker FROM PERSON
Superworker::Superworker(unsigned int fee, std::string name, unsigned int wealth) : Person(name, wealth) {}

void Superworker::work(unsigned int i) { increase_wealth(i + fee); }

std::ostream& Superworker::print(std::ostream& o) const {
    o << "[Superworker ";
    return Person::print(o);
}