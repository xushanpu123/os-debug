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
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000004;
*(uint64_t*)0x20000700 = 0;
*(uint32_t*)0x20000708 = 0;
*(uint64_t*)0x20000710 = 0;
*(uint64_t*)0x20000718 = 0;
*(uint64_t*)0x20000720 = 0x20000740;
*(uint64_t*)0x20000740 = 0x10;
*(uint32_t*)0x20000748 = 0;
*(uint32_t*)0x2000074c = 0;
*(uint64_t*)0x20000728 = 0x10;
*(uint32_t*)0x20000730 = 0;
*(uint32_t*)0x20000738 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000700ul, 1ul, 0ul);
	return 0;
}
