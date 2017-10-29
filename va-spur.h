/*  varargs.h for SPUR */

/* NB.  This is NOT the definition needed for the new ANSI proposed
   standard */
 

struct va_struct { char regs[20]; };

#define va_alist va_regs, va_stack

#define va_dcl struct va_struct va_regs; int va_stack;

typedef struct {
    int pnt;
    char *regs;
    char *stack;
} va_list;

#define va_start(pvar) \
     ((pvar).pnt = 0, (pvar).regs = va_regs.regs, \
      (pvar).stack = (char *) &va_stack)
#define va_end(pvar)

#define va_arg(pvar,type)  \
    ({  type va_result; \
        if ((pvar).pnt >= 20) { \
           va_result = *( (type *) ((pvar).stack + (pvar).pnt - 20)); \
	   (pvar).pnt += (sizeof(type) + 7) & ~7; \
	} \
	else if ((pvar).pnt + sizeof(type) > 20) { \
	   va_result = * (type *) (pvar).stack; \
	   (pvar).pnt = 20 + ( (sizeof(type) + 7) & ~7); \
	} \
	else if (sizeof(type) == 8) { \
	   union {double d; int i[2];} u; \
	   u.i[0] = *(int *) ((pvar).regs + (pvar).pnt); \
	   u.i[1] = *(int *) ((pvar).regs + (pvar).pnt + 4); \
	   va_result = * (type *) &u; \
	   (pvar).pnt += 8; \
	} \
	else { \
	   va_result = * (type *) ((pvar).regs + (pvar).pnt); \
	   (pvar).pnt += (sizeof(type) + 3) & ~3; \
	} \
	va_result; })
