#pragma once
#include "card.h"
#include "utils.h"
#include <vector>

namespace Core {

    class Player;

    class Game {
        Pile ressourcePile;
        Pile goldenPile;
        Pile objectivePile;
        vector<Player> players;
        public:
            Game() : ressourcePile(Pile(CardType::Ressource)), goldenPile(Pile(CardType::Golden)), objectivePile(Pile(CardType::Goal)) {}
            void addPlayer(const Player& p) {players.push_back(p);}
            void givePoints(Player& p, int points);
        };
}