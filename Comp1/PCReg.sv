module PCReg #(
    parameter       DATA_WIDTH = 4
) (
    input logic                     clk,               
    input logic                     rst,                
//    input logic [DATA_WIDTH-1:0]    next_PC,
    output logic [DATA_WIDTH-1:0]   PC   
);
    logic [DATA_WIDTH-1:0]   next_PC,


ProgramCounter pc1(
    .clk(clk)
    .rst(rst)
    .PCsrc(Pcsrc)
    .PC(next_PC)

);

endmodule