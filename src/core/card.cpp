#include "core/card.h"
#include "core/face.h"
#include <iostream>

int Card::num_card = 0;

/** 
 * Constructor for the Card class.
 * @param id The ID of the card.
 * @param name The name of the card.
 */
Card::Card(const std::string& name, CardDomaine domaine) : id(num_card++), name(name), domaine(domaine) {
    std::cout << "Carte ID : " << id << " | Nom : " << name << " | Domaine : " << static_cast<int>(domaine) << std::endl;
}

void Card::setFace(Face& face) {
    faces[static_cast<int>(face.getFaceType())] = face;
}

// Refactor to SETUP CARD with only RECTO
void Card::setupCard(Face& recto) {
    setFace(recto);
    // CALCULER le VERSO !
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