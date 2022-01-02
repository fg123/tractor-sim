#pragma once

#include "TractorState.h"
#include "TractorEvaluator.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

class Hand 
{
    std::unordered_map<TractorEvaluator::PlaySuit, std::vector<Card>> handMap;

public:
    Hand(std::vector<Card> cards, TractorState* state);
};