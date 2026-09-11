#pragma once
#include <string>
#include <map>
#include "utils.h"

// Déclaration préalable de la classe Card
class Card;
// Déclaration préalable de la classe Board
class Board;

class Face {
    private:
        FaceType face_type;
    public:
        Face(FaceType face_type);
        Face();
        FaceType getFaceType() const;
};

class Card {
    public:
        Card(unsigned int id, const std::string& name, CardDomaine domaine);
        unsigned int getId() const;
        std::string getName() const;
        void setupCard(Face& recto, Face& verso);
    protected:
        void setFace(Face& face);
        unsigned int id;
        CardDomaine domaine;
        std::string name;
        Face faces[2];
};

class Board {
    private:
        std::map<Vector2, Card> cards;
        Card getCardAt(const Vector2& position) const;
        void setCardAt(const Vector2& position, const Card& card);
};