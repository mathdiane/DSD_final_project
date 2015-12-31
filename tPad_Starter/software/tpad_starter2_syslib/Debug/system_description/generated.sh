#!/bin/sh
#
# generated.sh - shell script fragment - not very useful on its own
#
# Machine generated for a CPU named "cpu" as defined in:
# f:\dsdFinalProject\tPad_Starter\software\tpad_starter2_syslib\..\..\tPad_Starter_SOPC.ptf
#
# Generated: 2015-12-16 17:57:39.706

# DO NOT MODIFY THIS FILE
#
#   Changing this file will have subtle consequences
#   which will almost certainly lead to a nonfunctioning
#   system. If you do modify this file, be aware that your
#   changes will be overwritten and lost when this file
#   is generated again.
#
# DO NOT MODIFY THIS FILE

# This variable indicates where the PTF file for this design is located
ptf=f:\dsdFinalProject\tPad_Starter\software\tpad_starter2_syslib\..\..\tPad_Starter_SOPC.ptf

# This variable indicates whether there is a CPU debug core
nios2_debug_core=yes

# This variable indicates how to connect to the CPU debug core
nios2_instance=0

# This variable indicates the CPU module name
nios2_cpu_name=cpu

# These variables indicate what the System ID peripheral should hold
sidp=0x080000e0
id=58678540u
timestamp=1283946474u

# Include operating system specific parameters, if they are supplied.

if test -f /cygdrive/c/altera/10.1sp1/nios2eds/components/micrium_uc_osii/build/os.sh ; then
   . /cygdrive/c/altera/10.1sp1/nios2eds/components/micrium_uc_osii/build/os.sh
fi
