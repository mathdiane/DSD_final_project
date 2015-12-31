module D5M_Bayer(
	reset_n,
	
	D5M_D,
	D5M_FVAL,
	D5M_LVAL,
	D5M_PIXLCLK,
	
	BAYER_X,
	BAYER_Y,
	BAYER_DATA,
	BAYER_VALID,
	BAYER_WIDTH,
	BAYER_HEIGH
);

input						reset_n;

input		    [11:0]		D5M_D;
input		          		D5M_FVAL;
input		          		D5M_LVAL;
input		          		D5M_PIXLCLK;

output	reg		[11:0]		BAYER_X;
output	reg		[11:0]		BAYER_Y;
output	reg		[11:0]		BAYER_DATA;
output	reg					BAYER_VALID;
output	reg		[11:0]		BAYER_WIDTH;
output	reg		[11:0]		BAYER_HEIGH;





reg pre_D5M_FVAL;
reg pre_D5M_LVAL;

always @ (negedge D5M_PIXLCLK)
begin
	pre_D5M_FVAL <= D5M_FVAL;
	pre_D5M_LVAL <= D5M_LVAL;
end

//////////////////////
// Y, heigh count
reg [11:0] y_cnt;
always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
		begin
		BAYER_HEIGH <= 0;
		y_cnt <= 0;
		end
	else if (pre_D5M_FVAL & ~D5M_FVAL)
	begin
		y_cnt <= 0;
		if (y_cnt > BAYER_HEIGH)
			BAYER_HEIGH <= y_cnt;		
	end		
	else if (pre_D5M_LVAL && ~D5M_LVAL)
		y_cnt <= y_cnt + 1;		

end

always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
		BAYER_Y <= 0;
	else
		BAYER_Y <= y_cnt;
end

//////////////////////
// X, width count
reg [11:0] x_cnt;
always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
	begin
		BAYER_WIDTH <= 0;
		x_cnt <= 0;
	end
	else if (pre_D5M_LVAL & ~D5M_LVAL)
	begin
		x_cnt <= 0;
		if (x_cnt > BAYER_WIDTH)
			BAYER_WIDTH <= x_cnt;		
	end
	else if (D5M_FVAL & D5M_LVAL)
		x_cnt <= x_cnt + 1;
end

always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
		BAYER_X <= 0;
	else
		BAYER_X <= x_cnt;
end

// data valid
always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
		BAYER_VALID <= 1'b0;
	else
		BAYER_VALID <= (D5M_FVAL & D5M_LVAL)?1'b1:1'b0;
	
end

// data 
always @ (posedge D5M_PIXLCLK or negedge reset_n)
begin
	if (~reset_n)
		BAYER_DATA <= 12'h000;
	else
		BAYER_DATA <= D5M_D;
	
end

endmodule
