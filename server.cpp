#include <iostream>
#include <zmq_addon.hpp>
#include "connectFour.hpp"

bool newThread = 1;
// bool closeServer = 0;

void game()
{
    cout << "new Thread" << endl;

    connectFourServer connectFour;
    connectFour.waitForPlayers();
    newThread = 1;

    while (connectFour.handleNetworkEvent()) //& !closeServer
    {
        connectFour.checkConnect();

        if (connectFour.getWinner())
            break;
        else
            continue;
    }
    connectFour.declareWinner();
}

// void getInput()
// {
//     std::cin.get();
//     closeServer = 1;
// }

int main()
{
    // std::thread close(getInput);
    while (true) // closeServer
    {
        // class hier instantiaten, waitForPLayer() en class pointer meegeven aan thread. Lastig om locatie van gameInstatie in vector bij te houden wanneer andere zich verwijderen uit vector.
        if (newThread)
        {
            std::thread gameInstance(game);
            gameInstance.detach();
            newThread = 0;
        }
    }

    return 0;
}