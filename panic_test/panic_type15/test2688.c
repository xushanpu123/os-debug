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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000080ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000080;
r[1] = *(uint32_t*)0x20000084;
	}
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
*(uint64_t*)0x20000198 = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_recvmsg, r[0], 0x20000180ul, 0ul, 0);
	res = syscall(__NR_dup3, r[0], r[1], 0ul);
	if (res != -1)
		r[2] = res;
	res = syscall(__NR_epoll_create, 0x200000);
	if (res != -1)
		r[3] = res;
*(uint32_t*)0x20000000 = 0;
*(uint64_t*)0x20000004 = 0;
	syscall(__NR_epoll_ctl, r[3], 1ul, r[0], 0x20000000ul);
*(uint16_t*)0x20000540 = 0;
memcpy((void*)0x20000542, "./file0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 108);
	syscall(__NR_connect, r[2], 0x20000540ul, 0x6eul);
	return 0;
}