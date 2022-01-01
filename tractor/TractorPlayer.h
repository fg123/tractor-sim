#pragma once 

#include "sim/Player.h"

#include "TractorState.h"

struct TractorPlayer : public Player 
{
    TractorPlayer(TractorState* state, PlayerID id) : Player(id), state(state) {}

    void QueryPlay() override;

    // Dealer and need to put a card in the bottom
    void QueryPlaceBottom();

private:
    TractorState* state;
};