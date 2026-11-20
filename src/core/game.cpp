#include "game.h"
#include "player.h"

using namespace Core;

Player& Game::getPlayer(const string& name){
    for(auto it = players.begin(); it != players.end();it++){
        if(it->getName() == name){
            return *it;
        }
    }
    throw "Player doesnt exist";
};

Player& Game::getPlayer(const Player& player){
    for(auto it = players.begin(); it != players.end();it++){
        if(it->getName() == player.getName()){
            return *it;
        }
    }
    throw "Player doesnt exist";
}

void Game::givePoints(Player& p, int points){
    for(auto it = players.begin(); it != players.end(); it++){
        if(p.getName() == it->getName()){
            it->addScore(points);
        }
    }
}