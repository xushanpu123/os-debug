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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_keyctl, 7ul, 0, 0, 0, 0);
	syscall(__NR_getpid);
	syscall(__NR_prlimit64, 0, 0ul, 0ul, 0ul);
	syscall(__NR_write, -1, 0ul, 0ul);
	res = syscall(__NR_getpid);
	if (res != -1)
		r[0] = res;
	syscall(__NR_openat, 0xffffff9c, 0ul, 2ul, 0ul);
	syscall(__NR_read, -1, 0ul, 0ul);
*(uint64_t*)0x20000000 = 0x20ffe000;
*(uint64_t*)0x20000008 = 0x20ffe000;
*(uint32_t*)0x20000100 = 0x81;
	syscall(__NR_move_pages, r[0], 2ul, 0x20000000ul, 0x20000100ul, 0ul, 0ul);
	return 0;
}