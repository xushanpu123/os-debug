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
memcpy((void*)0x20000000, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 0;
*(uint32_t*)0x20000104 = 8;
*(uint32_t*)0x20000108 = 7;
*(uint32_t*)0x2000010c = 0;
*(uint32_t*)0x20000110 = 0x10000;
*(uint32_t*)0x20000114 = 0xfffffffe;
*(uint32_t*)0x20000118 = 0x3f;
memset((void*)0x2000011c, 0, 64);
	syscall(__NR_ioctl, r[0], 0x402c5342, 0x20000100ul);
	return 0;
}
