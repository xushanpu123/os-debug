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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x200003c0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200003c0;
r[1] = *(uint32_t*)0x200003c4;
	}
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_recvmsg, r[0], 0x20000380ul, 0x2102ul, 0);
*(uint64_t*)0x20001780 = 0;
*(uint32_t*)0x20001788 = 0;
*(uint64_t*)0x20001790 = 0x20000280;
*(uint64_t*)0x20000280 = 0x20000400;
memset((void*)0x20000400, 3, 1);
*(uint64_t*)0x20000288 = 1;
*(uint64_t*)0x20001798 = 1;
*(uint64_t*)0x200017a0 = 0;
*(uint64_t*)0x200017a8 = 0;
*(uint32_t*)0x200017b0 = 0;
*(uint32_t*)0x200017b8 = 0;
	syscall(__NR_sendmmsg, r[1], 0x20001780ul, 1ul, 0ul);
	return 0;
}