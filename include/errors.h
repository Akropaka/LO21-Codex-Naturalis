#pragma once

enum class TurnError {
    Undefined,
    NotPlayerTurn,
    DoNoHaveCard,
    AlreadyPlacedCard,
    InvalidPlacement,
};