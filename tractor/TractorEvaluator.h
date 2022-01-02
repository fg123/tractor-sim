#pragma once

#include "TractorState.h"

#include "sim/Card.h"

#include <vector>

namespace TractorEvaluator 
{
    struct PlayStructure 
    {
        // TODO:
        // one way could be to have a priority structure waterfall, i.e. 222-333 becomes:
        // 1. length 2 - triple tractor
        // 2. length 2 - double tractor + 2 single
        // 3. length 2 - triple
        // 4. length 1 - triple, length 1 double, 1 single
        // 5. etc.etc
    };

    enum class PlaySuit
    {
        Spades,
        Hearts,
        Diamonds,
        Clubs,
        Trump
    };

    PlaySuit CardToPlaySuit(const Card& card, const TractorState* state);
    size_t GetCardValueWithinSuit(PlaySuit suit, const Card& card, const TractorState* state);
    bool IsLegalLead(const Play& play, const TractorState* state);
    bool IsLegalFollow(const Play& play, const TractorState* state);
};