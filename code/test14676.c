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

uint64_t r[3] = {0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000004;
	res = syscall(__NR_fstat, r[0], 0x20000040ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20000058;
	syscall(__NR_setuid, r[1]);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20002e00 = 0;
*(uint32_t*)0x20002e08 = 0;
*(uint64_t*)0x20002e10 = 0;
*(uint64_t*)0x20002e18 = 0;
*(uint64_t*)0x20002e20 = 0;
*(uint64_t*)0x20002e28 = 0;
*(uint32_t*)0x20002e30 = 0;
*(uint32_t*)0x20002e38 = 0;
*(uint64_t*)0x20002e40 = 0x20000380;
*(uint16_t*)0x20000380 = 0x10;
*(uint16_t*)0x20000382 = 0;
*(uint32_t*)0x20000384 = 0x25dfdbfe;
*(uint32_t*)0x20000388 = 0;
*(uint32_t*)0x20002e48 = 0x80;
*(uint64_t*)0x20002e50 = 0;
*(uint64_t*)0x20002e58 = 0;
*(uint64_t*)0x20002e60 = 0;
*(uint64_t*)0x20002e68 = 0;
*(uint32_t*)0x20002e70 = 0;
*(uint32_t*)0x20002e78 = 0;
	syscall(__NR_sendmmsg, r[2], 0x20002e00ul, 2ul, 0ul);
	return 0;
}
