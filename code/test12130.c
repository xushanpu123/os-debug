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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 1, 0x20000440ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000440;
*(uint64_t*)0x20002900 = 0x20000080;
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint16_t*)0x20000090 = 0;
*(uint16_t*)0x20000092 = 0;
*(uint32_t*)0x20000094 = r[0];
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint64_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b8 = 0;
*(uint32_t*)0x200000bc = -1;
*(uint64_t*)0x20002908 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint16_t*)0x200000d0 = 7;
*(uint16_t*)0x200000d2 = 0;
*(uint32_t*)0x200000d4 = r[0];
*(uint64_t*)0x200000d8 = 0x20000480;
memcpy((void*)0x20000480, "\x53\x9b\x1e\x9a\x06\x16\x0e\xad\x25\x4b\xa0\xd3\xad\x51\x8e\x97", 16);
*(uint64_t*)0x200000e0 = 0x10;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f8 = 0;
*(uint32_t*)0x200000fc = -1;
	syscall(__NR_io_submit, r[1], 2ul, 0x20002900ul);
	return 0;
}