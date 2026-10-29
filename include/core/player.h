#pragma once
#include <vector>
#include "card.h"
#include "board.h"
#include <string>

namespace Core {

    class Player {
        private:
            vector<Card> hand;
            Board board;
            unsigned int score;
            string name;
        public:
            Player(const string& n) : name(n), score(0) {}
            void setBoard(const Board& b){board = b;}
            void addScore(unsigned int s){score += s;}
    };
}