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
memcpy((void*)0x20000080, "/proc/self/exe\000", 15);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000080ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001800 = 0;
*(uint64_t*)0x20001808 = 0;
*(uint64_t*)0x20001810 = 0;
*(uint64_t*)0x20001818 = 0;
*(uint64_t*)0x20001820 = 0;
*(uint64_t*)0x20001828 = 0;
*(uint64_t*)0x20001830 = 0;
*(uint64_t*)0x20001838 = 0;
*(uint64_t*)0x20001840 = 0;
*(uint64_t*)0x20001848 = 0;
*(uint64_t*)0x20001850 = 0;
*(uint64_t*)0x20001858 = 0;
*(uint64_t*)0x20001860 = 0;
*(uint64_t*)0x20001868 = 0;
*(uint64_t*)0x20001870 = 0;
*(uint64_t*)0x20001878 = 0;
*(uint64_t*)0x20001880 = 0;
*(uint64_t*)0x20001888 = 0;
	syscall(__NR_pwritev, r[0], 0x20001800ul, 9ul, 0, 0);
	return 0;
}
