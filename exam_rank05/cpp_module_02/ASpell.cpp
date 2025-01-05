#include "ASpell.hpp"


ASpell::~ASpell() {}
ASpell::ASpell() {}
ASpell::ASpell(std::string name, std::string effect) : _name(name), _effect(effect) {}
ASpell::ASpell(const ASpell& other) { *this = other; }

const ASpell& ASpell::operator=(const ASpell& other) {
    this->_name = other._name;
    this->_effect = other._effect;
    return *this;
}

std::string ASpell::getName() const { return _name; }
std::string ASpell::getEffect() const { return _effect; }

void ASpell::launch(const ATarget& target) {
    target.getHitBySpell(*this);
}
