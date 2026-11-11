#include "game.h"
#include "player.h"

using namespace Core;

void Game::givePoints(Player& p, int points){
    for(auto it = players.begin(); it != players.end(); it++){
        if(p.getName() == it->getName()){
            it->addScore(points);
        }
    }
}