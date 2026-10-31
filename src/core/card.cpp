#include "card.h"
#include "json.h"
#include <QDir>

using namespace Core;

size_t Core::Card::amount = 0;
Loader::CardDatabase* Loader::CardDatabase::instance = nullptr;

const Core::Face& Core::RessourceCard::getFace(unsigned int i) const {
    if(i>1 || i<0){
        throw "ERROR";
    }
    else{
        return faces[i];
    }
}

QJsonObject Card::toJson() const{
    QJsonObject json;
    json["name"] = name;
    return json;
}

Card Card::fromJson(const QJsonObject &json){
    Card card;

    if(json.contains("name") && json["name"].isString()){
        card.name = json["name"].toString();
    }
    
    return card;
}

QJsonObject RessourceCard::toJson() const{
    QJsonObject json = Card::toJson();
    json["domaine"] = static_cast<int>(domaine);
    json["recto"] = this->getFace(0).toJson();
    return json;
}

RessourceCard RessourceCard::fromJson(const QJsonObject &json){
    RessourceCard card;

    if(json.contains("name") && json["name"].isString()){
        card.name = json["name"].toString();
    }

    if(json.contains("domaine")){
        card.domaine = static_cast<Utils::Domaine>(json["domaine"].toInt());
    }

    QJsonValue faceJson = json.value("recto");
    if (!faceJson.isObject()) {
        faceJson = json.value("face");
    }
    if (faceJson.isObject()) {
        card.faces[0] = Face::fromJson(faceJson.toObject());
    }
    
    return card;
}

Loader::CardDatabase::CardDatabase(){
    const QString pathRessources = "ressources";
    const QDir directory(QDir(Json::JsonHandler::GetAssetsDirectory())
        .filePath(pathRessources));
    for (const QFileInfo& file : directory.entryInfoList({"*.json"}, QDir::Files)) {
        const QString name = file.completeBaseName();
        auto card = Json::JsonHandler::getInstance()->ReadCard(name, pathRessources);
        ressourceCards.push_back(static_cast<Core::RessourceCard*>(card));
    }
}

Loader::CardDatabase* Loader::CardDatabase::getInstance(){
    if(instance){
        return instance;
    }

    instance = new CardDatabase();
    return instance;
}

vector<Core::Card*> Loader::CardDatabase::getCards(CardType ct) const {
    if(ct == Utils::CardType::Base){
        return baseCards;
    }
    else if(ct == Utils::CardType::Ressource){
        return vector<Core::Card*>(ressourceCards.begin(),ressourceCards.end());
    }
    throw "Erreur";
}