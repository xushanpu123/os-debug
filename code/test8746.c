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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0x20000140;
*(uint64_t*)0x20000140 = 0x20000300;
*(uint32_t*)0x20000300 = 0x5c;
*(uint16_t*)0x20000304 = 0x1e;
*(uint16_t*)0x20000306 = 1;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 0;
*(uint8_t*)0x20000310 = 0xac;
*(uint8_t*)0x20000311 = 0x14;
*(uint8_t*)0x20000312 = 0x14;
*(uint8_t*)0x20000313 = 0xaa;
*(uint32_t*)0x20000320 = htobe32(0);
*(uint16_t*)0x20000324 = 0;
*(uint8_t*)0x20000326 = 0;
*(uint8_t*)0x20000328 = 0xac;
*(uint8_t*)0x20000329 = 0x14;
*(uint8_t*)0x2000032a = 0x14;
*(uint8_t*)0x2000032b = 0xaa;
*(uint32_t*)0x20000338 = 0;
*(uint32_t*)0x2000033c = 0;
*(uint16_t*)0x20000340 = 0x1c;
*(uint16_t*)0x20000342 = 0x17;
*(uint32_t*)0x20000344 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint32_t*)0x2000034c = 0;
*(uint32_t*)0x20000350 = 0;
*(uint32_t*)0x20000354 = 0;
*(uint32_t*)0x20000358 = 0;
*(uint64_t*)0x20000148 = 0x5c;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	return 0;
}
