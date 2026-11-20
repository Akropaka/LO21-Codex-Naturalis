#include "player.h"

using namespace Core;

void Player::removeCardFromHand(const string& name){
    auto toRemove = hand.end();
    for(auto it = this->hand.begin(); it != hand.end(); it++){
        if((*it)->getName().toStdString() == name){
            toRemove = it;
        }
    }
    if(toRemove != hand.end()){
        delete *toRemove;
        hand.erase(toRemove);
    }
    else{
        // throw "Error";
    }
}

void Player::setSecretObjective(ObjectiveCard& oc){
    this->secretObjective = &oc;
}

void Player::drawCardFromPile(Pile& p){
    if (p.getCount() == 0) {
        throw "Pile vide";
    }

    auto card = p.PickCard();
    addCardToHand(*card);
}
