`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2026 11:03:24 AM
// Design Name: 
// Module Name: tb_clk_gen
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


module tb_clk_gen();

    reg             clkin;
    reg             run;
    reg             err;
    wire            clkout;
    
    
    clk_gen CLKGEN
    (
        .clkin(clkin),
        .run(run),
        .err(err),
        .clkout(clkout)
    );
    
    
    always #5 clkin <= ~clkin;
    
    
    initial
    begin
        clkin = 0;
        run = 0;
        err = 0;
    end
    
    
    initial
    begin
        
//        @(posedge clkin) run <= 1;
//        @(posedge clkin) run <= 0;
   
//    #2;
//    run <= 1;
//    #1;
//    run <= 0; 

    
    #7;
    run <= 1;
    #5;
    run <= 0;
   
        
    end

endmodule
