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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0x20000200;
*(uint64_t*)0x20000200 = 0x200001c0;
*(uint32_t*)0x200001c0 = 0x1c;
*(uint8_t*)0x200001c4 = 1;
*(uint8_t*)0x200001c5 = 4;
*(uint16_t*)0x200001c6 = 0x101;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint8_t*)0x200001d0 = 0;
*(uint8_t*)0x200001d1 = 0;
*(uint16_t*)0x200001d2 = htobe16(0);
*(uint16_t*)0x200001d4 = 5;
*(uint16_t*)0x200001d6 = 1;
*(uint8_t*)0x200001d8 = 2;
*(uint64_t*)0x20000208 = 0x1c;
*(uint64_t*)0x20000258 = 1;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint32_t*)0x20000270 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000240ul, 0ul);
	return 0;
}
