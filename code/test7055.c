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

#ifndef __NR_openat2
#define __NR_openat2 437
#endif
#ifndef __NR_pwritev2
#define __NR_pwritev2 328
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20001640, "./file0\000", 8);
*(uint64_t*)0x20001680 = 0x41;
*(uint64_t*)0x20001688 = 0;
*(uint64_t*)0x20001690 = 0;
	res = syscall(__NR_openat2, 0xffffff9c, 0x20001640ul, 0x20001680ul, 0x18ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000380 = 0x20000180;
memset((void*)0x20000180, 112, 1);
*(uint64_t*)0x20000388 = 1;
	syscall(__NR_pwritev2, r[0], 0x20000380ul, 1ul, 0x10000, 0, 0ul);
memcpy((void*)0x20001640, "./file0\000", 8);
*(uint64_t*)0x20001680 = 0x4841;
*(uint64_t*)0x20001688 = 0;
*(uint64_t*)0x20001690 = 0;
	res = syscall(__NR_openat2, 0xffffff9c, 0x20001640ul, 0x20001680ul, 0x18ul);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000280 = 0x20000240;
memset((void*)0x20000240, 85, 1);
*(uint64_t*)0x20000288 = 1;
	syscall(__NR_pwritev2, r[1], 0x20000280ul, 1ul, 0x2000000, 0, 0ul);
	return 0;
}
