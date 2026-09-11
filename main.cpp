#include <iostream>
#include "core.h"
#include "utils.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char** argv){
    
    // GAME LOGIC
    Card myCard(1, "Fongique Equilibre", CardDomaine::FONGIQUE);


    std::vector<Card> cards = loadCSVToCards("../assets/cards.csv");

    // Idea Init for cards
    //vector<Card> cards = Loader.load("path/to/card/data.csv");

    Face rectoFace(FaceType::RECTO);
    Face versoFace(FaceType::VERSO);

    myCard.setupCard(rectoFace, versoFace);

    // UI
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
