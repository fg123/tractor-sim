#include "TractorSim.h"
#include "TractorPlayer.h"

#include "utils/Logging.h"

TractorSim::TractorSim()
{

}

void TractorSim::Initialize()
{
    for (size_t i = 0; i < numPlayers; i++) {
        TractorPlayer* player = new TractorPlayer(&state, state.players.size());
        state.players.emplace_back(player);
    }
    state.ApplyStateChange(new ResetDecksStateChange(2, true, "asdjkl;asdfjkl;"));
}

void TractorSim::StartDeal()
{
    size_t p = 0;
    while (state.deck.GetCardCount() > 8)
    {
        state.ApplyStateChange(new DealCardStateChange(state.deck.GetTopCard(), p));
        p = (p + 1) % numPlayers;
    }
}

void TractorSim::DealBottom()
{
    state.ApplyStateChange(new DealCardStateChange(state.deck.GetTopCard(), state.dealer));
}

void TractorSim::StartGame()
{
    // Wait for dealer to finish putting bottom cards down
    while (state.deck.GetCardCount() != 8) {
        dynamic_cast<TractorPlayer*>(state.players[state.dealer])->QueryPlaceBottom();
    }

    LOG_DEBUG(state);

    state.currentTrickLeader += 1;
    
    
}
