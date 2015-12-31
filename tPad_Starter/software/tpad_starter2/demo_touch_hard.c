#include "terasic_includes.h"
#include "alt_touchscreen.h"
#include "alt_video_display.h"
#include "demo_touch.h"
#include "simple_graphics.h"
#include "skin1.h"
#include "terasic_draw.h"
#include "math.h"

void demo_touch_hard( alt_video_display* display, alt_touchscreen* screen, bool bLimited){
    char szText[128];
    int  score=0;
    int  life=10;
    int  time=0;
    int  x0=0, y0=0, vo=0, xt=0,yt=0,dx=0,dy=0,t=0,x1,xfinal;
    alt_touchscreen_scaled_pen_data pen_data;
    bool bFirstTouch = TRUE;
    bool bExit = FALSE;
    RECT rcExit, rcScore, rcLife;
    
    AssignRect(&rcExit, 30, display->height-70, 100, display->height-30);//EXIT
    AssignRect(&rcScore, 30, 30, 250, 70);//Score 
    AssignRect(&rcLife, 280, 30, 430, 70);//Life   
   
    printf("===== Welcome to Buzzer_Beater -  hard=====\n");
    usleep(20*1000);
    

//START!!
    // clean canvas as black
    alt_video_display_clear_screen( display, 0x0 );
    sprintf(szText,"START!!");
    vid_print_string_alpha(315, 290, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
    // update canvas
    alt_video_display_register_written_buffer( display );
    while(alt_video_display_buffer_is_available(display) != 0);

 //wait for touch   
    while(1){
            alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
            if (pen_data.pen_down==0) continue;
            break;
    }

    
    // loop 
   // Touch_EmptyFifo(hTouch);
     while(!bExit){
//initial
        alt_video_display_clear_screen( display, 0x0 );//clear
        vid_draw_circle(130, 415, 25, 0xffaa00, DO_FILL, display);//ball      
        //exit button
        sprintf(szText,"Exit");
        vid_print_string_alpha(rcExit.left+5, rcExit.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcExit.left, rcExit.top, rcExit.right, rcExit.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
        //Score
        sprintf(szText,"Score:%d",score);
        vid_print_string_alpha(rcScore.left+5, rcScore.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcScore.left, rcScore.top, rcScore.right, rcScore.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
        //Life
        if(bLimited){
            sprintf(szText,"Life:%d",life);
            vid_print_string_alpha(rcLife.left+5, rcLife.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
            vid_draw_round_corner_box ( rcLife.left, rcLife.top, rcLife.right, rcLife.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
        }        
        //background
        vid_draw_circle(100, 370, 30, 0xffaa00, DO_NOT_FILL, display);//head
        vid_draw_line(100,400,100,470,1,WHITE_24,display);//body
        vid_draw_line(100,470,75,570,1,WHITE_24,display);
        vid_draw_line(100,470,125,570,1,WHITE_24,display);
        vid_draw_line(100,400,60,450,1,WHITE_24,display);//hand
        vid_draw_line(60,450,120,420,1,WHITE_24,display);
        vid_draw_line(780,100,780,250,16,BLUE_24,display);//
        //vid_draw_box(780,120,795,250,RED_24, DO_FILL,display);
        vid_draw_line(650,220,780,220,4,RED_24,display);
        vid_draw_line(792,251,792,570,4,BLUE_24,display); 
        vid_draw_line(0,570,799,570,1,WHITE_24,display);//ground    
        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);     

        
 //wait for touch   
        time=0;
        while(1){
            alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
            if (pen_data.pen_down==0)// continue;
            {
                usleep(500);
                time++;
                if(time==2500)
                    time=0;
            }
            else{ 
                printf("time=%d\n",time);
                break;
            }
        }
        
//shoot
        for(t=1,x0=0,y0=0,xt=25,yt=25,xfinal=0;yt<=545 && xt>=25&&xt<=775;t++){    
            alt_video_display_clear_screen( display, 0x0 );//clear
            dx=  pen_data.x-130;
            dy=  pen_data.y-415;       
            vo=  ((time-500)%4000)/25+60;
            x0=  xt;
            y0=  yt;
            xt=  130+ vo*dx*(t)/( sqrt(dx*dx+dy*dy));
            yt=  415+ (vo*dy*(t)/( sqrt(dx*dx+dy*dy)) + 5*(t)*(t));
            if(xt<=775 && yt<=545 ){
                if(yt>=25)
                    vid_draw_circle(xt, yt, 25, 0xffaa00, DO_FILL, display); // ball
                x1=(xt*(yt-y0)-(yt-220)*(xt-x0))/(yt-y0);
                if(x1>=(650+10) && x1<=(780-10) &&y0<220 &&yt>220){
                    score++;            
                    printf("x1=%d,x0=%d,y0=%d,xt=%d,yt=%d\r\n",x1,x0,y0,xt,yt);
                    xfinal=x1;
                }           
            }
            //exit button
            sprintf(szText,"Exit");
            vid_print_string_alpha(rcExit.left+5, rcExit.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
            vid_draw_round_corner_box ( rcExit.left, rcExit.top, rcExit.right, rcExit.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
            //Score
            sprintf(szText,"Score:%d",score);
            vid_print_string_alpha(rcScore.left+5, rcScore.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
            vid_draw_round_corner_box ( rcScore.left, rcScore.top, rcScore.right, rcScore.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
            //Life
            if(bLimited){
                sprintf(szText,"Life:%d",life);
                vid_print_string_alpha(rcLife.left+5, rcLife.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
                vid_draw_round_corner_box ( rcLife.left, rcLife.top, rcLife.right, rcLife.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
            }
            //background
            vid_draw_circle(100, 370-50, 30, 0xffaa00, DO_NOT_FILL, display);//head
            vid_draw_line(100,400-50,100,470-50,1,WHITE_24,display);//body
            vid_draw_line(100,470-50,110,460,1,WHITE_24,display);//left leg
            vid_draw_line(110,460,70,530,1,WHITE_24,display);
            vid_draw_line(100,470-50,140,430,1,WHITE_24,display);//right leg
            vid_draw_line(140,430,110,480,1,WHITE_24,display);//
            vid_draw_line(100,400-50,100+100*dx/(sqrt(dx*dx+dy*dy)),350+100*dy/(sqrt(dx*dx+dy*dy)),1,WHITE_24,display);//hand
            vid_draw_line(650,220,780,220,4,RED_24,display);//basket
            vid_draw_line(780,100,780,250,16,BLUE_24,display);//            
            vid_draw_line(792,251,792,570,4,BLUE_24,display);      
            vid_draw_line(0,570,799,570,1,WHITE_24,display);//ground  
            // update canvas
            alt_video_display_register_written_buffer( display );
            while(alt_video_display_buffer_is_available(display) != 0);     
            usleep(20000);    
        }//for end
        life--;
            
//wait ball down
        if(xfinal!=0){
            life++;
            for(;y0<495;){
                alt_video_display_clear_screen( display, 0x0 );//clear
                vid_draw_circle(x0, y0+50, 25, 0xffaa00, DO_FILL, display);//ball
                y0=y0+50; 
                //exit button
                sprintf(szText,"Exit");
                vid_print_string_alpha(rcExit.left+5, rcExit.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
                vid_draw_round_corner_box ( rcExit.left, rcExit.top, rcExit.right, rcExit.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
                //Score
                sprintf(szText,"Score:%d",score);
                vid_print_string_alpha(rcScore.left+5, rcScore.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
                vid_draw_round_corner_box ( rcScore.left, rcScore.top, rcScore.right, rcScore.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
                //Life
                if(bLimited){
                    sprintf(szText,"Life:%d",life);
                    vid_print_string_alpha(rcLife.left+5, rcLife.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
                    vid_draw_round_corner_box ( rcLife.left, rcLife.top, rcLife.right, rcLife.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
                }
                //background
                vid_draw_circle(100, 370, 30, 0xffaa00, DO_NOT_FILL, display);//head
                vid_draw_line(100,400,100,470,1,WHITE_24,display);//body
                vid_draw_line(100,470,75,570,1,WHITE_24,display);
                vid_draw_line(100,470,125,570,1,WHITE_24,display);
                vid_draw_line(100,400,80,480,1,WHITE_24,display);
                vid_draw_line(100,400,115,480,1,WHITE_24,display);
                vid_draw_line(650,220,780,220,4,RED_24,display);//basket
                vid_draw_line(780,100,780,250,16,BLUE_24,display);//            
                vid_draw_line(792,251,792,570,4,BLUE_24,display);      
                vid_draw_line(0,570,799,570,1,WHITE_24,display);//ground         
                // update canvas
                alt_video_display_register_written_buffer( display );
                while(alt_video_display_buffer_is_available(display) != 0); 
                usleep(20000);  
           }//for end
        }//if end
    
//wait again
        alt_video_display_clear_screen( display, 0x0 );//clear
        if(xt<=775 && xt>=0){
            vid_draw_circle(xt, 545, 25, 0xffaa00, DO_FILL, display);//ball
        }    
        //exit button
        sprintf(szText,"Exit");
        vid_print_string_alpha(rcExit.left+5, rcExit.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcExit.left, rcExit.top, rcExit.right, rcExit.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
        //Score
        sprintf(szText,"Score:%d",score);
        vid_print_string_alpha(rcScore.left+5, rcScore.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcScore.left, rcScore.top, rcScore.right, rcScore.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
        //Life
        if(bLimited){
            sprintf(szText,"Life:%d",life);
            vid_print_string_alpha(rcLife.left+5, rcLife.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
            vid_draw_round_corner_box ( rcLife.left, rcLife.top, rcLife.right, rcLife.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);
        }      
        //background
        vid_draw_circle(100, 370, 30, 0xffaa00, DO_NOT_FILL, display);//head
        vid_draw_line(100,400,100,470,1,WHITE_24,display);//body
        vid_draw_line(100,470,75,570,1,WHITE_24,display);
        vid_draw_line(100,470,125,570,1,WHITE_24,display);
        vid_draw_line(100,400,80,480,1,WHITE_24,display);
        vid_draw_line(100,400,115,480,1,WHITE_24,display);
        vid_draw_line(650,220,780,220,4,RED_24,display);//basket
        vid_draw_line(780,100,780,250,16,BLUE_24,display);
        vid_draw_line(792,251,792,570,4,BLUE_24,display);
        vid_draw_line(0,570,799,570,1,WHITE_24,display);//ground     
        //Again
        if(life==0) {  
        sprintf(szText,"Game over, touch for play again.");
        vid_print_string_alpha(200, 280, COLOR_WHITE, COLOR_BLACK, tahomabold_32, display, szText);
        }
        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0); 
        
        if(life==0){
        //wait for touch   
            while(1){
                life=10;
		score=0;
                alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
                if (pen_data.pen_down==0) continue;
                break;
            }
        }//if end

        // is exit?
        if (!bFirstTouch){
            if (PtInRect(&rcExit, pen_data.x, pen_data.y)){
                bExit = TRUE;
                continue;
            }    
        }    
        bFirstTouch = FALSE;                  
    }
    //Touch_EmptyFifo(hTouch);
    printf("Exit\r\n");
}
