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
memcpy((void*)0x20000000, "/dev/snd/timer\000", 15);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 1;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0;
memset((void*)0x20000054, 0, 32);
	syscall(__NR_ioctl, r[0], 0x40345410, 0x20000040ul);
*(uint32_t*)0x20000140 = 0;
*(uint32_t*)0x20000144 = 0xb5;
*(uint32_t*)0x20000148 = 0x68;
*(uint32_t*)0x2000014c = 0;
*(uint32_t*)0x20000150 = 0;
memset((void*)0x20000154, 0, 60);
	syscall(__NR_ioctl, r[0], 0x40505412, 0x20000140ul);
	return 0;
}
