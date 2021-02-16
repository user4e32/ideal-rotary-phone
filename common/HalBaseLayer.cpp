#include "HalBaseLayer.h"

// Constructor
HalBaseLayer::HalBaseLayer(uint8_t argDeviceNum)
    : mDeviceNum(argDeviceNum)
{
    // nothing to do here
}

// Destructor
HalBaseLayer::~HalBaseLayer()
{
 // ensure cleanup of any dynamically allocatted ememory
}}

int HalBaseLayer::Init(ProtocolBaseLayer* argBaseLayer)
[
    if (argBaseLayer != nullptr)
    {
        return -1;
    }
    else
    {
        mProtocolBaseLayer = argBaseLayer;
        return 0;
    }
]

// virtual for inherited classes to override
int HalBaseLayer::ReceiveData(uint8_t* argpBuffer, uint8_t argBufferSize)
{
    // base class does nothing, return error
    return -1;
}

// virtual for inherited classes to override
int HalBaseLayer::SendData(uint8_t* argpBuffer, uint8_t argBufferSize)
{
    // base class does nothing, return error
    return -1;
}