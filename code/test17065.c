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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000140ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000144;
*(uint64_t*)0x200003c0 = 0xffffffff81000000;
*(uint32_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0x20000340;
*(uint64_t*)0x20000340 = 0x20000000;
*(uint32_t*)0x20000000 = 0x14;
*(uint16_t*)0x20000004 = 0;
*(uint16_t*)0x20000006 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 1;
*(uint8_t*)0x20000011 = 0;
*(uint16_t*)0x20000012 = 0;
*(uint64_t*)0x20000348 = 0xfffffda3;
*(uint64_t*)0x200003d8 = 1;
*(uint64_t*)0x200003e0 = 0;
*(uint64_t*)0x200003e8 = 0;
*(uint32_t*)0x200003f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200003c0ul, 0x40ul);
	return 0;
}