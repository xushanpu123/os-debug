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
	syscall(__NR_setreuid, -1, 0xee00);
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(3);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x80;
memset((void*)0x2000004a, 0, 13);
*(uint8_t*)0x20000057 = 0xaa;
*(uint32_t*)0x20000058 = 0;
	syscall(__NR_bind, r[0], 0x20000040ul, 0x1cul);
	return 0;
}
