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
memcpy((void*)0x20000240, "/dev/ptp0\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000240ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000280 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
*(uint64_t*)0x20000290 = 0xfffffffffffffffd;
*(uint32_t*)0x20000298 = 0;
*(uint32_t*)0x2000029c = 0;
*(uint32_t*)0x200002a0 = 0;
*(uint32_t*)0x200002a4 = 3;
memset((void*)0x200002a8, 0, 16);
	syscall(__NR_ioctl, r[0], 0x40383d0c, 0x20000280ul);
	return 0;
}
