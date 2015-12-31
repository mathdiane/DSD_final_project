/*****************************************************************************
 *  File: main.c
 * 
 *  This file is the top level of the application selector.
 *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <sys/alt_alarm.h>
#include "app_selector.h"
#include "alt_video_display.h"
#include "my_ui.h"
#include "system.h"
#include "io.h"
#include "alt_touchscreen.h"
#include "demo_main.h"

int main()
{

  volatile int ret_code;

  // This is our LCD display
  alt_video_display* display;
  ///touch screen
    alt_touchscreen touch_screen;
    int result;
    result = alt_touchscreen_init(
    &touch_screen,
    TOUCH_PANEL_SPI_BASE,
    TOUCH_PANEL_SPI_IRQ,
    TOUCH_PANEL_PENIRQ_N_BASE,
    100,
    ALT_TOUCHSCREEN_SWAP_XY);
    
  /* Set calibration constants */
  alt_touchscreen_calibrate_upper_right (&touch_screen, 
                     3946,   3849,    // ADC readings
                      799,      0  ); // pixel coords

  alt_touchscreen_calibrate_lower_left  (&touch_screen,  
                     132,    148,     // ADC readings
                       0,    599  );  // pixel coords
  
  


  // Initialize and start the LCD display
  display = alt_video_display_init( ALT_VIDEO_DISPLAY_SGDMA_NAME,         // char* sgdma_name
                                    ALT_VIDEO_DISPLAY_COLS,               // int width
                                    ALT_VIDEO_DISPLAY_ROWS,               // int height
                                    ALT_VIDEO_DISPLAY_COLOR_DEPTH,        // int color_depth
                                    ALT_VIDEO_DISPLAY_USE_HEAP,           // int buffer_location
                                    ALT_VIDEO_DISPLAY_USE_HEAP,           // int descriptor_location
                                    2 );                                  // int num_buffers
  //
//  hTouch = Touch_Init(TOUCH_PANEL_SPI_BASE, TOUCH_PANEL_PENIRQ_N_BASE, TOUCH_PANEL_PENIRQ_N_IRQ);
//  if (!hTouch){
//      printf("Failed to init touch");
//  }   
                                      
  demo_main(display, &touch_screen);

  alt_video_display_close( display,
                           ALT_VIDEO_DISPLAY_USE_HEAP,
                           ALT_VIDEO_DISPLAY_USE_HEAP  );

  return ( ret_code );
}











