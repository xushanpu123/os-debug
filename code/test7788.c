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

*(uint16_t*)0x20000240 = 1;
*(uint64_t*)0x20000248 = 0x20000200;
*(uint16_t*)0x20000200 = 6;
*(uint8_t*)0x20000202 = 0;
*(uint8_t*)0x20000203 = 0;
*(uint32_t*)0x20000204 = 0x7fffffff;
	syscall(__NR_seccomp, 1ul, 0ul, 0x20000240ul);
	syscall(__NR_getitimer, 0ul, 0x20000080ul);
	return 0;
}