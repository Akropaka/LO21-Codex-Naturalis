#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include "card.h"
#include "face.h"
#include "json.h"
#include "generator.h"
#include "condition.h"
#include <string>
#include <iostream>

int main(int argc, char** argv){

    for(int i=1; i<argc-1; i++){
        if(argv[i] == "-e" || argv[i] == "--editor")
        {
            Tools::CardGenerator();
        }
    }

    // Création d'une face
    Core::Face f(1);

    // Ajouts de coins
    f.AddSlot(Utils::SlotPosition::TopLeft,Utils::Ressource::Feather);
    f.AddSlot(Utils::SlotPosition::TopRight,Utils::Ressource::Empty);
    
    Core::FaceWithCondition fSecond(3);

    fSecond.AddSlot(Utils::SlotPosition::TopLeft,Utils::Ressource::Animal);
    fSecond.AddSlot(Utils::SlotPosition::BottomLeft,Utils::Ressource::Champignon);
    fSecond.AddSlot(Utils::SlotPosition::TopRight,Utils::Ressource::Animal);
    fSecond.ModifyScoreCondition<Core::ScoreConditionWithObject>(Core::ScoreConditionWithObject(2,Utils::Ressource::Ink));
    fSecond.AddCondition(3,Utils::Ressource::Animal);

    const QString name = "Frog";
    const QString nameSecond = "Vipere";
    const QString nameObjective = "Determination";

    Core::RessourceCard r(name,Utils::Domaine::Animal,f);
    Core::GoldenCard rg(nameSecond,Utils::Domaine::Animal,fSecond);
    Core::ObjectiveCard robj(nameObjective,Core::ScoreConditionWithObject(3,Utils::Ressource::Animal));
    
    Json::JsonHandler::getInstance()->WriteCard(r,name, "ressources");
    Json::JsonHandler::getInstance()->WriteCard(rg,nameSecond, "doree");
    Json::JsonHandler::getInstance()->WriteCard(robj,nameObjective, "objectives");
    auto c = Json::JsonHandler::getInstance()->ReadCard(name, "ressources");
    auto cSecond = Json::JsonHandler::getInstance()->ReadCard(nameSecond, "doree");
    auto cObjectif = Json::JsonHandler::getInstance()->ReadCard(nameObjective, "objectives");

    Loader::CardDatabase::getInstance();

    for(auto c : Loader::CardDatabase::getInstance()->getCards(Utils::CardType::Ressource)){
        auto* ressourceCard = dynamic_cast<Core::RessourceCard*>(c);
        ressourceCard->SetupAutoVerso();
        ressourceCard->Flip();
        qInfo() << (int)ressourceCard->getDomaine() << " | " << "Nom : " << ressourceCard->getName();
        qInfo() << "Nombre Ressource Animal : " << ressourceCard->getVisibleFace().getRessourceCount(Utils::Ressource::Animal);
    }

    for(auto c : Loader::CardDatabase::getInstance()->getCards(Utils::CardType::Golden)){
        auto* goldenCard = dynamic_cast<Core::GoldenCard*>(c);
        goldenCard->SetupAutoVerso();
        qInfo() << (int)goldenCard->getDomaine() << " | " << "Nom : " << goldenCard->getName();
        qInfo() << "Nombre Ressource Animal : " << goldenCard->getVisibleFace().getRessourceCount(Utils::Ressource::Animal);
    }

    // Pile

    Core::Pile p(Utils::CardType::Ressource);
    qInfo() <<  p.getCount() << p.PickCard().get()->getName() << p.getCount() << p.ShowTopCard().getName() << p.getCount();

    p.removeCardByName("Wolf");
    qInfo() << p.getCount();
    // QT

    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
