#include "terasic_includes.h"
#include "alt_touchscreen.h"
#include "alt_video_display.h"
#include "demo_touch.h"
#include "simple_graphics.h"
#include "skin1.h"
#include "terasic_draw.h"

typedef enum{
    PATTERN_COLOR,
    PATTERN_RED,
    PATTERN_GREEN,
    PATTERN_BLUE,
    PATTERN_WHITE,
    PATTERN_BLACK,
    PATTERN_MATRIX,
    PATTERN_NUM
}PATTERN_ID;

void draw_color_pattern(alt_video_display* display, int pattern_type){
    int x,y;
    alt_u32 *pBase = (alt_u32 *)(display->buffer_ptrs[display->buffer_being_written]->buffer);
    alt_u32 *pDes, data32, bytes_per_line;
    bytes_per_line = display->width * display->bytes_per_pixel;
    pDes = pBase;
    for(y=0;y<display->height;y++){
       // pDes = pBase + y*bytes_per_line;// + x * display->bytes_per_pixel;
        for(x=0;x<display->width;x++){
            if (x==0 || y == 0 || x == display->width-1 || y == display->height-1){
                data32 = 0xFFFFFF; // white
            }else{
                if (pattern_type == PATTERN_COLOR){   
                    if (y < display->height/4)
                        data32 = x & 0xFF; // blue
                    else if (y < display->height/2)
                        data32 = (x & 0xFF) << 8; // green
                    else if (y < display->height*3/4)
                        data32 = (x & 0xFF) << 16;  // red
                    else
                        data32 = (x & 0xFF) | ((x & 0xFF) << 8) | ((x & 0xFF) << 16); // gray
                }else if (pattern_type == PATTERN_RED){
                    data32 = 0xFF0000;
                }else if (pattern_type == PATTERN_GREEN){
                    data32 = 0x00FF00;
                }else if (pattern_type == PATTERN_BLUE){
                    data32 = 0x0000FF;
                }else if (pattern_type == PATTERN_WHITE){
                    data32 = 0xFFFFFF;
                }else if (pattern_type == PATTERN_BLACK){
                    data32 = 0x00;
                }else if (pattern_type == PATTERN_MATRIX){
                    data32 = (x%8==0 || y%8==0)?0xFFFFFF:0;
//                    data32 = (x%2==0 || y%2==0)?0xFFFFFF:0;  cause touch panel fail???
                }                        
            }                        
            *pDes++ = data32;
        }
    }
}

/*

typedef enum{
    PAT_H_COLOR,
    PAT_V_COLOR,
    PAT_RED,
    PAT_GREEN,
    PAT_BLUE,
    PAT_BORDER,
    PAT_NUM
}PATTERN_ID;

void DrawPattern_HColor(alt_video_display* display){
    int x,y;
    alt_u32 *pBase = (alt_u32 *)(display->buffer_ptrs[display->buffer_being_written]->buffer);
    alt_u32 *pDes, data32, bytes_per_line;
    bytes_per_line = display->width * display->bytes_per_pixel;
    pDes = pBase;
    for(y=0;y<display->height;y++){
       // pDes = pBase + y*bytes_per_line;// + x * display->bytes_per_pixel;
        for(x=0;x<display->width;x++){
            if (x==0 || y == 0 || x == display->width-1 || y == display->height-1)
                data32 = 0xFFFFFF; // white
            else if (y < display->height/4)
                data32 = x & 0xFF; // blue
            else if (y < display->height/2)
                data32 = (x & 0xFF) << 8; // green
            else if (y < display->height*3/4)
                data32 = (x & 0xFF) << 16;  // red
            else
                data32 = (x & 0xFF) | ((x & 0xFF) << 8) | ((x & 0xFF) << 16); // gray
            *pDes++ = data32;
        }
    }    
}


void DrawPattern(alt_video_display* display, PATTERN_ID PatId){
    switch(PatId){
        case PAT_H_COLOR:
            DrawPattern_HColor(display);
            break;
        case PAT_RED:
            alt_video_display_clear_screen(display, COLOR_R);
            break;            
        case PAT_GREEN:
            alt_video_display_clear_screen(display, COLOR_G);
            break;            
        case PAT_BLUE:
            alt_video_display_clear_screen(display, COLOR_B);
            break;            
        case PAT_BORDER:
            break;            
    }
}
*/

void demo_pattern( alt_video_display* display, alt_touchscreen* screen){
    char szText[128];
    //int x=ALT_VIDEO_DISPLAY_COLS/2,y=ALT_VIDEO_DISPLAY_ROWS/2;
    alt_touchscreen_scaled_pen_data pen_data;
    bool bExit = FALSE;
    bool bClear = FALSE;
    RECT rcExit;
    PATTERN_ID PatId = PATTERN_COLOR;
    
    
    AssignRect(&rcExit, 30, display->height-70, 100, display->height-30);
    
    printf("===== Welcome to pattern demo program =====\n");
    usleep(20*1000);
    
    
    // loop 
    //Touch_EmptyFifo(hTouch);
     while(!bExit){
        if (!bClear){
            alt_video_display_clear_screen( display, 0x0 );
            bClear = TRUE;
        }
        
        // show pattern
        draw_color_pattern(display, PatId);
        

       // show menu 
        sprintf(szText,"Exit");
//        vid_print_string_alpha(rcExit.left+5, rcExit.top, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
        if (PatId == PATTERN_WHITE)
            vid_print_string_alpha(rcExit.left+5, rcExit.top, COLOR_BLACK, 0xFFFFFFFF, tahomabold_32, display, szText);
        else
            vid_print_string_alpha(rcExit.left+5, rcExit.top, COLOR_WHITE, 0xFFFFFFFF, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcExit.left, rcExit.top, rcExit.right, rcExit.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);

        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);
        
        
        usleep(200*1000);
        PatId++;
        PatId %= PATTERN_NUM;
        
        // wait user touch
        bClear = FALSE;
          while(1){
                   alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
                   if  (pen_data.pen_down==1) break;
                       if (!bClear){
                                    alt_video_display_clear_screen( display, 0x0 );
                                    bClear = TRUE;}
          }
                       
//        while (!Touch_GetXY(hTouch, &x,&y)){
//            if (!bClear){
//                alt_video_display_clear_screen( display, 0x0 );
//                bClear = TRUE;
//            }
//        }
        //Touch_EmptyFifo(hTouch);   Ben
            
        // is exit?
        if (PtInRect(&rcExit, pen_data.x, pen_data.y)){
            bExit = TRUE;
            continue;
        }    
       
    }
    
    //Touch_EmptyFifo(hTouch);
    printf("Exit\r\n");
}

