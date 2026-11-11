#include "card.h"
#include "json.h"
#include <QDir>

using namespace Core;

size_t Core::Card::amount = 0;
Loader::CardDatabase* Loader::CardDatabase::instance = nullptr;

const Face& Core::RessourceCard::getFace(unsigned int i) const {
    if(i>1 || i<0){
        throw "ERROR";
    }
    else{
        if(i==0){
            return *recto;
        }
        else{
            return *verso;
        }
    }
}

void Core::RessourceCard::setFace(const Face& face, unsigned int i) {
    auto copy = face.clone();

    if (i == 0) {
        recto = std::move(copy);
    } else if (i == 1) {
        verso = std::move(copy);
    } else {
        throw std::out_of_range("Indice de face invalide");
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
    json["recto"] = getFace(0).toJson();
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
        card.recto = std::make_shared<Face>(Face::fromJson(faceJson.toObject()));
        card.visible = card.recto;
    }
    
    return card;
}

QJsonObject GoldenCard::toJson() const{
    QJsonObject json = Card::toJson();
    json["domaine"] = static_cast<int>(domaine);
    json["recto"] = getFace(0).toJson();
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
        card.recto = std::make_shared<FaceWithCondition>(FaceWithCondition::fromJson(faceJson.toObject()));
        card.visible = card.recto;
    }
    
    return card;
}

QJsonObject ObjectiveCard::toJson() const{
    QJsonObject json = Card::toJson();
    json["objective"] = scoreCondition->toJson();
    return json;
}
ObjectiveCard ObjectiveCard::fromJson(const QJsonObject &json){
    // Maybe need to clone here ?
    ObjectiveCard card(json["name"].toString(),*ScoreCondition::fromJson(json["objective"].toObject()).get());
    return card;
}

void Core::RessourceCard::SetupAutoVerso(){
    verso = std::make_shared<Face>();

    verso->AddSlot(Utils::SlotPosition::TopLeft, Utils::Ressource::Empty);
    verso->AddSlot(Utils::SlotPosition::TopRight, Utils::Ressource::Empty);
    verso->AddSlot(Utils::SlotPosition::BottomLeft, Utils::Ressource::Empty);
    verso->AddSlot(Utils::SlotPosition::BottomRight, Utils::Ressource::Empty);
    
    if(domaine == Utils::Domaine::Animal){
        verso->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Animal);
    }
    else if(domaine == Utils::Domaine::Champignon){
        verso->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Champignon);
    }
    else if(domaine == Utils::Domaine::Insecte){
        verso->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Insecte);
    }
    else if(domaine == Utils::Domaine::Insecte){
        verso->AddSlot(Utils::SlotPosition::Center, Utils::Ressource::Insecte);
    }
}

void Core::RessourceCard::Flip(){
    if(visible == recto){
        visible = verso;
    }
    else{
        visible = recto;
    }
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

    const QString pathObjectives = "objectives";
    const QDir directoryObjectives(QDir(Json::JsonHandler::GetAssetsDirectory())
        .filePath(pathObjectives));
    for (const QFileInfo& file : directoryObjectives.entryInfoList({"*.json"}, QDir::Files)) {
        const QString name = file.completeBaseName();
        auto card = Json::JsonHandler::getInstance()->ReadCard(name, pathObjectives);
        objectiveCards.push_back(static_cast<Core::ObjectiveCard*>(card));
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
    else if(ct == Utils::CardType::Goal){
        return vector<Core::Card*>(objectiveCards.begin(),objectiveCards.end());
    }
    throw "Erreur";
}

Core::Pile::Pile(CardType ct){
    auto sourceCards = Loader::CardDatabase::getInstance()->getCards(ct);

    for(const Core::Card* card : sourceCards){
        if(ct == Utils::CardType::Base){
            cards.push_back(std::make_unique<Card>(*card));
        }
        else if(ct == Utils::CardType::Ressource){
            const auto* resourceCard = dynamic_cast<const RessourceCard*>(card);
            cards.push_back(std::make_unique<RessourceCard>(*resourceCard));
        }
        else if(ct == Utils::CardType::Golden){
            const auto* goldenCard = dynamic_cast<const GoldenCard*>(card);
            cards.push_back(std::make_unique<GoldenCard>(*goldenCard));
        }
        else if(ct == Utils::CardType::Goal){
            const auto* objectiveCard = dynamic_cast<const ObjectiveCard*>(card);
            cards.push_back(std::make_unique<ObjectiveCard>(*objectiveCard));
        }
        else{
            throw "Erreur";
        }
    }
}

std::unique_ptr<Card> Pile::PickCard(){
    auto c = std::move(cards.back());
    cards.pop_back();
    return c;
}

Card& Pile::ShowTopCard(){
    return *(cards.back()).get();
}

unsigned int Pile::getCount(){
    return cards.size();
}

void Pile::removeCardByName(QString name){
    auto search = cards.end();
    for(auto it = cards.begin(); it != cards.end(); it++)
    {
        if(it->get()->getName() == name){
            search = it;
        }
    }
    if(search != cards.end()){
        cards.erase(search);
    }
}