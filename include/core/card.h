#pragma once

#include "utils.h"
#include "face.h"

class Card {
    private:
        static int num_card;
    public:
        Card(const std::string& name, CardDomaine domaine);
        unsigned int getId() const;
        std::string getName() const;
        void setupCard(Face& recto);
    protected:
        void setFace(Face& face);
        unsigned int id;
        CardDomaine domaine;
        std::string name;
        Face faces[2];
};