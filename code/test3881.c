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

#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20001304 = 0;
*(uint32_t*)0x20001308 = 2;
*(uint32_t*)0x2000130c = 0;
*(uint32_t*)0x20001310 = 0;
*(uint32_t*)0x20001318 = -1;
memset((void*)0x2000131c, 0, 12);
	syscall(__NR_io_uring_setup, 0x2506, 0x20001300ul);
	return 0;
}
