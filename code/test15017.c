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
*(uint32_t*)0x20000040 = htobe32(0xe0000002);
*(uint8_t*)0x20000044 = 0xac;
*(uint8_t*)0x20000045 = 0x1e;
*(uint8_t*)0x20000046 = 0;
*(uint8_t*)0x20000047 = 1;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 3;
	syscall(__NR_setsockopt, r[0], 0, 0x29, 0x20000040ul, 0x12ul);
	return 0;
}
