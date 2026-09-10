#pragma once
#include <string>

class Card {
    public:
        Card(unsigned int id, const std::string& name);
        unsigned int getId() const;
        std::string getName() const;

    private:
        unsigned int id;
        std::string name;
};