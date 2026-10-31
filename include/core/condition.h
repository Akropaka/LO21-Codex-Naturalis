#pragma once
#include "player.h"

namespace Core{
    class ScoreCondition{
        protected:
            unsigned int score;
        public:
            virtual ~ScoreCondition(){};
            ScoreCondition(unsigned int s) : score(s) {};
            virtual unsigned int getScorePoints(const Player& p) = 0;
    };

    class ScoreConditionWithObject : public ScoreCondition {
        private:
            Utils::Ressource obj;
        public:
            ScoreConditionWithObject(unsigned int s, Utils::Ressource r) : ScoreCondition(s), obj(r) {};
            unsigned int getScorePoints(const Player& p) override;
    };
}