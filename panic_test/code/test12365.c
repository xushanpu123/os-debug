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
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000180 = 0x20000700;
*(uint16_t*)0x20000700 = 0xa;
*(uint16_t*)0x20000702 = htobe16(0);
*(uint32_t*)0x20000704 = htobe32(0);
memset((void*)0x20000708, 0, 16);
*(uint32_t*)0x20000718 = 0;
*(uint32_t*)0x20000188 = 0x1c;
*(uint64_t*)0x20000190 = 0;
*(uint64_t*)0x20000198 = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b8 = 0;
*(uint64_t*)0x200001c0 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x200001c8 = 0x1c;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000180ul, 2ul, 0ul);
	return 0;
}