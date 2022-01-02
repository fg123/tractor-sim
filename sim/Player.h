#pragma once

#include "Card.h"

#include <vector>
#include <unordered_map>

using PlayerID = size_t;


class Player
{
protected:
    PlayerID id;
public:
    Player(PlayerID id) : id(id) {}
    virtual ~Player() {}

    std::vector<Card> hand;
    std::vector<Card> playedCards;

    virtual void QueryPlay() = 0;
    PlayerID GetId() const { return id; }
};

std::ostream& operator<<(std::ostream &os, const Player &player);