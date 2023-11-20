module top #(
    parameter       ADD_WIDTH  = 5,
                    IMM_WIDTH  = 32,
                    DATA_WIDTH = 32
) (
    input logic                     clk,
    input logic [ADD_WIDTH-1:0]     rs1,
    input logic [ADD_WIDTH-1:0]     rs2,
    input logic [ADD_WIDTH-1:0]     rd,
    input logic                     RegWrite,
    input logic [IMM_WIDTH-1:0]     ImmOp,
    input logic                     ALUsrc,
    input logic                     ALUctrl,

    output logic [DATA_WIDTH-1:0]   a0,
    output logic                    EQ
);

logic [DATA_WIDTH-1:0]      regOp2;
logic [DATA_WIDTH-1:0]      ALUout;
logic [DATA_WIDTH-1:0]      ALUop1;
logic [DATA_WIDTH-1:0]      ALUop2;

regFile regFile(
    .clk        (clk),
    .AD1        (rs1),
    .AD2        (rs2),
    .AD3        (rd),
    .WD3        (ALUout),                // internal use
    .WE3        (RegWrite),
    .RD1        (ALUop1),                // internal use
    .RD2        (regOp2),                // internal use
    .a0         (a0)
);

mux2 mux(
    .select     (ALUsrc),
    .channel0   (regOp2),
    .channel1   (ImmOp),
    .muxRes     (ALUop2)
);

alu alu(
    .ALUctrl    (ALUctrl),
    .ALUop1     (ALUop1),
    .ALUop2     (ALUop2),
    .EQ         (EQ),
    .ALUout     (ALUout)
);

endmodule
