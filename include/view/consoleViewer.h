#pragma once
#include "card.h"
#include "board.h"
#include "player.h"

namespace View {

    class ConsoleViewer {
    public:
        static ConsoleViewer& getInstance() {
            static ConsoleViewer instance;
            return instance;
        }
        ConsoleViewer(const ConsoleViewer&) = delete;
        ConsoleViewer& operator=(const ConsoleViewer&) = delete;

        void printCard(const Core::Card& card);               // Carte
        void printCard(const Core::RessourceCard& card);      // Carte ressource
        void printHand(const Core::Player& player);           // Main d'un joueur
        void printBoard(const Core::Player& player);          // Plateau d'un joueur
        void showScore(const Core::Player& player);           // Score d'un joueur

    private:
        ConsoleViewer() = default;
    };
}