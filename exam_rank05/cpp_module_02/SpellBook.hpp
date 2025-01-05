#pragma once

#include <map>
#include "ASpell.hpp"

class ASpell;
class SpellBook {
    private:
        std::map<std::string, ASpell*> _spells;

        SpellBook(const SpellBook& other);
        SpellBook& operator=(const SpellBook& other);

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spell);
        ASpell* createSpell(const std::string& spell);
};