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
memcpy((void*)0x20000640, "/sys/power/pm_trace", 19);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000640ul, 0x82001ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 0xa0;
*(uint8_t*)0x20000004 = 0x19;
*(uint16_t*)0x20000005 = 0;
*(uint64_t*)0x20000007 = 0;
*(uint8_t*)0x2000000f = 0;
*(uint32_t*)0x20000010 = 0;
*(uint64_t*)0x20000014 = 0;
*(uint32_t*)0x2000001c = 0;
*(uint32_t*)0x20000020 = -1;
*(uint32_t*)0x20000024 = 0xee00;
*(uint64_t*)0x20000028 = 0;
*(uint64_t*)0x20000030 = 0;
*(uint64_t*)0x20000038 = 0;
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
	syscall(__NR_write, r[0], 0x20000000ul, 0xa0ul);
	return 0;
}