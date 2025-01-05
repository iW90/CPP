#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"


class ASpell;
class ATarget {
    protected:
        std::string _type;

        ATarget();

    public:
        virtual ~ATarget();
        virtual ATarget* clone() const = 0;
        
        ATarget(std::string type);
        ATarget(const ATarget& other);
        const ATarget& operator=(const ATarget& other);

        const std::string& getType() const;

        void getHitBySpell(const ASpell& spell) const;
};