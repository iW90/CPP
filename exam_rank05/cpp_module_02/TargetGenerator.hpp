#pragma once

#include <map>
#include "ATarget.hpp"


class ATarget;
class TargetGenerator {
    private:
        std::map<std::string, ATarget*> _targets;

        TargetGenerator(const TargetGenerator& other);
        TargetGenerator& operator=(const TargetGenerator& other);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& type);
        ATarget* createTarget(const std::string& target);

};
