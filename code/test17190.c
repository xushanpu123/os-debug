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

*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0;
*(uint32_t*)0x20000058 = -1;
memset((void*)0x2000005c, 0, 12);
	syscall(__NR_io_uring_setup, 0x7358, 0x20000040ul);
*(uint32_t*)0x20004b04 = 0x87f8;
*(uint32_t*)0x20004b08 = 0;
*(uint32_t*)0x20004b0c = 0;
*(uint32_t*)0x20004b10 = 0;
*(uint32_t*)0x20004b18 = -1;
memset((void*)0x20004b1c, 0, 12);
	syscall(__NR_io_uring_setup, 0x233e, 0x20004b00ul);
	return 0;
}