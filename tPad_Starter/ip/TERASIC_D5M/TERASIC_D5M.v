module TERASIC_D5M(
	clk,
	reset_n,
	
	// streaming source interface
	st_data,
	st_valid,
	st_sop,
	st_eop,
	st_ready,



	// export
	D5M_D,
	D5M_RESET_N,
	D5M_FVAL,
	D5M_LVAL,
	D5M_PIXLCLK,
	D5M_SCLK,
	D5M_SDATA,
	D5M_STROBE,
	D5M_TRIGGER,
	D5M_XCLKIN,
	
INFO_FRAME_COUNT,
INFO_FRAME_INVALID_COUNT,
INFO_FRAME_START,
INFO_FRAME_END,
INFO_FRAME_PIX_COUNT,
USER_CTRL
	
	
);

//parameter BITS_PER_SYMBOL = 8;
//parameter SYMBOLS_PER_BEAT = 3;

input	clk;
input 	reset_n;

`ifdef DUMMY_CAMERA
output	reg  [23:0]		st_data;
output	reg 			st_valid;
output	reg 			st_sop;
output	reg 			st_eop;
input					st_ready;
`else
output	  [23:0]	st_data;
output				st_valid;
output				st_sop;
output		 		st_eop;
input				st_ready;
`endif


input		      [11:0]		D5M_D;
output		          			D5M_RESET_N;
input		            		D5M_FVAL;
input		            		D5M_LVAL;
input		            		D5M_PIXLCLK;
output		          			D5M_SCLK;
inout		            		D5M_SDATA;
input		            		D5M_STROBE;
output		          			D5M_TRIGGER;
output		          			D5M_XCLKIN;

input							USER_CTRL;

//wire		    [9:0]  		mccd_data;
//wire			        	mccd_dval;
//wire            [10:0]  	x_cont;
//wire	        [10:0]	    y_cont;
//
//wire	         [9:0]	  	sccd_r, sccd_g, sccd_b;
//wire		              	sccd_dval;
//wire            [10:0]  	rgb_x;
//wire            [10:0]  	rgb_y;



////////////////////////////////////////////
// latched iput data
//reg		      [11:0]		my_D5M_D;
//reg		            		my_D5M_FVAL;
//reg		            		my_D5M_LVAL;
//
//always @ (posedge D5M_PIXLCLK)
//begin
//	my_D5M_D <= D5M_D;
//	my_D5M_FVAL <= D5M_FVAL;
//	my_D5M_LVAL <= D5M_LVAL;
//end

wire [11:0] RGB_R,RGB_G, RGB_B;
wire [11:0] RGB_X,RGB_Y;
wire		RGB_VALID;

D5M_RGB D5M_RGB_inst( 
	.reset_n(reset_n),
	
	// Bayer Input
	.D5M_D(D5M_D),
	.D5M_FVAL(D5M_FVAL),
	.D5M_LVAL(D5M_LVAL),
	.D5M_PIXLCLK(D5M_PIXLCLK),
	.D5M_RESET_N(),
	.D5M_SCLK(),
	.D5M_SDATA(),
	.D5M_STROBE(),
	.D5M_TRIGGER(),
	.D5M_XCLKIN(),
	
	// RGB Output
	.RGB_R(RGB_R),
	.RGB_G(RGB_G),
	.RGB_B(RGB_B),
	.RGB_X(RGB_X),
	.RGB_Y(RGB_Y),
	.RGB_VALID(RGB_VALID),
	
	.USER_CTRL(USER_CTRL)
	
);		
		
`define	VIDEO_W 800
`define VIDEO_H 600
`define VIDEO_PIX_NUM	(`VIDEO_W * `VIDEO_H)
							

//`define DUMMY_CAMERA	
						

