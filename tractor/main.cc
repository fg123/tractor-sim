#include "TractorSim.h"

#include "utils/Logging.h"

int main()
{
    TractorSim sim;

    sim.Initialize();
    sim.StartDeal();
    sim.DealBottom();
    sim.StartGame();

    return 0;
}