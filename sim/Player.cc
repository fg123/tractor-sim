#include "Player.h"

std::ostream& operator<<(std::ostream &os, const Player &player)
{
    os << "Player " << player.GetId() << ": ";
    for (auto& card : player.hand) {
        os << card << " ";
    }
    return os;
}