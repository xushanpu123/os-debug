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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x88;
memset((void*)0x2000004a, 0, 12);
*(uint8_t*)0x20000056 = 0;
*(uint8_t*)0x20000057 = 1;
*(uint32_t*)0x20000058 = 0xf86;
	syscall(__NR_connect, r[0], 0x20000040ul, 0x1cul);
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint8_t*)0x20000088 = 0xfe;
*(uint8_t*)0x20000089 = 0x80;
memset((void*)0x2000008a, 0, 13);
*(uint8_t*)0x20000097 = 0;
*(uint32_t*)0x20000098 = 0;
	syscall(__NR_connect, r[0], 0x20000080ul, 0x1cul);
	return 0;
}
