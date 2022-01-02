#include "TractorHand.h"

using namespace TractorEvaluator;

Hand::Hand(std::vector<Card> cards, TractorState* state)
{
    for (auto card : cards)
    {
        handMap[TractorEvaluator::CardToPlaySuit(card, state)].push_back(card);
    }
    for (auto& suit : handMap)
    {
        std::sort(suit.second.begin(), suit.second.end(), [&state, &suit](const Card& a, const Card& b) {
            return GetCardValueWithinSuit(suit.first, a, state) < GetCardValueWithinSuit(suit.first, b, state);
        });
    }
}
