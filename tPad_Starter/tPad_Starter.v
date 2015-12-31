// --------------------------------------------------------------------
// Copyright (c) 2010 by Terasic Technologies Inc. 
// --------------------------------------------------------------------
//
// Permission:
//
//   Terasic grants permission to use and modify this code for use
//   in synthesis for all Terasic Development Boards and Altera Development 
//   Kits made by Terasic.  Other use of this code, including the selling 
//   ,duplication, or modification of any portion is strictly prohibited.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  Terasic provides no warranty regarding the use 
//   or functionality of this code.
//
// --------------------------------------------------------------------
//           
//                     Terasic Technologies Inc
//                     356 Fu-Shin E. Rd Sec. 1. JhuBei City,
//                     HsinChu County, Taiwan
//                     302
//
//                     web: http://www.terasic.com/
//                     email: support@terasic.com
//
// --------------------------------------------------------------------

// --------------------------------------------------------------------
//
// Major Functions:	DE2-115 tPad Starter
//
// --------------------------------------------------------------------
//
// Revision History :
// --------------------------------------------------------------------
//   Ver  :| Author            :| Mod. Date :| Changes Made:
//   V1.0 :| Richard           :| 08/22/10  :| Initial Revision
//   V1.1 :| Ya-qun Chang      :| 09/11/10  :| Flash added
// --------------------------------------------------------------------

module tPad_Starter(

	//////// CLOCK //////////
	CLOCK_50,
	CLOCK2_50,
	CLOCK3_50,

	//////// Sma //////////
	SMA_CLKIN,
	SMA_CLKOUT,

	//////// LED //////////
	LEDG,
	LEDR,

	//////// KEY //////////
	KEY,

	//////// EJTAG //////////
	EX_IO,

	//////// SW //////////
	SW,

	//////// SEG7 //////////
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,
	HEX6,
	HEX7,

	//////// LCD //////////
	LCD_BLON,
	LCD_DATA,
	LCD_EN,
	LCD_ON,
	LCD_RS,
	LCD_RW,

	//////// RS232 //////////
	UART_CTS,
	UART_RTS,
	UART_RXD,
	UART_TXD,

	//////// PS2 for Keyboard and Mouse //////////
	PS2_CLK,
	PS2_CLK2,
	PS2_DAT,
	PS2_DAT2,

	//////// SDCARD //////////
	SD_CLK,
	SD_CMD,
	SD_DAT,
	SD_WP_N,

	//////// VGA //////////
	VGA_B,
	VGA_BLANK_N,
	VGA_CLK,
	VGA_G,
	VGA_HS,
	VGA_R,
	VGA_SYNC_N,
	VGA_VS,

	//////// Audio //////////
	AUD_ADCDAT,
	AUD_ADCLRCK,
	AUD_BCLK,
	AUD_DACDAT,
	AUD_DACLRCK,
	AUD_XCK,

	//////// I2C for EEPROM //////////
	EEP_I2C_SCLK,
	EEP_I2C_SDAT,

	//////// I2C for Audio Tv-Decoder HSMC  //////////
	I2C_SCLK,
	I2C_SDAT,

	//////// Ethernet 0 //////////
	ENET0_GTX_CLK,
	ENET0_INT_N,
	ENET0_LINK100,
	ENET0_MDC,
	ENET0_MDIO,
	ENET0_RST_N,
	ENET0_RX_CLK,
	ENET0_RX_COL,
	ENET0_RX_CRS,
	ENET0_RX_DATA,
	ENET0_RX_DV,
	ENET0_RX_ER,
	ENET0_TX_CLK,
	ENET0_TX_DATA,
	ENET0_TX_EN,
	ENET0_TX_ER,
	ENETCLK_25,

	//////// Ethernet 1 //////////
	ENET1_GTX_CLK,
	ENET1_INT_N,
	ENET1_LINK100,
	ENET1_MDC,
	ENET1_MDIO,
	ENET1_RST_N,
	ENET1_RX_CLK,
	ENET1_RX_COL,
	ENET1_RX_CRS,
	ENET1_RX_DATA,
	ENET1_RX_DV,
	ENET1_RX_ER,
	ENET1_TX_CLK,
	ENET1_TX_DATA,
	ENET1_TX_EN,
	ENET1_TX_ER,

	//////// TV Decoder //////////
	TD_CLK27,
	TD_DATA,
	TD_HS,
	TD_RESET_N,
	TD_VS,

	//////// USB 2.0 OTG //////////
	OTG_ADDR,
	OTG_CS_N,
	OTG_DACK_N,
	OTG_DATA,
	OTG_DREQ,
	OTG_FSPEED,
	OTG_INT,
	OTG_LSPEED,
	OTG_RD_N,
	OTG_RST_N,
	OTG_WE_N,

	//////// IR Receiver //////////
	IRDA_RXD,

	//////// SDRAM //////////
	DRAM_ADDR,
	DRAM_BA,
	DRAM_CAS_N,
	DRAM_CKE,
	DRAM_CLK,
	DRAM_CS_N,
	DRAM_DQ,
	DRAM_DQM,
	DRAM_RAS_N,
	DRAM_WE_N,

	//////// SRAM //////////
	SRAM_ADDR,
	SRAM_CE_N,
	SRAM_DQ,
	SRAM_LB_N,
	SRAM_OE_N,
	SRAM_UB_N,
	SRAM_WE_N,

	//////// Flash //////////
	FL_ADDR,
	FL_CE_N,
	FL_DQ,
	FL_OE_N,
	FL_RST_N,
	FL_RY,
	FL_WE_N,
	FL_WP_N,
	
	//////// GPIO //////////
	LTM_ADC_PENIRQ_n,
	LTM_ADC_BUSY,
	LTM_ADC_DCLK,
	LTM_ADC_DIN,
	LTM_ADC_DOUT,
	LTM_B,
	LTM_DEN,
	LTM_G,
	LTM_GREST,
	LTM_HD,
	LTM_NCLK,
	LTM_R,
	LTM_SCEN,
	LTM_SDA,
	LTM_VD, 	

	//////////// HSMC, HSMC connect to tPAD - 8" LCD/Touch/Camera //////////
	D,
	FVAL,
	HC_ADC_BUSY,
	HC_ADC_CS_N,
	HC_ADC_DCLK,
	HC_ADC_DIN,
	HC_ADC_DOUT,
	HC_ADC_PENIRQ_N,
	HC_B,
	HC_DEN,
	HC_DIM,
	HC_G,
	HC_NCLK,
	HC_R,
	LVAL,
	PIXCLK,
	RESET_N,
	SCLK,
	SDATA,
	STROBE,
	TRIGGER,
	XCLKIN 
);

