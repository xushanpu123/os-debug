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
	res = syscall(__NR_socketpair, 1ul, 5ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000004;
*(uint32_t*)0x20001f80 = 9;
	syscall(__NR_setsockopt, r[0], 1, 0x23, 0x20001f80ul, 4ul);
*(uint32_t*)0x20001500 = 0;
	syscall(__NR_getsockopt, r[0], 1, 0x3f, 0ul, 0x20001500ul);
	return 0;
}
