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

    class ScoreConditionWithMultipleObject : public ScoreConditionWithObject {
        private:
            unsigned int number;
        public:
            ScoreConditionWithMultipleObject(unsigned int s, Utils::Ressource r, unsigned int n) : ScoreConditionWithObject(s,r), number(n){};
            unsigned int getScorePoints(const Board& p) override;
        };

    class ScoreConditionWithPattern : public ScoreCondition {
        private:
            map<Utils::Vector2i,Utils::Domaine> pattern;
        public:
            ScoreConditionWithPattern(unsigned int s) : ScoreCondition(s){};
            unsigned int getScorePoints(const Board& p) override;
            void AddElementToPattern(Utils::Domaine domaine, Utils::Vector2i relativePosition);
    };

    class ScoreConditionWithBorder : public ScoreCondition {
        private:
            Utils::Vector2i futurePosition;
        public:
            ScoreConditionWithBorder(unsigned int s) : ScoreCondition(s){futurePosition = {0,0};};
            unsigned int getScorePoints(const Board& p) override;
            void setFuturePosition(Utils::Vector2i pos){futurePosition = pos;}
    };
}