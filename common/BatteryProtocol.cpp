#include "BatteryProtocol.h"

#define BATTERY_PROTOCOL_FIRST_BYTE 0xFE

// Constructor
BatteryProtocol::BatteryProtocol(bool argEncrypted)
    : ProtocolBaseLayer(argEncrypted)
{
    // nothing to do here
}

// Destructor
BatteryProtocol::~BatteryProtocol()
{
    // ensure cleanup of any dynamically allocatted ememory
}

int BatteryProtocol::Init(HalBaseLayer* argHalLayer)
[
    return ProtocolBaseLayer::Init(argHalLayer);
]

// override parent defnition
int BatteryProtocol::Receive(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    uint32_t BytesRead = 0;

    // get bytes from HAL
    BytesRead = mHalLayer->ReceiveData(argpBuffer, argBufferSize);

    if (BytesRead > 0)
    {
        if (mEncrypted)
        {
            DeencryptPacket(argpBuffer, argBufferSize);
        }

        // example check received bytes to ensue they conform to protocol
        if (argpBuffer[0] != BATTERY_PROTOCOL_FIRST_BYTE)
        {
            BytesRead = -1;
        }
    }

    return BytesRead;

}

// override parent defnition
int BatteryProtocol::Transmit(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // example set bytes to conform to protocol
    argpBuffer[0] = BATTERY_PROTOCOL_FIRST_BYTE;
    
    if (mEncrypted)
    {
        EncryptPacket(argpBuffer, argBufferSize);
    }

    // send packet to HAL
    return mHalLayer->SendData(argpBuffer, argBufferSize);
}

// virtual for inherited classes to override
int EncryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // example encrypt by adding 1 from each byte in packet
    for (int i = 0; i < argBufferSize; i ++)
    {
        argpBuffer[i] = (argpBuffer[i] + 1);
    }

    return 0;
}

// virtual for inherited classes to override
int DeencryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // example decrypt by subtracting 1 from each byte in packet
    for (int i = 0; i < argBufferSize; i ++)
    {
        argpBuffer[i] = (argpBuffer[i] - 1);
    }

    return 0;
}