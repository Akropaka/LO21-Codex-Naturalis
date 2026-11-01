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

ScoreCondition ScoreCondition::fromJson(const QJsonObject &json){
    ScoreCondition sc(static_cast<unsigned int>(json["score"].toInt()));
    return sc;
}

QJsonObject ScoreConditionWithObject::toJson() const{
    QJsonObject json = ScoreCondition::toJson();
    json["obj"] = static_cast<int>(obj);
    return json;
}

ScoreCondition ScoreConditionWithObject::fromJson(const QJsonObject &json){
    ScoreConditionWithObject sc(
        static_cast<unsigned int>(json["score"].toInt()),
        static_cast<Utils::Ressource>(json["obj"].toInt())
    );

    return sc;
}