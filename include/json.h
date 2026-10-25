#pragma once
#include "card.h"
#include <QString>

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
            static QString GetAssetsDirectory();
            static void WriteCard(const Core::Card& c, const QString& name, const QString& pile);
            static Core::Card* ReadCard(const QString& name, const QString& pile);
        };
}