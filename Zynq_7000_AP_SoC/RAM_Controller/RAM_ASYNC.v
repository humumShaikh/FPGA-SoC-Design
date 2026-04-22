`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/22/2026 02:04:11 PM
// Design Name: 
// Module Name: RAM_ASYNC
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


module RAM_ASYNC
(
    input   wire    [7:0]   data_in,
    input   wire    [1:0]   addr,
    input   wire            wr_en,
    output  reg     [7:0]   data_out
);

    reg [7:0]   MEM [0:3];
    
    always @(*)
    begin
        if(wr_en == 0)
        begin
            data_out <= MEM[addr];
        end
        
        else if(wr_en == 1)
        begin
            MEM[addr] <= data_in;
        end
    end

endmodule
