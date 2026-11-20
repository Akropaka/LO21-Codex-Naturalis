#pragma once
#include "card.h"
#include "board.h"
#include <string>
#include "utils.h"
#include <vector>

namespace Core {

    class Player;

    class Game {
        Pile ressourcePile;
        Pile goldenPile;
        Pile objectivePile;
        Shop shop;
        vector<Player> players;
        public:
            Game() : ressourcePile(Pile(CardType::Ressource)), goldenPile(Pile(CardType::Golden)), objectivePile(Pile(CardType::Goal)), shop(ressourcePile,goldenPile) {}
            void addPlayer(const Player& p) {players.push_back(p);}
            Player& getPlayer(const string& name);
            Player& getPlayer(const Player& player);
            void givePoints(Player& p, int points);
        };
}