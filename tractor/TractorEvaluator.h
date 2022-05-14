#pragma once

#include "TractorState.h"

#include "sim/Card.h"

#include <vector>
#include <map>
#include <set>

namespace TractorEvaluator 
{
    using PlayStructureWaterfall = std::set<PlayStructure, std::greater<PlayStructure>>;
    // Assumes that Play is all one PlaySuit, since waterfalls are only
    //   created for Leads.
    PlayStructureWaterfall WaterfallFromPlay(const Play& play);
    
    struct PlayStructure 
    {
        // TODO:
        // one way could be to have a priority structure waterfall, i.e. 222-333 becomes:
        // 1. length 2 - triple tractor
        // 2. length 2 - double tractor + 2 single
        // 3. length 2 - triple
        // 4. length 1 - triple, length 1 double, 1 single
        // 5. etc.etc
        using Arity = size_t;
        // How many of each arity, sorted by arity for key-ing
        std::map<Arity, size_t, std::greater<Arity>> nonTractors;

        // TODO: Aggregate and implement tractors

        std::string ToString() const;

        bool operator<(const PlayStructure& other) const;
        bool operator==(const PlayStructure& other) const;
    };

    enum class PlaySuit
    {
        Spades,
        Hearts,
        Diamonds,
        Clubs,
        Trump
    };

    PlaySuit CardToPlaySuit(const Card& card, const TractorState* state);
    size_t GetCardValueWithinSuit(PlaySuit suit, const Card& card, const TractorState* state);
    bool IsLegalLead(const Play& play, const TractorState* state);
    bool IsLegalFollow(const Play& play, const TractorState* state);
};

// Hash fpr PlayStructure
namespace std {

    template <>
    struct hash<TractorEvaluator::PlayStructure>
    {
        std::size_t operator()(const TractorEvaluator::PlayStructure& k) const
        {
            return hash<string>()(k.ToString());
        }
    };
};