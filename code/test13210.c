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
*(uint16_t*)0x20000380 = 0xa;
*(uint16_t*)0x20000382 = htobe16(0x10);
*(uint32_t*)0x20000384 = htobe32(0);
*(uint64_t*)0x20000388 = htobe64(0);
*(uint64_t*)0x20000390 = htobe64(1);
*(uint32_t*)0x20000398 = 0;
	syscall(__NR_bind, r[0], 0x20000380ul, 0x1cul);
	return 0;
}
