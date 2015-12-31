/* system.h
 *
 * Machine generated for a CPU named "cpu" as defined in:
 * f:\dsdFinalProject\tPad_Starter\software\tpad_starter2_syslib\..\..\tPad_Starter_SOPC.ptf
 *
 * Generated: 2015-12-16 17:54:33.996
 *
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/*

DO NOT MODIFY THIS FILE

   Changing this file will have subtle consequences
   which will almost certainly lead to a nonfunctioning
   system. If you do modify this file, be aware that your
   changes will be overwritten and lost when this file
   is generated again.

DO NOT MODIFY THIS FILE

*/

/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2003 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
******************************************************************************/

/*
 * system configuration
 *
 */

#define ALT_SYSTEM_NAME "tPad_Starter_SOPC"
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_ARCHITECTURE "altera_nios2"
#define ALT_DEVICE_FAMILY "CYCLONEIVE"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN_BASE 0x0b081050
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_PRESENT
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT_BASE 0x0b081050
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_PRESENT
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDERR_BASE 0x0b081050
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_PRESENT
#define ALT_CPU_FREQ 100000000
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT

/*
 * processor configuration
 *
 */

#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_BIG_ENDIAN 0
#define NIOS2_INTERRUPT_CONTROLLER_ID 0

#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_FLUSHDA_SUPPORTED

#define NIOS2_EXCEPTION_ADDR 0x0b040020
#define NIOS2_RESET_ADDR 0x0a800000
#define NIOS2_BREAK_ADDR 0x0b080820

#define NIOS2_HAS_DEBUG_STUB

#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0

/*
 * A define for each class of peripheral
 *
 */

#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTPLL
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_CLOCK_CROSSING
#define __ALTERA_AVALON_SYSID
#define __ALTERA_AVALON_LCD_16207
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_SGDMA
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __TERASIC_IRM
#define __ALTERA_AVALON_TRI_STATE_BRIDGE
#define __ALTERA_AVALON_CFI_FLASH

/*
 * onchip_mem configuration
 *
 */

#define ONCHIP_MEM_NAME "/dev/onchip_mem"
#define ONCHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_BASE 0x0b040000
#define ONCHIP_MEM_SPAN 262144
#define ONCHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_INIT_CONTENTS_FILE "onchip_mem"
#define ONCHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_MEM_WRITEABLE 1
#define ONCHIP_MEM_DUAL_PORT 0
#define ONCHIP_MEM_SIZE_VALUE 262144
#define ONCHIP_MEM_SIZE_MULTIPLE 1
#define ONCHIP_MEM_USE_SHALLOW_MEM_BLOCKS 0
#define ONCHIP_MEM_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_INSTANCE_ID "NONE"
#define ONCHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_IGNORE_AUTO_BLOCK_TYPE_ASSIGNMENT 1
#define ONCHIP_MEM_CONTENTS_INFO "QUARTUS_PROJECT_DIR/onchip_mem.hex 1283946606"
#define ALT_MODULE_CLASS_onchip_mem altera_avalon_onchip_memory2

/*
 * sdram configuration
 *
 */

#define SDRAM_NAME "/dev/sdram"
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_BASE 0x00000000
#define SDRAM_SPAN 134217728
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_SDRAM_DATA_WIDTH 32
#define SDRAM_SDRAM_ADDR_WIDTH 13
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_CAS_LATENCY 3
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_AC 5.5
#define SDRAM_T_WR 14.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_SHARED_DATA 0
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_IS_INITIALIZED 1
#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller

/*
 * altpll configuration
 *
 */

#define ALTPLL_NAME "/dev/altpll"
#define ALTPLL_TYPE "altpll"
#define ALTPLL_BASE 0x0b081040
#define ALTPLL_SPAN 16
#define ALT_MODULE_CLASS_altpll altpll

/*
 * jtag_uart configuration
 *
 */

