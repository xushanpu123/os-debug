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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 4, 0x20000080ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000080;
	res = syscall(__NR_eventfd2, 0, 0x80800ul);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000440 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint16_t*)0x200000d0 = 0;
*(uint16_t*)0x200000d2 = 0;
*(uint32_t*)0x200000d4 = r[1];
*(uint64_t*)0x200000d8 = 0x20000040;
memcpy((void*)0x20000040, "\x2e\x43\x0f\xe9\xef\x69\x15\x7c", 8);
*(uint64_t*)0x200000e0 = 8;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f8 = 0;
*(uint32_t*)0x200000fc = -1;
	syscall(__NR_io_submit, r[0], 1ul, 0x20000440ul);
	return 0;
}
