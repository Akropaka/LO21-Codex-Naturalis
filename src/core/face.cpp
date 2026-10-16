#include "face.h"

void Core::Face::AddSlot(Utils::SlotPosition sp, Utils::Ressource r) {
    if(borders.find(sp) != borders.end())
    {
        throw "ERROR";
    }
    this->borders[sp] = r;
}

json Core::Face::to_json() const{
    return json{{"score",getScore()},{"borders",getBorders()}};
}