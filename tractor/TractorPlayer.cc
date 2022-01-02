#include "TractorPlayer.h"
#include "TractorHand.h"

#include <algorithm>

using namespace TractorEvaluator;

void TractorPlayer::QueryPlay()
{
    TractorHand tractorHand(hand, state);
    if (state->currentTrick.empty())
    {
        // A lead must only be of the same "suit"
        // IsLegalLead(hand, play, state);
    }
    else 
    {
        // Follower
        // IsLegalFollow(hand, play, state);
    }
}

void TractorPlayer::QueryPlaceBottom()
{
    // Stupid player
    state->ApplyStateChange(new ReturnCardToDeckStateChange(hand[0], id));
}
