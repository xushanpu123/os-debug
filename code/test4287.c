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

#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memset((void*)0x20000000, 0, 1);
	res = syscall(__NR_memfd_create, 0x20000000ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x200000c0 = 0;
*(uint16_t*)0x200000c2 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d8 = 0;
	syscall(__NR_fcntl, r[0], 0x25ul, 0x200000c0ul);
memcpy((void*)0x20000040, "security.", 9);
memset((void*)0x20000049, 0, 1);
	syscall(__NR_fremovexattr, r[0], 0x20000040ul);
	return 0;
}