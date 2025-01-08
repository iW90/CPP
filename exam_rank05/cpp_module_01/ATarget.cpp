#include "ATarget.hpp"


ATarget::~ATarget() {}
ATarget::ATarget(std::string type) : _type(type) {}

const std::string& ATarget::getType() const { return _type; }

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}
