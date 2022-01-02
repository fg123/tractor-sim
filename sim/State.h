#pragma once

#include "Deck.h"
#include "Player.h"
#include "StateChange.h"

#include <vector>
#include <ostream>
#include <unordered_map>

struct State
{
    Deck deck;
    
    // Players must be ordered in the play-order
    std::vector<Player*> players;

    std::vector<StateChange*> stateChanges;

    // Current Trick (playerIndex -> CardsPlayed)
    std::unordered_map<PlayerID, Play> currentTrick;
    PlayerID currentTrickLeader = 0;

    ~State()
    {
        for (auto& player : players) {
            delete player;
        }
        for (auto& stateChange : stateChanges) {
            delete stateChange;
        }
    }

    void ApplyStateChange(StateChange* stateChange)
    {
        stateChange->ApplyTo(*this);
        stateChanges.push_back(stateChange);
    }
};

std::ostream& operator<<(std::ostream &os, const State &state);