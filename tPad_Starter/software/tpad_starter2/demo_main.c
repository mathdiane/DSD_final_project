#include "terasic_includes.h"
#include "alt_touchscreen.h"
#include "alt_video_display.h"
#include "demo_touch.h"
#include "simple_graphics.h"
#include "skin1.h"
#include "terasic_draw.h"
#include "demo_touch.h"
#include "demo_pattern.h"


typedef enum{
    BTN_TOUCH = 0,
    BTN_PATTERN,
    BTN_NUM
}BUTTON_ID;



void demo_main( alt_video_display* display, alt_touchscreen* screen){
    alt_touchscreen_scaled_pen_data pen_data;
    int x, y, i, sel;
    bool bExit = FALSE;
    bool bLimited = FALSE;
    char szText[128];
    RECT rcButton[BTN_NUM];
    RECT rcLimited;
    const int nMenuRow = 1;
//    const int nMenuCol = (BTN_NUM+nMenuRow-1)/nMenuRow;
    const int nMenuCol = 2;
    const int nMenuWidth = ALT_VIDEO_DISPLAY_COLS/(nMenuCol*2+1);
    const int nMenuHeight = ALT_VIDEO_DISPLAY_ROWS/(nMenuRow*2*2+1);///
    
    char szMenu[][32] = {
            "Easy",
            "Hard"
    };
    
    // cal button boundary
    i = 0;
    for(y=0;y<nMenuRow;y++){
        for(x=0;x<nMenuCol;x++){
            AssignRect(&rcButton[i++], 
                (x*2+1)*nMenuWidth, //left
                (y*2+2)*nMenuHeight, // top///
                (x*2+2)*nMenuWidth, // right
                (y*2+3)*nMenuHeight // bottom///
                );
        }
    }
    AssignRect(&rcLimited, 310,400,490,465);
    printf("===== Welcome to tPAD demo program =====\n");
    usleep(20*1000);
    

    // loop 
    //Touch_EmptyFifo(hTouch);
     while(!bExit){
        // clear background
        alt_video_display_clear_screen( display, 0x0 );
        
        // draw menu
        for(i=0;i<BTN_NUM;i++){
            //vid_print_string_alpha(rcButton[i].left, rcButton[i].top, COLOR_WHITE, 0xFFFFFFFF, tahomabold_20, display, szMenu[i]);
            draw_button(display, &rcButton[i], szMenu[i]); 
        }            
        // show hint
        sprintf(szText,"Buzzer_Beater");
        vid_print_string_alpha(290, 150, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
        //Limited
        if( bLimited == TRUE)
            draw_button(display, &rcLimited, "Limited"); 
        else if(bLimited == FALSE)           
            draw_button(display, &rcLimited, "Unlimited"); 

        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);        
        
        // wait user input
        sel = -1;
        while(sel == -1){
//            while (!Touch_GetXY(hTouch, &x,&y)){
//            }
            alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
            if (pen_data.pen_down==0) continue;
            for(i=0;i<BTN_NUM && sel==-1;i++){
                if (PtInRect(&rcButton[i], pen_data.x, pen_data.y))
                    sel = i;
            }
            if(PtInRect(&rcLimited,pen_data.x, pen_data.y)){
                if( bLimited == TRUE)
                    bLimited = FALSE; 
                else if(bLimited == FALSE)           
                    bLimited = TRUE;
                break;
            }          
        }
        
        // clear background
        //alt_video_display_clear_screen( display, 0x0 );        
        //alt_video_display_register_written_buffer( display );
        //while(alt_video_display_buffer_is_available(display) != 0);
       // Touch_EmptyFifo(hTouch);        
        
        switch(sel){
            case BTN_TOUCH:
                demo_touch(display, screen, bLimited);
                break;                
            case BTN_PATTERN:
                demo_touch_hard(display, screen, bLimited);
                break;
            default:
                break;                
        }
    }

    
    //Touch_EmptyFifo(hTouch);
    printf("Exit\r\n");
}

