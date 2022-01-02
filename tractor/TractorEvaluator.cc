#include "TractorEvaluator.h"
#include "TractorPlayer.h"

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
        // // TODO: implement throw and tractor
        // return IsAllSameCard(play);
        return IsAllSameSuit(play, state);
    }

    bool IsLegalFollow(const Play& play, const TractorState* state)
    {
        const Play& lead = state->currentTrick.at(state->currentTrickLeader);
        if (lead.size() != play.size())
        {
            return false;
        }
        // Validate pairs and stuff
        return true;
    }
};