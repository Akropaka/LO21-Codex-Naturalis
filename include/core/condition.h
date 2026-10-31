#pragma once
#include "utils.h"

namespace Core{

    class Board;

    class ScoreCondition{
        protected:
            unsigned int score;
        public:
            virtual ~ScoreCondition(){};
            ScoreCondition(unsigned int s) : score(s) {};
            ScoreCondition& operator=(unsigned int i){
                this->score = i;
                return *this;
            };
            virtual unsigned int getScorePoints() const {return score;}
            virtual unsigned int getScorePoints(const Board& p){return score;}
    };

    class ScoreConditionWithObject : public ScoreCondition {
        private:
            Utils::Ressource obj;
        public:
            ScoreConditionWithObject(unsigned int s, Utils::Ressource r) : ScoreCondition(s), obj(r) {};
            unsigned int getScorePoints(const Board& p) override;
    };
}