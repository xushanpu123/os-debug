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
	res = syscall(__NR_socket, 0xaul, 3ul, 0x3a);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20007e00 = 0x20000140;
*(uint16_t*)0x20000140 = 0;
*(uint16_t*)0x20000142 = 0;
*(uint32_t*)0x20000144 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x20007e08 = 0x80;
*(uint64_t*)0x20007e10 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000000;
memcpy((void*)0x20000000, "\x61\x03\x03\x92", 4);
*(uint64_t*)0x200000c8 = 4;
*(uint64_t*)0x20007e18 = 1;
*(uint64_t*)0x20007e20 = 0;
*(uint64_t*)0x20007e28 = 0;
*(uint32_t*)0x20007e30 = 0;
*(uint32_t*)0x20007e38 = 0;
*(uint64_t*)0x20007e40 = 0x20000040;
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = 0;
*(uint32_t*)0x20000044 = htobe32(0);
*(uint64_t*)0x20000048 = htobe64(0);
*(uint64_t*)0x20000050 = htobe64(1);
*(uint32_t*)0x20000058 = 0;
*(uint32_t*)0x2000005c = 0;
*(uint32_t*)0x20007e48 = 0x80;
*(uint64_t*)0x20007e50 = 0x20000500;
*(uint64_t*)0x20000500 = 0x200001c0;
memcpy((void*)0x200001c0, "\xc0\xef", 2);
*(uint64_t*)0x20000508 = 2;
*(uint64_t*)0x20007e58 = 1;
*(uint64_t*)0x20007e60 = 0;
*(uint64_t*)0x20007e68 = 0;
*(uint32_t*)0x20007e70 = 0;
*(uint32_t*)0x20007e78 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20007e00ul, 2ul, 0ul);
	return 0;
}
