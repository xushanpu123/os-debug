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
*(uint32_t*)0x20000080 = 0x19980330;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000100 = 0;
*(uint32_t*)0x20000104 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint32_t*)0x20000110 = 0;
*(uint32_t*)0x20000114 = 0;
	syscall(__NR_capset, 0x20000080ul, 0x20000100ul);
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000200 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x20000208 = 0xc;
*(uint64_t*)0x20000210 = 0x200001c0;
*(uint64_t*)0x200001c0 = 0x20000040;
*(uint32_t*)0x20000040 = 0x14;
*(uint8_t*)0x20000044 = 2;
*(uint8_t*)0x20000045 = 9;
*(uint16_t*)0x20000046 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint8_t*)0x20000050 = 0;
*(uint8_t*)0x20000051 = 0;
*(uint16_t*)0x20000052 = htobe16(0);
*(uint64_t*)0x200001c8 = 0x14;
*(uint64_t*)0x20000218 = 1;
*(uint64_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0;
*(uint32_t*)0x20000230 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000200ul, 0ul);
	return 0;
}