//=======================================================
//  PARAMETER declarations
//=======================================================


//=======================================================
//  PORT declarations
//=======================================================

//////////// CLOCK //////////
input		          		CLOCK_50;
input		          		CLOCK2_50;
input		          		CLOCK3_50;

//////////// Sma //////////
input		          		SMA_CLKIN;
output		          		SMA_CLKOUT;

//////////// LED //////////
output		     [8:0]		LEDG;
output		    [17:0]		LEDR;

//////////// KEY //////////
input		     [3:0]		KEY;

//////////// EJTAG //////////
inout		     [6:0]		EX_IO;

//////////// SW //////////
input		    [17:0]		SW;

//////////// SEG7 //////////
output		     [6:0]		HEX0;
output		     [6:0]		HEX1;
output		     [6:0]		HEX2;
output		     [6:0]		HEX3;
output		     [6:0]		HEX4;
output		     [6:0]		HEX5;
output		     [6:0]		HEX6;
output		     [6:0]		HEX7;

//////////// LCD //////////
output		          		LCD_BLON;
inout		     [7:0]		LCD_DATA;
output		          		LCD_EN;
output		          		LCD_ON;
output		          		LCD_RS;
output		          		LCD_RW;

//////////// RS232 //////////
output		          		UART_CTS;
input		          		UART_RTS;
input		          		UART_RXD;
output		          		UART_TXD;

