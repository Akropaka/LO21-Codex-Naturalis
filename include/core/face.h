#pragma once
#include <map>
#include "utils.h"
#include <QJsonObject>
#include <QJsonArray>
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

    class Face {

        protected:
            map<Utils::SlotPosition,Utils::Ressource> borders;
            map<Utils::SlotPosition,Card> neightboors;
            ScoreCondition scoreCondition;
        public:
            Face() : scoreCondition(0) {};
            Face(unsigned int s) : scoreCondition(s){};
            unsigned int getScore() const {return scoreCondition.getScorePoints();}
            const map<Utils::SlotPosition,Utils::Ressource>& getBorders() const {return borders;}
            void AddSlot(Utils::SlotPosition sp, Utils::Ressource r);
            bool AddNeightboorCard(Utils::SlotPosition sp, const Core::Card& c);

            unsigned int getRessourceCount(Utils::Ressource ressource);
            virtual bool isPlayable(Board& board){return true;};

            virtual QJsonObject toJson() const;
            static Face fromJson(const QJsonObject &json);
    };

    class FaceWithCondition : public Face {
        private:
            map<Utils::Ressource,unsigned int> conditions;
        public:
            FaceWithCondition() : Face(){};
            FaceWithCondition(unsigned int s) : Face(s){};
            FaceWithCondition(Face& f){
                this->borders = f.getBorders();
                this->scoreCondition = ScoreCondition(f.getScore());
            };
            void AddCondition(unsigned int quantity, Utils::Ressource ressource);
            void ModifyScoreCondition(const ScoreCondition& sc){scoreCondition = sc;}
            vector<Utils::Ressource> getRessourcesType();
            bool isPlayable(Board& board) override;

            QJsonObject toJson() const override;
            static FaceWithCondition fromJson(const QJsonObject &json);
    };
}