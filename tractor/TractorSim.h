#pragma once 

#include "sim/Sim.h"
#include "sim/StateChange.h"

#include "TractorState.h"

// Rules and Constraints for Tractor 

class TractorSim : public Sim
{
    TractorState state;

    size_t numPlayers = 4;

public:
    TractorSim();

    // Sets up the decks
    void Initialize();

    // Begins dealing and trump determination process
    void StartDeal();

    // Bottom cards dealt to the dealer
    void DealBottom();

    void StartGame();

};
