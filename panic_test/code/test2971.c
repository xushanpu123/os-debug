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

#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint16_t*)0x20000480 = 2;
*(uint64_t*)0x20000488 = 0x20000440;
*(uint16_t*)0x20000440 = 0x25;
*(uint8_t*)0x20000442 = 0;
*(uint8_t*)0x20000443 = 0;
*(uint32_t*)0x20000444 = 0xfffffffa;
*(uint16_t*)0x20000448 = 6;
*(uint8_t*)0x2000044a = 0;
*(uint8_t*)0x2000044b = 0;
*(uint32_t*)0x2000044c = 0;
	syscall(__NR_seccomp, 1ul, 0ul, 0x20000480ul);
	return 0;
}
