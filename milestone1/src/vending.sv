module vending(
	input logic clk,
	input logic rst_n,
	input logic nickel,
	input logic dime,
	input logic quarter,
	output logic soda,
	output logic [2:0] change
);

typedef enum logic [3:0] {
    ZERO = 4'b0000,
    FIVE = 4'b0001,
    TEN  = 4'b0010,
    FIFTEEN = 4'b0011,
    TWENTY = 4'b0100,
    TWENTY_FIVE = 4'b0101,
    THIRTY = 4'b0110,
    THIRTY_FIVE = 4'b0111,
    FORTY = 4'b1000
} state_t;

state_t current_state, next_state;

// state memory
always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        current_state <= ZERO; 
    end else begin
        current_state <= next_state;
    end
end

// next-state logic
always @(*) begin
    case (current_state)
        ZERO: begin
            if (nickel) begin
                next_state = FIVE;
            end else if (dime) begin
                next_state = TEN;
            end else if (quarter) begin
                next_state = TWENTY_FIVE;
            end else begin
                next_state = ZERO;
            end
        end
        FIVE: begin
            if (nickel) begin
                next_state = TEN;
            end else if (dime) begin
                next_state = FIFTEEN;
            end else if (quarter) begin
                next_state = THIRTY;
            end else begin
                next_state = FIVE;
            end
        end
        TEN: begin
            if (nickel) begin
                next_state = FIFTEEN;
            end else if (dime) begin
                next_state = TWENTY;
            end else if (quarter) begin
                next_state = THIRTY_FIVE;
            end else begin
                next_state = TEN;
            end
        end
        FIFTEEN: begin
            if (nickel) begin
                next_state = TWENTY;
            end else if (dime) begin
                next_state = TWENTY_FIVE;
            end else if (quarter) begin
                next_state = FORTY;
            end else begin
                next_state = FIFTEEN;
            end
        end
        TWENTY: begin
            next_state = ZERO;
        end
        TWENTY_FIVE: begin
            next_state = ZERO;
        end
        THIRTY: begin
            next_state = ZERO;
        end
        THIRTY_FIVE: begin
            next_state = ZERO;
        end
        FORTY: begin
            next_state = ZERO;
        end
        default: begin
            next_state = ZERO;
        end
    endcase
end

// output logic
always @(*) begin
    case (current_state)
        FIVE: begin
            soda = 1'b0;
            change = 3'b000;
        end
        TEN: begin
            soda = 1'b0;
            change = 3'b000;
        end
        FIFTEEN: begin
            soda = 1'b0;
            change = 3'b000;
        end 
        TWENTY: begin
            soda = 1'b1;
            change = 3'b000;
        end
        TWENTY_FIVE: begin
            soda = 1'b1;
            change = 3'b001;
        end
        THIRTY: begin
            soda = 1'b1;
            change = 3'b010;
        end
        THIRTY_FIVE: begin
            soda = 1'b1;
            change = 3'b011;
        end
        FORTY: begin
            soda = 1'b1;
            change = 3'b100;
        end
        default: begin
            soda = 1'b0;
            change = 3'b000;
        end
    endcase
end

endmodule
