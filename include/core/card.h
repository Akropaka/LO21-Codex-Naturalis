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
            const Face& getFace(unsigned int i=0) const {
                if(i>1 || i<0){
                    throw "ERROR";
                }
                else{
                    return faces[i];
                }

            }
    };

    void to_json(json& j, const Core::RessourceCard& p);

    class GoldenCard : public RessourceCard {

    };
}

namespace Loader {

    class CardDatabase {
        private:
            vector<Core::Card> cards;
    };

}