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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "/proc/mdstat\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_pipe, 0x20000200ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20000200;
*(uint32_t*)0x200000c0 = r[1];
*(uint16_t*)0x200000c4 = 0;
*(uint16_t*)0x200000c6 = 0;
*(uint32_t*)0x200000c8 = r[0];
*(uint16_t*)0x200000cc = 0xa081;
*(uint16_t*)0x200000ce = 0;
*(uint64_t*)0x20000100 = 0x77359400;
*(uint64_t*)0x20000108 = 0;
	syscall(__NR_ppoll, 0x200000c0ul, 2ul, 0x20000100ul, 0ul, 0ul);
	return 0;
}
