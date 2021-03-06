/*
 *  linux/kernel/printk.c
 *
 *  (C) 1991  Linus Torvalds
 */

/*
 * When in kernel-mode, we cannot use printf, as fs is liable to
 * point to 'interesting' things. Make a printf with fs-saving, and
 * all is well.
 */
#include "stdarg.h"
#include "string.h"

static char buf[1024];

extern int vsprintf(char * buf, const char * fmt, va_list args);
extern void putc(const char c);

int printk(const char *fmt, ...)
{
	va_list args;
	int i;

	va_start(args, fmt);
	i=vsprintf(buf,fmt,args);
	va_end(args);

    int len = strlen(buf);

    for (i=0; i<len; i++) {
        putc(buf[i]);
    }

    return len;
}

