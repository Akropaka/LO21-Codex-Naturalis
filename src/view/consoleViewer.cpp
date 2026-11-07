#include "consoleViewer.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace View;

namespace {

    std::string ressourceCode(Utils::Ressource r) {
        switch (r) {
        case Utils::Ressource::Empty:      return "--";
        case Utils::Ressource::Vegetal:    return "Ve";
        case Utils::Ressource::Animal:     return "An";
        case Utils::Ressource::Champignon: return "Fo";
        case Utils::Ressource::Insecte:    return "In";
        case Utils::Ressource::Feather:    return "Pl";
        case Utils::Ressource::Ink:        return "En";
        case Utils::Ressource::Tome:       return "Ma"; //manuscrit
        }
        return "??";
    }

    //contenu dun coin
    std::string corner(const Core::Face& face, Utils::SlotPosition sp) {
        const auto& borders = face.getBorders();
        auto it = borders.find(sp);
        if (it == borders.end()) return "  "; //sil nexiste pas
        return ressourceCode(it->second);
    }


    std::vector<std::string> cardLines(const Core::RessourceCard& card) {
        using Utils::SlotPosition;
        const Core::Face& face = card.getFace(0);

        std::string name = card.getName().toStdString().substr(0, 11);
        name.resize(11, ' ');  // complète avec des espaces

        std::vector<std::string> lines;
        lines.push_back("+-----------+");
        lines.push_back("|" + corner(face, SlotPosition::TopLeft)
            + "   " + std::to_string(face.getScore()) + "   "
            + corner(face, SlotPosition::TopRight) + "|");
        lines.push_back("|" + name + "|");
        lines.push_back("|" + corner(face, SlotPosition::BottomLeft)
            + "       "
            + corner(face, SlotPosition::BottomRight) + "|");
        lines.push_back("+-----------+");
        return lines;
    }
}




void ConsoleViewer::printCard(const Core::Card& card){
    std::cout << "Card: " << card.getName().toStdString() << "\n";
}

void ConsoleViewer::printCard(const Core::RessourceCard& card){
    for (const auto& line : cardLines(card))
        std::cout << line << "\n";
}

//si on veut les afficher ne meme temps, plus simple pour jouer avec board
void ConsoleViewer::printCards(const std::vector<const Core::RessourceCard*>& cards) {
    if (cards.empty()) return;

    std::vector<std::vector<std::string>> all;
    for (const auto* card : cards)
        all.push_back(cardLines(*card));

    for (size_t row = 0; row < all[0].size(); row++) {
        for (const auto& lines : all)
            std::cout << lines[row] << " ";
        std::cout << "\n";
    }
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

void ConsoleViewer::clearScreen() {
#ifdef __linux__
    system("clear");
#else
    system("cls");
#endif
}