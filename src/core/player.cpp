#include "player.h"

using namespace Core;

void Player::removeCardFromHand(const string& name){
    auto toRemove = hand.end();
    for(auto it = this->hand.begin(); it != hand.end(); it++){
        if(it->get()->getName().toStdString() == name){
            toRemove = it;
        }
    }
    if(toRemove != hand.end()){
        hand.erase(toRemove);
    }
    else{
        // throw "Error";
    }
}

void Player::setSecretObjective(ObjectiveCard& oc){
    this->secretObjective = &oc;
}