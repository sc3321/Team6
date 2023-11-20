module ControlUnit #(
    input logic                     EQ,                 // 1 if equal, 0 if not equal
    input logic [6:0]               instr[6:0],         // 7bit opcode
    output logic                    RegWrite,
    output logic                    ALUctrl,
    output logic                    ALUsrc,
    output logic                    Immsrc,
    output logic                    PCsrc,
);
 
always_comb begin
    if (instr[6:0] == 7'h13){           // if we are doing addi 001 0011
        RegWrite = 1;                   // 1 because we write in register
        ALUctrl = 1;                    // do ALU
        ALUsrc = 1;                     // 1 to use ImmOp, 0 to use Reg2
        Immsrc = 1;                     // 1 if we're doing sign extend??
        PCscr = 0;                      // 0 if incrementing PC by 1, 1 if branching
    }
    else{                               // we are doing bne 110 0011
        RegWrite = 0;                   // we don't write on a register
        ALUctrl = 1;                    // not do ALU
        ALUsrc = 0;                     // 0 to use Reg2
        Immsrc = 0;                     // sign extend not needed
        if (EQ == 0)    PCscr = 1;       
        else            PCscr = 0;
    }

end
 
endmodule
