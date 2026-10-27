#pragma once
#include "utils.h"
#include "face.h"
#include <string>
#include <vector>
#include <QJsonObject>

using namespace Utils;
using namespace std;

namespace Core {

    /*! \class Card
        \author <Thomas El Haj Hussein>
        \brief A class that represent the card logic
        
        A base class used for more specifics cards class.
    */
    class Card {
        protected:
            QString name;
        private:
            size_t id;
            static size_t amount;
        public:
            Card(const QString& n) : name(n) {
                id = amount;
                amount += 1;
            }
            Card() {
                id = amount;
                amount += 1;
            }
            const QString& getName() const {return name;}
            ~Card() = default;
            virtual QJsonObject toJson() const;
            static Card fromJson(const QJsonObject &json);
    };
    /*! \class RessourceCard
        \author <Thomas El Haj Hussein>
        \brief A specialized Card class that represent a Card from the Ressource pile
        
        \param domaine a domaine linked to the card.
        \param faces a table of [2] entries that represent both faces.
    */
    class RessourceCard : public Card {
        protected:
            Domaine domaine;
            Face faces[2];
            void SetupVerso();
        public:
            RessourceCard(const QString& n, const Domaine& d, const Face& r) : Card(n), domaine(d) {
                faces[0] = r;
            };
            RessourceCard() : Card() {};
            const Domaine& getDomaine() const { return domaine;}
            const Face& getFace(unsigned int i=0) const;
            QJsonObject toJson() const override;
            static RessourceCard fromJson(const QJsonObject &json);
    };

    class GoldenCard : public RessourceCard {

    };
}

namespace Loader {

    class CardDatabase {
        private:
            vector<Core::Card*> baseCards;
            vector<Core::RessourceCard*> ressourceCards;

            static CardDatabase* instance;
            CardDatabase();
            ~CardDatabase() {};
            CardDatabase(const CardDatabase&) = delete;
            CardDatabase& operator=(const CardDatabase&) = delete;
        public:
            static CardDatabase* getInstance();
    };

}