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

*(uint32_t*)0x20000944 = 0;
*(uint32_t*)0x20000948 = 0;
*(uint32_t*)0x2000094c = 0;
*(uint32_t*)0x20000950 = 0;
*(uint32_t*)0x20000958 = -1;
memset((void*)0x2000095c, 0, 12);
	syscall(__NR_io_uring_setup, 0x3022, 0x20000940ul);
	return 0;
}