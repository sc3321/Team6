module PCReg #(         //topfile
    parameter       DATA_WIDTH = 32
) (
    input logic                     clk,               
    input logic                     rst,
    input logic [DATA_WIDTH-1:0]    PCsrc,  
    input logic [DATA_WIDTH-1:0]    ImmOp,
    output logic [DATA_WIDTH-1:0]   PC   
);
    logic [DATA_WIDTH-1:0]   next_PC,


ProgramCounter pc1(
    .clk(clk),
    .rst(rst),
    .PCsrc(PCsrc),
    .ImmOp(ImmOp),
    .PC(next_PC)
);

endmodule
