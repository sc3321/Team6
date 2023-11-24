module combine#(
        parameter WIDTH =16
)(
        input logic     clk,
        input logic     rst,
        output logic    [31:0]a0 
        
);
        logic   [31:0]PC;
        logic   [31:0]instr;
        logic   ImmSrc;
        logic   RegWrite;
        logic   ALUctrl;
        logic   ALUsrc;
        logic   PCsrc;
        logic   EQ;
        logic   [31:0]ImmOp;
rom      rom1(
        .inscode(instr),
        .pc(PC)///// this rom pc bits is 4 bits and might contradict the junwon 32 bit pc.
);
PCReg           PCRegJW(////////jungwon i think there might me some error in the code? im not sure how it outputs.
        .rst(rst)
        .clk(clk)
        .PC(PC) 
        .ImmOp(ImmOp)
        .PCsrc(PCsrc)
);
controlUnit    controlUnit1(
        .instr(instr)
        .Immsrc(ImmSrc),
        .RegWrite(RegWrite),
        .ALUctrl(ALUctrl),
        .ALUsrc(ALUsrc),
        .PCsrc(PCsrc),
        .EQ(EQ)


);
sgnext          sgnext1(
        .ins(instr),
        .immSrc(ImmSrc),
        .immOp(ImmOp)
)

top     topPut(////////put
        .rs1([24:20]instr),
        .rs2([19:15]instr),
        .rd3([11:7]instr),
        .clk(clk),
        .RegWrite(RegWrite),
        .a0(a0),
        .ALUsrc(ALUsrc),
        .ALUctrl(ALUctrl),
        .ImmOp(ImmOp),
        .EQ(EQ)

);


