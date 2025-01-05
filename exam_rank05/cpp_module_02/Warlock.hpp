#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"


class Warlock {
    private:
        std::string _name;
        std::string _title;
        SpellBook _grimoire;

        Warlock();
        Warlock(const Warlock& other);
        Warlock& operator=(const Warlock& other);

    public:
        ~Warlock();
        Warlock(std::string name, std::string title);
        const std::string& getName() const;
        const std::string& getTitle() const;

        void setTitle(const std::string& title);

        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spell);
        void launchSpell(std::string spell, ATarget& target);
};