#pragma once
#include "utils.h"
#include "face.h"
#include <string>
#include <vector>
#include <QJsonObject>
#include <memory>

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
            virtual ~Card() = default;
            virtual QJsonObject toJson() const;
            virtual Card* clone() const =0;
    };
    /*! \class RessourceCard
        \author <Thomas El Haj Hussein>
        \brief A specialized Card class that represent a Card from the Ressource pile
        
        \param domaine a domaine linked to the card.
        \param recto represent the recto face.
        \param verso represent the verso face.
        \param visible represent the current visible face.
    */
    class RessourceCard : public Card {
        protected:
            Domaine domaine;
            std::unique_ptr<Face> recto;
            std::unique_ptr<Face> verso;
            bool rectoVisible = true;
        public:
            RessourceCard(const QString& n, const Domaine& d, const Face& r) : Card(n), domaine(d) {
                recto = r.clone();
                SetupAutoVerso();
            };
            RessourceCard(const QString& n, const Domaine& d, const Face& r, const Face& v) : Card(n), domaine(d) {
                recto = r.clone();
                verso = v.clone();
            }

            RessourceCard() : Card() {};
            RessourceCard(const RessourceCard& other)
                : Card(other), domaine(other.domaine),
                  recto(other.recto ? other.recto->clone() : nullptr),
                  verso(other.verso ? other.verso->clone() : nullptr),
                  rectoVisible(other.rectoVisible) {}

            const Domaine& getDomaine() const {return domaine;}
            const Face& getFace(unsigned int i=0) const;
            void setFace(const Face& f, unsigned int i=0);

            void SetupAutoVerso();

            void Flip();
            Face& getVisibleFace();

            RessourceCard* clone() const override {return new RessourceCard(*this);}

            QJsonObject toJson() const override;
            static RessourceCard fromJson(const QJsonObject &json);
    };
    /*! \class GoldenCard
        \author <Thomas El Haj Hussein>
        \brief A specialized Card class that represent a Card from the Golden Pile
        
        It replace the verso Face with a FaceWithCondition instance using smart pointer
    */
    class GoldenCard : public RessourceCard {
        public:
            GoldenCard(const QString& n, const Domaine& d, const FaceWithCondition& r) : RessourceCard(n,d,Face()){
                recto = std::make_unique<FaceWithCondition>(r);
            }
            GoldenCard() : RessourceCard() {};

            GoldenCard* clone() const override {return new GoldenCard(*this);}

            QJsonObject toJson() const override;
            static GoldenCard fromJson(const QJsonObject &json);
    };
    /*! \class ObjectiveCard
        \author <Thomas El Haj Hussein>
        \brief A specialized Card class that represent a Card from the ObjectiveCard
        
        \param scoreCondition a member that represent how to score points
    */
    class ObjectiveCard : public Card {
        private:
            std::shared_ptr<ScoreCondition> scoreCondition;
        public:
            ObjectiveCard(const QString& n, const ScoreCondition& sc) : Card(n) {
                scoreCondition = sc.clone();
            }

            unsigned int getScore() const {return scoreCondition.get()->getScorePoints();}

            ObjectiveCard* clone() const override {return new ObjectiveCard(*this);}

            QJsonObject toJson() const override;
            static ObjectiveCard fromJson(const QJsonObject &json);
    };
    
    class Pile{
        private:
            std::vector<std::unique_ptr<Card>> cards;
        public:
            Pile(CardType ct);
            std::unique_ptr<Card> PickCard();
            void removeCardByName(QString name);
            Card& ShowTopCard();
            unsigned int getCount();
            bool isEmpty(){return getCount() == 0;}
    };
}

namespace Loader {
    /*! \class CardDatabase
        \author <Thomas El Haj Hussein>
        \brief A class that gather all data from file and populate vectors representing every cards of the game
        
        A Singleton class, gather json data from file to populate vectors and give access to theses cards to other class.
    */
    class CardDatabase {
        private:
            vector<Core::RessourceCard*> ressourceCards;
            vector<Core::GoldenCard*> goldenCards;
            vector<Core::ObjectiveCard*> objectiveCards;

            static CardDatabase* instance;
            CardDatabase();
            ~CardDatabase() {};
            CardDatabase(const CardDatabase&) = delete;
            CardDatabase& operator=(const CardDatabase&) = delete;
        public:
            static CardDatabase* getInstance();
            vector<Core::Card*> getCards(CardType ct) const;
    };

}