//////////// PS2 for Keyboard and Mouse //////////
inout		          		PS2_CLK;
inout		          		PS2_CLK2;
inout		          		PS2_DAT;
inout		          		PS2_DAT2;

//////////// SDCARD //////////
output		          		SD_CLK;
inout		          		SD_CMD;
inout		     [3:0]		SD_DAT;
input		          		SD_WP_N;

//////////// VGA //////////
output		     [7:0]		VGA_B;
output		          		VGA_BLANK_N;
output		          		VGA_CLK;
output		     [7:0]		VGA_G;
output		          		VGA_HS;
output		     [7:0]		VGA_R;
output		          		VGA_SYNC_N;
output		          		VGA_VS;

//////////// Audio //////////
input		          		AUD_ADCDAT;
inout		          		AUD_ADCLRCK;
inout		          		AUD_BCLK;
output		          		AUD_DACDAT;
inout		          		AUD_DACLRCK;
output		          		AUD_XCK;

//////////// I2C for EEPROM //////////
output		          		EEP_I2C_SCLK;
inout		          		EEP_I2C_SDAT;

//////////// I2C for Audio Tv-Decoder HSMC  //////////
output		          		I2C_SCLK;
inout		          		I2C_SDAT;

//////////// Ethernet 0 //////////
output		          		ENET0_GTX_CLK;
input		          		ENET0_INT_N;
input		          		ENET0_LINK100;
output		          		ENET0_MDC;
inout		          		ENET0_MDIO;
output		          		ENET0_RST_N;
input		          		ENET0_RX_CLK;
input		          		ENET0_RX_COL;
input		          		ENET0_RX_CRS;
input		     [3:0]		ENET0_RX_DATA;
input		          		ENET0_RX_DV;
input		          		ENET0_RX_ER;
input		          		ENET0_TX_CLK;
output		     [3:0]		ENET0_TX_DATA;
output		          		ENET0_TX_EN;
output		          		ENET0_TX_ER;
input		          		ENETCLK_25;

//////////// Ethernet 1 //////////
output		          		ENET1_GTX_CLK;
input		          		ENET1_INT_N;
input		          		ENET1_LINK100;
output		          		ENET1_MDC;
inout		          		ENET1_MDIO;
output		          		ENET1_RST_N;
input		          		ENET1_RX_CLK;
input		          		ENET1_RX_COL;
input		          		ENET1_RX_CRS;
input		     [3:0]		ENET1_RX_DATA;
input		          		ENET1_RX_DV;
input		          		ENET1_RX_ER;
input		          		ENET1_TX_CLK;
output		     [3:0]		ENET1_TX_DATA;
output		          		ENET1_TX_EN;
output		          		ENET1_TX_ER;

//////////// TV Decoder //////////
input		          		TD_CLK27;
input		     [7:0]		TD_DATA;
input		          		TD_HS;
output		          		TD_RESET_N;
input		          		TD_VS;

//////////// USB 2.0 OTG //////////
output		     [1:0]		OTG_ADDR;
output		          		OTG_CS_N;
output		     [1:0]		OTG_DACK_N;
inout		    [15:0]		OTG_DATA;
input		     [1:0]		OTG_DREQ;
inout		          		OTG_FSPEED;
input		     [1:0]		OTG_INT;
inout		          		OTG_LSPEED;
output		          		OTG_RD_N;
output		          		OTG_RST_N;
output		          		OTG_WE_N;

//////////// IR Receiver //////////
input		          		IRDA_RXD;

//////////// SDRAM //////////
output		    [12:0]		DRAM_ADDR;
output		     [1:0]		DRAM_BA;
output		          		DRAM_CAS_N;
output		          		DRAM_CKE;
output		          		DRAM_CLK;
output		          		DRAM_CS_N;
inout		    [31:0]		DRAM_DQ;
output		     [3:0]		DRAM_DQM;
output		          		DRAM_RAS_N;
output		          		DRAM_WE_N;

