module lif
#
(
    parameter threshold = 100
)
(
    input   wire    clk,
    input   wire    reset,
    
    input   wire    i1,
    input   wire    i2,
    input   wire    i3,
    output  reg     fire
);

    
    reg [7:0]   Vmem;


    
    
    initial
    begin
        Vmem <= 0;
        fire <= 0;
    end
    
    
    always @(posedge clk or posedge reset)
    begin
        if(reset == 1)
        begin
            Vmem <= 0;
        end
        
        else
        begin
            if(Vmem >= threshold)
            begin
                Vmem <= 0;
                fire <= 1;
            end
            
            else if(Vmem >= 5)
            begin
                Vmem <= Vmem - 5;
                fire <= 0;
            end
            
            else
            begin
                Vmem <= 0;
                fire <= 0;
            end
        end
    end
    
    
    always @(posedge i1)
    begin
        Vmem = Vmem + 10;
    end
    
    always @(posedge i2)
    begin
        Vmem = Vmem + 20;
    end
    
    always @(posedge i3)
    begin
        Vmem = Vmem + 30;
    end
   

endmodule
