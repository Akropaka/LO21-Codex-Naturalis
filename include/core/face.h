#pragma once
#include <map>
#include "utils.h"
#include <QJsonObject>
#include <QJsonArray>
#include <memory>
#include <utility>
#include "condition.h"

using namespace std;

namespace Core {
    /*! \class Face
        \author <Thomas El Haj Hussein>
        \brief A class that represent the face of a Card Ressource and below classes

        Do have borders and may have a score
    */

    class Card;

    class Board;
    /*! \class Face
        \author <Thomas El Haj Hussein>
        \brief A class that represent one face

        \param borders a map that bind corner with a ressource type such as Animal, Empty...
        \param neightboors a map that bind corner with a Card that has been placed in that corner
        \param scoreCondition a smart pointer that descripe how to win points when placing the card with this face
    */
    class Face {
        protected:
            map<Utils::SlotPosition,Utils::Ressource> borders;
            map<Utils::SlotPosition,Card> neightboors;
            std::shared_ptr<ScoreCondition> scoreCondition = std::make_shared<ScoreCondition>(0);
        public:
            Face() {};
            Face(unsigned int s){
                scoreCondition.get()->setScore(s);
            };
            unsigned int getScore() const {return scoreCondition.get()->getScorePoints();}
            const map<Utils::SlotPosition,Utils::Ressource>& getBorders() const {return borders;}
            void AddSlot(Utils::SlotPosition sp, Utils::Ressource r);
            bool AddNeightboorCard(Utils::SlotPosition sp, const Core::Card& c);

            unsigned int getRessourceCount(Utils::Ressource ressource);
            virtual bool isPlayable(Board& board){return true;};

            virtual QJsonObject toJson() const;
            static Face fromJson(const QJsonObject &json);

            virtual std::shared_ptr<Face> clone() const {
                return std::make_shared<Face>(*this);
            }
    };
    /*! \class FaceWithCondition
        \author <Thomas El Haj Hussein>
        \brief A class that represent a face with conditions that require to be met to be placed

        \param conditions the conditions in ressource needed to be placed
    */
    class FaceWithCondition : public Face {
        private:
            map<Utils::Ressource,unsigned int> conditions;
        public:
            FaceWithCondition() : Face(){};
            FaceWithCondition(unsigned int s) : Face(s){};
            FaceWithCondition(const Face& f) : Face(f) {};
            void AddCondition(unsigned int quantity, Utils::Ressource ressource);
            template <typename T>
            void ModifyScoreCondition(T sc){scoreCondition = std::make_shared<T>(std::move(sc));}
            vector<Utils::Ressource> getRessourcesType();
            bool isPlayable(Board& board) override;

            QJsonObject toJson() const override;
            static FaceWithCondition fromJson(const QJsonObject &json);

            std::shared_ptr<Face> clone() const override {
                return std::make_shared<FaceWithCondition>(*this);
            }
     };
}