#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_BASE 0x0b081050
#define JTAG_UART_SPAN 8
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_READ_CHAR_STREAM ""
#define JTAG_UART_SHOWASCII 1
#define JTAG_UART_RELATIVEPATH 0
#define JTAG_UART_READ_LE 0
#define JTAG_UART_WRITE_LE 0
#define JTAG_UART_ALTERA_SHOW_UNRELEASED_JTAG_UART_FEATURES 0
#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart

/*
 * clock_crossing_io configuration
 *
 */

#define CLOCK_CROSSING_IO_NAME "/dev/clock_crossing_io"
#define CLOCK_CROSSING_IO_TYPE "altera_avalon_clock_crossing"
#define CLOCK_CROSSING_IO_BASE 0x08000000
#define CLOCK_CROSSING_IO_SPAN 256
#define CLOCK_CROSSING_IO_UPSTREAM_FIFO_DEPTH 256
#define CLOCK_CROSSING_IO_DOWNSTREAM_FIFO_DEPTH 32
#define CLOCK_CROSSING_IO_DATA_WIDTH 32
#define CLOCK_CROSSING_IO_NATIVE_ADDRESS_WIDTH 6
#define CLOCK_CROSSING_IO_USE_BYTE_ENABLE 1
#define CLOCK_CROSSING_IO_USE_BURST_COUNT 0
#define CLOCK_CROSSING_IO_MAXIMUM_BURST_SIZE 8
#define CLOCK_CROSSING_IO_UPSTREAM_USE_REGISTER 0
#define CLOCK_CROSSING_IO_DOWNSTREAM_USE_REGISTER 0
#define CLOCK_CROSSING_IO_SLAVE_SYNCHRONIZER_DEPTH 3
#define CLOCK_CROSSING_IO_MASTER_SYNCHRONIZER_DEPTH 3
#define CLOCK_CROSSING_IO_DEVICE_FAMILY "CYCLONEIVE"
#define ALT_MODULE_CLASS_clock_crossing_io altera_avalon_clock_crossing

/*
 * sysid configuration
 *
 */

#define SYSID_NAME "/dev/sysid"
#define SYSID_TYPE "altera_avalon_sysid"
#define SYSID_BASE 0x080000e0
#define SYSID_SPAN 8
#define SYSID_ID 58678540u
#define SYSID_TIMESTAMP 1283946474u
#define SYSID_REGENERATE_VALUES 0
#define ALT_MODULE_CLASS_sysid altera_avalon_sysid

/*
 * lcd configuration
 *
 */

#define LCD_NAME "/dev/lcd"
#define LCD_TYPE "altera_avalon_lcd_16207"
#define LCD_BASE 0x08000080
#define LCD_SPAN 16
#define ALT_MODULE_CLASS_lcd altera_avalon_lcd_16207

/*
 * timer configuration
 *
 */

#define TIMER_NAME "/dev/timer"
#define TIMER_TYPE "altera_avalon_timer"
#define TIMER_BASE 0x08000000
#define TIMER_SPAN 32
#define TIMER_IRQ 1
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_ALWAYS_RUN 0
#define TIMER_FIXED_PERIOD 0
#define TIMER_SNAPSHOT 1
#define TIMER_PERIOD 10
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_LOAD_VALUE 999999
#define TIMER_COUNTER_SIZE 32
#define TIMER_MULT 0.0010
#define TIMER_TICKS_PER_SEC 100
#define TIMER_FREQ 100000000
#define ALT_MODULE_CLASS_timer altera_avalon_timer

/*
 * lcd_sgdma configuration
 *
 */

