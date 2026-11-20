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

void Player::playCardToBoard(RessourceCard& c, Vector2i pos){
    board.addCard(pos,*(c.clone()));
    this->removeCardFromHand(c.getName().toStdString());
}

bool Player::operator==(const Player& other){
    if(this->getName() == other.getName()){
        return true;
    }
    else{
        return false;
    }
}
