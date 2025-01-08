#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"


class ATarget;
class ASpell {
    protected:
        std::string _name;
        std::string _effects;

    public:
        virtual ~ASpell();
        virtual ASpell* clone() const = 0;
        
        ASpell(std::string name, std::string effects);

        const std::string& getName() const;
        const std::string& getEffects() const;

        void launch(const ATarget& target) const;
};