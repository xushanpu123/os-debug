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
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20001500 = 2;
*(uint16_t*)0x20001502 = htobe16(0x4e22);
*(uint32_t*)0x20001504 = htobe32(0x7f000001);
	syscall(__NR_connect, r[0], 0x20001500ul, 0x10ul);
*(uint32_t*)0x200001c0 = 0;
	syscall(__NR_getpeername, r[0], 0ul, 0x200001c0ul);
	return 0;
}
