#include "ProtocolBaseLayer.h"

// Constructor
ProtocolBaseLayer::ProtocolBaseLayer(bool argEncrypted)
    : mEncrypted(argEncrypted)
{
    // nothing to do here
}

// Destructor
ProtocolBaseLayer::~ProtocolBaseLayer()
{
    // ensure cleanup of any dynamically allocatted ememory
}}

int ProtocolBaseLayer::Init(HalBaseLayer* argHalLayer)
[
    if (argHalLayer != nullptr)
    {
        return -1;
    }
    else
    {
        mHalLayer = argHalLayer;
        return 0;
    }
]

// virtual for inherited classes to override
int ProtocolBaseLayer::Receive(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // base class does nothing, return error
    return -1;
}

// virtual for inherited classes to override
int ProtocolBaseLayer::Transmit(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // base class does nothing, return error
    return -1;
}

// virtual for inherited classes to override
int EncryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // base class does nothing, return error
    return -1;
}

// virtual for inherited classes to override
int DeencryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    // base class does nothing, return error
    return -1;
}