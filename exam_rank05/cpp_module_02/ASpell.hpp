#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"


class ATarget;
class ASpell {
    protected:
        std::string _name;
        std::string _effect;

        ASpell();

    public:
        virtual ~ASpell();
        virtual ASpell* clone() const = 0;
        
        ASpell(std::string name, std::string effect);
        ASpell(const ASpell& other);
        const ASpell& operator=(const ASpell& other);

        std::string getName() const;
        std::string getEffect() const;

        void launch(const ATarget& target);
};