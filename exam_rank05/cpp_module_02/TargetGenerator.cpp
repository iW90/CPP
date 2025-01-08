#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    for (std::map<std::string, ATarget*>::iterator it = this->_targets.begin(); it != this->_targets.end(); it++)
        delete it->second;
    this->_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target && this->_targets.find(target->getType()) == _targets.end())
        _targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string& type) {
    if (this->_targets.find(type) != _targets.end()) {
        delete _targets[type];
        _targets.erase(type);
    }
}

ATarget* TargetGenerator::createTarget(const std::string& target) {
    if (this->_targets.find(target) != _targets.end())
        return _targets[target];
    return NULL;
}
