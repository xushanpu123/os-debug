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
	res = syscall(__NR_socket, 0xaul, 0x801ul, 0);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint64_t*)0x20000088 = htobe64(0);
*(uint64_t*)0x20000090 = htobe64(1);
*(uint32_t*)0x20000098 = 0;
	syscall(__NR_bind, r[0], 0x20000080ul, 0x1cul);
*(uint16_t*)0x20000340 = 0xa;
*(uint16_t*)0x20000342 = 0;
*(uint32_t*)0x20000344 = htobe32(0);
memset((void*)0x20000348, 0, 10);
memset((void*)0x20000352, 255, 2);
*(uint32_t*)0x20000354 = htobe32(0);
*(uint32_t*)0x20000358 = 0;
*(uint32_t*)0x2000035c = 0;
	syscall(__NR_connect, r[0], 0x20000340ul, 0x80ul);
	return 0;
}
