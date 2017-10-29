/* Definitions for Compaq as target machine.  NOT TESTED!
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

/* Use the ATT assembler syntax.  */

#include "tm-att386.h"

/* By default, target has a 80387.  */

#define TARGET_DEFAULT 1

#define ASM_SPEC ""

/* Names to predefine in the preprocessor for this target machine.  */

#define CPP_PREDEFINES "-Di386 -Di80386 -Dunix"


#include "tm-i386.h"
#include "tm-att386.h"
