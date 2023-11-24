module ProgramCounter #(            //works as an adder
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         rst,         
    input logic                         PCsrc, 
    input logic [DATA_WIDTH-1:0]        ImmOp, 
    output logic [DATA_WIDTH-1:0]        PC  
);

logic   [DATA_WIDTH-1:0]    branch_PC;
logic   [DATA_WIDTH-1:0]    inc_PC;
logic   [DATA_WIDTH-1:0]    next_PC;

always_comb begin
    branch_PC = PC + ImmOp;
    inc_PC = PC + 4;
end

PCReg myReg (
    .clk        (clk),        
    .rst        (rst),
    .next_PC    (next_PC),
    .PC         (PC)
);

mux MyChoose (
    .channel0       (inc_PC),
    .channel1       (branch_PC),
    .select         (PCsrc),
    .result         (next_PC)
);

endmodule
