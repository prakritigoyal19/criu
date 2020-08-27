#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/param.h>
#include <sys/mman.h>

//#include <ffi.h>

#include "uapi/flog.h"
#include "flog_util.h"
#include "cr_options.h"
#include "log.h"
#include "servicefd.h"

int flog_encode_msg(int loglevel, unsigned int nargs, unsigned int mask, const char *format, ...)
{
	va_list argptr;

	va_start(argptr, format);
	vprint_on_level(loglevel, format, argptr);
	va_end(argptr);
	return 0;
}
