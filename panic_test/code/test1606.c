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

#ifndef __NR_openat2
#define __NR_openat2 437
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20001a40, "./file0\000", 8);
	syscall(__NR_open, 0x20001a40ul, 0ul, 0ul);
memcpy((void*)0x20000440, "./file0\000", 8);
*(uint64_t*)0x20000480 = 0x840;
*(uint64_t*)0x20000488 = 0;
*(uint64_t*)0x20000490 = 0x12;
	syscall(__NR_openat2, 0xffffffffffffff9cul, 0x20000440ul, 0x20000480ul, 0x18ul);
	return 0;
}
