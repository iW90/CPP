#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"


class ASpell;
class ATarget {
    protected:
        std::string _type;

    public:
        virtual ~ATarget();
        virtual ATarget* clone() const = 0;
        
        ATarget(std::string type);

        const std::string& getType() const;

        void getHitBySpell(const ASpell& spell) const;
};