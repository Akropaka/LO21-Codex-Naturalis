#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include "card.h"
#include "face.h"
#include "json.h"
#include <string>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    Core::Face f(1);
    f.AddSlot(Utils::SlotPosition::TopLeft,Utils::Ressource::Animal);
    f.AddSlot(Utils::SlotPosition::BottomRight,Utils::Ressource::Animal);
    
    const QString name = "Wolf";

    Core::RessourceCard r(name,Utils::Domaine::Animal,f);
    
    Json::JsonHandler::getInstance()->WriteCard(r,name, "ressources");
    auto c = Json::JsonHandler::getInstance()->ReadCard(name, "ressources");

    qInfo() << c->getName();

    Loader::CardDatabase::getInstance();

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
