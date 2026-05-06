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

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xparameters.h"
#include "sleep.h"
#include "xil_types.h"


int main()
{
    init_platform();

    XGpio	masterRead;
    XGpio	masterWrite;
    XGpio	reset;
    XGpio	err;
    XGpio	cs;
    XGpio	run;
    XGpio	slaveRead;
    XGpio	slaveWrite;


    XGpio_Initialize(&masterRead, XPAR_AXI_GPIO_MASTERREAD_DEVICE_ID);
    XGpio_Initialize(&masterWrite, XPAR_AXI_GPIO_MASTERWRITE_DEVICE_ID);
    XGpio_Initialize(&reset, XPAR_AXI_GPIO_RESET_DEVICE_ID);
    XGpio_Initialize(&err, XPAR_AXI_GPIO_ERR_DEVICE_ID);
    XGpio_Initialize(&cs, XPAR_AXI_GPIO_CS_DEVICE_ID);
    XGpio_Initialize(&run, XPAR_AXI_GPIO_RUN_DEVICE_ID);
    XGpio_Initialize(&slaveRead, XPAR_AXI_GPIO_SLAVEREAD_DEVICE_ID);
    XGpio_Initialize(&slaveWrite, XPAR_AXI_GPIO_SLAVEWRITE_DEVICE_ID);

    XGpio_SetDataDirection(&masterRead, 1, 1);
    XGpio_SetDataDirection(&masterWrite, 1, 0);
    XGpio_SetDataDirection(&reset, 1, 0);
    XGpio_SetDataDirection(&err, 1, 1);
    XGpio_SetDataDirection(&cs, 1, 1);
    XGpio_SetDataDirection(&run, 1, 0);
    XGpio_SetDataDirection(&slaveRead, 1, 1);
    XGpio_SetDataDirection(&slaveWrite, 1, 0);


    printf("PSPI TEST Controller \n\n\n");

	int choice;

	int masterTxVal;
	u8 masterTxHex;

	int slaveTxVal;
	u8 slaveTxHex;

	int masterRxVal;
	u8 masterRxHex;

	int slaveRxVal;
	u8 slaveRxHex;

	int errStat;

	int ssStat;

    while(1)
    {

    	printf("1. Set master data  : \n");
    	printf("2. Set slave data   : \n");
    	printf("3. Read master data : \n");
    	printf("4. Read slave data  : \n");
    	printf("5. Check error stat : \n");
    	printf("6. Run System       : \n");
    	printf("7. Reset System     : \n");
    	scanf("%d" , &choice);


    	if(choice == 1)
    	{
    		ssStat = XGpio_DiscreteRead(&cs, 1);

    		if(ssStat == 1)
    		{
    			printf("Enter the master data : \n");
				scanf("%x" , &masterTxVal);
				masterTxHex = (u8)(masterTxVal & 0xFF);
				XGpio_DiscreteWrite(&masterWrite, 1, masterTxHex);
				printf("You entered : 0x%02X \n\n" , masterTxHex);
    		}

    		else
    		{
    			printf("System Busy.....\n\n");
    		}
    	}

    	else if(choice == 2)
    	{
    		ssStat = XGpio_DiscreteRead(&cs, 1);

    		if(ssStat == 1)
    		{
    			printf("Enter the slave data : \n");
				scanf("%x" , &slaveTxVal);
				slaveTxHex = (u8)(slaveTxVal & 0xFF);
				XGpio_DiscreteWrite(&slaveWrite, 1, slaveTxHex);
				printf("You entered : 0x%02X \n\n" , slaveTxHex);
    		}

    		else
    		{
    			printf("System Busy.....\n\n");
    		}
    	}

    	else if(choice == 3)
    	{
    		ssStat = XGpio_DiscreteRead(&cs, 1);

    		if(ssStat == 1)
    		{
    			masterRxVal = XGpio_DiscreteRead(&masterRead, 1);
				masterRxHex = (u8)(masterRxVal & 0xFF);
				printf("Master received data : 0x%02X \n\n" , masterRxHex);
    		}

    		else
    		{
    			printf("System Busy.....\n\n");
    		}
    	}

    	else if(choice == 4)
    	{
    		ssStat = XGpio_DiscreteRead(&cs, 1);

    		if(ssStat == 1)
    		{
    			slaveRxVal = XGpio_DiscreteRead(&slaveRead, 1);
				slaveRxHex = (u8)(slaveRxVal & 0xFF);
				printf("Slave received data : 0x%02X \n\n" , slaveRxHex);
    		}

    		else
    		{
    			printf("System Busy.....\n\n");
    		}
    	}

    	else if(choice == 5)
    	{
    		errStat = XGpio_DiscreteRead(&err, 1);
    		printf("Error Status : %d \n\n" , errStat);
    	}

    	else if(choice == 6)
    	{
    		ssStat = XGpio_DiscreteRead(&cs, 1);

    		if(ssStat == 1)
    		{
    			printf("Initiating Communication......\n\n");
				XGpio_DiscreteWrite(&run, 1, 1);
				usleep(160000);
				XGpio_DiscreteWrite(&run, 1, 0);
    		}

    		else
    		{
    			printf("System Busy.....\n\n");
    		}
    	}

    	else if(choice == 7)
    	{
    		ssStat = XGpio_DiscreteRead(&cs, 1);

    		if(ssStat == 1)
    		{
    			printf("Resetting system .....\n");
    			XGpio_DiscreteWrite(&reset, 1, 1);
    			usleep(500000);
    			XGpio_DiscreteWrite(&reset, 1, 0);
    			printf("System Reset Done \n\n");
    		}

    		else
    		{
    			printf("System Busy.....\n\n");
    		}
    	}

    }

    cleanup_platform();
    return 0;
}
