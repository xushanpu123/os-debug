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
*(uint32_t*)0x200001c0 = 0;
*(uint16_t*)0x200001c8 = 0xa;
*(uint16_t*)0x200001ca = htobe16(0);
*(uint32_t*)0x200001cc = htobe32(0);
*(uint64_t*)0x200001d0 = htobe64(0);
*(uint64_t*)0x200001d8 = htobe64(1);
*(uint32_t*)0x200001e0 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x2d, 0x200001c0ul, 0x88ul);
	return 0;
}
