#include "condition.h"

using namespace Core;

unsigned int ScoreConditionWithObject::getScorePoints(const Board& p){
    /*
        TO DO :
            Parcourir le plateau (board) du joueur (player) p, afin de récupérer tous les objets == obj
            Retourner score * nbrObjet
    */
    return score;
}

unsigned int ScoreConditionWithMultipleObject::getScorePoints(const Board& p){
    /*
        TO DO :
            Parcourir le plateau (board) du joueur (player) p, afin de récupérer tous les objets
            Utiliser la division entière cette fois ci du nbrObjet avec number qui représente le nombre
            de cet objet nécessaire à l'obtention de ces points
            Retourner score * (nbrObjet / number)
    */
    return score;
}

unsigned int ScoreConditionWithPattern::getScorePoints(const Board& p){
    /*
        TO DO :
            Rappel un pattern est une disposition de carte de couleur(domaine) et de position particulière
            Parcourir le plateau (board) du joueur (player) p, afin de regarder si le pattern de pose existe
            Retourner score * nbrPattern
    */
    return score;
}

unsigned int ScoreConditionWithBorder::getScorePoints(const Board& p){
    /*
        TO DO :
            IMPORTANT VERIFIER SI LA POS EST POSSIBLE
            Définir le membre futurePosition avec la position où la carte souhaite posé
                car il faut compter le nombre de coins des (0 à 4) cartes autours qui seront offusquer  

            Retourner score * nbrCoinOffusquer lors de la pose (donc les Neightboors)
    */
    return score;
}

void ScoreConditionWithPattern::AddElementToPattern(Utils::Domaine domaine, Utils::Vector2i relativePosition){
    /*
        TO DO :
            Ajouter un élément au pattern (pour se familiariser avec les maps)
            Bien penser avec l'itérator à utiliser it->first (key), et it->second (value)
    */
}

QJsonObject ScoreCondition::toJson() const{
    QJsonObject json;
    json["score"] = (int)score;

    return json;
}

std::shared_ptr<ScoreCondition> ScoreCondition::fromJson(const QJsonObject &json){
    // Check if contains obj, in that case it's a ScoreConditionObject
    if(json.contains("pattern")){
        return std::make_shared<ScoreConditionWithPattern>(ScoreConditionWithPattern::fromJson(json));
    }
    if(json.contains("quantity")){
        return std::make_shared<ScoreConditionWithMultipleObject>(ScoreConditionWithMultipleObject::fromJson(json));
    }
    if (json.contains("obj")) {
        return std::make_shared<ScoreConditionWithObject>(ScoreConditionWithObject::fromJson(json));
    }
    if(json.contains("onBorder")){
        return std::make_shared<ScoreConditionWithBorder>(ScoreConditionWithBorder::fromJson(json));
    }

    return std::make_shared<ScoreCondition>(
        static_cast<unsigned int>(json["score"].toInt())
    );
}

QJsonObject ScoreConditionWithObject::toJson() const{
    QJsonObject json = ScoreCondition::toJson();
    json["obj"] = static_cast<int>(obj);
    return json;
}

ScoreConditionWithObject ScoreConditionWithObject::fromJson(const QJsonObject &json){
    ScoreConditionWithObject sc(
        static_cast<unsigned int>(json["score"].toInt()),
        static_cast<Utils::Ressource>(json["obj"].toInt())
    );

    return sc;
}

QJsonObject ScoreConditionWithMultipleObject::toJson() const {
    QJsonObject json = ScoreConditionWithObject::toJson();
    json["quantity"] = static_cast<int>(number);
    return json;
}

ScoreConditionWithMultipleObject ScoreConditionWithMultipleObject::fromJson(const QJsonObject &json){
    ScoreConditionWithMultipleObject sc(
        static_cast<unsigned int>(json["score"].toInt()),
        static_cast<Utils::Ressource>(json["obj"].toInt()),
        static_cast<unsigned int>(json["qunaity"].toInt())
    );

    return sc;
}

QJsonObject ScoreConditionWithPattern::toJson() const {
    QJsonObject json = ScoreCondition::toJson();
    
    QJsonObject patternJson;
    
    for (auto it = pattern.begin(); it != pattern.end(); ++it) {
        QString keyStr = QString::number(static_cast<int>(it->first.x))+","+QString::number(static_cast<int>(it->first.y));
        int valueInt = static_cast<int>(it->second);
        patternJson.insert(keyStr, valueInt);
    }

    json["pattern"] = patternJson;
    return json;
}

ScoreConditionWithPattern ScoreConditionWithPattern::fromJson(const QJsonObject &json){
    using std::map;
    map<Utils::Vector2i,Utils::Domaine> mapPattern = map<Utils::Vector2i,Utils::Domaine>();

    const QJsonValue patternJson = json.value("pattern");
    if (patternJson.isObject()) {
        const QJsonObject patternObj = patternJson.toObject();
        for (auto it = patternObj.begin(); it != patternObj.end(); ++it) {
            QStringList coords = it.key().split(',');
            Utils::Vector2i position{coords[0].toInt(), coords[1].toInt()};
            auto domaine = static_cast<Utils::Domaine>(it.value().toInt());
            mapPattern.insert({position, domaine});
        }
    }
    ScoreConditionWithPattern sc(static_cast<unsigned int>(json["score"].toInt()));
    sc.pattern = mapPattern;
    return sc;
}

QJsonObject ScoreConditionWithBorder::toJson() const {
    QJsonObject json = ScoreCondition::toJson();
    json["onBorder"] = true;
    return json;
}

ScoreConditionWithBorder ScoreConditionWithBorder::fromJson(const QJsonObject &json){
    if(json["onBorder"].toBool()){
        ScoreConditionWithBorder sc(
            static_cast<unsigned int>(json["score"].toInt())
        );
        return sc;
    }
    throw "Error";
}