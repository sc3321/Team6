module regFile #(
    parameter       ADD_WIDTH = 5,
                    DATA_WIDTH = 32
)(
    input logic                     clk,

    input logic [ADD_WIDTH-1:0]    AD1,     //to extenal in top level | register 1
    input logic [ADD_WIDTH-1:0]    AD2,     //to extenal | register 2
    input logic [ADD_WIDTH-1:0]    AD3,     //to extenal | to store results
    input logic [DATA_WIDTH-1:0]    WD3,    //to extenal | write to register
    input logic                     WE3,    //to extenal | write enable

    output logic [DATA_WIDTH-1:0]   RD1,    //internal in top level
    output logic [DATA_WIDTH-1:0]   RD2,    //internal
    output logic [DATA_WIDTH-1:0]   a0      //internal | what is a0
);

// create 32 registers
// initialise all to zero
logic [DATA_WIDTH-1:0] register [2**ADD_WIDTH-1:0];

always_ff @ (posedge clk) begin
    if(AD1 != 'b00000) RD1 <= register[AD1];            //output register at RD1
    if(AD2 != 'b00000) RD2 <= register[AD2];            //output register at RD2
    if(AD3 != 'b00000 & WE3) register[AD3] <= WD3;      //store result from WE3
    a0 <= register[10];
end

endmodule
