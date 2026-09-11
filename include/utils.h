#pragma once
#include <vector>
#include "core.h"
#include <string>

class Card;

std::vector<Card> loadCSVToCards(const std::string& filename);

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