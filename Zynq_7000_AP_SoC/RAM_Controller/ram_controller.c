/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

//CWIR3

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"



int main()
{
    init_platform();

    int	val;

    XGpio address;
    XGpio dataWrite;
    XGpio wr_en;
    XGpio dataRead;

    XGpio_Initialize(&address, XPAR_AXI_GPIO_ADDR_DEVICE_ID);
    XGpio_Initialize(&dataWrite, XPAR_AXI_GPIO_DATAWRITE_DEVICE_ID);
    XGpio_Initialize(&wr_en, XPAR_AXI_GPIO_WR_EN_DEVICE_ID);
    XGpio_Initialize(&dataRead, XPAR_AXI_GPIO_DATAREAD_DEVICE_ID);

    XGpio_SetDataDirection(&address, 1, 0);
    XGpio_SetDataDirection(&dataWrite, 1, 0);
    XGpio_SetDataDirection(&wr_en, 1, 0);
    XGpio_SetDataDirection(&dataRead, 1, 1);	//instance_pointer , channel , direction (1 for input and 0 for output)

    printf("RAM Controller Test Initiated \n");

    printf("Writing in the RAM \n");

    XGpio_DiscreteWrite(&address, 1, 0);	//writing at address location 0
    XGpio_DiscreteWrite(&dataWrite, 1, 10);	//writing data 100
    XGpio_DiscreteWrite(&wr_en, 1, 1);			//enable signal
    usleep(1);									//delay 1 us
    XGpio_DiscreteWrite(&wr_en, 1, 0);			//disabling the write signal

    XGpio_DiscreteWrite(&address, 1, 1);	//writing at address location 1
	XGpio_DiscreteWrite(&dataWrite, 1, 20);	//writing data 200
	XGpio_DiscreteWrite(&wr_en, 1, 1);			//enable signal
	usleep(1);									//delay 1 us
	XGpio_DiscreteWrite(&wr_en, 1, 0);			//disabling the write signal

	XGpio_DiscreteWrite(&address, 1, 2);	//writing at address location 2
	XGpio_DiscreteWrite(&dataWrite, 1, 30);	//writing data 300
	XGpio_DiscreteWrite(&wr_en, 1, 1);			//enable signal
	usleep(1);									//delay 1 us
	XGpio_DiscreteWrite(&wr_en, 1, 0);			//disabling the write signal

	XGpio_DiscreteWrite(&address, 1, 3);	//writing at address location 3
	XGpio_DiscreteWrite(&dataWrite, 1, 40);	//writing data 400
	XGpio_DiscreteWrite(&wr_en, 1, 1);			//enable signal
	usleep(1);									//delay 1 us
	XGpio_DiscreteWrite(&wr_en, 1, 0);			//disabling the write signal


	printf("Writing in RAM Locations Finished.....Starting with Read Operations \n");

	XGpio_DiscreteWrite(&address, 1, 0);	//reading from location 0
	val = XGpio_DiscreteRead(&dataRead, 1);
	printf("RAM Location 0 : %d \n" , val);

	XGpio_DiscreteWrite(&address, 1, 1);	//reading from location 1
	val = XGpio_DiscreteRead(&dataRead, 1);
	printf("RAM Location 1 : %d \n" , val);

	XGpio_DiscreteWrite(&address, 1, 2);	//reading from location 2
	val = XGpio_DiscreteRead(&dataRead, 1);
	printf("RAM Location 2 : %d \n" , val);

	XGpio_DiscreteWrite(&address, 1, 3);	//reading from location 3
	val = XGpio_DiscreteRead(&dataRead, 1);
	printf("RAM Location 3 : %d \n" , val);


	printf("RAM Controller Test Finished \n");

    cleanup_platform();
    return 0;
}
