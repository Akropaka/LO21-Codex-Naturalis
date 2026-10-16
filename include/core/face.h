#pragma once
#include <map>
#include "utils.h"
#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;

namespace Core {

    class Face {
        private:
            map<Utils::SlotPosition,Utils::Ressource> borders;
            unsigned int score;
        public:
            Face(){};
            Face(unsigned int s) : score(s){};
            const map<Utils::SlotPosition,Utils::Ressource>& getBorders() const {return borders;}
            void AddSlot(Utils::SlotPosition sp, Utils::Ressource r);
    };

    void to_json(json& j, const Face& f);
}