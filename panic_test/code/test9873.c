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
	res = syscall(__NR_socketpair, 1ul, 5ul, 0, 0x200000c0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200000c0;
r[1] = *(uint32_t*)0x200000c4;
	}
*(uint64_t*)0x20002b80 = 0;
*(uint32_t*)0x20002b88 = 0;
*(uint64_t*)0x20002b90 = 0;
*(uint64_t*)0x20002b98 = 0;
*(uint64_t*)0x20002ba0 = 0x200002c0;
*(uint64_t*)0x20002ba8 = 0x20;
*(uint32_t*)0x20002bb0 = 0;
*(uint32_t*)0x20002bb8 = 0;
*(uint64_t*)0x20002bc0 = 0;
*(uint32_t*)0x20002bc8 = 0;
*(uint64_t*)0x20002bd0 = 0;
*(uint64_t*)0x20002bd8 = 0;
*(uint64_t*)0x20002be0 = 0x20002140;
*(uint64_t*)0x20002be8 = 0;
*(uint32_t*)0x20002bf0 = 0;
*(uint32_t*)0x20002bf8 = 0;
	syscall(__NR_recvmmsg, r[0], 0x20002b80ul, 2ul, 0x40000002ul, 0ul);
*(uint64_t*)0x200022c0 = 0;
*(uint32_t*)0x200022c8 = 0;
*(uint64_t*)0x200022d0 = 0;
*(uint64_t*)0x200022d8 = 0;
*(uint64_t*)0x200022e0 = 0x200005c0;
*(uint64_t*)0x200005c0 = 0x14;
*(uint32_t*)0x200005c8 = 1;
*(uint32_t*)0x200005cc = 1;
*(uint32_t*)0x200005d0 = r[0];
*(uint64_t*)0x200022e8 = 0x18;
*(uint32_t*)0x200022f0 = 0;
*(uint32_t*)0x200022f8 = 0;
	syscall(__NR_sendmmsg, r[1], 0x200022c0ul, 1ul, 0ul);
	return 0;
}