`ifndef DUMMY_CAMERA	

/////////////////////////////
// write rgb to fifo

//output reg	push_fail;

reg [25:0]	 fifo_w_data;  // 1-bit sop + 1-bit eop + 24-bits data
wire fifo_w_full;
wire sop;
wire eop;
wire in_active_area;

assign sop = (RGB_X == 0 && RGB_Y == 0)?1'b1:1'b0;
assign eop = (((RGB_X+1) == `VIDEO_W) && ((RGB_Y+1) == `VIDEO_H))?1'b1:1'b0;

assign in_active_area = ((RGB_X < `VIDEO_W) && (RGB_Y < `VIDEO_H))?1'b1:1'b0;

reg fifo_w_write;
always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
	begin
		fifo_w_write <= 1'b0;
		//push_fail <= 1'b0;
	end
	else if (RGB_VALID & in_active_area)
	begin
		if (!fifo_w_full)
		begin
			fifo_w_data <= {sop,eop, RGB_B[11:4], RGB_G[11:4], RGB_R[11:4]};
			fifo_w_write <= 1'b1;
		end
		else
		begin
			fifo_w_write <= 1'b0;
		//	push_fail <= 1'b1; // fifo full !!!!!
		end
	end
	else
		fifo_w_write <= 1'b0;
end

// debug
//output reg my_sop;
//output reg my_eop;
//output reg [21:0] my_cnt;
//
//always @ (posedge D5M_PIXLCLK or negedge reset_n)
//begin
//	if (~reset_n)
//	begin
//		my_cnt <= 0;
//	end
//	else if (RGB_VALID & in_active_area)
//	begin
//		my_sop <= sop;
//		my_eop <= eop;
//		if (eop)
//			my_cnt <= 0;
//		else
//			my_cnt <= my_cnt + 1;
//	end
//end


/////////////////////////////
// read from fifo
wire 		fifo_r_empty;
wire [25:0] fifo_r_q;		
wire 		fifo_r_rdreq_ack;


assign st_valid = ~fifo_r_empty;
assign fifo_r_rdreq_ack = st_valid & st_ready;
assign {st_sop, st_eop, st_data} = fifo_r_q;

// fifo_r_rdreq_ack
//always @ (posedge clk or negedge reset_n)
//begin
//	if (~reset_n)
//		fifo_r_rdreq_ack <= 1'b0;
//	else
//		fifo_r_rdreq_ack <= st_ready;
//end

// st_valid
//always @ (posedge clk or negedge reset_n)
//begin
//	if (~reset_n)
//		st_valid <= 1'b0;
//	else if (st_valid & st_ready & ~fifo_r_empty)
//		st_valid <= 1'b1;
//	else if (!st_valid & ~fifo_r_empty)
//		st_valid <= 1'b1;
//	else if (st_valid & !st_ready)
//		st_valid <= 1'b1; // keep
//	else
//		st_valid <= 1'b0;
//end

// st_data
//always @ (posedge clk or negedge reset_n)
//begin
//	if (~reset_n)
//	begin
//		{st_sop, st_eop, st_data} <= 26'h0000000;
//		fifo_r_rdreq_ack <= 1'b0;
//		st_valid <= 1'b0;
//	end
//	else if ((!st_valid | st_ready) & ~fifo_r_empty)
//	begin
//		{st_sop, st_eop, st_data} <= fifo_r_q;
//		fifo_r_rdreq_ack <= 1'b1;
//		st_valid <= 1'b1;
//	end
//	else if (st_valid & !st_ready)
//	begin
//		st_valid <= 1'b1; // keep
//		fifo_r_rdreq_ack <= 1'b0;
//	end
//	else
//	begin
//		st_valid <= 1'b0;
//		fifo_r_rdreq_ack <= 1'b0;
//	end
//end


//
//
//always @ (posedge clk or negedge reset_n)
//begin
//	if (~reset_n)
//		{st_sop, st_eop, st_data} <= 26'h0000000;
//	else if (fifo_r_empty)
//	begin
//		st_valid <= 1'b0;
//		{st_sop, st_eop, st_data} <= 26'h0000000;
//	end
//	else
//	begin
//		st_valid <= 1'b1;
//		{st_sop, st_eop, st_data} <= fifo_r_q;
//	end
//end

//always @ (posedge clk or negedge reset_n)
//begin
//	if (~reset_n)
//		{st_sop, st_eop, st_data} <= 26'h0000000;
//	else if (fifo_r_empty)
//	begin
//		// fifo empty
//		if (st_valid & st_ready)
//		begin
//			st_valid <= 1'b0;
//			{st_sop, st_eop, st_data} <= 26'h0000000;
//		end
//		fifo_r_rdreq_ack <= 1'b0;
//	end
//	else
//	begin  
//		// fifo not empty
//		if (!st_valid | st_ready)
//		begin
//			st_valid <= 1'b1;
//			{st_sop, st_eop, st_data} <= fifo_r_q;
//			fifo_r_rdreq_ack <= 1'b1;
//		end
//		else if (st_valid & !st_ready)
//		begin
//			// keep data
//			fifo_r_rdreq_ack <= 1'b0;
//		end
//	end
//end

// output pixel count in a frame
output reg [21:0] INFO_FRAME_PIX_COUNT;
reg		find_eop;
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
	begin
		INFO_FRAME_PIX_COUNT <= 0;
		find_eop <= 1'b0;
	end
	else if (st_ready & st_valid)
	begin
		if (st_sop)
		begin
			INFO_FRAME_PIX_COUNT <= 1;
			find_eop <= 1'b0;
		end 
		else if (st_eop)
		begin
			if (~find_eop)
				INFO_FRAME_PIX_COUNT <= INFO_FRAME_PIX_COUNT + 1;
			find_eop <= 1'b1;
		end
		else if (~find_eop)
			INFO_FRAME_PIX_COUNT <= INFO_FRAME_PIX_COUNT + 1;
	end
end

// output frame count
output reg [21:0] INFO_FRAME_COUNT;
reg		find_sop;
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
	begin
		INFO_FRAME_COUNT <= 0;
		find_sop <= 1'b0;
	end
	else if (st_ready & st_valid)
	begin
		if (st_sop)
			find_sop <= 1'b1;
		else if (st_eop & find_sop)
		begin
			find_sop <= 1'b0;
			INFO_FRAME_COUNT <= INFO_FRAME_COUNT + 1;
		end
	end
end

// invalid frame count
output reg [21:0] INFO_FRAME_INVALID_COUNT;
reg		find_sop_2;
reg		[19:0] pix_cnt;
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
	begin
		INFO_FRAME_INVALID_COUNT <= 0;
		find_sop_2 <= 1'b0;
		pix_cnt <= 0;
	end
	else if (st_ready & st_valid)
	begin
		if (st_sop)
		begin
			find_sop_2 <= 1'b1;
			pix_cnt <= 1;
		end
		else
		begin
			pix_cnt <= pix_cnt + 1;
			if (st_eop)
			begin
				find_sop_2 <= 1'b0;
				if (((pix_cnt+1) != `VIDEO_PIX_NUM) || !find_sop_2)
					INFO_FRAME_INVALID_COUNT <= INFO_FRAME_INVALID_COUNT + 1;
			end
		end
	end
