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

#ifndef __NR_rseq
#define __NR_rseq 334
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint32_t*)0x20000050 = 0;
	syscall(__NR_rseq, 0x20000040ul, 0x20ul, 0ul, 0ul);
	syscall(__NR_lchown, 0ul, 0, 0);
memcpy((void*)0x20000040, "./file0\000", 8);
	syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x26e1ul, 0ul);
	syscall(__NR_dup3, -1, -1, 0ul);
	return 0;
}
