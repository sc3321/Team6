module ProgramCounter #(
    parameter DATA_WIDTH = 4
)(
    input logic                         clk,
    input logic                         rst,         
    input logic                         PCsrc, 
    input logic [DATA_WIDTH-1:0]        ImmOp, 
    output logic [DATA_WIDTH-1:0]       PC    
);

reg [DATA_WIDTH-1:0] next_PC;

always_ff @(posedge clk, posedge rst, posedge PCsrc) begin     //asynchronous
    if (rst)            PC <= 4'b0;
    if (PCsrc)          PC <= PC + ImmOp
    else                PC <= PC + 4'b0100;  
end

endmodule
