#include "card.h"

using json = nlohmann::json;

size_t Core::Card::amount = 0;

const Core::Face& Core::RessourceCard::getFace(unsigned int i) const {
    if(i>1 || i<0){
        throw "ERROR";
    }
    else{
        return faces[i];
    }
}