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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0;
*(uint64_t*)0x20000178 = 0;
*(uint64_t*)0x200001c0 = 3;
*(uint64_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint64_t*)0x200001f0 = 0;
*(uint64_t*)0x200001f8 = 0;
*(uint64_t*)0x20000200 = 0;
*(uint64_t*)0x20000208 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000140ul, 0ul, 0x200001c0ul, 0x20000200ul, 0ul);
	return 0;
}