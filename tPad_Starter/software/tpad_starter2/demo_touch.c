#include "terasic_includes.h"
#include "alt_touchscreen.h"
#include "alt_video_display.h"
#include "demo_touch.h"
#include "simple_graphics.h"
#include "skin1.h"
#include "terasic_draw.h"
#include "math.h"
#include <io.h>
#include <stdio.h>
#include "includes.h"
#include "system.h"
//!changed
#define  N 5
typedef struct 
{
  int colorIndex;
  int touched;
}Balls_struct;

typedef struct
{
   alt_video_display* display;
   RECT rc;
   int state;//0->init; 1->game on
   alt_touchscreen* screen;
 }taskData,*ptaskD;

struct node { 
    int x; 
    int y;
    struct node *next; 
}; 
typedef struct node Node; 

OS_STK s1[2048];
OS_STK s2[2048];
Balls_struct Balls[N][N];
Node* sTouchedTop;

//functions for touched balls stack
Node* creates(void);         // 建立堆疊 
int isEmpty(Node*);           // 堆疊已空 
Node* add(Node*, int, int);   // 新增元素 
Node* delete(Node*);     // 刪除元素 
void list(Node*);      // 顯示所有內容 

void detectLCD(void *p) {
    alt_video_display* display=((ptaskD)p)->display;
    alt_video_display* screen=((ptaskD)p)->screen;
    alt_touchscreen_scaled_pen_data pen_data;
    int xt;
    int yt;
	int firstTouched;
  while(1){
            alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
            if (pen_data.pen_down==0)
            {
              xt=(pen_data.x-150)/100;
              yt=(pen_data.y-50)/100;
              printf("x=%d,y=%d\n",xt,yt);
			  Balls[yt][xt].touched=1;
			  if(isEmpty(sTouchedTop)==0){
				  sTouchedTop=add(sTouchedTop,xt,yt);
				  //!draw line
			  }
			  else{
				  sTouchedTop=add(sTouchedTop,xt,yt);
			  }
			  
              
            }
           // printf("in detect LCD\n");
            OSTimeDlyHMSM(0,0,1,0);
        }
        
}
void timer(void *p) {
    int time=0;
    char szText[128];
    RECT rcTime=((ptaskD)p)->rc;
    alt_video_display* display=((ptaskD)p)->display;
    ((ptaskD)p)->state=1;
  while (1) {
      // updating timer
     // printf("time=%d\n buffer_being_written=%d\n",time,display->buffer_being_written);//print the text on LCD
      display->buffer_being_written=0;
      vid_draw_round_corner_box ( rcTime.left+7, rcTime.top+7, rcTime.right-5, rcTime.bottom-5,10, COLOR_BLACK, DO_FILL, display);
      sprintf(szText,"Time:%d",time);
      vid_print_string_alpha(rcTime.left+5, rcTime.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);            
      // update canvas
      alt_video_display_register_written_buffer( display );
      while(alt_video_display_buffer_is_available(display) != 0);
      OSTimeDlyHMSM(0,0,1,0);//time delay 3 seconds. OSTimeDlyHMSM(hour, min, sec, millisecond)
      time++; 
  }
}

