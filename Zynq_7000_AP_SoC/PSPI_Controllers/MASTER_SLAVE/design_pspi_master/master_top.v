`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2026 11:37:08 AM
// Design Name: 
// Module Name: master_top
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


module master_top
(
    input   wire            clk,
    input   wire            reset,
    input   wire            run,
    input   wire    [07:00] pin,
    input   wire            sin,
    output  wire    [07:00] pout,
    output  wire            sout,
    output  wire            ss,
    output  wire            err,
    output  wire            sclk
);


    wire    wERR;
    wire    wCLK;
    
    assign  err = SIPO.err;
    assign  sclk = wCLK;
        
    clk_gen CLKGEN
    (
        .clkin(clk),
        .reset(reset),
        .run(run),
        .err(wERR),
        .clkout(wCLK),
        .ss(ss)
    );
    
    piso    PISO
    (
        .clk(wCLK),
        .reset(reset),
        .min(pin),
        .out(sout)
    );
    
    sipo    SIPO
    (
        .clk(wCLK),
        .reset(reset),
        .sin(sin),
        .out(pout),
        .err(wERR)
    );
    

endmodule

