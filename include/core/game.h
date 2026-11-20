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
        Player* playing;
        public:
            Game() : playing(nullptr), ressourcePile(Pile(CardType::Ressource)), goldenPile(Pile(CardType::Golden)), objectivePile(Pile(CardType::Goal)), shop(ressourcePile,goldenPile) {}
            void addPlayer(const Player& p) {players.push_back(p);}
            Player& getPlayer(const string& name);
            Player& getPlayer(const Player& player);
            Player& getCurrentPlayibgPlayer(){return *playing;}
            void givePoints(Player& p, int points);
            void nextTurn();
        };
}