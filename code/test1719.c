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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000040ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000040;
r[1] = *(uint32_t*)0x20000044;
	}
*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0;
*(uint64_t*)0x20000258 = 0;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0x70;
*(uint32_t*)0x20000270 = 0;
	syscall(__NR_recvmsg, r[0], 0x20000240ul, 0ul, 0);
	syscall(__NR_close_range, r[1], -1, 0ul);
	return 0;
}
