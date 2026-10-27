#pragma once
#include <map>
#include "utils.h"
#include <QJsonObject>
#include <QJsonArray>

using namespace std;

namespace Core {
    /*! \class Face
        \author <Thomas El Haj Hussein>
        \brief A class that represent the face of a Card Ressource and below classes

        Does have borders and may have a score
    */
    class Face {
        private:
            map<Utils::SlotPosition,Utils::Ressource> borders;
            unsigned int score;
        public:
            Face(){};
            Face(unsigned int s) : score(s){};
            const int getScore() const {return score;}
            const map<Utils::SlotPosition,Utils::Ressource>& getBorders() const {return borders;}
            void AddSlot(Utils::SlotPosition sp, Utils::Ressource r);
            QJsonObject toJson() const;
            static Face fromJson(const QJsonObject &json);
        };
}