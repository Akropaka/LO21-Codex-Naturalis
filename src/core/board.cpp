#include "board.h"

using namespace Core;

unsigned int Board::getRessourceCount(Utils::Ressource ressource){
    unsigned int count = 0;
    for(auto it = cards.begin(); it != cards.end(); it++){
        RessourceCard rc = dynamic_cast<RessourceCard&>(*it);
        Face f = rc.getVisibleFace();
        f.getRessourceCount(ressource);
        count++;
    }
    return count;
}