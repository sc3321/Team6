module top #(
    parameter       DATA_WIDTH = 5
) (
    input logic                     clk,
    input logic [DATA_WIDTH-1:0]    rs1,
    input logic [DATA_WIDTH-1:0]    rs2,
    input logic [DATA_WIDTH-1:0]    rd,
    input logic [DATA_WIDTH-1:0]    RegWrite,
    input logic [DATA_WIDTH-1:0]    ImmOp,
    input logic                     ALUsrc,
    input logic                     ALUctrl,

    output logic                    a0,
    output logic                    EQ
);

logic [DATA_WIDTH-1:5]      regOp2;
logic [DATA_WIDTH-1:5]      ALUout;
logic [DATA_WIDTH-1:5]      ALUop1;
logic [DATA_WIDTH-1:5]      ALUop2;

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
