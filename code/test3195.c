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

memcpy((void*)0x20000100, "./file1\000", 8);
	syscall(__NR_openat, 0xffffff9c, 0x20000100ul, 0x42ul, 0ul);
memcpy((void*)0x20000000, "./file1\000", 8);
*(uint64_t*)0x20000540 = 0x220c0;
*(uint64_t*)0x20000548 = 0;
*(uint64_t*)0x20000550 = 0;
	syscall(__NR_openat2, 0xffffffffffffff9cul, 0x20000000ul, 0x20000540ul, 0x18ul);
	return 0;
}
