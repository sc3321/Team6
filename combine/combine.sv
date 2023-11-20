module combine#(
        parameter WIDTH =16
)(
        input logic     clk,
        input logic     rst,
        output logic    [8:1]a0 
        
);
        logic   [4:1]PC;
        logic   [32:1]instr;
        logic   [check]ImmSrc;
        logic   [check]RegWrite;
        logic   [check]ALUctrl;
        logic   [check]ALUsrc;
        logic   [check]PCsrc;
        logic   EQ;
Instr_Mem(
        .RD(instr),
        .A(PC)
);
PC_Reg(////////jungwon
        .rst(rst)
        .clk(clk)
        .PC(PC) 
        .ImmOp(ImmOp)
        .PCsrc(PCsrc)
);
Control_Unit(
        .in(instr)// check name of port
        .ImmSrc(ImmSrc),
        .RegWrite(RegWrite),
        .ALUctrl(ALUctrl),
        .ALUsrc(ALUsrc),
        .PCsrc(PCsrc),
        .EQ(EQ)


);
Sign_extend(
        .in([31:20]),//////check name of port. this is 12 bits immediate.
        .ImmSrc(ImmSrc),
        .ImmOp(ImmOp)
)

Reg_File(////////put
        .AD1([24:20]instr),
        .AD2([19:15]instr),
        .AD3([11:7]instr),
        .clk(clk),
        .WE3(RegWrite),
        .a0(a0),
        .ALUsrc(ALUsrc),
        .ALUctrl(ALUctrl),
        .ImmOp(ImmOp),
        .EQ(EQ)

);


