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
*(uint32_t*)0x20000080 = 0xa;
	syscall(__NR_setsockopt, r[0], 0, 3, 0x20000080ul, 4ul);
	syscall(__NR_shutdown, r[0], 1ul);
*(uint64_t*)0x20003c80 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint8_t*)0x20000004 = 0xac;
*(uint8_t*)0x20000005 = 0x14;
*(uint8_t*)0x20000006 = 0x14;
*(uint8_t*)0x20000007 = 0xaa;
*(uint32_t*)0x20003c88 = 0x10;
*(uint64_t*)0x20003c90 = 0x20000240;
*(uint64_t*)0x20000240 = 0x20000300;
memcpy((void*)0x20000300, "\xc4\xc3\xf4\x64\x1c\x1c\x7e\x02\x00\x00\x00\x77\x6b\x31\x57\x18\x02\xa2\x32\x1a", 20);
*(uint64_t*)0x20000248 = 0x14;
*(uint64_t*)0x20003c98 = 1;
*(uint64_t*)0x20003ca0 = 0;
*(uint64_t*)0x20003ca8 = 0;
*(uint32_t*)0x20003cb0 = 0;
*(uint32_t*)0x20003cb8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003c80ul, 1ul, 0ul);
	return 0;
}