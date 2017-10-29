#include "tm-m68k.h"

/* See tm-m68k.h.  0 means 68000 with no 68881.  */

#define TARGET_DEFAULT 0

/* Define __HAVE_FPU__ in preprocessor, unless -msoft-float is specified.
   This will control the use of inline 68881 insns in certain macros.
   Also inform the program which CPU this is for.  */

#define CPP_SPEC "%{!msoft-float:-D__HAVE_68881__} \
%{m68020:-Dmc68020}%{mc68020:-Dmc68020}%{!mc68020:%{!m68020:-Dmc68010}}"

/* -m68020 requires special flags to the assembler.  */

#define ASM_SPEC \
 "%{m68020:-mc68020}%{mc68020:-mc68020}%{!mc68020:%{!m68020:-mc68010}}"

/* Names to predefine in the preprocessor for this target machine.  */

#define CPP_PREDEFINES "-Dmc68000 -Dsun -Dunix"

/* Alignment of field after `int : 0' in a structure.  */

#undef EMPTY_FIELD_BOUNDARY
#define EMPTY_FIELD_BOUNDARY 16

/* Every structure or union's size must be a multiple of 2 bytes.  */

#define STRUCTURE_SIZE_BOUNDARY 16

/* This is BSD, so it wants DBX format.  */

#define DBX_DEBUGGING_INFO
