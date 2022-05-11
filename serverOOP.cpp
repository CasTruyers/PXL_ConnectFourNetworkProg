#include <iostream>
#include <zmq_addon.hpp>
#include "connectFour.hpp"

int main()
{
    connectFourServer connectFour;

    connectFour.waitForPlayers();

    while (connectFour.handleNetworkEvent())
    {
        connectFour.checkConnect();

        if (connectFour.winner) //! getwinner()
            break;
        else
            continue;
    }

    connectFour.declareWinner();

    return 0;
}