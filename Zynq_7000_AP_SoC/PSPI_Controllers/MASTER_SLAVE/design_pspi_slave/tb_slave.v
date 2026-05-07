`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2026 12:36:05 PM
// Design Name: 
// Module Name: tb_slave
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


module tb_slave();

    reg     [07:00] DIN;
    reg             SCLK;
    reg             MOSI;
    reg             SS;
    wire            MISO;
    
    
    slave   PSPIS
    (
        .DIN(DIN),
        .SCLK(SCLK),
        .MOSI(MOSI),
        .SS(SS),
        .MISO(MISO)
    );
    
    
    
    initial
    begin
        DIN = 8'h42;
        SCLK = 0;
        MOSI = 0;
        SS = 0;
        
        repeat(20)
        begin
            #10 SCLK <= ~SCLK;
        end
    end
    
    
    initial
    begin
        @(posedge SCLK) MOSI <= 1;
        @(posedge SCLK) MOSI <= 0;
        @(posedge SCLK) MOSI <= 0;
        @(posedge SCLK) MOSI <= 1;
        @(posedge SCLK) MOSI <= 1;
        @(posedge SCLK) MOSI <= 0;
        @(posedge SCLK) MOSI <= 0;
        @(posedge SCLK) MOSI <= 0;
        @(posedge SCLK) MOSI <= 0;
        @(posedge SCLK) MOSI <= 0;
    end

endmodule
