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
//Tried and tested on the ZYNQ 7000 AP SoC

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xparameters.h"
#include "xil_types.h"
#include "sleep.h"


int main()
{
    init_platform();

    XGpio dataWrite;
    XGpio dataRead;
    XGpio cs;
    XGpio error;
    XGpio pgen;
    XGpio run;

    XGpio_Initialize(&dataWrite, XPAR_AXI_GPIO_DATAWRITE_DEVICE_ID);
    XGpio_Initialize(&dataRead, XPAR_AXI_GPIO_DATAREAD_DEVICE_ID);
    XGpio_Initialize(&cs, XPAR_AXI_GPIO_CS_DEVICE_ID);
    XGpio_Initialize(&error, XPAR_AXI_GPIO_ERROR_DEVICE_ID);
    XGpio_Initialize(&pgen, XPAR_AXI_GPIO_PGEN_DEVICE_ID);
    XGpio_Initialize(&run, XPAR_AXI_GPIO_RUN_DEVICE_ID);

    XGpio_SetDataDirection(&dataWrite, 1, 0);
    XGpio_SetDataDirection(&dataRead, 1, 1);
    XGpio_SetDataDirection(&cs, 1, 1);
    XGpio_SetDataDirection(&error, 1, 1);
    XGpio_SetDataDirection(&pgen, 1, 0);
    XGpio_SetDataDirection(&run, 1, 0);

    XGpio_DiscreteWrite(&run, 1, 0);

    int masterVal;
    u8 masterHex;
    int slaveVal;
    u8 slaveHex;

    int choice;

    int s;

    printf("PSPI Master Controller \n\n");

    XGpio_DiscreteWrite(&run, 1, 0);
    XGpio_DiscreteWrite(&pgen, 1, 0);


    while(1)
    {
    	printf("Make a selection : \n");
    	printf("1. Check Read Data \n");
    	printf("2. Initiate Communication \n");
    	printf("3. Check error status \n");
    	scanf("%d" , &choice);

    	if(choice == 1)
    	{
    		slaveVal = XGpio_DiscreteRead(&dataRead, 1);
    		slaveHex = (u8)(slaveVal & 0xFF);
    		printf("Read Data : 0x%02X \n\n" , slaveHex);
    	}

    	else if(choice == 2)
    	{
    		printf("Enter the data to be transmitted : \n");
    		scanf("%x" , &masterVal);
    		masterHex = (u8)(masterVal & 0xFF);
    		printf("You entered : 0x%02X \n" , masterHex);
    		printf("Initiating Communication \n");
    		XGpio_DiscreteWrite(&dataWrite, 1, masterHex);
    		XGpio_DiscreteWrite(&run, 1, 1);
    		usleep(500000);
    		XGpio_DiscreteWrite(&run, 1, 0);
    		s = XGpio_DiscreteRead(&cs, 1);
    		while(s != 1)
    		{
    			s = XGpio_DiscreteRead(&cs, 1);
    		}
    		printf("Communication Ended \n");
    	}

    	else if(choice == 3)
    	{
    		s = XGpio_DiscreteRead(&error, 1);
    		printf("Error Status : %d \n\n" , s);
    	}

    	else
    	{
    		printf("Invalid Choice......\n\n");
    	}
    }

    cleanup_platform();
    return 0;
}
