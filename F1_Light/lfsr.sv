module lfsr (
    input logic         clk,
    input logic         en,
    input logic         rst,
    output logic [8:1]  data_out
);

logic [8:1] sreg;

always_ff @ (posedge clk)
    if(rst)
        sreg <= 8'b1;
    else if(en) begin
        sreg[7] <= sreg[6];
        sreg[6] <= sreg[5];
        sreg[5] <= sreg[4];
        sreg[4] <= sreg[3];
        sreg[3] <= sreg[2];
        sreg[2] <= sreg[1];
        sreg[1] <= sreg[7] ^ sreg[6]; // XOR?
    end
assign data_out = sreg;

endmodule
