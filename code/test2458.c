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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20003d40 = 0x20000080;
*(uint16_t*)0x20000080 = 2;
*(uint16_t*)0x20000082 = htobe16(0x4e24);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint32_t*)0x20003d48 = 0x80;
*(uint64_t*)0x20003d50 = 0;
*(uint64_t*)0x20003d58 = 0;
*(uint64_t*)0x20003d60 = 0x20001440;
*(uint64_t*)0x20001440 = 0x14;
*(uint32_t*)0x20001448 = 1;
*(uint32_t*)0x2000144c = 0x25;
*(uint32_t*)0x20001450 = 0;
*(uint64_t*)0x20001458 = 0x14;
*(uint32_t*)0x20001460 = 1;
*(uint32_t*)0x20001464 = 0x25;
*(uint32_t*)0x20001468 = 8;
*(uint64_t*)0x20003d68 = 0x30;
*(uint32_t*)0x20003d70 = 0;
*(uint32_t*)0x20003d78 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003d40ul, 1ul, 0ul);
	return 0;
}
