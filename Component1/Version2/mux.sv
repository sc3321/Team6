module mux #(
    parameter       DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]        channel0,
    input logic [DATA_WIDTH-1:0]        channel1,
    input logic                         select,

    output logic [DATA_WIDTH-1:0]        result
);

assign result = select ? channel1 : channel0;

endmodule
