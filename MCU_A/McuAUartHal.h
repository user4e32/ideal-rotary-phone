#include "HalBaseLayer.h"

class McuAUartHal : public HalBaseLayer
{
private:
    // hardware device/module number
    uint8_t mDeviceNum;

    ProtocolBaseLayer* mProtocolLayer;

public:
    // Constructor
    McuAUartHal(uint8_t argDeviceNum);

    // Destructor
    ~McuAUartHal();

    int Init(ProtocolBaseLayer* argBaseLayer);

    // inherited from parent
    int ReceiveData(uint8_t* argpBuffer, uint32_t argBufferSize);

    // inherited from parent
    int SendData(uint8_t* argpBuffer, uint32_t argBufferSize);
}