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

#ifndef __NR_mlock2
#define __NR_mlock2 325
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memset((void*)0x20000340, 0, 32);
*(uint16_t*)0x20000360 = 0;
*(uint32_t*)0x20000364 = 0;
*(uint32_t*)0x20000368 = 0;
*(uint64_t*)0x20000370 = 0;
*(uint64_t*)0x20000378 = 0;
*(uint32_t*)0x20000380 = -1;
	syscall(__NR_ioctl, -1, 0xc0481273, 0x20000340ul);
	syscall(__NR_mlock, 0x20ffb000ul, 0x1000ul);
	syscall(__NR_mlock2, 0x20ffa000ul, 0x3000ul, 0ul);
	return 0;
}
