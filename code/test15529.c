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

#ifndef __NR_rseq
#define __NR_rseq 334
#endif

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint32_t*)0x20000050 = 0;
	syscall(__NR_rseq, 0x20000040ul, 0x20ul, 0ul, 0ul);
	res = syscall(__NR_io_setup, 5, 0x20000000ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000000;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0x3938700;
	syscall(__NR_io_getevents, r[0], 4ul, 4ul, 0x20000140ul, 0x20000080ul);
	return 0;
}
