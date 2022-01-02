#pragma once

#include "TractorState.h"
#include "TractorEvaluator.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

class TractorHand 
{
    std::unordered_map<TractorEvaluator::PlaySuit, std::vector<Card>> handMap;

public:
    TractorHand(std::vector<Card> cards, const TractorState* state);
    size_t GetSuitCount(TractorEvaluator::PlaySuit suit) const;
};