#include "TractorHand.h"

using namespace TractorEvaluator;

TractorHand::TractorHand(std::vector<Card> cards, const TractorState* state)
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


size_t TractorHand::GetSuitCount(TractorEvaluator::PlaySuit suit) const
{
    if (handMap.find(suit) == handMap.end()) return 0;
    return handMap.at(suit).size();
}