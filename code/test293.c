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
*(uint64_t*)0x20000340 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0x20000300;
*(uint64_t*)0x20000300 = 0x20001540;
*(uint32_t*)0x20001540 = 0x14;
*(uint16_t*)0x20001544 = 0x10;
*(uint16_t*)0x20001546 = 1;
*(uint32_t*)0x20001548 = 0;
*(uint32_t*)0x2000154c = 0;
*(uint8_t*)0x20001550 = 0;
*(uint8_t*)0x20001551 = 0;
*(uint16_t*)0x20001552 = htobe16(0xa);
*(uint32_t*)0x20001554 = 0x14;
*(uint16_t*)0x20001558 = 0x11;
*(uint16_t*)0x2000155a = 1;
*(uint32_t*)0x2000155c = 0;
*(uint32_t*)0x20001560 = 0;
*(uint8_t*)0x20001564 = 0;
*(uint8_t*)0x20001565 = 0;
*(uint16_t*)0x20001566 = htobe16(0xa);
*(uint64_t*)0x20000308 = 0x28;
*(uint64_t*)0x20000358 = 1;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000340ul, 0ul);
	return 0;
}