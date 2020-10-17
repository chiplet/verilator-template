`default_nettype none

// simple 8-bit counter
module MODULENAME(i_reset, i_clk, o_count);
    input   wire        i_reset;
    input   wire        i_clk;
    output  reg [7:0]   o_count;

    always @ (posedge i_clk or posedge i_reset) begin
        if (i_reset) begin
            o_count <= 8'b0;
        end else begin
            o_count <= o_count + 1;
        end
    end
endmodule
