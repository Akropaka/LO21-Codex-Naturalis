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
        card.visible = card.faces[0];
    }
    
    return card;
}

QJsonObject GoldenCard::toJson() const{
    QJsonObject json = Card::toJson();
    json["domaine"] = static_cast<int>(domaine);
    json["recto"] = faceCondition.toJson();
    return json;
}

GoldenCard GoldenCard::fromJson(const QJsonObject &json){
    GoldenCard card;

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
        card.faceCondition = FaceWithCondition::fromJson(faceJson.toObject());
        card.visible = card.faceCondition;
    }
    
    return card;
}

void Core::RessourceCard::SetupAutoVerso(){
    Face* f = new Face();

    f->AddSlot(Utils::SlotPosition::TopLeft, Utils::Ressource::Empty);
    f->AddSlot(Utils::SlotPosition::TopRight, Utils::Ressource::Empty);
    f->AddSlot(Utils::SlotPosition::BottomLeft, Utils::Ressource::Empty);
    f->AddSlot(Utils::SlotPosition::BottomRight, Utils::Ressource::Empty);
    
    if(domaine == Utils::Domaine::Animal){
        f->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Animal);
    }
    else if(domaine == Utils::Domaine::Champignon){
        f->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Champignon);
    }
    else if(domaine == Utils::Domaine::Insecte){
        f->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Insecte);
    }
    else if(domaine == Utils::Domaine::Insecte){
        f->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Insecte);
    }

    faces[1] = *f;
}

void Core::RessourceCard::Flip(){
    currentVisible = (currentVisible+1) % 2;
    visible = faces[currentVisible];
}

Loader::CardDatabase::CardDatabase(){
    const QString pathRessources = "ressources";
    const QDir directoryRessource(QDir(Json::JsonHandler::GetAssetsDirectory())
        .filePath(pathRessources));
    for (const QFileInfo& file : directoryRessource.entryInfoList({"*.json"}, QDir::Files)) {
        const QString name = file.completeBaseName();
        auto card = Json::JsonHandler::getInstance()->ReadCard(name, pathRessources);
        ressourceCards.push_back(static_cast<Core::RessourceCard*>(card));
    }

    const QString pathGolden = "doree";
    const QDir directoryGolden(QDir(Json::JsonHandler::GetAssetsDirectory())
        .filePath(pathGolden));
    for (const QFileInfo& file : directoryGolden.entryInfoList({"*.json"}, QDir::Files)) {
        const QString name = file.completeBaseName();
        auto card = Json::JsonHandler::getInstance()->ReadCard(name, pathGolden);
        goldenCards.push_back(static_cast<Core::GoldenCard*>(card));
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
    else if(ct == Utils::CardType::Golden){
        return vector<Core::Card*>(goldenCards.begin(),goldenCards.end());
    }
    throw "Erreur";
}

