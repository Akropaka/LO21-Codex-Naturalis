#include <iostream>
#include "core.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char** argv){
    
    // GAME LOGIC
    Card myCard(1, "Règne Fongique");

    // UI
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Codex Naturalis");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
