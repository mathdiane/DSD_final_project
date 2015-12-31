// --------------------------------------------------------------------
// Copyright (c) 2007 by Terasic Technologies Inc. 
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
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "alt_video_display.h"
#include "app_selector.h"
#include "my_ui.h"
#include "simple_graphics.h"
#include "fonts.h"
#include "sys/alt_alarm.h"
//#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"  // interrupt
#include <unistd.h>
#include "skin1.h"


#define PIO_KEYS_BASE   0



void draw_border(int color, alt_video_display* display){
    int x,y;
    alt_u8 *pDes = display->buffer_ptrs[display->buffer_being_written]->buffer;
    for(y=0;y<display->height;y++){
        for(x=0;x<display->width;x++){
            if (x<=1 || x >= display->width-2 || y <= 1 || y >= display->height-2){
                *pDes++ = color & 0xFF; // blue
                *pDes++ = (color >> 8) & 0xFF; // green
                *pDes++ = (color >> 16) & 0xFF; // red
                pDes++;                 // reserved
            }else{
                pDes += 4;
            }
        }
    }
    
}

void key_isr(void* context, alt_u32 id){
    int *pActiveFunc = (int *)context;
    alt_u8 KeyMask;
    
    // get the edge capture mask
   // KeyMask = IORD_ALTERA_AVALON_PIO_EDGE_CAP(PIO_KEYS_BASE) & 0x0F;  // 4-button
    
    // Reset the edge capture register
  //  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_KEYS_BASE,0);
    
    if (KeyMask & 0x08){
        *pActiveFunc = *pActiveFunc+1;
        if (*pActiveFunc >= 2)
            *pActiveFunc = 0;
    }            
    
}

int my_ui( alt_video_display* display){
    int i, time_start, time_elapsed, border_index=0, color;
    char szText[128];
    float fSecond;
    static int nActiveFunc=0;
    
    printf("===== Welcome to TERASIC tPAD demo program =====\n");
    usleep(200*1000);
    
    time_start = alt_nticks();
    
    // draw static information on all frame buffer (draw background)
    for(i=0;i<display->num_frame_buffers;i++){
        
        //===== draw canvas
        // clean canvas as black
        alt_video_display_clear_screen( display, 0x0 );
        
        // draw box
        //int vid_draw_box (int horiz_start, int vert_start, int horiz_end, int vert_end, int color, int fill, alt_video_display* display);
        vid_draw_box (10,10,80,80, COLOR_B, DO_FILL, display);  // fill
        vid_draw_box (100,10,170,80, COLOR_B, DO_NOT_FILL, display);  // not fill
        
        // draw circle
        //vid_draw_circle(int Hcenter, int Vcenter, int radius, int color, char fill, alt_video_display* display);
        vid_draw_circle(220, 45, 40, COLOR_G, DO_FILL, display); // fill
        vid_draw_circle(320, 45, 40, COLOR_G, DO_NOT_FILL, display); // not fill
        
        // draw line (x symble)
        //vid_draw_line(int horiz_start, int vert_start, int horiz_end, int vert_end, int width, int color, alt_video_display* display)
        vid_draw_line(370, 20, 430, 80, 5, COLOR_R, display);
        vid_draw_line(370, 80, 430, 20, 5, COLOR_R, display);
        
        // draw round rectangle
        //int vid_draw_round_corner_box ( int horiz_start, int vert_start, int horiz_end, int vert_end, int radius, int color, int fill, alt_video_display* display);
        vid_draw_round_corner_box ( 440, 10, 520, 80, 10, COLOR_WHITE, DO_FILL, display);
        vid_draw_round_corner_box ( 540, 10, 620, 80, 10, COLOR_WHITE, DO_NOT_FILL, display);
        
        // draw text
        strcpy(szText, "0123456789~!@#$%^&*()_-+={}[]|\\:"";'<>?,./");
        vid_print_string_alpha(10, 100, COLOR_R, COLOR_BLACK, tahomabold_20, display, szText);
        strcpy(szText, "0123456789~!@#$%^&*()_-+={}[]"); // |\\:"";'<>?,./");
        vid_print_string_alpha(10, 180, COLOR_R, COLOR_BLACK, tahomabold_32, display, szText);
        strcpy(szText, "abcdefghijklmnopqrstuvwxyz");        
        vid_print_string_alpha(10, 125, COLOR_G, COLOR_BLACK, tahomabold_20, display, szText);
        vid_print_string_alpha(10, 220, COLOR_G, COLOR_BLACK, tahomabold_32, display, szText);
        strcpy(szText, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");        
        vid_print_string_alpha(10, 150, COLOR_B, COLOR_BLACK, tahomabold_20, display, szText);
        vid_print_string_alpha(10, 260, COLOR_B, COLOR_BLACK, tahomabold_32, display, szText);
        

        //=====draw_border
        draw_border(COLOR_B, display);
        
        //===== update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);
        
     }  // for i
     
     // enable interrupt, 4-button
    // IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_KEYS_BASE, 0x0F); 
     // Reset the edge capture register
    // IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_KEYS_BASE,0); 
   //  alt_irq_register(PIO_KEYS_IRQ, &nActiveFunc, key_isr);
     while(1){   
        // See if there was a touch on the touchscreen.
        // polling touch panel status, and display it on lcd
        
        // clear button background
        vid_draw_box (10, 300, 630, 410, COLOR_BLACK, DO_FILL, display);  // fill
        //===== draw function 1
        // draw 3D button
        if (nActiveFunc==0){
            vid_draw_round_corner_box ( 20, 320, 300, 400, 5, COLOR_GRAY, DO_FILL, display);
            vid_draw_round_corner_box ( 20-6, 320-6, 300-6, 400-6, 5, COLOR_WHITE, DO_FILL, display);
            vid_draw_round_corner_box ( 20-6+5, 320-6+5, 300-6-5, 400-6-5, 5, COLOR_BLACK, DO_FILL, display);
        }
        strcpy(szText, "Music");
        vid_print_string_alpha(90, 330, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
        
        //===== draw function 2
        // draw 3D button
        if (nActiveFunc==1){
            vid_draw_round_corner_box ( 340, 320, 620, 400, 5, COLOR_GRAY, DO_FILL, display);
            vid_draw_round_corner_box ( 340-6, 320-6, 620-6, 400-6, 5, COLOR_WHITE, DO_FILL, display);
            vid_draw_round_corner_box ( 340-6+5, 320-6+5, 620-6-5, 400-6-5, 5, COLOR_BLACK, DO_FILL, display);
        }
        strcpy(szText, "Motion");
        vid_print_string_alpha(80+320, 330, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
       
       // show time
        time_elapsed = alt_nticks() - time_start;
        fSecond = (float)time_elapsed/(float)alt_ticks_per_second(); 
        sprintf(szText,"%.2f sec", fSecond);
        vid_print_string_alpha(50, display->height-45, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
        
        // draw border
        switch(border_index%4){
            case 0: color = COLOR_WHITE; break;
            case 1: color = COLOR_R; break;
            case 2: color = COLOR_G; break;
            case 3: color = COLOR_B; break;
        }
        border_index++;
        draw_border(color, display);

        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);
        
    }
}
