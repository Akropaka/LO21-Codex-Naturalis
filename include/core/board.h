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

    class Card;

    class Board {
        private:
            QMap<Utils::Vector2i, Card> cards;
        public:
            Board() : cards(QMap<Utils::Vector2i, Card>()) {}
            void addCard(Utils::Vector2i pos, const Card& card);
            bool doesCardExist(Utils::Vector2i pos);
            Card& getCard(Utils::Vector2i pos);
            unsigned int getRessourceCount(Utils::Ressource ressource);
    };
}