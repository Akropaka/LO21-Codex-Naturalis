#pragma once
#include <QJsonObject>
/* 
    \class Generator
    \brief A class used to create Card from the terminal

    Implémentation :
        Cette classe doit être appelé si on passe un argument à notre exécutable (-c)
        Elle doit prévoir une boucle do while(true) qui controle les saisies du l'utilisateur pour générer une carte
        Bonus : afficher toutes les cartes

        Methodés utiles dans le header json.h.
            Dans le namespace Json :

            static void WriteCard(const Core::Card& c, const QString& name, const QString& pile);
            static Core::Card* ReadCard(const QString& name, const QString& pile);
*/

namespace Tools {
    class CardGenerator{
        private:
            // Toutes les méthodes qui paraissent utiles
            void showCardsFromPile(QString pile);
            void createCard();
            void deleteCard();
        public:
            CardGenerator(); // A implémenter avec do...while dans le .cpp, doit écrire dans les bons dossiers !
            // exemple : ressources
    };
}