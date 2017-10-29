/* Definitions for Intel 386 running SunOS 4.0.
   Copyright (C) 1988 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.  No author or distributor
accepts responsibility to anyone for the consequences of using it
or for whether it serves any particular purpose or works at all,
unless he says so in writing.  Refer to the GNU CC General Public
License for full details.

Everyone is granted permission to copy, modify and redistribute
GNU CC, but only under the conditions described in the
GNU CC General Public License.   A copy of this license is
supposed to have been given to you along with GNU CC so you
can know your rights and responsibilities.  It should be in a
file named COPYING.  Among other things, the copyright notice
and this notice must be preserved on all copies.  */


#include "tm-i386.h"

/* Use the Sun assembler syntax.  */

#include "tm-sun386.h"

/* By default, target has a 80387.  */

#define TARGET_DEFAULT 1

/* Use crt0.o as a startup file.  */

#define STARTFILE_SPEC  \
  "%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"

#define LIB_SPEC "%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"

/* Extra switches to give the assembler.  */

#define ASM_SPEC "-i386"

/* Specify predefined symbols in preprocessor.  */

#define CPP_PREDEFINES "-Dunix -Di386 -Dsun386"

/* Allow #ident and #sccs in preprocessor.  */

#define IDENT_DIRECTIVE
#define SCCS_DIRECTIVE

/* We don't want to output SDB debugging information.  */

#undef SDB_DEBUGGING_INFO

/* We want to output DBX debugging information.  */

#define DBX_DEBUGGING_INFO

/* Implicit library calls should use memcpy, not bcopy, etc.  */

#define TARGET_MEM_FUNCTIONS


/* Define how to find the value returned by a function.
   VALTYPE is the data type of the value (as a tree).
   If the precise function being called is known, FUNC is its FUNCTION_DECL;
   otherwise, FUNC is 0.  */

#define VALUE_REGNO(MODE) \
  (((MODE)==SFmode || (MODE)==DFmode) ? FIRST_FLOAT_REG : 0)

/* 1 if N is a possible register number for a function value. */

#define FUNCTION_VALUE_REGNO_P(N) ((N) == 0 || (N)== FIRST_FLOAT_REG)

/* This is partly guess.  */

#undef DBX_REGISTER_NUMBER
#define DBX_REGISTER_NUMBER(n) \
((n) == 1 ? 2 : (n) == 2 ? 1 : (n) < 8 ? (n) : 12)

/* Every debugger symbol must be in the text section.
   Otherwise the assembler or the linker screws up.  */

#define DEBUG_SYMS_TEXT
