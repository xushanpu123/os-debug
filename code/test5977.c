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

#ifndef __NR_close_range
#define __NR_close_range 436
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_close_range, -1, -1, 2ul);
*(uint32_t*)0x20000180 = 1;
*(uint32_t*)0x20000184 = 1;
*(uint32_t*)0x20000188 = 0x18;
*(uint32_t*)0x2000018c = -1;
*(uint32_t*)0x20000190 = 0xee00;
*(uint32_t*)0x20000194 = -1;
memcpy((void*)0x20000198, "./file1\000", 8);
	syscall(__NR_ioctl, -1, 0xc018937b, 0x20000180ul);
*(uint32_t*)0x20000140 = -1;
*(uint16_t*)0x20000144 = 0;
*(uint16_t*)0x20000146 = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0x989680;
	syscall(__NR_ppoll, 0x20000140ul, 0x20000000000000d0ul, 0x20000280ul, 0ul, 0ul);
	return 0;
}
