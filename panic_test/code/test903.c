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
				syscall(__NR_msgrcv, 0, 0ul, 0ul, 0ul, 0ul);
*(uint32_t*)0x20000340 = 0x798e2635;
*(uint32_t*)0x20000344 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint32_t*)0x2000034c = 0xee01;
*(uint32_t*)0x20000350 = 0;
*(uint32_t*)0x20000354 = 0;
*(uint16_t*)0x20000358 = 0;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint64_t*)0x20000370 = 0;
*(uint64_t*)0x20000378 = 0;
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint16_t*)0x20000398 = 0;
*(uint16_t*)0x2000039a = 0;
*(uint16_t*)0x2000039c = 0;
*(uint32_t*)0x200003a0 = -1;
*(uint32_t*)0x200003a4 = 0;
	syscall(__NR_msgctl, 0, 1ul, 0x20000340ul);
	return 0;
}
