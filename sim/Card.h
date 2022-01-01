#pragma once 

#include <ostream>

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
};

std::ostream& operator<<(std::ostream &os, const Card &card);
