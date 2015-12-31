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

#include "terasic_includes.h"
#include "terasic_draw.h"
//#include "gimp_bmp.h"
#include <math.h>

extern struct gimp_image_struct big_number_font;
extern struct gimp_image_struct gCDegreeBitmap;


void InflateRect(RECT *rc, int x, int y){
    rc->left -= x;
    rc->right += x;
    rc->top -= y;
    rc->bottom += y;
}

void OffsetRect(RECT *rc, int x, int y){
    rc->left += x;
    rc->right += x;
    rc->top += y;
    rc->bottom += y;
}

void AssignRect(RECT *rc, int left, int top, int right, int bottom){
    rc->left = left;
    rc->right = right;
    rc->top = top;
    rc->bottom = bottom;
}


bool PtInRect(RECT *rc, int x, int y){
    bool result = FALSE;
    if (x >= rc->left && x <= rc->right){
        if (y >= rc->top && y <= rc->bottom){
            result = TRUE;
        }   
    }
    return result;
}

void draw_text(alt_video_display* display, int x, int y, char *pText, alt_u32 text_color){
        vid_print_string_alpha(x,
                            y,
                            text_color, //PROGRESS_WINDOW_BODY_COLOR, 
                            PROGRESS_WINDOW_TEXT_COLOR,
                            tahomabold_32, //tahomabold_20, //PROGRESS_WINDOW_TEXT_FONT, 
                            display, 
                            pText);//szTestList[i]->szTitle);    
}

void draw_small_text(alt_video_display* display, int x, int y, char *pText, alt_u32 text_color){
        vid_print_string_alpha(x,
                            y,
                            text_color, //PROGRESS_WINDOW_BODY_COLOR, 
                            PROGRESS_WINDOW_TEXT_COLOR,
                            tahomabold_20, //tahomabold_20, //PROGRESS_WINDOW_TEXT_FONT, 
                            display, 
                            pText);//szTestList[i]->szTitle);    
}

void draw_button(alt_video_display* display, RECT *rc, char *szText){
    const int nBorder = 6;
    int text_x_shift, text_y_shift;
    text_x_shift = ((rc->right-rc->left) - strlen(szText)*17)/2;
    text_y_shift = ((rc->bottom-rc->top) - 36)/2;
    vid_draw_round_corner_box( rc->left, rc->top, rc->right, rc->bottom, nBorder, COMMAND_BUTTON_BORDER_COLOR_SELECTED, DO_FILL, display);
    // Print the button interior
    InflateRect(rc, -nBorder, -nBorder);
    vid_draw_round_corner_box( rc->left, rc->top, rc->right, rc->bottom, nBorder/2, COMMAND_BUTTON_COLOR_SELECTED, DO_FILL, display);
    InflateRect(rc, nBorder, nBorder);
    // Print window text
    draw_text(display, rc->left + text_x_shift, rc->top + text_y_shift, szText, COLOR_WHITE);
    //vid_print_string_alpha( rc->left + text_x_shift, rc->top + text_y_shift, PROGRESS_WINDOW_BODY_COLOR, PROGRESS_WINDOW_TEXT_COLOR,  tahomabold_32,display, szText);
    //    
}

void draw_rect(alt_video_display* display, RECT *rc, alt_u32 color){
    vid_paint_block (rc->left, rc->top, rc->right, rc->bottom, color, display);
}


void draw_screen_pattern(alt_video_display* display){
#if 1    
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
#else    
    alt_video_display_clear_screen(display, 0xFFFFFFFF);
#endif    
    alt_video_display_register_written_buffer( display );
}


int DRAW_CopyRGBImageToBuffer( char* dest, char* src, 
                            int dest_width, 
                            int src_width, int src_height )
{
  int x, y;
  
  
  //Copy one line at a time from top to bottom
  char *pSrcBase, *pDesBase;
  pSrcBase = src;
  pDesBase = dest;
  for ( y = 0; y < src_height; y++ )
  {
        char *pDes = pDesBase;
        char *pSrc = pSrcBase;
        for(x = 0; x< src_width; x++){
            *pDes++ = *pSrc++;
            *pDes++ = *pSrc++;
            *pDes++ = *pSrc++;
            *pDes++ = 255;  // alpha
        }
        
        pDesBase += dest_width * 4;
        pSrcBase += src_width * 3;
  }
  
  return( 0 );
}



