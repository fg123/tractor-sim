#include "State.h"

std::ostream& operator<<(std::ostream &os, const State &state)
{
    os << "Deck: " << state.deck << std::endl;
    os << "Players: " << std::endl;
    for (auto& player : state.players) {
        os << *player << std::endl;
    }
    os << "Current Trick: " << std::endl;
    for (auto& trick : state.currentTrick) {
        os << "Player " << trick.first << ": ";
        for (auto& card : trick.second) {
            os << card << " ";
        }
        os << std::endl;
    }
    os << "Current Trick Leader: " << state.currentTrickLeader << std::endl;
    return os;
}