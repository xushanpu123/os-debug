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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20003080 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0xa;
*(uint16_t*)0x200000c2 = htobe16(0x4e24);
*(uint32_t*)0x200000c4 = htobe32(0);
memset((void*)0x200000c8, 0, 16);
*(uint32_t*)0x200000d8 = 0;
*(uint32_t*)0x20003088 = 0x80;
*(uint64_t*)0x20003090 = 0;
*(uint64_t*)0x20003098 = 0;
*(uint64_t*)0x200030a0 = 0;
*(uint64_t*)0x200030a8 = 0;
*(uint32_t*)0x200030b0 = 0;
*(uint32_t*)0x200030b8 = 0;
*(uint64_t*)0x200030c0 = 0x20000200;
*(uint16_t*)0x20000200 = 0;
*(uint16_t*)0x20000202 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x200030c8 = 0x80;
*(uint64_t*)0x200030d0 = 0;
*(uint64_t*)0x200030d8 = 0;
*(uint64_t*)0x200030e0 = 0;
*(uint64_t*)0x200030e8 = 0;
*(uint32_t*)0x200030f0 = 0;
*(uint32_t*)0x200030f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003080ul, 2ul, 0ul);
	return 0;
}
