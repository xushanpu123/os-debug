// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "~\032\302\307x\261n>\241\260uCTDB\327\201:\021h\257\247\261s\324\240\000\251\343\214\204\377\277\267{\006\365\r\004l\362\023\353\b\377\203\b\270^e\340\203;\215W\257\243\336/\266urT\006\271\b\367d\277\355\334\v\347\210\333o\257\375\271\274\3638~/c\023\370\021\340\251\351\365\277$\237v\237\020S\024qz2\215h\313h\365a\v\226i\243\3207\026h\254\207\227\006\261\301\tq\331\026\234\224\355\3247\235jX\305\216\262vY\315\222\001l\204\220n>\230\311\202W\377\330^\326\177\177<\030\374A\227\n\264\275\201\266PJ\t\200U\267ow{z\264\022\246\"k\217\254\346Z8j;}?o\023w\341:\373\375\027\347\346^\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 219);
	res = syscall(__NR_memfd_create, 0x20000040ul, 5ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_fchmod, r[0], 0ul);
	return 0;
}
