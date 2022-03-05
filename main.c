#include "mcu.h"
#include "gpio.h"
#include "spiCom.h"

int main(void)
{

    mcu_initClocks();
    gpio_init();
    spi_init();

	return 0;
}
