#include "BatteryProtocol.h"
#include "McuAUartHal.h"

#define RX_BUFFER_LENGTH 256

bool gSendPacketToBattery;
bool gSendPacketToGateway;

int main()
{
    // TODO: if initializatoins fail, notify user/host and handle errors or return

    // initialize Battery Unencrypted Protocol to Uart to Battery (Uart hw module 1)
    BatteryProtocol BattUnencProt(false);
    McuAUartHal UartHalToBatt(1);
    BattUnencProt.Init(&UartHalToBatt);
    UartHalToBatt.Init(&BattUnencProt);

    // initialize Gateway Encrypted Protocol to Uart to Gateway (Uart hw module 2)
    GatewayProtocol GatewayEncProt(true);
    McuAUartHal UartHalToGateway(2);
    GatewayEncProt.Init(&UArtHaltoGateway);
    UartHalToGateway.Init(&GatewayEncProt);

    // demo buffers and counts
    uint8_t TxBufferToBattery[4] = {1, 2, 3, 4};

    uint8_t RxBufferFromBattery[RX_BUFFER_LENGTH];

    uint8_t TxBufferToGateway[4] = {4, 5, 6, 7};

    uint8_t RxBufferFromGateway[RX_BUFFER_LENGTH];

    uint32_t BatteryBytesReceived = 0;

    uint32_t GatewayBytesReceived = 0;
    
    while(1)
    {
        BatteryBytesReceived = BattProt.Receive(RxBuffer, RX_BUFFER_LENGTH);

        if (BatteryBytesReceived > 0)
        {
            for (int i = 0; i < BatteryBytesReceived; i++ )
            {
                printf("Battery Byte[%d] received: %02X\n", RxBufferFromBattery[i]);
            }
        }

        // assume user can set gSendPacketToBattery to true
        if (gSendPacketToBattery)
        {
            BattUnencProt.Transmit(&TxBufferToBattery, sizeof(TxBufferToBattery);
        }

        GatewayBytesReceived = GatewayEncProt.Receive(RxBufferFromGateway, RX_BUFFER_LENGTH);

        if (GatewayBytesReceived > 0)
        {
            for (int i = 0; i < GatewayBytesReceived; i++ )
            {
                printf("Gateway Byte[%d] received: %02X\n", RxBufferFromGateway[i]);
            }
        }

        // assume user can set gSendPacketToGateway to true
        if (gSendPacketToGateway)
        {
            GatewayEncProt.Transmit(&TxBufferToGateway, sizeof(TxBufferToGateway);
        }
        
        // OS delay in seconds
        delay(1);
    }
}
