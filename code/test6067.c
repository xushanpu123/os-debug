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
memcpy((void*)0x200000c0, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200000c0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x4c81, 0ul);
	syscall(__NR_ioctl, -1, 0xc0605345, 0ul);
	syscall(__NR_ioctl, -1, 0xc04c5349, 0ul);
	syscall(__NR_ioctl, -1, 0x2275, 0ul);
memcpy((void*)0x20000180, "filter\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint32_t*)0x200001a0 = 0xe;
*(uint32_t*)0x200001a4 = 5;
*(uint32_t*)0x200001a8 = 0x92e;
*(uint64_t*)0x200001b0 = 0;
*(uint64_t*)0x200001b8 = 0x200003c0;
*(uint64_t*)0x200001c0 = 0x20000606;
*(uint64_t*)0x200001c8 = 0x20000982;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint32_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint64_t*)0x200001f0 = 0;
	syscall(__NR_setsockopt, -1, 0, 0x80, 0x20000180ul, 0xa46ul);
	return 0;
}
