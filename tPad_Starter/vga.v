// vga.v

// This file was auto-generated as part of a SOPC Builder generate operation.
// If you edit it your changes will probably be lost.

module vga (
		output wire        ready_out, // avalon_streaming_sink.ready
		input  wire        valid_in,  //                      .valid
		input  wire [23:0] data_in,   //                      .data
		input  wire        sop_in,    //                      .startofpacket
		input  wire        eop_in,    //                      .endofpacket
		input  wire        empty_in,  //                      .empty
		output wire        vga_clk,   //           conduit_end.export
		output wire        vga_de,    //                      .export
		output wire [7:0]  vga_r,     //                      .export
		output wire [7:0]  vga_g,     //                      .export
		output wire [7:0]  vga_b,     //                      .export
		output wire        vga_hs,    //                      .export
		output wire        vga_vs,    //                      .export
		input  wire        clk,       //            clock_sink.clk
		input  wire        reset_n    //      clock_sink_reset.reset_n
	);

	VGA_SINK #(
		.SYMBOLS_PER_BEAT (1),
		.BITS_PER_SYMBOL  (24),
		.READY_LATENCY    (0),
		.MAX_CHANNEL      (0),
		.H_DISP           (800),
		.H_FPORCH         (40),
		.H_SYNC           (128),
		.H_BPORCH         (88),
		.V_DISP           (600),
		.V_FPORCH         (1),
		.V_SYNC           (4),
		.V_BPORCH         (23)
	) vga (
		.ready_out (ready_out), // avalon_streaming_sink.ready
		.valid_in  (valid_in),  //                      .valid
		.data_in   (data_in),   //                      .data
		.sop_in    (sop_in),    //                      .startofpacket
		.eop_in    (eop_in),    //                      .endofpacket
		.empty_in  (empty_in),  //                      .empty
		.vga_clk   (vga_clk),   //           conduit_end.export
		.vga_de    (vga_de),    //                      .export
		.vga_r     (vga_r),     //                      .export
		.vga_g     (vga_g),     //                      .export
		.vga_b     (vga_b),     //                      .export
		.vga_hs    (vga_hs),    //                      .export
		.vga_vs    (vga_vs),    //                      .export
		.clk       (clk),       //            clock_sink.clk
		.reset_n   (reset_n)    //      clock_sink_reset.reset_n
	);

endmodule