#define LCD_SGDMA_NAME "/dev/lcd_sgdma"
#define LCD_SGDMA_TYPE "altera_avalon_sgdma"
#define LCD_SGDMA_BASE 0x0b081000
#define LCD_SGDMA_SPAN 64
#define LCD_SGDMA_IRQ 2
#define LCD_SGDMA_IRQ_INTERRUPT_CONTROLLER_ID 0
#define LCD_SGDMA_READ_BLOCK_DATA_WIDTH 64
#define LCD_SGDMA_WRITE_BLOCK_DATA_WIDTH 64
#define LCD_SGDMA_STREAM_DATA_WIDTH 64
#define LCD_SGDMA_ADDRESS_WIDTH 32
#define LCD_SGDMA_HAS_READ_BLOCK 1
#define LCD_SGDMA_HAS_WRITE_BLOCK 0
#define LCD_SGDMA_READ_BURSTCOUNT_WIDTH 4
#define LCD_SGDMA_WRITE_BURSTCOUNT_WIDTH 4
#define LCD_SGDMA_BURST_TRANSFER 0
#define LCD_SGDMA_ALWAYS_DO_MAX_BURST 1
#define LCD_SGDMA_DESCRIPTOR_READ_BURST 0
#define LCD_SGDMA_UNALIGNED_TRANSFER 0
#define LCD_SGDMA_CONTROL_SLAVE_DATA_WIDTH 32
#define LCD_SGDMA_CONTROL_SLAVE_ADDRESS_WIDTH 4
#define LCD_SGDMA_DESC_DATA_WIDTH 32
#define LCD_SGDMA_DESCRIPTOR_WRITEBACK_DATA_WIDTH 32
#define LCD_SGDMA_STATUS_TOKEN_DATA_WIDTH 24
#define LCD_SGDMA_BYTES_TO_TRANSFER_DATA_WIDTH 16
#define LCD_SGDMA_BURST_DATA_WIDTH 8
#define LCD_SGDMA_CONTROL_DATA_WIDTH 8
#define LCD_SGDMA_STATUS_DATA_WIDTH 8
#define LCD_SGDMA_ATLANTIC_CHANNEL_DATA_WIDTH 4
#define LCD_SGDMA_COMMAND_FIFO_DATA_WIDTH 104
#define LCD_SGDMA_SYMBOLS_PER_BEAT 8
#define LCD_SGDMA_IN_ERROR_WIDTH 0
#define LCD_SGDMA_OUT_ERROR_WIDTH 0
#define ALT_MODULE_CLASS_lcd_sgdma altera_avalon_sgdma

/*
 * touch_panel_busy configuration
 *
 */

#define TOUCH_PANEL_BUSY_NAME "/dev/touch_panel_busy"
#define TOUCH_PANEL_BUSY_TYPE "altera_avalon_pio"
#define TOUCH_PANEL_BUSY_BASE 0x080000a0
#define TOUCH_PANEL_BUSY_SPAN 16
#define TOUCH_PANEL_BUSY_DO_TEST_BENCH_WIRING 0
#define TOUCH_PANEL_BUSY_DRIVEN_SIM_VALUE 0
#define TOUCH_PANEL_BUSY_HAS_TRI 0
#define TOUCH_PANEL_BUSY_HAS_OUT 0
#define TOUCH_PANEL_BUSY_HAS_IN 1
#define TOUCH_PANEL_BUSY_CAPTURE 0
#define TOUCH_PANEL_BUSY_DATA_WIDTH 1
#define TOUCH_PANEL_BUSY_RESET_VALUE 0
#define TOUCH_PANEL_BUSY_EDGE_TYPE "NONE"
#define TOUCH_PANEL_BUSY_IRQ_TYPE "NONE"
#define TOUCH_PANEL_BUSY_BIT_CLEARING_EDGE_REGISTER 0
#define TOUCH_PANEL_BUSY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TOUCH_PANEL_BUSY_FREQ 10000000
#define ALT_MODULE_CLASS_touch_panel_busy altera_avalon_pio

/*
 * touch_panel_spi configuration
 *
 */

