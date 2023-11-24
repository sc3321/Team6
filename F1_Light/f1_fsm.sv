module f1_fsm (
    input   logic           clk,
    input   logic           rst,
    input   logic           en,
    input   logic           trigger,

    output  logic           cmd_seq,    // high during sequencing
    output  logic           cmd_delay,  // trigger start of delay.sv

    output  logic [7:0]     out
);

typedef enum {IDLE, S1, S2, S3, S4, S5, S6, S7, S8, SS2} my_state;
my_state current_state, next_state;

// state transition
always_ff @ (posedge clk, posedge trigger) begin
    if(rst)                 current_state <= IDLE;
    else if(en)             current_state <= next_state;
    else                    current_state <= current_state;
    
    // if all lights are on, then use delay timer.
    if(current_state == S8) begin
        cmd_seq <= 0;
        cmd_delay <= 1;
    end

    // OR if all lights are off, then check if trigger or not
    else if(current_state == IDLE) begin

        // if trigger, then check action of trigger.
        // trigger to start counting.
        // OR trigger to stop the delay module.
        if(trigger)
            if(cmd_delay) cmd_delay <= 0;
            else cmd_seq <= 1;
        
        // if all lights are off and no trigger then no counting
        else begin
            cmd_seq <= 0;
            cmd_delay <= 0;
        end 
    end

    // Otherwise continue counting normally.
    else begin
        cmd_seq <= 1;
        cmd_delay <= 0;
        // current_state <= S2;
    end 

// next state logic
always_comb
    case (current_state)
        IDLE:       next_state = S1;
        S1:         next_state = S2;
        S2:         next_state = S3;
        S3:         next_state = S4;
        S4:         next_state = S5;
        S5:         next_state = S6;
        S6:         next_state = S7;
        S7:         next_state = S8;
        S8:         next_state = IDLE;
        default:    next_state = IDLE;
    endcase

// state output logic
always_comb
    case (current_state)
        IDLE:       out = 'b00000000;
        S1:         out = 'b00000001;
        S2:         out = 'b00000011;
        S3:         out = 'b00000111;
        S4:         out = 'b00001111;
        S5:         out = 'b00011111;
        S6:         out = 'b00111111;
        S7:         out = 'b01111111;
        S8:         out = 'b11111111;
        SS2:        out = 'b01010101;
        default:    out = 'b00000000;
    endcase

endmodule
