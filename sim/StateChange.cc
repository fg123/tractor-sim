#include "StateChange.h"
#include "State.h"

#include <stdexcept>
#include <algorithm>

void ValidateErase(std::vector<Card>& cards, Card cardToErase)
{
    auto it = std::find(cards.begin(), cards.end(), cardToErase);
    if (it != cards.end())
    {
        cards.erase(it);
    }
    else
    {
        throw std::runtime_error("Card not found in vector");
    }
}

void DealCardStateChange::ApplyTo(State& state)
{
    state.players[player]->hand.push_back(card);
    ValidateErase(state.deck.GetCards(), card);
}

void ReturnCardToDeckStateChange::ApplyTo(State& state)
{
    state.deck.GetCards().push_back(card);
    ValidateErase(state.players[player]->hand, card);
}

void PlayCardsStateChange::ApplyTo(State& state)
{
    for (auto& card : cards)
    {
        ValidateErase(state.players[player]->hand, card);
        state.players[player]->playedCards.push_back(card);
    }
}

void ResetDecksStateChange::ApplyTo(State& state)
{
    state.deck.ResetDeck(deckCount, withJokers);
    if (!shuffleSeed.empty())
    {
        state.deck.Shuffle(shuffleSeed);
    }
}