#define TOUCH_PANEL_SPI_NAME "/dev/touch_panel_spi"
#define TOUCH_PANEL_SPI_TYPE "altera_avalon_spi"
#define TOUCH_PANEL_SPI_BASE 0x08000040
#define TOUCH_PANEL_SPI_SPAN 32
#define TOUCH_PANEL_SPI_IRQ 3
#define TOUCH_PANEL_SPI_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TOUCH_PANEL_SPI_DATABITS 8
#define TOUCH_PANEL_SPI_DATAWIDTH 16
#define TOUCH_PANEL_SPI_TARGETCLOCK 32000
#define TOUCH_PANEL_SPI_CLOCKUNITS "Hz"
#define TOUCH_PANEL_SPI_CLOCKMULT 1
#define TOUCH_PANEL_SPI_NUMSLAVES 1
#define TOUCH_PANEL_SPI_ISMASTER 1
#define TOUCH_PANEL_SPI_CLOCKPOLARITY 0
#define TOUCH_PANEL_SPI_CLOCKPHASE 0
#define TOUCH_PANEL_SPI_LSBFIRST 0
#define TOUCH_PANEL_SPI_EXTRADELAY 0
#define TOUCH_PANEL_SPI_INSERT_SYNC 0
#define TOUCH_PANEL_SPI_SYNC_REG_DEPTH 2
#define TOUCH_PANEL_SPI_DISABLEAVALONFLOWCONTROL 0
#define TOUCH_PANEL_SPI_TARGETSSDELAY 0.0
#define TOUCH_PANEL_SPI_DELAYUNITS "ns"
#define TOUCH_PANEL_SPI_DELAYMULT "1e-009"
#define TOUCH_PANEL_SPI_PREFIX "spi_"
#define TOUCH_PANEL_SPI_CLOCKUNIT "kHz"
#define TOUCH_PANEL_SPI_DELAYUNIT "us"
#define ALT_MODULE_CLASS_touch_panel_spi altera_avalon_spi

/*
 * touch_panel_penirq_n configuration
 *
 */

#define TOUCH_PANEL_PENIRQ_N_NAME "/dev/touch_panel_penirq_n"
#define TOUCH_PANEL_PENIRQ_N_TYPE "altera_avalon_pio"
#define TOUCH_PANEL_PENIRQ_N_BASE 0x080000c0
#define TOUCH_PANEL_PENIRQ_N_SPAN 16
#define TOUCH_PANEL_PENIRQ_N_IRQ 4
#define TOUCH_PANEL_PENIRQ_N_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TOUCH_PANEL_PENIRQ_N_DO_TEST_BENCH_WIRING 0
#define TOUCH_PANEL_PENIRQ_N_DRIVEN_SIM_VALUE 0
#define TOUCH_PANEL_PENIRQ_N_HAS_TRI 0
#define TOUCH_PANEL_PENIRQ_N_HAS_OUT 0
#define TOUCH_PANEL_PENIRQ_N_HAS_IN 1
#define TOUCH_PANEL_PENIRQ_N_CAPTURE 1
#define TOUCH_PANEL_PENIRQ_N_DATA_WIDTH 1
#define TOUCH_PANEL_PENIRQ_N_RESET_VALUE 0
#define TOUCH_PANEL_PENIRQ_N_EDGE_TYPE "FALLING"
#define TOUCH_PANEL_PENIRQ_N_IRQ_TYPE "EDGE"
#define TOUCH_PANEL_PENIRQ_N_BIT_CLEARING_EDGE_REGISTER 0
#define TOUCH_PANEL_PENIRQ_N_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TOUCH_PANEL_PENIRQ_N_FREQ 10000000
#define ALT_MODULE_CLASS_touch_panel_penirq_n altera_avalon_pio

/*
 * irm configuration
 *
 */

#define IRM_NAME "/dev/irm"
#define IRM_TYPE "TERASIC_IRM"
#define IRM_BASE 0x080000f0
#define IRM_SPAN 4
#define IRM_IRQ 5
#define IRM_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ALT_MODULE_CLASS_irm TERASIC_IRM

/*
 * sd_clk configuration
 *
 */

