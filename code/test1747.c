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

#ifndef __NR_futex_waitv
#define __NR_futex_waitv 449
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x200001c0 = 0;
*(uint64_t*)0x200001c8 = 0;
*(uint32_t*)0x200001d0 = 0x82;
*(uint32_t*)0x200001d4 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint32_t*)0x200001e8 = 2;
*(uint32_t*)0x200001ec = 0;
*(uint64_t*)0x20000240 = 0x77359400;
*(uint64_t*)0x20000248 = 0;
	syscall(__NR_futex_waitv, 0x200001c0ul, 2ul, 0ul, 0x20000240ul, 0ul);
	return 0;
}
