//CWIR3
//tried and tested om the ZYNQ AP SoC 7000

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"

#define BASE_REG_ADDR	XPAR_MATRIXER_0_S00_AXI_BASEADDR

int main()
{
    init_platform();

    int temp;

    printf("Matrix Multiplier Initiated \n");

    while(1)
    {
    	printf("Enter the matrix element values for matrix A : \n");

    	for(int i = 0; i <= 32; i=i+4)
    	{
    		scanf("%d" , &temp);
    		Xil_Out32( (BASE_REG_ADDR + i) , temp);
    	}

    	printf("Enter the matrix element values for matrix B : \n");

    	for(int i = 36; i <= 68; i=i+4)
    	    	{
    	    		scanf("%d" , &temp);
    	    		Xil_Out32( (BASE_REG_ADDR + i) , temp);
    	    	}

    	printf("Printing Solution \n");


    	for(int i = 72; i <= 80; i = i + 4)
    	{
    		temp = Xil_In32(BASE_REG_ADDR + i);
    		printf("%d " , temp);
    	}

    	printf("\n");

    	for(int i = 84; i <= 92; i = i + 4)
    	    	{
    	    		temp = Xil_In32(BASE_REG_ADDR + i);
    	    		printf("%d " , temp);
    	    	}

    	printf("\n");

    	for(int i = 96; i <= 104; i = i + 4)
    	    	    	{
    	    	    		temp = Xil_In32(BASE_REG_ADDR + i);
    	    	    		printf("%d " , temp);
    	    	    	}

    	printf("\n");
    	printf("Done \n");

    }

    cleanup_platform();
    return 0;
}
