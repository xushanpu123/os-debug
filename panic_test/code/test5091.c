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
	res = syscall(__NR_socket, 0xaul, 3ul, 0xff);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0x4e24);
*(uint32_t*)0x20000044 = htobe32(1);
memset((void*)0x20000048, 0, 16);
*(uint32_t*)0x20000058 = 0x6c6;
	syscall(__NR_connect, r[0], 0x20000040ul, 0x1cul);
*(uint32_t*)0x20000c00 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x16, 0x20000c00ul, 4ul);
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x200000c0 = 0;
	syscall(__NR_getsockopt, r[1], 6, 0xd, 0ul, 0x200000c0ul);
	syscall(__NR_socket, 0x10ul, 3ul, 6);
	return 0;
}
