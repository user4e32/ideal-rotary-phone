#include "McuAUartHal.h"

// Constructor
McuAUartHal::McuAUartHal(uint8_t argDeviceNum)
    : HalBaseLayer(argDeviceNum)
{
    // nothing to do here
}

// Destructor
McuAUartHal::~McuAUartHal()
{
 // ensure cleanup of any dynamically allocatted ememory
}

int McuAUartHal::Init(ProtocolBaseLayer* argBaseLayer)
[
    HalBaseLayer::Init(argBaseLayer);

    // TODO: replace hardcodes with inputs from a config file/struct input argument to this function
    // assume overlay exists to mcu A configuration registers for UART
    mpUartConfig = &McuAUarts[mDeviceNum];
    mpUartConfig->Baud = 9600;
    mpUartConfig->Parity = 0;
    mpUartConfig->StopBits = 8;
    mpUartconfig->Start = 1;
]

// virtual for inherited classes to override
int McuAUartHal::ReceiveData(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    uint32_t BytesAvailable = mpUart->RxBytesAvailable;

    if (BytesAvailable)
    {
        for (int i = 0; i < BytesAvailable; i++)
        {
            // TODO: check if more bytes available than argBufferSize?
            argpBuffer[i] = pUart->TxFifo;
        }
    }

    return BytesAvailable;
}

// virtual for inherited classes to override
int McuAUartHal::SendData(uint8_t* argpBuffer, uint32_t argBufferSize)
{
    for (int i = 0; i < argBufferSize; i++)
    {
        // TODO: check if more bytes available than argBufferSize?
        pUart->TxFifo = argpBuffer[i];

        // TODO: delay if necessary for UART to ingest byte to transmit
    }

    return 0;
}