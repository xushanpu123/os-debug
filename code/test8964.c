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

#ifndef __NR_execveat
#define __NR_execveat 322
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000080, "./file0\000", 8);
*(uint64_t*)0x200000c0 = 0xffffffffff600000;
*(uint64_t*)0x20000180 = 0x20000100;
memcpy((void*)0x20000100, "}-%*\000", 5);
*(uint64_t*)0x20000188 = 0x20000140;
memcpy((void*)0x20000140, "{\000", 2);
	syscall(__NR_execveat, -1, 0x20000080ul, 0x200000c0ul, 0x20000180ul, 0ul);
	return 0;
}
