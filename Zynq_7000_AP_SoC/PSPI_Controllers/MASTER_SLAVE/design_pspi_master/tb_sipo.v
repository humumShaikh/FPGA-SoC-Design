`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2026 10:23:53 AM
// Design Name: 
// Module Name: tb_sipo
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


module tb_sipo();

    reg             clk;
    reg             sin;
    wire    [07:00] out;
    
    
    sipo    SIPO
    (
        .clk(clk),
        .sin(sin),
        .out(out)
    );
    
    
    always #5 clk <= ~clk;
    
    initial
    begin
        clk = 0;
        sin = 0;
    end
    
    
    initial
    begin
        
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 0;
        
        @(posedge clk) sin <= 0;
        
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 0;
        @(posedge clk) sin <= 1;
        @(posedge clk) sin <= 1;
        
        @(posedge clk) sin <= 0;
        
    end
    
    

endmodule
