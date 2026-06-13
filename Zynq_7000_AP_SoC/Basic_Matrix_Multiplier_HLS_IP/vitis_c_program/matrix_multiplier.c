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
#include "sleep.h"

#define BASE_REG_ADDR XPAR_MUL22_0_S_AXI_CONTROL_BASEADDR

#define EA11	BASE_REG_ADDR + 0x10
#define EA12	BASE_REG_ADDR + 0x18
#define EA21	BASE_REG_ADDR + 0x20
#define EA22	BASE_REG_ADDR + 0x28

#define EB11	BASE_REG_ADDR + 0x30
#define EB12	BASE_REG_ADDR + 0x38
#define EB21	BASE_REG_ADDR + 0x40
#define EB22	BASE_REG_ADDR + 0x48

#define EC11	BASE_REG_ADDR + 0x50
#define EC12	BASE_REG_ADDR + 0x60
#define EC21	BASE_REG_ADDR + 0x70
#define EC22	BASE_REG_ADDR + 0x80



int main()
{
    init_platform();

    int nA11 , nA12 , nA21 , nA22 , nB11 , nB12 , nB21 , nB22 , nC11 , nC12 , nC21 , nC22;


    sleep(2);

    printf("Matrix Multiplier Hardware Accelerator \n");

    while(1)
    {
    	printf("Enter the values for Matrix A : \n");

		printf("A11 : ");
		scanf("%d" , &nA11);
		printf("A12 : ");
		scanf("%d" , &nA12);
		printf("A21 : ");
		scanf("%d" , &nA21);
		printf("A21 : ");
		scanf("%d" , &nA22);
		printf("\n");


		printf("Enter the values for Matrix B : \n");

		printf("B11 : ");
		scanf("%d" , &nB11);
		printf("B12 : ");
		scanf("%d" , &nB12);
		printf("B21 : ");
		scanf("%d" , &nB21);
		printf("B21 : ");
		scanf("%d" , &nB22);

		Xil_Out32(EA11, nA11);
		Xil_Out32(EA12, nA12);
		Xil_Out32(EA21, nA21);
		Xil_Out32(EA22, nA22);

		Xil_Out32(EB11, nB11);
		Xil_Out32(EB12, nB12);
		Xil_Out32(EB21, nB21);
		Xil_Out32(EB22, nB22);

		Xil_Out32(BASE_REG_ADDR, 0x01);
		sleep(1);

		nC11 = Xil_In32(EC11);
		nC12 = Xil_In32(EC12);
		nC21 = Xil_In32(EC21);
		nC22 = Xil_In32(EC22);

		printf("Results : \n");
		printf("%d  %d \n" , nC11 , nC12);
		printf("%d  %d \n" , nC21 , nC22);
		printf("\n\n");

    }

    cleanup_platform();
    return 0;
}