end

// start of frame
output reg INFO_FRAME_START;
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
		INFO_FRAME_START <= 1'b0;
	else
		INFO_FRAME_START <= st_sop & st_valid & st_ready;
end

// end of frame
output reg INFO_FRAME_END;
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
		INFO_FRAME_END <= 1'b0;
	else
		INFO_FRAME_END <= st_eop & st_valid & st_ready;
end



/////////////////////////////
// FIFO
rgb_fifo rgb_fifo_inst(
	// write
	.data(fifo_w_data),
	.wrclk(D5M_PIXLCLK),
	.wrreq(fifo_w_write),
	.wrfull(fifo_w_full),
	
	// read
	.rdclk(clk),
	.rdreq(fifo_r_rdreq_ack),
	.q(fifo_r_q),
	.rdempty(fifo_r_empty),
	//
	.aclr(~reset_n)
	
	);	

// debug info

//reg my_error;
//output reg [11:0] pix_cnt;
//
//always @ (posedge clk or negedge reset_n)
//begin
//	if (~reset_n)
//	begin
//		pix_cnt <= 0;
//		my_error <= 0;
//	end
//	else if (st_valid && st_ready)
//	begin
//		if (st_sop)
//			begin
//			pix_cnt <= 1;
//			if (pix_cnt != (`VIDEO_PIX_NUM))
//				my_error <= 1'b1;
//			end
//		else if (st_eop)
//			pix_cnt <= 0;
//		else 
//			pix_cnt <= pix_cnt + 1;
//	end
//end


`else /////////////////////////////////////////// else /////////////////////////////
/////////////////////////////
// output pattern
/////////////////////////////



reg [9:0]	gray;
reg [19:0]  pix_cnt;

// counter
always @ (posedge clk or negedge reset_n)
begin	
	if (~reset_n)
		pix_cnt <= 0;
	else if (st_ready && st_valid)
	begin
		if ((pix_cnt+1) < `VIDEO_PIX_NUM) 
			pix_cnt <= pix_cnt + 1;
		else
			pix_cnt <= 0;
	end
end

always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
		st_sop <= 1'b0;
	else if (pix_cnt == 0)
		st_sop <= 1'b1;
	else
		st_sop <= 1'b0;
end

always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
		st_eop <= 1'b0;
	else if ((pix_cnt+1) == `VIDEO_PIX_NUM)
		st_eop <= 1'b1;
	else
		st_eop <= 1'b0;
end


// rgb data
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
		gray <= 0; 
	else if (st_ready && st_valid)
	begin
		if ((gray+1) < `VIDEO_W)
			gray <= gray + 1;
		else
			gray <= 0;
	end
end



always @ (posedge clk)
begin
	st_data <= {8'b0, gray, 8'b0};
end

//
always @ (posedge clk or negedge reset_n)
begin
	if (~reset_n)
		st_valid <= 1'b0;
	else
		st_valid <= 1'b1;//(st_valid && st_ready)?1'b0:1'b1;
end

`endif

endmodule
