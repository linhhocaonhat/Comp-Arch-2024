module top
(
	input logic i_clk,
	input logic i_rst,
	input logic i_nickel,
	input logic i_dime,
	input logic i_quarter,
    output logic o_soda,
    output logic [2:0] o_change
);
// wire soda;
// wire [2:0] change;

vending vending(
    .clk (i_clk),
    .rst_n (i_rst),
    .nickel(i_nickel),
    .dime(i_dime),
    .quarter(i_quarter),
    .soda(o_soda),
    .change(o_change)
);

endmodule : top
