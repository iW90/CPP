#pragma once

#include <string>
#include <iostream>


class Warlock {
    private:
        std::string _name;
        std::string _title;

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
};