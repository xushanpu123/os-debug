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
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200005c0 = 0x20ffb000;
*(uint32_t*)0x200005c8 = 0x3000;
*(uint64_t*)0x200005d8 = 0;
*(uint32_t*)0x200005e0 = 0;
*(uint32_t*)0x200005e4 = 0;
*(uint64_t*)0x200005e8 = 0;
*(uint64_t*)0x200005f0 = 0;
*(uint32_t*)0x200005fc = 0;
*(uint32_t*)0x20000600 = 0x40;
	syscall(__NR_getsockopt, r[0], 6, 0x23, 0x200005c0ul, 0x20000600ul);
	return 0;
}