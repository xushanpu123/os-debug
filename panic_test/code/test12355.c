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
	res = syscall(__NR_socket, 0x10ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_epoll_create1, 0ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000000 = 0;
*(uint64_t*)0x20000004 = 0;
	syscall(__NR_epoll_ctl, r[1], 1ul, r[0], 0x20000000ul);
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x200000c0ul);
	if (res != -1)
r[2] = *(uint32_t*)0x200000c4;
*(uint32_t*)0x20000180 = 0;
*(uint64_t*)0x20000184 = 0;
	syscall(__NR_epoll_ctl, r[1], 3ul, r[2], 0x20000180ul);
	return 0;
}
