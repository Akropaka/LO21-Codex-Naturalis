#pragma once
#include "utils.h"
#include "face.h"
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

using namespace Utils;
using namespace std;

using json = nlohmann::json;

namespace Core {

    /*! \class Card
        \author <Thomas El Haj Hussein>
        \brief A class that represent the card logic
        
        A base class used for more specifics cards class.
        \param name a name that refer to the card.
        \param id is defined by a static field and should never be defined elsewhere.
    */
    class Card {
        private:
            string name;
            size_t id;
            static size_t amount;
        public:
            Card(const string& n) : name(n) {
                id = amount;
                amount += 1;
            }
            const string& getName() const {return name;}
            virtual json to_json() const {
                return json{{"name", name}};
            }
    };

    class RessourceCard : public Card {
        protected:
            Domaine domaine;
            Face faces[2];
            void SetupVerso();
        public:
            RessourceCard(const string& n, const Domaine& d, const Face& r) : Card(n), domaine(d) {
                faces[0] = r;
            };
            const Domaine& getDomaine() const { return domaine;}
            const Face& getFace(unsigned int i=0) const;
            json to_json() const override {
                json j = Card::to_json();
                j["domaine"] = getDomaine();
                j["face"] = getFace().to_json();
                return j;
            }
    };

    void from_json(const json& j, RessourceCard& r);

    class GoldenCard : public RessourceCard {

    };
}

namespace Loader {

    class CardDatabase {
        private:
            vector<Core::Card> cards;
    };

}