#define SD_CLK_NAME "/dev/sd_clk"
#define SD_CLK_TYPE "altera_avalon_pio"
#define SD_CLK_BASE 0x09000060
#define SD_CLK_SPAN 16
#define SD_CLK_DO_TEST_BENCH_WIRING 0
#define SD_CLK_DRIVEN_SIM_VALUE 0
#define SD_CLK_HAS_TRI 0
#define SD_CLK_HAS_OUT 1
#define SD_CLK_HAS_IN 0
#define SD_CLK_CAPTURE 0
#define SD_CLK_DATA_WIDTH 1
#define SD_CLK_RESET_VALUE 0
#define SD_CLK_EDGE_TYPE "NONE"
#define SD_CLK_IRQ_TYPE "NONE"
#define SD_CLK_BIT_CLEARING_EDGE_REGISTER 0
#define SD_CLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SD_CLK_FREQ 80000000
#define ALT_MODULE_CLASS_sd_clk altera_avalon_pio

/*
 * sd_cmd configuration
 *
 */

#define SD_CMD_NAME "/dev/sd_cmd"
#define SD_CMD_TYPE "altera_avalon_pio"
#define SD_CMD_BASE 0x09000040
#define SD_CMD_SPAN 16
#define SD_CMD_DO_TEST_BENCH_WIRING 0
#define SD_CMD_DRIVEN_SIM_VALUE 0
#define SD_CMD_HAS_TRI 1
#define SD_CMD_HAS_OUT 0
#define SD_CMD_HAS_IN 0
#define SD_CMD_CAPTURE 0
#define SD_CMD_DATA_WIDTH 1
#define SD_CMD_RESET_VALUE 0
#define SD_CMD_EDGE_TYPE "NONE"
#define SD_CMD_IRQ_TYPE "NONE"
#define SD_CMD_BIT_CLEARING_EDGE_REGISTER 0
#define SD_CMD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SD_CMD_FREQ 80000000
#define ALT_MODULE_CLASS_sd_cmd altera_avalon_pio

/*
 * sd_dat configuration
 *
 */

#define SD_DAT_NAME "/dev/sd_dat"
#define SD_DAT_TYPE "altera_avalon_pio"
#define SD_DAT_BASE 0x09000020
#define SD_DAT_SPAN 16
#define SD_DAT_DO_TEST_BENCH_WIRING 0
#define SD_DAT_DRIVEN_SIM_VALUE 0
#define SD_DAT_HAS_TRI 1
#define SD_DAT_HAS_OUT 0
#define SD_DAT_HAS_IN 0
#define SD_DAT_CAPTURE 0
#define SD_DAT_DATA_WIDTH 4
#define SD_DAT_RESET_VALUE 0
#define SD_DAT_EDGE_TYPE "NONE"
#define SD_DAT_IRQ_TYPE "NONE"
#define SD_DAT_BIT_CLEARING_EDGE_REGISTER 0
#define SD_DAT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SD_DAT_FREQ 80000000
#define ALT_MODULE_CLASS_sd_dat altera_avalon_pio

/*
 * sd_wp_n configuration
 *
 */

#define SD_WP_N_NAME "/dev/sd_wp_n"
#define SD_WP_N_TYPE "altera_avalon_pio"
#define SD_WP_N_BASE 0x09000000
#define SD_WP_N_SPAN 16
#define SD_WP_N_DO_TEST_BENCH_WIRING 0
#define SD_WP_N_DRIVEN_SIM_VALUE 0
#define SD_WP_N_HAS_TRI 0
#define SD_WP_N_HAS_OUT 0
#define SD_WP_N_HAS_IN 1
#define SD_WP_N_CAPTURE 0
#define SD_WP_N_DATA_WIDTH 1
#define SD_WP_N_RESET_VALUE 0
#define SD_WP_N_EDGE_TYPE "NONE"
#define SD_WP_N_IRQ_TYPE "NONE"
#define SD_WP_N_BIT_CLEARING_EDGE_REGISTER 0
#define SD_WP_N_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SD_WP_N_FREQ 80000000
#define ALT_MODULE_CLASS_sd_wp_n altera_avalon_pio

/*
 * clock_crossing_sdcard configuration
 *
 */

