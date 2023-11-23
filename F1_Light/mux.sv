module mux (
    input logic         channel0,
    input logic         channel1,    
    input logic         select,
    output logic        result
);

assign result = select ? channel1 : channel0;

endmodule
