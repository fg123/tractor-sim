#include "Deck.h"

#include <random>
#include <algorithm>

void Deck::ResetDeck(int deckCount, bool withJokers)
{
    cards.clear();
    for (int i = 0; i < deckCount; i++) {
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 1; rank <= 13; rank++) {
                cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
            }
        }
        if (withJokers) {
            cards.push_back(Card(SmallJoker, Rank::None));
            cards.push_back(Card(BigJoker, Rank::None));
        }
    }
}

void Deck::Shuffle(const std::string& seed)
{
    std::vector<int> seedLst;
    for (auto c : seed) {
        seedLst.push_back(c);
    }
    std::seed_seq s(seedLst.begin(), seedLst.end());
    std::mt19937 eng(s);
    std::shuffle(cards.begin(), cards.end(), eng);
}

size_t Deck::GetCardCount() const
{
    return cards.size();
}

Card Deck::GetTopCard() const
{
    if (cards.empty()) {
        throw std::runtime_error("Deck is empty");
    }
    return cards.front();
}

std::ostream& operator<<(std::ostream &os, const Deck &deck)
{
    os << "[";
    bool first = true;
    for (auto& card : deck.cards) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << card;
    }
    os << "]";
    return os;
}