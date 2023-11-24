module PCReg #(         //topfile
    parameter       DATA_WIDTH = 32
) (
    input logic                     clk,               
    input logic                     rst,
    input logic [DATA_WIDTH-1:0]    next_PC,
    output logic [DATA_WIDTH-1:0]   PC   
);

always_ff @ (posedge clk, posedge rst) 
    if(clk)         PC <= next_PC;
    else if(rst)    PC <= 0;

endmodule
