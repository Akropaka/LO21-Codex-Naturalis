#pragma once
#include "utils.h"
#include <map>
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
            map<Utils::Vector2i, RessourceCard*> cards;
            ObjectiveCard* secretObjective;
        public:
            Board() : cards(map<Utils::Vector2i, RessourceCard*>()) {}
            void addCard(Utils::Vector2i pos, RessourceCard& card);
            void addObjectiveCard(ObjectiveCard& card);
            bool doesCardExist(Utils::Vector2i pos);
            Card& getCard(Utils::Vector2i pos);
            unsigned int getRessourceCount(Utils::Ressource ressource);
    };
}