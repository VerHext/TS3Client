
//FreaxBot - TS3Client

#include <iostream>
#include "header/client.h"
#include "header/PacketHandler.h"


int main(void) 
{
    InstallTomCrypt();
    std::cout << "> TS3Client developed by Freaxbot\n> Licensed under the MIT license! \n";
    
        startingUDPSocket(9987, "127.0.0.1");
    
    return 0;
} 
