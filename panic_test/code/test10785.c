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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000140 = 0x20000080;
*(uint16_t*)0x20000080 = 0x10;
*(uint16_t*)0x20000082 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x20000148 = 0xc;
*(uint64_t*)0x20000150 = 0x20000100;
*(uint64_t*)0x20000100 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x14;
*(uint8_t*)0x200000c4 = 7;
*(uint8_t*)0x200000c5 = 1;
*(uint16_t*)0x200000c6 = 0x101;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint8_t*)0x200000d0 = 0;
*(uint8_t*)0x200000d1 = 0;
*(uint16_t*)0x200000d2 = htobe16(0);
*(uint64_t*)0x20000108 = 0x14;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 0ul);
	return 0;
}
