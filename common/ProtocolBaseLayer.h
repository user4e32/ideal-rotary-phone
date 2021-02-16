#include "HalBaseLayer.h"

class ProtocolBaseLayer
{
private:
    // whether protocol is encrypted
    bool mEncrypted;

    HalBaseLayer* mHalLayer;

public:
    // Constructor
    ProtocolBaseLayer(bool argEncrypted);

    // Destructor
    ~ProtocolBaseLayer();

    int Init(HalBaseLayer* argHalLayer);

    // virtual for inherited classes to override
    virtual int Receive(uint8_t* argpBuffer, uint32_t argBufferSize);

    // virtual for inherited classes to override
    virtual int Transmit(uint8_t* argpBuffer, uint32_t argBufferSize);

    // virtual for inherited classes to override
    virtual int EncryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize);

    // virtual for inherited classes to override
    virtual int DeencryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize);
}