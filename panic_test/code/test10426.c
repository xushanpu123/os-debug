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
	res = syscall(__NR_socket, 2ul, 2ul, 1);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000180 = 0xa;
*(uint16_t*)0x20000182 = htobe16(0);
*(uint32_t*)0x20000184 = htobe32(0);
*(uint8_t*)0x20000188 = -1;
*(uint8_t*)0x20000189 = 1;
memset((void*)0x2000018a, 0, 13);
*(uint8_t*)0x20000197 = 1;
*(uint32_t*)0x20000198 = 0;
	syscall(__NR_bind, r[0], 0x20000180ul, 0x1cul);
	return 0;
}
