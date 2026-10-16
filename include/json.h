#pragma once
#include "card.h"
#include <iostream>
#include <fstream>

namespace Json {
    class JsonHandler{
        private:
            static JsonHandler* instance;
            JsonHandler() = default;
            ~JsonHandler() {};
            JsonHandler(const JsonHandler&) = delete;
            JsonHandler& operator=(const JsonHandler&) = delete;
        public:
            static JsonHandler* getInstance();
            static void WriteCard(const Core::Card& c, const string& name);
            static Core::Card ReadCard(fstream& f);
        };
}