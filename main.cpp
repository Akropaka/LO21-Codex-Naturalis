#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include "nlohmann/json.hpp"
#include "card.h"
#include "face.h"
#include <string>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    Core::Face f(1);
    f.AddSlot(Utils::SlotPosition::TopLeft,Utils::Ressource::Animal);
    f.AddSlot(Utils::SlotPosition::BottomRight,Utils::Ressource::Animal);
    Core::RessourceCard r("Frog",Utils::Domaine::Animal,f);

    json j = r;

    std::cout << j.dump(4) << std::endl;

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
