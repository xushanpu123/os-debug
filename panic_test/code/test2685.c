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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200003c0 = 0x21;
*(uint8_t*)0x200003c4 = 0x37;
*(uint16_t*)0x200003c5 = 0;
*(uint8_t*)0x200003c7 = 0;
*(uint64_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0;
*(uint32_t*)0x200003d8 = 0;
*(uint16_t*)0x200003dc = 3;
memcpy((void*)0x200003de, "#\303\'", 3);
	syscall(__NR_write, r[0], 0x200003c0ul, 0x21ul);
	return 0;
}
