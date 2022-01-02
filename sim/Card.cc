#include "Card.h"

std::ostream& operator<<(std::ostream &os, const Card &card)
{
    switch (card.suit)
    {
    case Clubs:
        os << "C";
        break;
    case Diamonds:
        os << "D";
        break;
    case Hearts:
        os << "H";
        break;
    case Spades:
        os << "S";
        break;
    case SmallJoker:
        os << "J  ";
        return os;
    case BigJoker:
        os << "JJ ";
        return os;
    }
    switch (card.rank)
    {
    case None:
        break;
    default:
        int rank = static_cast<int>(card.rank);
        if (rank < 10)
        {
            os << rank << " ";
        }
        else
        {
            os << rank;
        }
        break;
    }
    return os;
}