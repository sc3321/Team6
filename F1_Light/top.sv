module top (
    input logic             clk,
    input logic             rst,
    input logic             en,
    input logic             trigger,
    input logic  [15:0]     caliN,
    output logic [7:0]      out,
    output logic            cmd_delay,
    output logic            cmd_seq
);

logic tick;
logic FIRED;
logic [8:1] random;
logic light_en;

clktick myClk (
    .clk    (clk),
    .rst    (rst),
    .en     (cmd_seq),
    .N      (caliN),
    .tick   (tick) //output
);

lfsr myRandom (
    .clk         (clk),
    .en          (en),
    .rst         (rst),
    .data_out    (random)
);

delay myDelay (
    .clk        (clk),
    .rst        (rst),
    .trigger    (cmd_delay),
    .n          (random),
    .time_out   (FIRED)
);

mux myChoose (
    .channel0   (FIRED),
    .channel1   (tick),
    .select     (cmd_seq),
    .result     (light_en)
);

f1_fsm fsm (
    .clk            (clk),
    .rst            (rst),
    .en             (light_en),
    .trigger        (trigger),
    .cmd_seq        (cmd_seq),
    .cmd_delay      (cmd_delay),
    .out            (out)
);


endmodule
