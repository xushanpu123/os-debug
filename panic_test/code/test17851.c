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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x200000c0 = 0;
*(uint8_t*)0x200000c1 = 5;
*(uint8_t*)0x200000c2 = 4;
*(uint8_t*)0x200000c3 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint8_t*)0x200000c8 = 0xfe;
*(uint8_t*)0x200000c9 = 0x88;
memset((void*)0x200000ca, 0, 12);
*(uint8_t*)0x200000d6 = 0;
*(uint8_t*)0x200000d7 = 1;
*(uint8_t*)0x200000d8 = -1;
*(uint8_t*)0x200000d9 = 2;
memset((void*)0x200000da, 0, 13);
*(uint8_t*)0x200000e7 = 1;
*(uint8_t*)0x200000e8 = 0xfe;
*(uint8_t*)0x200000e9 = 0x80;
memset((void*)0x200000ea, 0, 13);
*(uint8_t*)0x200000f7 = 0;
memcpy((void*)0x200000f8, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
	syscall(__NR_setsockopt, r[0], 0x29, 0x39, 0x200000c0ul, 0x48ul);
	return 0;
}