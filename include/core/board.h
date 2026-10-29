#pragma once
#include "utils.h"
#include <QMap>
#include "card.h"

namespace Core {
    /*! \class Board
        \author None
        \brief A class that represent the board of a Player

        Use of QMap instead of Map while be easier to handle when saving the game
    */
    class Board {
        private:
            QMap<Vector2i, Card> cards;
        public:
            Board() : cards(QMap<Vector2i, Card>()) {}
            void addCard(Vector2i pos, const Card& card);
    };
}