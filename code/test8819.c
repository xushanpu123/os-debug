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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x200000c0 = 0xa;
*(uint16_t*)0x200000c2 = htobe16(0);
*(uint32_t*)0x200000c4 = htobe32(0);
*(uint8_t*)0x200000c8 = 0xfe;
*(uint8_t*)0x200000c9 = 0x88;
memset((void*)0x200000ca, 0, 12);
*(uint8_t*)0x200000d6 = 0;
*(uint8_t*)0x200000d7 = 1;
*(uint32_t*)0x200000d8 = 1;
	syscall(__NR_connect, r[0], 0x200000c0ul, 0x1cul);
	res = syscall(__NR_dup2, r[0], r[0]);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000040 = 1;
	syscall(__NR_setsockopt, r[1], 6, 0x13, 0x20000040ul, 4ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint8_t*)0x20000008 = 0xfe;
*(uint8_t*)0x20000009 = 0x80;
memset((void*)0x2000000a, 0, 13);
*(uint8_t*)0x20000017 = 0;
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
	return 0;
}