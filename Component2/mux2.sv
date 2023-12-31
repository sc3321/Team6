module mux2 #(
    parameter       DATA_WIDTH = 32
) (
    input logic                     select,
    input logic [DATA_WIDTH-1:0]    channel0,
    input logic [DATA_WIDTH-1:0]    channel1,

    output logic [DATA_WIDTH-1:0]   muxRes
);

always_comb 
    assign muxRes = select ? channel1 : channel0;

endmodule
