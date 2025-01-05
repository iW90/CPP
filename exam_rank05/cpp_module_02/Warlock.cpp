#include "Warlock.hpp"


Warlock::Warlock() {}
Warlock::Warlock(const Warlock& other) { *this = other; }
Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
     std::cout << this->_name << ": This looks like another boring day." << std::endl; 
}

Warlock::~Warlock() {
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock& Warlock::operator=(const Warlock& other) { 
    this->_name = other._name;
    this->_title = other._title;
    return *this;
}

const std::string& Warlock::getName() const { return this->_name; }
const std::string& Warlock::getTitle() const { return this->_title; }

void Warlock::setTitle(const std::string& title) { this->_title = title; }

void Warlock::introduce() const {
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    this->_grimoire.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell) {
    this->_grimoire.forgetSpell(spell);
}

void Warlock::launchSpell(std::string spell, ATarget& target) {
    ASpell *launcher = _grimoire.createSpell(spell);
    if (launcher)
        (*launcher).launch(target);
}
