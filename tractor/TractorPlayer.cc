#include "TractorPlayer.h"

void TractorPlayer::QueryPlay()
{
    if (state->currentTrick.empty())
    {
        // Leader
        
    }

}

void TractorPlayer::QueryPlaceBottom()
{
    // Stupid player
    state->ApplyStateChange(new ReturnCardToDeckStateChange(hand[0], id));
}
