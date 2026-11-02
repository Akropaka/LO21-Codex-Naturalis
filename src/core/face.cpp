#include "face.h"
#include "board.h"
#include "card.h"

using namespace Core;

void Face::AddSlot(Utils::SlotPosition sp, Utils::Ressource r) {
    if(borders.find(sp) != borders.end())
    {
        throw "ERROR";
    }
    this->borders[sp] = r;
}

bool Face::AddNeightboorCard(Utils::SlotPosition sp, const Card& c){
    if(borders.find(sp) == borders.end()){
        return false;
    }
    if(neightboors.find(sp) != neightboors.end()){
        return false;
    }
    neightboors[sp] = c;
    return true;
}

unsigned int Face::getRessourceCount(Utils::Ressource ressource){
    unsigned int count = 0;
    for(auto it = borders.begin(); it != borders.end(); it++){
        if(neightboors.find(it->first) != neightboors.end()){
            // Le coin est obstrué, on passe
        }
        else if(it->second == ressource){
            // La ressource correspond
            count++;
        }
    }
    return count;
}

void FaceWithCondition::AddCondition(unsigned int quantity, Utils::Ressource ressource){
    if(quantity<=0){
        return;
    }
    if(conditions.find(ressource) != conditions.end()){
        return;
    }
    conditions[ressource] = quantity;
}

bool FaceWithCondition::isPlayable(Board& board){
    for(auto it = conditions.begin(); it != conditions.end(); it++){
        Utils::Ressource r = it->first;
        if(board.getRessourceCount(r) < it->second){
            return false;
        }
    }
    return true;
}

vector<Utils::Ressource> FaceWithCondition::getRessourcesType(){
    vector<Utils::Ressource> resources;
    for(auto it = conditions.begin();it != conditions.end(); it++){
        resources.push_back(it->first);
    }
    return resources;
}

QJsonObject Face::toJson() const {
    QJsonObject json = scoreCondition.get()->toJson();

    QJsonObject bordersJson;
    
    for (auto it = getBorders().begin(); it != getBorders().end(); ++it) {
        QString keyStr = QString::number(static_cast<int>(it->first)); 
        int valueInt = static_cast<int>(it->second);
        bordersJson.insert(keyStr, valueInt);
    }

    json["borders"] = bordersJson;

    return json;
}

Face Face::fromJson(const QJsonObject& json) {
    Face face;

    face.scoreCondition = ScoreCondition::fromJson(json);

    const QJsonValue bordersValue = json.value("borders");
    if (bordersValue.isObject()) {
        const QJsonObject bordersJson = bordersValue.toObject();
        for (auto it = bordersJson.begin(); it != bordersJson.end(); ++it) {
            auto position = static_cast<Utils::SlotPosition>(it.key().toInt());
            auto ressource = static_cast<Utils::Ressource>(it.value().toInt());
            face.AddSlot(position, ressource);
        }
    }
    
    return face;
}

QJsonObject FaceWithCondition::toJson() const {
    QJsonObject json = Face::toJson();

    QJsonObject conditionsJson;

    for (auto it = conditions.begin(); it != conditions.end(); ++it) {
        QString keyStr = QString::number(static_cast<int>(it->first)); 
        int valueInt = static_cast<int>(it->second);
        conditionsJson.insert(keyStr, valueInt);
    }

    json["conditions"] = conditionsJson;

    return json;
}

FaceWithCondition FaceWithCondition::fromJson(const QJsonObject &json){
    Face face = Face::fromJson(json);
    FaceWithCondition faceCondition(face);
    
    const QJsonValue conditionsValue = json.value("conditions");
    if (conditionsValue.isObject()) {
        const QJsonObject bordersJson = conditionsValue.toObject();
        for (auto it = bordersJson.begin(); it != bordersJson.end(); ++it) {
            auto quantity = static_cast<unsigned int>(it.value().toInt());
            auto ressource = static_cast<Utils::Ressource>(it.key().toInt());
            faceCondition.AddCondition(quantity, ressource);
        }
    }

    return faceCondition;
}