#define CLOCK_CROSSING_SDCARD_NAME "/dev/clock_crossing_sdcard"
#define CLOCK_CROSSING_SDCARD_TYPE "altera_avalon_clock_crossing"
#define CLOCK_CROSSING_SDCARD_BASE 0x09000000
#define CLOCK_CROSSING_SDCARD_SPAN 128
#define CLOCK_CROSSING_SDCARD_UPSTREAM_FIFO_DEPTH 512
#define CLOCK_CROSSING_SDCARD_DOWNSTREAM_FIFO_DEPTH 32
#define CLOCK_CROSSING_SDCARD_DATA_WIDTH 32
#define CLOCK_CROSSING_SDCARD_NATIVE_ADDRESS_WIDTH 5
#define CLOCK_CROSSING_SDCARD_USE_BYTE_ENABLE 1
#define CLOCK_CROSSING_SDCARD_USE_BURST_COUNT 0
#define CLOCK_CROSSING_SDCARD_MAXIMUM_BURST_SIZE 8
#define CLOCK_CROSSING_SDCARD_UPSTREAM_USE_REGISTER 0
#define CLOCK_CROSSING_SDCARD_DOWNSTREAM_USE_REGISTER 0
#define CLOCK_CROSSING_SDCARD_SLAVE_SYNCHRONIZER_DEPTH 3
#define CLOCK_CROSSING_SDCARD_MASTER_SYNCHRONIZER_DEPTH 3
#define CLOCK_CROSSING_SDCARD_DEVICE_FAMILY "CYCLONEIVE"
#define ALT_MODULE_CLASS_clock_crossing_sdcard altera_avalon_clock_crossing

/*
 * tri_state_bridge configuration
 *
 */

#define TRI_STATE_BRIDGE_NAME "/dev/tri_state_bridge"
#define TRI_STATE_BRIDGE_TYPE "altera_avalon_tri_state_bridge"
#define ALT_MODULE_CLASS_tri_state_bridge altera_avalon_tri_state_bridge

/*
 * cfi_flash configuration
 *
 */

#define CFI_FLASH_NAME "/dev/cfi_flash"
#define CFI_FLASH_TYPE "altera_avalon_cfi_flash"
#define CFI_FLASH_BASE 0x0a800000
#define CFI_FLASH_SPAN 8388608
#define CFI_FLASH_SETUP_VALUE 60
#define CFI_FLASH_WAIT_VALUE 160
#define CFI_FLASH_HOLD_VALUE 60
#define CFI_FLASH_TIMING_UNITS "ns"
#define CFI_FLASH_UNIT_MULTIPLIER 1
#define CFI_FLASH_SIZE 8388608
#define ALT_MODULE_CLASS_cfi_flash altera_avalon_cfi_flash

/*
 * MicroC/OS-II configuration
 *
 */

#define ALT_MAX_FD 32
#define OS_MAX_TASKS 10
#define OS_LOWEST_PRIO 20
#define OS_FLAG_EN 1
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_MUTEX_EN 1
#define OS_SEM_EN 1
#define OS_MBOX_EN 1
#define OS_Q_EN 1
#define OS_MEM_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_MAX_FLAGS 20
#define OS_FLAGS_NBITS 16
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_SET_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_MAX_QS 20
#define OS_MEM_QUERY_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MAX_MEM_PART 60
#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TICK_STEP_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_MAX_EVENTS 60
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TMR_EN 0
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TASK_TMR_STK_SIZE 512
#define OS_TASK_TMR_PRIO 1
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none
#define OS_TICKS_PER_SEC 100

/*
 * Devices associated with code sections.
 *
 */

#define ALT_TEXT_DEVICE       ONCHIP_MEM
#define ALT_RODATA_DEVICE     SDRAM
#define ALT_RWDATA_DEVICE     SDRAM
#define ALT_EXCEPTIONS_DEVICE ONCHIP_MEM
#define ALT_RESET_DEVICE      CFI_FLASH


#endif /* __SYSTEM_H_ */
