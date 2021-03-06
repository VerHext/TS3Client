#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "header/PacketHandler.h"
#include "header/crypto.h"
#include "header/Util.h"


class Packet {
public:
    int PackeiId;
    int ClientId;
    int PacketType;
    std::string Data;
    std::string Header;
};

std::vector<unsigned char> BuildHeader(char packettype)
{
    std::vector<unsigned char> h = string_to_char("TS3INIT1");

    h.push_back(0x00);
    h.push_back(0x65);
    h.push_back(0x00);
    h.push_back(0x00);
    h.push_back(packettype);
    return h;
}



void GetPacket(char* data, int lengh)
{
    std::string  type = getByte(data, 11, lengh);
    
    if (type == "88") 
    {
        std::cout << "Package INIT1" << std::endl;
        InitProcess(data, lengh);
    }

    if (type == "20")
    {
        std::cout << "[CMD]" << std::endl;
        Decrypt(data, lengh); 
        char PId[2];
        memcpy(PId, &data[8], 2);

        Encrypt(PId, 2, 6);
          
    }
    

}
