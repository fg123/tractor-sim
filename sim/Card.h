#pragma once 

#include <ostream>
#include <vector>

enum Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
    SmallJoker,
    BigJoker
};

enum Rank
{
    None,
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

struct Card
{
    Suit suit;
    Rank rank;

    Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

    bool operator==(const Card& other) const
    {
        return suit == other.suit && rank == other.rank;
    }

    bool operator!=(const Card& other) const
    {
        return !(*this == other);
    }
};

namespace std
{
    template<>
    struct hash<Card>
    {
        size_t operator()(const Card& card) const
        {
            return hash<int>()(static_cast<int>(card.suit)) ^ hash<int>()(static_cast<int>(card.rank));
        }
    };
};


using Play = std::vector<Card>;

std::ostream& operator<<(std::ostream &os, const Card &card);
