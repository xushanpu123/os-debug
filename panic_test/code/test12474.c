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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0xc8, 0x20000000ul, 4ul);
	syscall(__NR_setsockopt, r[0], 0, 0xcd, 0ul, 0ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[1] = res;
*(uint16_t*)0x20000540 = 0;
*(uint8_t*)0x20000542 = 0;
*(uint8_t*)0x20000543 = 0;
*(uint32_t*)0x20000544 = 0;
*(uint32_t*)0x20000548 = 0;
*(uint32_t*)0x2000054c = htobe32(0);
	syscall(__NR_setsockopt, r[1], 0, 0xcb, 0x20000540ul, 0x10ul);
*(uint16_t*)0x20000080 = 0;
*(uint8_t*)0x20000082 = 4;
*(uint8_t*)0x20000083 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = htobe32(0xe0000001);
	syscall(__NR_setsockopt, -1, 0, 0xca, 0x20000080ul, 0x10ul);
	return 0;
}
