#pragma once
#include <string>
#include <map>
#include "utils.h"
#include "core/card.h"

/**
 * @class Board
 * @brief Represents the game board, which holds cards at specific positions for a player.
 */
class Board {
    private:
        std::map<Vector2, Card> cards;
    public:
        Board();
        Card getCardAt(const Vector2& position) const;
        void setCardAt(const Vector2& position, const Card& card);
};