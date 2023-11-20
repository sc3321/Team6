module alu #(
    parameter           DATA_WIDTH = 12
) (
    input logic                     ALUctrl,        // what is this used for?
    input logic [DATA_WIDTH-1:0]    ALUop1,         // 1st data to add
    input logic [DATA_WIDTH-1:0]    ALUop2,         // 2nd data to add

    output logic                    EQ,             // 1 if both input are the same
    output logic [DATA_WIDTH-1:0]   ALUout          // result of operation
);

always_comb begin
    assign ALUout = ALUop1 + ALUop2;
    if( (ALUop1 - ALUop2) == 'b0 ) EQ = 'b1;
end

endmodule
