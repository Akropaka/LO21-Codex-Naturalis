#include "core.h"
#include <iostream>

/** 
 * Constructor for the Card class.
 * @param id The ID of the card.
 * @param name The name of the card.
 */
Card::Card(unsigned int id, const std::string& name, CardDomaine domaine) : id(id), name(name), domaine(domaine) {
    std::cout << "Carte ID : " << id << " | Nom : " << name << " | Domaine : " << static_cast<int>(domaine) << std::endl;
}

void Card::setFace(Face& face) {
    faces[static_cast<int>(face.getFaceType())] = face;
}

void Card::setupCard(Face& face_one, Face& face_two) {
    setFace(face_one);
    setFace(face_two);
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