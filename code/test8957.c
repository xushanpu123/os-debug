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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000004;
	res = syscall(__NR_gettid);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20002080 = 0;
*(uint32_t*)0x20002088 = 0;
*(uint64_t*)0x20002090 = 0;
*(uint64_t*)0x20002098 = 0;
*(uint64_t*)0x200020a0 = 0;
*(uint64_t*)0x200020a8 = 0;
*(uint32_t*)0x200020b0 = 0;
*(uint32_t*)0x200020b8 = 0;
*(uint64_t*)0x200020c0 = 0x200001c0;
*(uint16_t*)0x200001c0 = 1;
*(uint8_t*)0x200001c2 = 0;
*(uint32_t*)0x200001c4 = 0;
*(uint32_t*)0x200020c8 = 0x6e;
*(uint64_t*)0x200020d0 = 0;
*(uint64_t*)0x200020d8 = 0;
*(uint64_t*)0x200020e0 = 0x20000080;
*(uint64_t*)0x20000080 = 0x1c;
*(uint32_t*)0x20000088 = 1;
*(uint32_t*)0x2000008c = 2;
*(uint32_t*)0x20000090 = r[1];
*(uint32_t*)0x20000094 = 0xee00;
*(uint32_t*)0x20000098 = 0;
*(uint64_t*)0x200020e8 = 0x20;
*(uint32_t*)0x200020f0 = 0;
*(uint32_t*)0x200020f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002080ul, 2ul, 0ul);
	return 0;
}
