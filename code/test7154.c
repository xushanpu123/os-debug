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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_epoll_create1, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "/dev/hpet\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c4 = 0;
	syscall(__NR_epoll_ctl, r[0], 1ul, r[1], 0x200000c0ul);
	return 0;
}
