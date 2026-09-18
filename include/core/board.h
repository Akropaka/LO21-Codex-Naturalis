#pragma once
#include <string>
#include <map>
#include "utils.h"
#include "card.h"
#include "face.h"

class Board {
    private:
        std::map<Vector2, Card> cards;
        Card getCardAt(const Vector2& position) const;
        void setCardAt(const Vector2& position, const Card& card);
};