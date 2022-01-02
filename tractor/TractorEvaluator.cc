#include "TractorEvaluator.h"
#include "TractorPlayer.h"
#include "TractorHand.h"

namespace TractorEvaluator
{
    PlaySuit CardToPlaySuit(const Card& card, const TractorState* state)
    {
        if (card.suit == state->trumpSuit ||
            card.rank == state->trumpRank ||
            card.suit == Suit::SmallJoker ||
            card.suit == Suit::BigJoker)
        {
            return PlaySuit::Trump;
        }
        switch (card.suit)
        {
        case Suit::Clubs:
            return PlaySuit::Clubs;
        case Suit::Diamonds:
            return PlaySuit::Diamonds;
        case Suit::Hearts:
            return PlaySuit::Hearts;
        case Suit::Spades:
            return PlaySuit::Spades;
        default:
            // Should never reach here
            break;
        }
        throw std::runtime_error("Unknown suit");
    }

    size_t GetCardValueWithinSuit(PlaySuit suit, const Card& card, const TractorState* state)
    {
        // TODO: implement 
        return card.rank;
    }

    bool IsAllSameCard(const Play& play)
    {
        for (size_t i = 1; i < play.size(); ++i) {
            if (play[i] != play[0]) {
                return false;
            }
        }
        return true;
    }

    bool IsAllSameSuit(const Play& play, const TractorState* state) 
    {
        for (size_t i = 1; i < play.size(); ++i) {
            if (CardToPlaySuit(play[i], state) != CardToPlaySuit(play[0], state)) {
                return false;
            }
        }
        return true;
    }

    bool IsLegalLead(const Play& play, const TractorState* state)
    {
        // TODO: implement throw and tractor
        return IsAllSameSuit(play, state);
    }

    bool IsLegalFollow(const TractorHand& hand, const Play& play, const TractorState* state)
    {
        const Play& lead = state->currentTrick.at(state->currentTrickLeader);
        if (lead.size() != play.size())
        {
            return false;
        }

        TractorHand playHand { play, state };

        PlaySuit leadSuit = CardToPlaySuit(lead[0], state);
        
        // If you're out, anything is legal
        if (hand.GetSuitCount(leadSuit) == 0)
        {
            return true;
        }
        
        if (hand.GetSuitCount(leadSuit) <= lead.size())
        {
            // No choice anyway, make sure it's all in there
            return playHand.GetSuitCount(leadSuit) == lead.size();
        }
        
        // We have more in the suit than possible, ensure structure matches
        
        
        return true;
    }
};