#pragma once

namespace Utils {
    /*! \struct Vector2i
    \brief A simple structure to handle 2D - Vector of Integer
    \note Useful to handle position logic
    */
    struct Vector2i {
        int x;
        int y;

        bool operator<(const Vector2i& other) const {
            return x < other.x || (x == other.x && y < other.y);
        }
    };

    enum class Domaine {
        Champignon,
        Animal,
        Insecte,
        Vegetal
    };

    enum class Ressource {
        Empty,
        Champignon,
        Animal,
        Insecte,
        Vegetal,
        Ink,
        Feather,
        Tome
    };

    enum class SlotPosition {
        Center,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    enum class CardType {
        Base,
        Ressource,
        Golden,
        Goal
    };
}