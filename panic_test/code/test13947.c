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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000080, "(\000\237\004b\315\265D\003\233\0067\312|\312\213D\372\364\'^\021JT\326\211\016|[j\341*\"B\336\346\360\212@\321\037d\227\244\217G`\206\307\300\0027k\036:\320!\266\022b\276\365\370\360\365\023\025:\311E\027(\312/C\273\344XhME>\303\n", 84);
*(uint64_t*)0x20000100 = 0x7ff;
*(uint64_t*)0x20000108 = 5;
*(uint64_t*)0x20000110 = 0x800;
*(uint64_t*)0x20000118 = 7;
memset((void*)0x20000120, 0, 32);
	res = syscall(__NR_mq_open, 0x20000080ul, 0ul, 0x3ful, 0x20000100ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_mq_timedreceive, r[0], 0x20000140ul, 0x45ul, 0x594559c9ul, 0ul);
	return 0;
}