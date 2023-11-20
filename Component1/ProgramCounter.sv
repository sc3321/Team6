module ProgramCounter #(            //works as an adder
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         rst,         
    input logic                         PCsrc, 
    input logic [DATA_WIDTH-1:0]        ImmOp, 
    output logic [DATA_WIDTH-1:0]       PC    
);


always_ff @(posedge clk, posedge rst, posedge PCsrc) begin     //asynchronous
    if (rst)            PC <= 32'b0;
    if (PCsrc)          PC <= PC + ImmOp
    else                PC <= PC + 4'b0100;  
end

endmodule
