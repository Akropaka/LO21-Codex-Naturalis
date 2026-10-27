#pragma once
#include "card.h"
#include "board.h"

class consoleViewer{
    public:
        static void printCard(const Core::Card& card); // Surchage pour la Carte de base
        static void printCard(const Core::RessourceCard& card); // Surcharge pour la Carte ressource
        static void printHand(); // Main d'un joueur, class joueur pas encore défini
        static void printBoard(const Core::Board& board); // Plateau d'un joueur, class joueur pas encore défini
        static void showScore(); // Afficher le score d'un joueur, class joueur pas encore défini
};