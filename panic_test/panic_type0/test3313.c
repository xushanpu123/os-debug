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

#ifndef __NR_io_uring_register
#define __NR_io_uring_register 427
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000440, "/dev/sr0\000", 9);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000440ul, 0x20881ul, 0ul);
*(uint32_t*)0x200004c0 = -1;
	syscall(__NR_io_uring_register, -1, 7ul, 0x200004c0ul, 1ul);
	syscall(__NR_write, -1, 0ul, 0ul);
	return 0;
}
