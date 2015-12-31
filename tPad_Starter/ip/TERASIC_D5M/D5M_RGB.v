module D5M_RGB(
	reset_n,
	
	// Bayer Input
	D5M_D,
	D5M_FVAL,
	D5M_LVAL,
	D5M_PIXLCLK,
	D5M_RESET_N,
	D5M_SCLK,
	D5M_SDATA,
	D5M_STROBE,
	D5M_TRIGGER,
	D5M_XCLKIN,
	
	// RGB Output
	RGB_R,
	RGB_G,
	RGB_B,
	RGB_X,
	RGB_Y,
	RGB_VALID,
	
	USER_CTRL
	
);


input		          		reset_n;

input		    [11:0]		D5M_D;
input		          		D5M_FVAL;
input		          		D5M_LVAL;
input		          		D5M_PIXLCLK;
output		          		D5M_RESET_N;
output		          		D5M_SCLK;
inout		          		D5M_SDATA;
input		          		D5M_STROBE;
output		          		D5M_TRIGGER;
output		          		D5M_XCLKIN;

output			[11:0]		RGB_R;
output			[11:0]		RGB_G;
output			[11:0]		RGB_B;
output			[11:0]		RGB_X;
output			[11:0]		RGB_Y;
output						RGB_VALID;

input						USER_CTRL;

////////////////////////////////////
wire		[11:0]		BAYER_X;
wire		[11:0]		BAYER_Y;
wire		[11:0]		BAYER_DATA;
wire					BAYER_VALID;

D5M_Bayer D5M_Bayer_inst(
	.reset_n(reset_n),
	
	.D5M_D(D5M_D),
	.D5M_FVAL(D5M_FVAL),
	.D5M_LVAL(D5M_LVAL),
	.D5M_PIXLCLK(D5M_PIXLCLK),
	
	.BAYER_X(BAYER_X),
	.BAYER_Y(BAYER_Y),
	.BAYER_DATA(BAYER_DATA),
	.BAYER_VALID(BAYER_VALID),
	.BAYER_WIDTH(),
	.BAYER_HEIGH()
);

Bayer2RGB Bayer2RGB_inst(
		.reset_n(reset_n),
		
		.BAYER_CLK(D5M_PIXLCLK),
		.BAYER_X(BAYER_X),
		.BAYER_Y(BAYER_Y),
		.BAYER_DATA(BAYER_DATA),
		.BAYER_VALID(BAYER_VALID),
		.BAYER_WIDTH(),
		.BAYER_HEIGH(),
		
		.RGB_R(RGB_R),
		.RGB_G(RGB_G),
		.RGB_B(RGB_B),
		.RGB_X(RGB_X),
		.RGB_Y(RGB_Y),
		.RGB_VALID(RGB_VALID),
		
		.USER_CTRL(USER_CTRL)
);


endmodule

