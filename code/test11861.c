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
*(uint32_t*)0x200000c0 = 1;
	syscall(__NR_setsockopt, r[0], 6, 0x1e, 0x200000c0ul, 4ul);
*(uint16_t*)0x20000100 = 0xa;
*(uint16_t*)0x20000102 = htobe16(0);
*(uint32_t*)0x20000104 = htobe32(0);
memset((void*)0x20000108, 0, 10);
memset((void*)0x20000112, 255, 2);
*(uint8_t*)0x20000114 = 0xac;
*(uint8_t*)0x20000115 = 0x14;
*(uint8_t*)0x20000116 = 0x14;
*(uint8_t*)0x20000117 = 0;
*(uint32_t*)0x20000118 = 0;
	syscall(__NR_sendto, r[0], 0ul, 0xfffffffffffffe15ul, 0x20000090ul, 0x20000100ul, 0x80ul);
	return 0;
}
