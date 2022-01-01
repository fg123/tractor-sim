#pragma once

#include "Card.h"

#include <ostream>
#include <vector>

class Deck
{
    std::vector<Card> cards;
    
public:
    void ResetDeck(int deckCount, bool withJokers);
    void Shuffle(const std::string& seed);

    std::vector<Card>& GetCards() { return cards; }
    
    size_t GetCardCount() const;
    Card GetTopCard() const;

    friend std::ostream& operator<<(std::ostream &os, const Deck &deck);
};

std::ostream& operator<<(std::ostream &os, const Deck &deck);