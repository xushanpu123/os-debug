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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000040 = 0xac;
*(uint8_t*)0x20000041 = 0x14;
*(uint8_t*)0x20000042 = 0x14;
*(uint8_t*)0x20000043 = 0xbb;
*(uint32_t*)0x20000044 = htobe32(0xe0000002);
*(uint16_t*)0x20000048 = 0;
memcpy((void*)0x2000004a, "\x55\x71\x6a\xe4\x19\x86\x45\x47\xa1\x98\x39\x12\xd4\x6c\xa3\x81\x2f\x99\x49\xfa\x9a\xa7\xa3\x58\x96\x59\xd0\xef\x2e\x36\x43\xff", 32);
*(uint32_t*)0x2000006c = 0;
*(uint32_t*)0x20000070 = 0;
*(uint32_t*)0x20000074 = 0;
*(uint32_t*)0x20000078 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0xcc, 0x20000040ul, 0x3cul);
	return 0;
}