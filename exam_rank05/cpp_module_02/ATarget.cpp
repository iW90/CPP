#include "ATarget.hpp"


ATarget::~ATarget() {}
ATarget::ATarget() {}
ATarget::ATarget(std::string type) : _type(type) {}
ATarget::ATarget(const ATarget& other) { *this = other; }

const ATarget& ATarget::operator=(const ATarget& other) {
    this->_type = other._type;
    return *this;
}

const std::string& ATarget::getType() const { return _type; }

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << this->_type << " has been " << spell.getEffect() << "!" << std::endl;
}
