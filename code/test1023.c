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
	res = syscall(__NR_socketpair, 1ul, 5ul, 0, 0x200001c0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200001c0;
r[1] = *(uint32_t*)0x200001c4;
	}
*(uint32_t*)0x20000000 = 0x78f;
	syscall(__NR_setsockopt, r[0], 1, 0x10, 0x20000000ul, 4ul);
*(uint64_t*)0x20000200 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0x20000180;
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000218 = 1;
*(uint64_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0;
*(uint32_t*)0x20000230 = 0;
	syscall(__NR_sendmsg, r[1], 0x20000200ul, 0ul);
	syscall(__NR_recvfrom, r[0], 0ul, 0ul, 0ul, 0ul, 0ul);
	return 0;
}
