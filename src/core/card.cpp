#include "core/card.h"
#include "core/face.h"
#include <iostream>

int Card::num_card = 0;

/** 
 * Constructor for the Card class.
 * @param id The ID of the card. (automatically assigned via static)
 * @param name The name of the card. (used to identify the card)
 * @param domaine The domain of the card.
 */
Card::Card(const std::string& name, CardDomaine domaine) : id(num_card++), name(name), domaine(domaine) {
    std::cout << "Carte ID : " << id << " | Nom : " << name << " | Domaine : " << static_cast<int>(domaine) << std::endl;
}

/**
 * Sets the face of the card.
 * @param face The face to be set.
 * This method will set the face in the appropriate position (recto or verso) based on the face type.
 */
void Card::setFace(Face& face) {
    faces[static_cast<int>(face.getFaceType())] = face;
}

/**
 * Sets up the card with the given recto face.
 * The verso face will be calculated based on the recto face.
 * @param recto The recto face of the card.
 */
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