`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/05/2026 07:02:47 PM
// Design Name: 
// Module Name: tb_piso
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


module tb_piso();

    reg             clk;
    reg     [07:00] min;
    wire            out;
    
    
    piso    PISO
    (
        .clk(clk),
        .min(min),
        .out(out)
    );
    
    always #5 clk <= ~clk;
    
    initial
    begin
        clk = 0;
        min = 0;
    end
    
    
    initial
    begin
        @(posedge clk)  min <= 8'h75;
        repeat(9)
        begin
            @(posedge clk);
        end
        
        @(posedge clk) min <= 8'h56;
        repeat(9)
        begin
            @(posedge clk);
        end
        
    end

endmodule
