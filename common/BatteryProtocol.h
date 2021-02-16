#include "ProtocolBaseLayer.h"

// example overlay to uart configuration/control registers
struct mcu_a_uart_config_struct_t
{
    uint8_t Baud;
    uint8_t Parity;
    uint8_t StopBits;
    uint8_t Start;
    uint32_t RxBytesAvailable;
    uint8_t RxFifo;
    uint8_t TxFifo;
};

class BatteryProtocol: public ProtocolBaseLayer
{
private:

    mcu_a_uart_config_struct_t* mpUartConfig;

public:
    // Constructor
    BatteryProtocol(bool argEncrypted);

    // Destructor
    ~BatteryProtocol();

    int Init(HalBaseLayer* argHalLayer);

    // inherited from parent
    int Receive(uint8_t* argpBuffer, uint32_t argBufferSize);

     // inherited from parent
    int Transmit(uint8_t* argpBuffer, uint32_t argBufferSize);

     // inherited from parent
    int EncryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize);

    // inherited from parent
    int DeencryptPacket(uint8_t* argpBuffer, uint32_t argBufferSize);
}