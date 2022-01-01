#pragma once

#include "sim/State.h"

struct TractorState : public State
{
    // Predetermined
    Rank trumpRank = None;

    // Predetermined or during dealing
    PlayerID dealer = 0;

    // Determined during dealing phase
    Suit trumpSuit;

    size_t defenderPoints;
    size_t attackerPoints;
};
