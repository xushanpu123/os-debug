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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "./file1\000", 8);
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x200000c0 = 0;
	syscall(__NR_execveat, 0xffffff9c, 0x20000040ul, 0x20000080ul, 0x200000c0ul, 0ul);
memcpy((void*)0x20000100, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000100ul, 0x42ul, 0x1fful);
	if (res != -1)
		r[0] = res;
	syscall(__NR_close, r[0]);
memcpy((void*)0x20000140, "./file1\000", 8);
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x200001c0 = 0;
	syscall(__NR_execveat, 0xffffff9c, 0x20000140ul, 0x20000180ul, 0x200001c0ul, 0ul);
memcpy((void*)0x20000200, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000200ul, 2ul, 0ul);
	if (res != -1)
		r[1] = res;
memset((void*)0x20000240, 1, 4);
	syscall(__NR_write, r[1], 0x20000240ul, 4ul);
	syscall(__NR_close, r[1]);
memcpy((void*)0x20000280, "./file1\000", 8);
*(uint64_t*)0x200002c0 = 0;
*(uint64_t*)0x20000300 = 0;
	syscall(__NR_execveat, 0xffffff9c, 0x20000280ul, 0x200002c0ul, 0x20000300ul, 0ul);
memcpy((void*)0x20000340, "./file0\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000340ul, 0x42ul, 0ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_close, r[2]);
memcpy((void*)0x20000380, "./file1\000", 8);
*(uint64_t*)0x200003c0 = 0;
*(uint64_t*)0x20000400 = 0;
	syscall(__NR_execveat, 0xffffff9c, 0x20000380ul, 0x200003c0ul, 0x20000400ul, 0ul);
memcpy((void*)0x20000440, "./file0\000", 8);
	syscall(__NR_fchmodat, 0xffffff9c, 0x20000440ul, 0x1fful);
memcpy((void*)0x20000480, "./file1\000", 8);
*(uint64_t*)0x200004c0 = 0;
*(uint64_t*)0x20000500 = 0;
	syscall(__NR_execveat, 0xffffff9c, 0x20000480ul, 0x200004c0ul, 0x20000500ul, 0ul);
	return 0;
}
