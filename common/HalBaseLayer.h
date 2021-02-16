#include "ProtocolBaseLayer.h"

class HalBaseLayer
{
private:
    // hardware device/module number
    uint8_t mDeviceNum;

    ProtocolBaseLayer* mProtocolLayer;

    // assume OS provide mutex
    mutex_t mTransmitMutex;

public:
    // Constructor
    HalBaseLayer(uint8_t argDeviceNum);

    // Destructor
    ~HalBaseLayer();

    int Init(ProtocolBaseLayer* argBaseLayer);

    // virtual for inherited classes to override
    virtual int ReceiveData(uint8_t* argpBuffer, uint8_t argBufferSize);

    // virtual for inherited classes to override
    virtual int SendData(uint8_t* argpBuffer, uint8_t argBufferSize);
}