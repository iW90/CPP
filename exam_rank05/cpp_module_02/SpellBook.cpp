#include "SpellBook.hpp"


SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    for (std::map<std::string, ASpell*>::iterator it = this->_spells.begin(); it != this->_spells.end(); it++)
        delete it->second;
    this->_spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
    if (spell && this->_spells.find(spell->getName()) == _spells.end())
        _spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string spell) {
    if (this->_spells.find(spell) != _spells.end()) {
        delete _spells[spell];
        _spells.erase(spell);
    }
}

ASpell* SpellBook::createSpell(const std::string& spell) {
    if (this->_spells.find(spell) != _spells.end())
        return _spells[spell];
    return NULL;
}
