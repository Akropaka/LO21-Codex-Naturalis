#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include "card.h"
#include "face.h"
#include "json.h"
#include "generator.h"
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
    
    const QString name = "Frog";

    Core::RessourceCard r(name,Utils::Domaine::Animal,f);
    
    Json::JsonHandler::getInstance()->WriteCard(r,name, "ressources");
    auto c = Json::JsonHandler::getInstance()->ReadCard(name, "ressources");


    Loader::CardDatabase::getInstance();

    for(auto c : Loader::CardDatabase::getInstance()->getCards(Utils::CardType::Ressource)){
        auto* ressourceCard = dynamic_cast<Core::RessourceCard*>(c);
        ressourceCard->SetupAutoVerso();
        ressourceCard->Flip();
        qInfo() << (int)ressourceCard->getDomaine() << " | " << "Nom : " << ressourceCard->getName();
    }

    // QT

    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
