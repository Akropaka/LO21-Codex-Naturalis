#pragma once
#include "card.h"
#include "board.h"
#include "player.h"

namespace View {
    
    class Viewer {
        //
    };

    class ConsoleViewer : public Viewer {
        public:
            static void printCard(const Core::Card& card); // Surchage pour la Carte de base
            static void printCard(const Core::RessourceCard& card); // Surcharge pour la Carte ressource
            static void printHand(const Core::Player& player); // Main d'un joueur
            static void printBoard(const Core::Player& player); // Plateau d'un joueur
            static void showScore(const Core::Player& player); // Afficher le score d'un joueur
    };
}