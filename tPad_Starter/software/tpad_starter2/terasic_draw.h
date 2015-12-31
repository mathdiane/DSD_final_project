#ifndef TERASIC_DRAW_H_
#define TERASIC_DRAW_H_

#include "alt_video_display.h"
#include "skin1.h"
#include "simple_graphics.h"
#include "alt_video_display.h"

/*
#define ALT_VIDEO_DISPLAY_COLS 800
#define ALT_VIDEO_DISPLAY_ROWS 480
#define ALT_VIDEO_DISPLAY_COLOR_DEPTH 32
#define ALT_VIDEO_DISPLAY_SGDMA_NAME LCD_SGDMA_NAME

#define NUM_VIDEO_FRAMES 2

#define COLOR_RED     0xFF0000
#define COLOR_GREEN   0xFF00
#define COLOR_BLUE    0xFF
#define COLOR_BLACK   0x00
#define COLOR_WHITE   0xFFFFFF
#define COLOR_GRAY    0x3F3F3F
*/

typedef struct{
    int left;
    int right;
    int top;
    int bottom;
}RECT;

typedef struct{
    int x;
    int y;
}POINT;

typedef struct{
    int cx;
    int cy;
}SIZE;

typedef struct{
  unsigned int   width;
  unsigned int   height;
  unsigned int   bytes_per_pixel; /* 3:RGB, 4:RGBA */ 
  unsigned char  pixel_data[];
}RAW_IMAGE;

#define bool    int
#define TRUE    1
#define FALSE   0


void InflateRect(RECT *rc, int x, int y);
void OffsetRect(RECT *rc, int x, int y);
void AssignRect(RECT *rc, int left, int top, int right, int bottom);
void CopyRect(RECT *rcDes, RECT *rcSrc);

void draw_text(alt_video_display* display, int x, int y, char *pText, alt_u32 text_color);
void draw_small_text(alt_video_display* display, int x, int y, char *pText, alt_u32 text_color);
void draw_button(alt_video_display* display, RECT *rc, char *szText);
bool PtInRect(RECT *rc, int x, int y);
void draw_screen_pattern(alt_video_display* display);
void draw_rect(alt_video_display* display, RECT *rc, alt_u32 color);


// bitmap
void DRAW_Bitmap(alt_video_display* display, int x, int y, RAW_IMAGE *pBitmap);
RAW_IMAGE* DRAW_BitmapDecode(char *pBitmap, int nSize);


#endif /*TERASIC_DRAW_H_*/
