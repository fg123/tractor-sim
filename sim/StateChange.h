#pragma once 

#include "Card.h"
#include "Player.h"

#include <vector>

class State;

class StateChange
{
public:
    virtual ~StateChange() {}
    virtual void ApplyTo(State& state) = 0;
};

class DealCardStateChange : public StateChange
{
    Card card;
    int player;
public:
    DealCardStateChange(Card card, PlayerID player)
        : card(card), player(player)
    {
    }
    void ApplyTo(State& state) override;
};

class PlayCardsStateChange : public StateChange
{
    std::vector<Card> cards;
    int player;
public:
    PlayCardsStateChange(std::vector<Card> cards, PlayerID player)
        : cards(cards), player(player)
    {
    }
    void ApplyTo(State& state) override;
};

class ReturnCardToDeckStateChange : public StateChange
{
    Card card;
    int player;
public:
    ReturnCardToDeckStateChange(Card card, PlayerID player)
        : card(card), player(player)
    {
    }
    void ApplyTo(State& state) override;
};

class ResetDecksStateChange : public StateChange
{
    int deckCount;
    bool withJokers;
    const std::string& shuffleSeed;
public:
    ResetDecksStateChange(int deckCount, bool withJokers, const std::string& shuffleSeed = "")
        : deckCount(deckCount), withJokers(withJokers), shuffleSeed(shuffleSeed)
    {
    }
    void ApplyTo(State& state) override;
};