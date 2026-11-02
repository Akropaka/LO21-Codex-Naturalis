#include "json.h"
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonParseError>
#include <stdexcept>

using namespace Json;

JsonHandler* JsonHandler::instance = nullptr;

JsonHandler* JsonHandler::getInstance() {
    if(instance == nullptr){
        instance = new JsonHandler();
    }
    return instance;
}

QString JsonHandler::GetAssetsDirectory() {
    const QString startingPath = QDir::currentPath();
    QDir directory(startingPath);
    QString assetsPath = directory.filePath("assets");
    QFileInfo fileInfo(assetsPath);
    if(fileInfo.exists()){
        if(fileInfo.isDir()){
            return assetsPath;
        }
    }
    else{
        QDir parentDir = directory.filePath("..");
        assetsPath = parentDir.filePath("assets");
        return assetsPath;
    }
    throw "Error";
}

void JsonHandler::WriteCard(const Core::Card& c, const QString& name, const QString& pile){
    const QString path = QDir(GetAssetsDirectory()).filePath(QStringLiteral("%1/%2.json").arg(pile, name));
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QJsonObject json = c.toJson();
    if(dynamic_cast<const Core::GoldenCard*>(&c)){
        json["type"] = "golden";
    }
    else if(dynamic_cast<const Core::RessourceCard*>(&c)){
        json["type"] = "ressource";
    }
    else if(dynamic_cast<const Core::ObjectiveCard*>(&c)){
        json["type"] = "objective";
    }
    else{
        json["type"] = "card";
    }
    const QByteArray data = QJsonDocument(json).toJson(QJsonDocument::Indented);
    file.write(data);
}

Core::Card* JsonHandler::ReadCard(const QString& name, const QString& pile) {
    const QString path = QDir(GetAssetsDirectory()).filePath(QStringLiteral("%1/%2.json").arg(pile, name));
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    const QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    const QJsonObject json = document.object();
    const QString type = json.value("type").toString("card");

    if (type == "objective") return new Core::ObjectiveCard(Core::ObjectiveCard::fromJson(json));
    if (type == "golden") return new Core::GoldenCard(Core::GoldenCard::fromJson(json));
    if (type == "ressource") return new Core::RessourceCard(Core::RessourceCard::fromJson(json));
    if (type == "card") return new Core::Card(Core::Card::fromJson(json));
    throw "Error";
}