//////////// SRAM //////////
output		    [19:0]		SRAM_ADDR;
output		          		SRAM_CE_N;
inout		    [15:0]		SRAM_DQ;
output		          		SRAM_LB_N;
output		          		SRAM_OE_N;
output		          		SRAM_UB_N;
output		          		SRAM_WE_N;

//////////// Flash //////////
output		    [22:0]		FL_ADDR;
output		          		FL_CE_N;
inout		     [7:0]		FL_DQ;
output		          		FL_OE_N;
output		          		FL_RST_N;
input		          		FL_RY;
output		          		FL_WE_N;
output		          		FL_WP_N;

//////////// GPIO //////////
input		          		LTM_ADC_PENIRQ_n;
input		          		LTM_ADC_BUSY;
output		          		LTM_ADC_DCLK;
output		          		LTM_ADC_DIN;
input		          		LTM_ADC_DOUT;
output		     [7:0]		LTM_B;
output		          		LTM_DEN;
output		     [7:0]		LTM_G;
output		          		LTM_GREST;
output		          		LTM_HD;
output		          		LTM_NCLK;
output		     [7:0]		LTM_R;
output		          		LTM_SCEN;
inout		          		LTM_SDA;
output		          		LTM_VD;

//////////// HSMC, HSMC connect to tPAD - 8" LCD/Touch/Camera //////////
input		    [11:0]		D;
input		          		FVAL;
input		          		HC_ADC_BUSY;
output		          		HC_ADC_CS_N;
output		          		HC_ADC_DCLK;
output		          		HC_ADC_DIN;
input		          		HC_ADC_DOUT;
input		          		HC_ADC_PENIRQ_N;
output		     [5:0]		HC_B;
output		          		HC_DEN;
output		          		HC_DIM;
output		     [5:0]		HC_G;
output		          		HC_NCLK;
output		     [5:0]		HC_R;
input		          		LVAL;
input		          		PIXCLK;
output		          		RESET_N;
output		          		SCLK;
inout		          		SDATA;
input		          		STROBE;
output		          		TRIGGER;
output		          		XCLKIN;



//=======================================================
//  REG/WIRE declarations
//=======================================================




//=======================================================
//  Structural coding
//=======================================================
wire locked_from_the_altpll;
wire reset_n;
assign reset_n = 1'b1;
assign FL_RST_N = 1'b1;
assign FL_WP_N = 1'b1;

wire [7:0] lcd_r;
wire [7:0] lcd_g;
wire [7:0] lcd_b;
wire [7:0] lcd_clk;


