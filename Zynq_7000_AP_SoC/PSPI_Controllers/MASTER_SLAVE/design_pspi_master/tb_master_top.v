`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2026 11:51:48 AM
// Design Name: 
// Module Name: tb_master_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_master_top();

    
    reg             clk;
    reg             reset;
    reg             run;
    reg     [07:00] pin;
    reg             sin;
    wire    [07:00] pout;
    wire            sout;
    wire            ss;
    
    
    master_top  PSPIM
    (
        .clk(clk),
        .reset(reset),
        .run(run),
        .pin(pin),
        .sin(sin),
        .pout(pout),
        .sout(sout),
        .ss(ss)
    );
    
    
    
    always #5 clk <= ~clk;
    
    initial
    begin
        clk = 0;
        run = 0;
        pin = 0;
        sin = 0;
    end
    
    
    initial
    begin
        
        @(posedge clk)
        begin
            reset <= 1;
        end
        
        @(posedge clk)
        begin
            reset <= 0;
        end
        
        @(posedge clk)
        begin
            run <= 1;
            pin <= 8'h95;
        end
        
        @(posedge clk)
        begin
            run <= 0;
        end
        
        @(posedge PSPIM.wCLK)   sin <= 1;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 1;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        
        
        repeat(5)
        begin
            @(posedge clk);
        end
        
        
        @(posedge clk)
        begin
            run <= 1;
            pin <= 8'h95;
        end
        
        @(posedge clk)
        begin
            run <= 0;
        end
        
        @(posedge PSPIM.wCLK)   sin <= 1;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 1;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 0;
        @(posedge PSPIM.wCLK)   sin <= 1;
        @(posedge PSPIM.wCLK)   sin <= 0;

        
    end
    
    

endmodule
