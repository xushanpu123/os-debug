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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000000;
r[1] = *(uint32_t*)0x20000004;
	}
	syscall(__NR_recvfrom, r[1], 0x20000040ul, 0x91ul, 0ul, 0ul, 0ul);
*(uint64_t*)0x200004c0 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0x20000440;
*(uint64_t*)0x20000440 = 0x20000340;
memset((void*)0x20000340, 83, 1);
*(uint64_t*)0x20000448 = 1;
*(uint64_t*)0x200004d8 = 1;
*(uint64_t*)0x200004e0 = 0x20000480;
*(uint64_t*)0x20000480 = 0x14;
*(uint32_t*)0x20000488 = 1;
*(uint32_t*)0x2000048c = 1;
*(uint32_t*)0x20000490 = r[1];
*(uint64_t*)0x200004e8 = 0x18;
*(uint32_t*)0x200004f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200004c0ul, 0ul);
	return 0;
}