void demo_touch( alt_video_display* display, alt_touchscreen* screen, bool bLimited){
    char szText[128];
    int  score=0;
    int  life=10; 
    int  time=0;
    int  x0=0, y0=0, vo=0, xt=0,yt=0,dx=0,dy=0,t=0,x1,xfinal;
    alt_touchscreen_scaled_pen_data pen_data;

    bool bFirstTouch = TRUE;
    bool bExit = FALSE;
    RECT rcExit, rcScore, rcLife, rcTime;
    int state=0;
    

    AssignRect(&rcExit, 30, display->height-70, 100, display->height-30);//EXIT
    AssignRect(&rcScore, 30, 30, 250, 70);//Score 
    AssignRect(&rcLife, 280, 30, 430, 70);//Life 
    AssignRect(&rcTime, 550, 30, 700, 70);//Time 
   
    printf("===== Welcome to Buzzer_Beater -  easy=====\n");
    usleep(20*1000);
    
    
    //START!!
    alt_video_display_clear_screen( display, 0x0 );//clean canvas as black
    // balls initialize
    int color[4];
    color[0]=PINK_24;//   0xFFC0CB 
    color[1]=0xffdd33;//    yellow
    color[2]=LIGHTGREEN_24;//   0x90EE90
    color[3]=LIGHTSKYBLUE_24;//   0x87CEFA 
	
    int colorIndex;
    int i,j;
    for(i=0;i<N;i++){
           for(j=0;j<N;j++){
               colorIndex=rand()%4;
               Balls[j][i].colorIndex=colorIndex;
               Balls[j][i].touched=0;
               vid_draw_circle(200+100*i,100*(j+1),20, color[colorIndex],TRUE,display);
               //printf("(%d,%d)--color:%x\n",i,j,color[colorIndex]);
           }
     } 
    for(j=0;j<N;j++){
           for(i=0;i<N;i++){
               printf("%x/%d ",Balls[j][i].colorIndex,Balls[j][i].touched);
           }
           printf("\n");
     } 
    // loop 
   //initialize
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
        //Time
        sprintf(szText,"Time:%d",time);
        vid_print_string_alpha(rcTime.left+5, rcTime.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcTime.left, rcTime.top, rcTime.right, rcTime.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);        
        //background
        
        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);
    // printf("buffer_being_written=%d\n",display->buffer_being_written);
	
     taskData p;
     p.rc=rcTime;
     p.display=display;
     p.state=state;
     p.screen=screen;
     sTouchedTop = creates(); 
     OSTaskCreateExt(timer, &p, (void*) &s1[2047], 1, 1, s1, 2048, 0, 0);
     OSTaskCreateExt(detectLCD, &p, (void*) &s2[2047], 2, 2, s2, 2048, 0, 0);
     OSStart();
    /* while(!bExit){
//initial
        //alt_video_display_clear_screen( display, 0x0 );//clear
             
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
        //Time
        sprintf(szText,"Time:%d",time);
        vid_print_string_alpha(rcTime.left+5, rcTime.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
        vid_draw_round_corner_box ( rcTime.left, rcTime.top, rcTime.right, rcTime.bottom, 10, COLOR_WHITE, DO_NOT_FILL, display);        
        //background
        
        // update canvas
        alt_video_display_register_written_buffer( display );
        while(alt_video_display_buffer_is_available(display) != 0);     

        
 //wait for touch   
        //time=0;
        while(1){
            //!changed
            alt_touchscreen_get_pen(screen, (&pen_data.pen_down), (&pen_data.x), (&pen_data.y));
            if (pen_data.pen_down==0)// continue;
            {
                
                time++;
                if(time%1000==0){
                    printf("time=%d\n",time/1000);
                    //not working!!!
                    vid_draw_round_corner_box ( rcTime.left+5, rcTime.top+5, rcTime.right-5, rcTime.bottom-5,10, COLOR_BLACK, DO_FILL, display);
                    sprintf(szText,"Time:%d",time/1000);
                    vid_print_string_alpha(rcTime.left+5, rcTime.top, 0xFFFFFFFF, COLOR_BLACK, tahomabold_32, display, szText);
                    usleep(1000);
                }
                else
                {
                    usleep(1000);
                }
                //if(time==2500)
                //    time=0;
                
            }
            else{ 
                printf("touched time=%d\n",time);
                break;
            }
        }
        
//shoot
        for(t=1,x0=0,y0=0,xt=25,yt=25,xfinal=0;yt<=545 && xt>=25&&xt<=775;t++){    
            alt_video_display_clear_screen( display, 0x0 );//clear
            dx=  pen_data.x-130;
            dy=  pen_data.y-415;       
            vo=  90;//sqrt(dx*dx+dy*dy)/5;//((time-500)%4000)/25+60;
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
    printf("Exit\r\n");*/
}
Node* creates() { 
    return NULL; 
} 

int isEmpty(Node* top) { 
    return (top == NULL); 
} 


Node* add(Node* top, int xitem, int yitem) { 
    Node* newnode; 

    newnode = (Node*) malloc(sizeof(Node)); 

    if(newnode == NULL) { 
        printf("\n記憶體配置失敗！"); 
        exit(1); 
    } 

    newnode->x = xitem; 
    newnode->y = yitem;
    newnode->next = top; 
    top = newnode; 

    return top; 
} 

Node* delete(Node* top) { 
    Node* tmpnode; 

    tmpnode = top; 
    if(tmpnode == NULL) { 
        printf("\n堆疊已空！"); 
        return NULL; 
    } 

    top = top->next; 
    free(tmpnode); 

    return top; 
} 

void list(Node* top) { 
    getnode* tmpnode; 
    tmpnode = top; 

    printf("\n堆疊內容："); 
    while(tmpnode != NULL) { 
        printf("%d %d ->", tmpnode->x, tmpnode->y); 
        tmpnode = tmpnode->next; 
    } 
}