/////////////////////////////////////////////////
// bitmap
/////////////////////////////////////////////////
void DRAW_Bitmap(alt_video_display* display, int x, int y, RAW_IMAGE *pBitmap){
    int nBytesPerPixel, nImageWidth, nImageHeight;
    char *pImageDes, *pImageSrc;
        
    nBytesPerPixel = pBitmap->bytes_per_pixel;        
    nImageWidth = pBitmap->width;
    nImageHeight = pBitmap->height;
    pImageDes = (char*)(( display->buffer_ptrs[display->buffer_being_written]->buffer ) + 
                    ((( y ) * display->width ) * 4 ) +
                    (( x ) * 4 ));         
     
        pImageSrc = pBitmap->pixel_data;   
        DRAW_CopyRGBImageToBuffer( 
                   pImageDes,
                   pImageSrc, 
                   display->width, 
                   nImageWidth, 
                   nImageHeight );    
}

RAW_IMAGE* DRAW_BitmapDecode(char *pBitmap, int nSize){
    //
    typedef struct{
        alt_u16 ID;
        alt_u32 FileSize;
        alt_u32 Reserved;
        alt_u32 BitmapDataOffset;
        alt_u32 HeaderSize;
        alt_u32 Width;
        alt_u32 Height;
        alt_u16 Planes;
        alt_u16 BitsPerPixel;
        alt_u32 Compression;
        alt_u32 BitmapDataSize;
        alt_u32 HResolution;
        alt_u32 VResolution;
        alt_u32 Colors;
        alt_u32 ImportantColors;
        alt_u32 Palette[0];
    }__attribute__ ((packed,aligned(1))) BMP_HEADER;
    
    BMP_HEADER *pHeader;
    RAW_IMAGE *pImage = NULL;
    char *pDes, *pSrc;
    int y;
    int nRawDataSize, nBitmapDataSize, nBytesPerBmpLine, nBytesPerRawLine;
   
    
    // parsing header
    if (nSize < sizeof(BMP_HEADER))
        return NULL;
    pHeader = (BMP_HEADER *)pBitmap;
    if (pHeader->ID != 0x4d42)
        return NULL; // invalid tag
    if (pHeader->FileSize != nSize)
        return NULL; // invalid file size
    if (pHeader->BitsPerPixel != 24)
        return NULL; // not support in our applicaiton
    if (pHeader->Compression != 0)
        return NULL; // not support compress in our applicaiton
    if (pHeader->Width > 800)
        return NULL; // not support compress in our applicaiton
    if (pHeader->Height > 600)
        return NULL; // not support compress in our applicaiton
    nBytesPerBmpLine = (pHeader->Width * 3+3)/4*4;        
    nBitmapDataSize = nBytesPerBmpLine*pHeader->Height; 
    nBytesPerRawLine = pHeader->Width * 3;       
    nRawDataSize = nBytesPerRawLine * pHeader->Height;
    if (pHeader->BitmapDataSize && pHeader->BitmapDataSize != nBitmapDataSize)
        return NULL; // unmatched raw data size
                    
    // alloc memory
    pImage = malloc(sizeof(RAW_IMAGE) + nRawDataSize + 1);
    
    // load body (bitmap scanline is 4-byte boundary)
    pImage->width = pHeader->Width;
    pImage->height = pHeader->Height;
    pImage->bytes_per_pixel = 3;
    
    // copy raw data (top-bottom invert)
    pDes = pImage->pixel_data;
    pSrc = pBitmap+pHeader->BitmapDataOffset + pHeader->Height*nBytesPerBmpLine;
    for(y=0;y<pHeader->Height;y++){
        pSrc -= nBytesPerBmpLine;
        memcpy(pDes, pSrc, nBytesPerRawLine);
        pDes += nBytesPerRawLine;
    }
    
    
    //
    return pImage;
}

void CopyRect(RECT *rcDes, RECT *rcSrc){
    rcDes->left = rcSrc->left;
    rcDes->top = rcSrc->top;
    rcDes->right = rcSrc->right;
    rcDes->bottom = rcSrc->bottom;        
}
