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
	res = syscall(__NR_socket, 0x10ul, 3ul, 4);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000500 = 0;
*(uint32_t*)0x20000508 = 0;
*(uint64_t*)0x20000510 = 0x20000140;
*(uint64_t*)0x20000140 = 0x20000300;
*(uint32_t*)0x20000300 = 0x14;
*(uint16_t*)0x20000304 = 0x15;
*(uint16_t*)0x20000306 = 0x4625;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 0;
*(uint8_t*)0x20000310 = 0;
*(uint8_t*)0x20000311 = 0;
*(uint64_t*)0x20000148 = 0x14;
*(uint64_t*)0x20000518 = 1;
*(uint64_t*)0x20000520 = 0;
*(uint64_t*)0x20000528 = 0;
*(uint32_t*)0x20000530 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000500ul, 0ul);
	return 0;
}
