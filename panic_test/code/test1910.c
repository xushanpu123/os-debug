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
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000080ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000080;
r[1] = *(uint32_t*)0x20000084;
	}
*(uint64_t*)0x20000400 = 0;
*(uint32_t*)0x20000408 = 0;
*(uint64_t*)0x20000410 = 0;
*(uint64_t*)0x20000418 = 0;
*(uint64_t*)0x20000420 = 0x20004700;
*(uint64_t*)0x20000428 = 0x20;
*(uint32_t*)0x20000430 = 0;
*(uint32_t*)0x20000438 = 0;
	syscall(__NR_recvmmsg, r[0], 0x20000400ul, 1ul, 0ul, 0ul);
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000480 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint64_t*)0x20000490 = 0;
*(uint64_t*)0x20000498 = 0;
*(uint64_t*)0x200004a0 = 0x20000200;
*(uint64_t*)0x20000200 = 0x18;
*(uint32_t*)0x20000208 = 1;
*(uint32_t*)0x2000020c = 1;
*(uint32_t*)0x20000210 = r[2];
*(uint32_t*)0x20000214 = r[0];
*(uint64_t*)0x200004a8 = 0x18;
*(uint32_t*)0x200004b0 = 0;
	syscall(__NR_sendmsg, r[1], 0x20000480ul, 0ul);
	return 0;
}