#include "core.h"
#include <iostream>

/** 
 * Constructor for the Card class.
 * @param id The ID of the card.
 * @param name The name of the card.
 */
Card::Card(unsigned int id, const std::string& name) : id(id), name(name) {
    std::cout << "Carte ID : " << id << " | Nom : " << name << std::endl;
}

/**
 * Getter for the ID of the card.
 * @return The ID of the card.
 */
unsigned int Card::getId() const {
    return id;
}

/**
 * Getter for the name of the card.
 * @return The name of the card.
 */
std::string Card::getName() const {
    return name;
}