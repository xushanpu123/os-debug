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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000140, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000140ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_close_range, -1, -1, 2ul);
*(uint32_t*)0x20001c80 = r[0];
*(uint16_t*)0x20001c84 = 0;
*(uint16_t*)0x20001c86 = 0;
	syscall(__NR_poll, 0x20001c80ul, 1ul, 0);
	return 0;
}
