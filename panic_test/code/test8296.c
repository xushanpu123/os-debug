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

#ifndef __NR_close_range
#define __NR_close_range 436
#endif

uint64_t r[3] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_getpgrp, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000040 = 5;
	syscall(__NR_sched_setaffinity, r[0], 8ul, 0x20000040ul);
	res = syscall(__NR_pipe, 0x20000240ul);
	if (res != -1) {
r[1] = *(uint32_t*)0x20000240;
r[2] = *(uint32_t*)0x20000244;
	}
	syscall(__NR_poll, 0ul, 0ul, 0xfffff801);
	syscall(__NR_read, r[1], 0x20000380ul, 0x1000ul);
	syscall(__NR_close_range, r[2], -1, 0ul);
	return 0;
}
