#pragma once
#include <vector>
#include "card.h"
#include "board.h"
#include <string>
#include <memory>

namespace Core {

    class Player {
        private:
            vector<Card*> hand;
            ObjectiveCard* secretObjective;
            Board board;
            unsigned int score;
            string name;
        public:
            Player(const string& n) : name(n), score(0) {}
            void setBoard(const Board& b){board = b;}
            void addScore(unsigned int s){score += s;}
            const string& getName() const { return name; }
            unsigned int getScore() const { return score; }
            const vector<Card*>& getHand() const { return hand; }
            void addCardToHand(const Card& c) { hand.push_back(c.clone());}
            void drawCardFromPile(Pile& p);
            void playCardToBoard(RessourceCard& c, Vector2i pos);
            void removeCardFromHand(const string& name);
            void setSecretObjective(ObjectiveCard& oc);
            ObjectiveCard& getSecretObjective(){return *secretObjective;}
    };
}