#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "core.h"
#include "utils.h"
#include <vector>

using namespace std;

vector<Card> loadCSVToCards(const std::string& filename) {
    vector<Card> cards;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        throw "Error opening file: " + filename;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        unsigned int id = 0;
        std::string name;
        CardDomaine domaine = static_cast<CardDomaine>(0);

        while (std::getline(ss, cell, ';')) {
            if (id == 0) {
                id = static_cast<unsigned int>(std::stoi(cell));
            } else if (name.empty()) {
                name = cell;
            } else if (domaine == static_cast<CardDomaine>(0)) {
                domaine = static_cast<CardDomaine>(std::stoi(cell));
            }
        }
        Card card(id, name, domaine);
        // Add the card to your collection or process it as needed
        cards.push_back(card);
    }

    file.close();
    return cards;
}