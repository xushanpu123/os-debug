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

*(uint32_t*)0x20000740 = 0x19980330;
*(uint32_t*)0x20000744 = 0;
*(uint32_t*)0x20000780 = 0;
*(uint32_t*)0x20000784 = 0;
*(uint32_t*)0x20000788 = 0;
*(uint32_t*)0x2000078c = 0;
*(uint32_t*)0x20000790 = 0;
*(uint32_t*)0x20000794 = 0;
	syscall(__NR_capset, 0x20000740ul, 0x20000780ul);
*(uint32_t*)0x200003c0 = 0x20080522;
*(uint32_t*)0x200003c4 = 0;
*(uint32_t*)0x20000400 = 0;
*(uint32_t*)0x20000404 = 0;
*(uint32_t*)0x20000408 = 0;
*(uint32_t*)0x2000040c = 0;
*(uint32_t*)0x20000410 = 0;
*(uint32_t*)0x20000414 = 0xaaf4;
	syscall(__NR_capset, 0x200003c0ul, 0x20000400ul);
	return 0;
}