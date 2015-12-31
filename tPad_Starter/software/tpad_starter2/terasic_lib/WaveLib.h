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

#ifndef _INC_WAVE_LIB_H
#define _INC_WAVE_LIB_H

//#include "my_types.h"

#ifdef __cplusplus
extern "C" {
#endif


bool WAVE_IsWaveFile(char *szWave, const int nSize);
int Wave_GetSampleRate(char *szWave, const int nSize);
int Wave_GetChannelNum(char *szWave, const int nSize);
int Wave_GetSampleBitNum(char *szWave, const int nSize);
int Wave_GetDataByteSize(char *szWave, const int nSize);
int Wave_GetWaveOffset(char *szWave, const int nSize);

#ifdef __cplusplus
}
#endif

#endif /* _INC_WAVE_LIB_H */
