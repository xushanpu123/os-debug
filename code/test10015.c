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
memcpy((void*)0x20000000, ".log\000", 5);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000000ul, 0x101541ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 3;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint32_t*)0x200000e0 = 0;
*(uint16_t*)0x200000e4 = 0;
*(uint16_t*)0x200000e6 = 0;
	syscall(__NR_ioctl, r[0], 0x40286608, 0x200000c0ul);
	return 0;
}
