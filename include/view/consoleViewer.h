#pragma once
#include "core/card.h"

class consoleViewer{
    public:
        static void printCard(const Core::Card& c); // Surchage pour la Carte de base
        static void printCard(const Core::RessourceCard& c); // Surcharge pour la Carte ressource
        static void printHand(); // Main d'un joueur, class joueur pas encore défini
        static void printPlateau(); // Plateau d'un joueur, class joueur pas encore défini
        static void showScore(); // Afficher le score d'un joueur, class joueur pas encore défini
};