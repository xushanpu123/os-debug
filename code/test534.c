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

#ifndef __NR_sched_setattr
#define __NR_sched_setattr 314
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_ptrace, 0x10ul, 1, 0, 0);
*(uint32_t*)0x20000040 = 0x38;
*(uint32_t*)0x20000044 = 6;
*(uint64_t*)0x20000048 = 0;
*(uint32_t*)0x20000050 = 0;
*(uint32_t*)0x20000054 = 0;
*(uint64_t*)0x20000058 = 0x8000000009917;
*(uint64_t*)0x20000060 = 0x400000000000fffd;
*(uint64_t*)0x20000068 = 0;
*(uint32_t*)0x20000070 = 0;
*(uint32_t*)0x20000074 = 0;
	syscall(__NR_sched_setattr, 0, 0x20000040ul, 0ul);
*(uint32_t*)0x20000080 = 0x38;
*(uint32_t*)0x20000084 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint32_t*)0x20000090 = -1;
*(uint32_t*)0x20000094 = 0;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
	syscall(__NR_sched_setattr, 0, 0x20000080ul, 0ul);
*(uint32_t*)0x200000c0 = 0x38;
*(uint32_t*)0x200000c4 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint32_t*)0x200000d0 = 1;
*(uint32_t*)0x200000d4 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f4 = 0;
	syscall(__NR_sched_setattr, 0, 0x200000c0ul, 0ul);
	return 0;
}