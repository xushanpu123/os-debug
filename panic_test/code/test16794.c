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

memcpy((void*)0x20000040, "\"\000", 2);
	syscall(__NR_prctl, 0xful, 0x20000040ul, 0, 0, 0);
*(uint16_t*)0x20000180 = 1;
*(uint64_t*)0x20000188 = 0x20000140;
*(uint16_t*)0x20000140 = 6;
*(uint8_t*)0x20000142 = 0;
*(uint8_t*)0x20000143 = 0;
*(uint32_t*)0x20000144 = 0;
	syscall(__NR_seccomp, 1ul, 0ul, 0x20000180ul);
	syscall(__NR_prctl, 0xful, 0ul, 0, 0, 0);
	return 0;
}