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
memcpy((void*)0x20000780, "./file0\000", 8);
	res = syscall(__NR_open, 0x20000780ul, 0xa8dc2ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000500 = 0x20000000;
memset((void*)0x20000000, 255, 1);
*(uint64_t*)0x20000508 = 1;
	syscall(__NR_pwritev, r[0], 0x20000500ul, 1ul, 0, 0);
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0x8000;
*(uint32_t*)0x20000050 = 0;
*(uint32_t*)0x20000054 = 0;
*(uint32_t*)0x20000058 = 1;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
memset((void*)0x20000078, 0, 16);
*(uint32_t*)0x20000088 = 0;
memset((void*)0x2000008c, 0, 12);
	syscall(__NR_ioctl, r[0], 0xc020662a, 0x20000040ul);
	return 0;
}
