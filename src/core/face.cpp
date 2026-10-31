#include "face.h"
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

QJsonObject Face::toJson() const {
    QJsonObject json;
    json["score"] = static_cast<int>(score);

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

    if (json.contains("score") && json["score"].isDouble()) {
        face.score = json["score"].toInt();
    }

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