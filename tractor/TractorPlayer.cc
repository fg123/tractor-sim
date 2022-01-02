#include "TractorPlayer.h"
#include "TractorHand.h"

#include <algorithm>

using namespace TractorEvaluator;

void TractorPlayer::QueryPlay()
{
    Hand _hand(hand, state);
    if (state->currentTrick.empty())
    {
        // A lead must only be of the same "suit"
        
    }
    else 
    {
        // Follower
    }
}

void TractorPlayer::QueryPlaceBottom()
{
    // Stupid player
    state->ApplyStateChange(new ReturnCardToDeckStateChange(hand[0], id));
}
