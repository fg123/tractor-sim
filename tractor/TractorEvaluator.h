#pragma once

#include "TractorState.h"

#include "sim/Card.h"

#include <vector>

namespace TractorEvaluator 
{
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