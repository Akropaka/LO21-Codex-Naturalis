#include "face.h"

void Core::Face::AddSlot(Utils::SlotPosition sp, Utils::Ressource r) {
    if(borders.find(sp) != borders.end())
    {
        throw "ERROR";
    }
    this->borders[sp] = r;
}

void Core::to_json(json& j, const Face& f){
    j = json{{"score",f.getScore()},{"borders",f.getBorders()}};
}