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
*(uint64_t*)0x20000280 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0x20000240;
*(uint64_t*)0x20000240 = 0x200001c0;
*(uint32_t*)0x200001c0 = 0x24;
*(uint16_t*)0x200001c4 = 0;
*(uint16_t*)0x200001c6 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint8_t*)0x200001d0 = 0x4a;
*(uint8_t*)0x200001d1 = 0;
*(uint16_t*)0x200001d2 = 0;
*(uint16_t*)0x200001d4 = 0xd;
*(uint16_t*)0x200001d6 = 0xa8;
memcpy((void*)0x200001d8, "\x04\x32\x5f\x50\x16\x9b\x22\xeb\x15", 9);
*(uint64_t*)0x20000248 = 0x24;
*(uint64_t*)0x20000298 = 1;
*(uint64_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0;
*(uint32_t*)0x200002b0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000280ul, 0ul);
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0x20000140;
*(uint64_t*)0x20000140 = 0x20000200;
*(uint32_t*)0x20000200 = 0x3c;
*(uint16_t*)0x20000204 = 0;
*(uint16_t*)0x20000206 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint8_t*)0x20000210 = 0xa;
*(uint8_t*)0x20000211 = 0;
*(uint16_t*)0x20000212 = 0;
*(uint16_t*)0x20000214 = 0xe;
*(uint16_t*)0x20000216 = 1;
memcpy((void*)0x20000218, "netdevsim\000", 10);
*(uint16_t*)0x20000224 = 0xf;
*(uint16_t*)0x20000226 = 2;
memcpy((void*)0x20000228, "netdevsim", 9);
*(uint8_t*)0x20000231 = 0x30;
*(uint8_t*)0x20000232 = 0;
*(uint16_t*)0x20000234 = 8;
*(uint16_t*)0x20000236 = 3;
*(uint32_t*)0x20000238 = 0;
*(uint64_t*)0x20000148 = 0x3c;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000180ul, 0ul);
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x40, 0x200001c0ul, 4ul);
	return 0;
}
