#include "tm-m68k.h"

/* See tm-m68k.h.  7 means 68020 with 68881.  */

#define TARGET_DEFAULT 7

/* Define __HAVE_FPA__ or __HAVE_68881__ in preprocessor,
   according to the -m flags.
   This will control the use of inline 68881 insns in certain macros.
   Also inform the program which CPU this is for.  */

#if TARGET_DEFAULT & 02

/* -m68881 is the default */
#define CPP_SPEC \
"%{!msoft-float:%{mfpa:-D__HAVE_FPA__ }%{!mfpa:-D__HAVE_68881__ }}\
%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}"

#else
#if TARGET_DEFAULT & 0100

/* -mfpa is the default */
#define CPP_SPEC \
"%{!msoft-float:%{m68881:-D__HAVE_68881__ }%{!m68881:-D__HAVE_FPA__ }}\
%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}"

#else

/* -msoft-float is the default */
#define CPP_SPEC \
"%{m68881:-D__HAVE_68881__ }%{mfpa:-D__HAVE_FPA__ }\
%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}"

#endif
#endif


/* -m68000 requires special flags to the assembler.  */

#define ASM_SPEC \
 "%{m68000:-mc68010}%{mc68000:-mc68010}%{!mc68000:%{!m68000:-mc68020}}"

/* Names to predefine in the preprocessor for this target machine.  */

#define CPP_PREDEFINES "-Dmc68000 -Dsun -Dunix"

/* STARTFILE_SPEC to include sun floating point initialization
   This is necessary (tr: Sun does it) for both the m68881 and the fpa
   routines.
   Note that includes knowledge of the default specs for gcc, ie. no
   args translates to the same effect as -m68881
   I'm not sure what would happen below if people gave contradictory
   arguments (eg. -msoft-float -mfpa) */

#if TARGET_DEFAULT & 0100
/* -mfpa is the default */
#define STARTFILE_SPEC					\
  "%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\
   %{m68881:Mcrt1.o%s}					\
   %{msoft-float:Fcrt1.o%s}				\
   %{!m68881:%{!msoft-float:Wcrt1.o%s}}"
#else
#if TARGET_DEFAULT & 2
/* -m68881 is the default */
#define STARTFILE_SPEC					\
  "%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\
   %{mfpa:Wcrt1.o%s}					\
   %{msoft-float:Fcrt1.o%s}				\
   %{!mfpa:%{!msoft-float:Mcrt1.o%s}}"
#else
/* -msoft-float is the default */
#define STARTFILE_SPEC					\
  "%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\
   %{m68881:Mcrt1.o%s}					\
   %{mfpa:Wcrt1.o%s}					\
   %{!m68881:%{!mfpa:Fcrt1.o%s}}"
#endif
#endif

/* Every structure or union's size must be a multiple of 2 bytes.  */

#define STRUCTURE_SIZE_BOUNDARY 16

/* This is BSD, so it wants DBX format.  */

#define DBX_DEBUGGING_INFO
