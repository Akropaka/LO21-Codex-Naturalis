#include "consoleViewer.h"
#include <iostream>

using namespace View;

void ConsoleViewer::printCard(const Core::Card& card){
    std::cout << "Card: " << card.getName().toStdString() << "\n";
}

void ConsoleViewer::printCard(const Core::RessourceCard& card){
    return; // TODO : dessiner la carte 
}

void ConsoleViewer::printHand(const Core::Player& player) {
    const auto& hand = player.getHand();

    std::cout << "Main de " << player.getName() << " :\n"; //ou numero du joueur?
    if (hand.empty()) {
        std::cout << "  (vide)\n";
        return;
    }
    for (size_t i = 0; i < hand.size(); i++) {
        std::cout << "  [" << i + 1 << "] " << hand[i].getName().toStdString() << "\n";
    }
}

void ConsoleViewer::showScore(const Core::Player& player) {
    std::cout << player.getName() << " : " << player.getScore() << " point(s)\n";
}

void ConsoleViewer::printBoard(const Core::Player& player) {
    return; // TODO : afficher le plateau
}