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

#define MAGIC 0xABCDABCD

#define BUF_SIZE (1<<20)
static char _mbuf[BUF_SIZE];
static char *mbuf = _mbuf;
static char *fbuf;
static uint64_t fsize;
static uint64_t mbuf_size = sizeof(_mbuf);

int flog_encode_msg(int loglevel, unsigned int nargs, unsigned int mask, const char *format, ...)
{
	va_list argptr;

	va_start(argptr, format);
	vprint_on_level(loglevel, format, argptr);
	va_end(argptr);
	return 0;
}
