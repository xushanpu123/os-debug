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
*(uint64_t*)0x20000190 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000300;
*(uint32_t*)0x20000300 = 0x13c;
*(uint16_t*)0x20000304 = 0x1a;
*(uint16_t*)0x20000306 = 1;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 0;
*(uint8_t*)0x20000310 = 0xfc;
*(uint8_t*)0x20000311 = 1;
memset((void*)0x20000312, 0, 13);
*(uint8_t*)0x2000031f = 0;
*(uint64_t*)0x20000320 = htobe64(0);
*(uint64_t*)0x20000328 = htobe64(1);
*(uint16_t*)0x20000330 = htobe16(0);
*(uint16_t*)0x20000332 = htobe16(0);
*(uint16_t*)0x20000334 = htobe16(0);
*(uint16_t*)0x20000336 = htobe16(0);
*(uint16_t*)0x20000338 = 0;
*(uint8_t*)0x2000033a = 0;
*(uint8_t*)0x2000033b = 0;
*(uint8_t*)0x2000033c = 0;
*(uint32_t*)0x20000340 = 0;
*(uint32_t*)0x20000344 = 0;
*(uint8_t*)0x20000348 = 0xac;
*(uint8_t*)0x20000349 = 0x14;
*(uint8_t*)0x2000034a = 0x14;
*(uint8_t*)0x2000034b = 0xbb;
*(uint32_t*)0x20000358 = htobe32(0);
*(uint8_t*)0x2000035c = 0x33;
*(uint8_t*)0x20000360 = 0xac;
*(uint8_t*)0x20000361 = 0x14;
*(uint8_t*)0x20000362 = 0x14;
*(uint8_t*)0x20000363 = 0xaa;
*(uint64_t*)0x20000370 = 0;
*(uint64_t*)0x20000378 = 0;
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint64_t*)0x200003b0 = 0;
*(uint64_t*)0x200003b8 = 0;
*(uint64_t*)0x200003c0 = 0;
*(uint64_t*)0x200003c8 = 0;
*(uint32_t*)0x200003d0 = 0;
*(uint32_t*)0x200003d4 = 0;
*(uint32_t*)0x200003d8 = 0;
*(uint32_t*)0x200003dc = 0;
*(uint32_t*)0x200003e0 = 0;
*(uint16_t*)0x200003e4 = 0xa;
*(uint8_t*)0x200003e6 = 0;
*(uint8_t*)0x200003e7 = 0;
*(uint8_t*)0x200003e8 = 0;
*(uint16_t*)0x200003f0 = 0x4c;
*(uint16_t*)0x200003f2 = 0x14;
memcpy((void*)0x200003f4, "md5\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x20000434 = 0;
*(uint32_t*)0x20000438 = 0;
*(uint64_t*)0x200000c8 = 0x13c;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	return 0;
}
