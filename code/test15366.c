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
*(uint64_t*)0x20000480 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e23);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint32_t*)0x20000488 = 0x10;
*(uint64_t*)0x20000490 = 0;
*(uint64_t*)0x20000498 = 0;
*(uint64_t*)0x200004a0 = 0x20000300;
*(uint64_t*)0x20000300 = 0x18;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 7;
*(uint8_t*)0x20000310 = 7;
*(uint8_t*)0x20000311 = 7;
*(uint8_t*)0x20000312 = 4;
*(uint8_t*)0x20000313 = 0xac;
*(uint8_t*)0x20000314 = 0x14;
*(uint8_t*)0x20000315 = 0x14;
*(uint8_t*)0x20000316 = 0xaa;
*(uint64_t*)0x200004a8 = 0x18;
*(uint32_t*)0x200004b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000480ul, 0ul);
	return 0;
}