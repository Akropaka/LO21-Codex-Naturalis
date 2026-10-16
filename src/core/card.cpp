#include "card.h"

using json = nlohmann::json;

size_t Core::Card::amount = 0;

void Core::to_json(json& j, const Core::RessourceCard& r){
    j = json{{"name", r.getName()}, "face", r.getFace()};
}