#include "json.h"

using namespace Json;

using json = nlohmann::json;

JsonHandler* JsonHandler::instance = nullptr;

JsonHandler* JsonHandler::getInstance() {
    if(instance == nullptr){
        instance = new JsonHandler();
    }
    return instance;
}

void JsonHandler::WriteCard(const Core::Card& c, const string& name){
    string extension = ".json";
    ofstream file("assets/" + name + extension,std::ios_base::out);
    file << c.to_json().dump(4);
    file.close();
}

Core::Card* JsonHandler::ReadCard(const string& name) {
    string extension = ".json";
    ifstream file("assets/" + name + extension);
    if (!file) throw "Error";
    json j;
    file >> j;
    file.close();
    const string type = j.value("type", "card");
    if (type == "ressource") return Core::RessourceCard::from_json(j);
    if (type == "card") return Core::Card::from_json(j);
    throw "Error";
}