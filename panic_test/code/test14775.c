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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "/sys/power/pm_async", 19);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x82001ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 0x8001, 0x200003c0ul);
	if (res != -1)
r[1] = *(uint64_t*)0x200003c0;
*(uint64_t*)0x20000040 = 0x200001c0;
*(uint64_t*)0x200001c0 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint16_t*)0x200001d0 = 1;
*(uint16_t*)0x200001d2 = 0;
*(uint32_t*)0x200001d4 = r[0];
*(uint64_t*)0x200001d8 = 0x20000080;
memcpy((void*)0x20000080, "6E", 2);
*(uint64_t*)0x200001e0 = 2;
*(uint64_t*)0x200001e8 = 0;
*(uint64_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f8 = 0;
*(uint32_t*)0x200001fc = -1;
	syscall(__NR_io_submit, r[1], 1ul, 0x20000040ul);
	return 0;
}
