#include "Warlock.hpp"


Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
     std::cout << this->_name << ": This looks like another boring day." << std::endl; 
}

Warlock::~Warlock() {
    std::cout << this->_name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell*>::iterator it = this->_grimoire.begin(); it != this->_grimoire.end(); it++)
        delete it->second;
    this->_grimoire.clear();
}

const std::string& Warlock::getName() const { return this->_name; }
const std::string& Warlock::getTitle() const { return this->_title; }

void Warlock::setTitle(const std::string& title) { this->_title = title; }

void Warlock::introduce() const {
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell && this->_grimoire.find(spell->getName()) == _grimoire.end())
        _grimoire[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spell) {
    if (this->_grimoire.find(spell) != _grimoire.end()) {
        delete _grimoire[spell];
        _grimoire.erase(spell);
    }
}

void Warlock::launchSpell(std::string spell, ATarget& target) {
    if (this->_grimoire.find(spell) != _grimoire.end())
        _grimoire[spell]->launch(target);
}
