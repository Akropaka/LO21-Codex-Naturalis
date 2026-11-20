#include "board.h"

using namespace Core;

unsigned int Board::getRessourceCount(Utils::Ressource ressource){
    unsigned int count = 0;
    for(auto it = cards.begin(); it != cards.end(); it++){
        Face f = it->second->getVisibleFace();
        count += f.getRessourceCount(ressource);
    }
    return count;
}

void Board::addCard(Utils::Vector2i pos, RessourceCard& card){
    if(cards[pos]){
        return; // Une carte existe déjà à cet emplacement
    }
    else{
        cards[pos] = &card;
    }
}

void Board::addObjectiveCard(ObjectiveCard& card){
    secretObjective = &card;
}

bool Board::doesCardExist(Utils::Vector2i pos){
    if(cards[pos]){
        return true;
    }
    return false;
}

Card& Board::getCard(Utils::Vector2i pos){
    return *(cards[pos]);
}