tPad_Starter_SOPC tPad_Starter_inst(
                   // 1) global signals:
                    .altpll_io(),
                    .altpll_pclk(),
                    .altpll_sdram(DRAM_CLK),
                    .altpll_sys(),
                    .clk_50(CLOCK_50),
                    .reset_n(reset_n),

                   // the_altpll
                    .locked_from_the_altpll(locked_from_the_altpll),
                    .phasedone_from_the_altpll(),
                    /////cfi flash
                    .tri_state_bridge_address            (FL_ADDR),
                    .tri_state_bridge_data              (FL_DQ),
                    .write_n_to_the_cfi_flash                 (FL_WE_N),
                    .read_n_to_the_cfi_flash                  (FL_OE_N),
                    .select_n_to_the_cfi_flash                (FL_CE_N),

                   ///////////////////////////////
                   // the_lcd
                    .LCD_E_from_the_lcd(LCD_EN),
                    .LCD_RS_from_the_lcd(LCD_RS),
                    .LCD_RW_from_the_lcd(LCD_RW),
                    .LCD_data_to_and_from_the_lcd(LCD_DATA),
                    

                   ///////////////////////////////
                      // the_sdram
                       .zs_addr_from_the_sdram(DRAM_ADDR),
                       .zs_ba_from_the_sdram(DRAM_BA),
                       .zs_cas_n_from_the_sdram(DRAM_CAS_N),
                       .zs_cke_from_the_sdram(DRAM_CKE),
                       .zs_cs_n_from_the_sdram(DRAM_CS_N),
                       .zs_dq_to_and_from_the_sdram(DRAM_DQ),
                       .zs_dqm_from_the_sdram(DRAM_DQM),
                       .zs_ras_n_from_the_sdram(DRAM_RAS_N),
                       .zs_we_n_from_the_sdram(DRAM_WE_N),
                       
`ifdef VGA_OUTPUT                       
                   ///////////////////////////////
                   // touch
                    .in_port_to_the_touch_panel_busy(LTM_ADC_BUSY),
                    .out_port_from_the_touch_panel_cs_n(),
                    .in_port_to_the_touch_panel_penirq_n(LTM_ADC_PENIRQ_n),

                   // the_touch_panel_spi
                    .MISO_to_the_touch_panel_spi(LTM_ADC_DOUT),
                    .MOSI_from_the_touch_panel_spi(LTM_ADC_DIN),
                    .SCLK_from_the_touch_panel_spi(LTM_ADC_DCLK),
                    .SS_n_from_the_touch_panel_spi(adc_cs_n),   
                    
                   ///////////////////////////////
                   // the_vga
                    .vga_b_from_the_vga(VGA_B),
                    .vga_clk_from_the_vga(VGA_CLK),
                    .vga_de_from_the_vga(),
                    .vga_g_from_the_vga(VGA_G),
                    .vga_hs_from_the_vga(VGA_HS),
                    .vga_r_from_the_vga(VGA_R),
                    .vga_vs_from_the_vga(VGA_VS),                    
`else
                   ///////////////////////////////
                   // touch
                    .in_port_to_the_touch_panel_busy(HC_ADC_BUSY),
                    .out_port_from_the_touch_panel_cs_n(),
                    .in_port_to_the_touch_panel_penirq_n(HC_ADC_PENIRQ_N),

                   // the_touch_panel_spi
                    .MISO_to_the_touch_panel_spi(HC_ADC_DOUT),
                    .MOSI_from_the_touch_panel_spi(HC_ADC_DIN),
                    .SCLK_from_the_touch_panel_spi(HC_ADC_DCLK),
                    .SS_n_from_the_touch_panel_spi(HC_ADC_CS_N),   
                    
                   ///////////////////////////////
                   // the_vga
                    .vga_b_from_the_vga(lcd_b),
                    .vga_clk_from_the_vga(lcd_clk),
                    .vga_de_from_the_vga(HC_DEN),
                    .vga_g_from_the_vga(lcd_g),
                    .vga_hs_from_the_vga(),
                    .vga_r_from_the_vga(lcd_r),
                    .vga_vs_from_the_vga(),   
`endif                    
                    
                   ///////////////////////////////
                   // ir
                    .ir_to_the_irm(IRDA_RXD),                    
                    
                   ///////////////////////////////
                   // sdcard
                    .out_port_from_the_sd_clk(SD_CLK),
                    .bidir_port_to_and_from_the_sd_cmd(SD_CMD),
                    .bidir_port_to_and_from_the_sd_dat(SD_DAT),
                    .in_port_to_the_sd_wp_n(SD_WP_N),                    


                    
//                    .DEN_from_the_vga(),
//                    .HD_from_the_vga(VGA_HS),
//                    .RGB_OUT_from_the_vga({VGA_R, VGA_G, VGA_B}),
//                    .VD_from_the_vga(VGA_VS)                    
                 );

///////////////////////////////////////////
// VGA Config
assign VGA_BLANK_N = 1'b1;
assign VGA_SYNC_N = 1'b0;

///////////////////////////////////////////
// LCD config
assign LCD_BLON = 0; // not supported
assign LCD_ON = 1'b1; // alwasy on

///////////////////////////////////////////
// LTM
wire adc_cs_n;                    
assign LTM_SCEN = ~adc_cs_n;

//assign HC_ADC_CS_N = 1'b0;
assign RESET_N = locked_from_the_altpll; //reset_n;
assign HC_DIM       = 1'b1;
assign HC_B = lcd_b[7:2];
assign HC_G = lcd_g[7:2];
assign HC_R = lcd_r[7:2];
assign HC_NCLK = lcd_clk;

endmodule
