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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "/proc/sysvipc/sem\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "./file0\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x2661ul, 0ul);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_dup3, r[1], r[0], 0ul);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000280 = 8;
*(uint32_t*)0x20000284 = 2;
*(uint32_t*)0x20000288 = 0xe2;
*(uint32_t*)0x2000028c = 0xffffff81;
	syscall(__NR_open_by_handle_at, r[2], 0x20000280ul, 0ul);
	return 0;
}
