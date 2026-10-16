#include "json.h"

using namespace Json;

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

static Core::Card ReadCard(fstream& f) {
    
}