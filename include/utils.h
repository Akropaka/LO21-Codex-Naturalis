#pragma once
#include <vector>
#include "core/card.h"
#include <string>

class Card;

/**
 * @brief Loads cards from a CSV file.
 * 
 * @param filename 
 * @return std::vector<Card> 
 */
std::vector<Card> loadCSVToCards(const std::string& filename);

/**
 * @brief Represents a 2D vector with x and y coordinates.
 * @details This struct is used to represent positions or directions in a 2D space, such as coordinates on a game board.
 */
struct Vector2{
    int x;
    int y;
};

enum class FaceType {
    RECTO,
    VERSO
};

enum class CardDomaine {
    NONE,
    FONGIQUE,
    ANIMALE,
    VEGETALE,
    ENTOMOLOGIQUE
};

enum class Corner {
    CENTER,
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
};

enum class SlotType {
    RESSOURCE_FONGIQUE,
    RESSOURCE_ANIMALE,
    RESSOURCE_VEGETALE,
    RESSOURCE_ENTOMOLOGIQUE,
    OBJECT_FEATHER,
    OBJECT_INK,
    EMPTY
};