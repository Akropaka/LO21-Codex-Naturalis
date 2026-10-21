#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include "nlohmann/json.hpp"
#include "card.h"
#include "face.h"
#include "json.h"
#include <string>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    Core::Face f(1);
    f.AddSlot(Utils::SlotPosition::TopLeft,Utils::Ressource::Animal);
    f.AddSlot(Utils::SlotPosition::BottomRight,Utils::Ressource::Animal);
    
    string name = "Wolf";

    Core::RessourceCard r(name,Utils::Domaine::Animal,f);
    
    Json::JsonHandler::getInstance()->WriteCard(r,name);
    auto c = Json::JsonHandler::getInstance()->ReadCard(name);

    std::cout << c->getName() << std::endl;

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
