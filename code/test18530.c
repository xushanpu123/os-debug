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

uint64_t r[3] = {0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 1, 0x20000180ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000180;
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000380 = 0x20000140;
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 0;
*(uint16_t*)0x20000150 = 0;
*(uint16_t*)0x20000152 = 0;
*(uint32_t*)0x20000154 = r[2];
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0;
*(uint32_t*)0x20000178 = 0;
*(uint32_t*)0x2000017c = -1;
*(uint64_t*)0x20000388 = 0x20000340;
*(uint64_t*)0x20000340 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint32_t*)0x2000034c = 0;
*(uint16_t*)0x20000350 = 7;
*(uint16_t*)0x20000352 = 0;
*(uint32_t*)0x20000354 = r[0];
*(uint64_t*)0x20000358 = 0x20000280;
memcpy((void*)0x20000280, "\xa5\x00\x00\x00\x00\x00\x00\x00\x00", 9);
*(uint64_t*)0x20000360 = 9;
*(uint64_t*)0x20000368 = 0xfffffffffffffffc;
*(uint64_t*)0x20000370 = 0;
*(uint32_t*)0x20000378 = 0;
*(uint32_t*)0x2000037c = -1;
	syscall(__NR_io_submit, r[1], 2ul, 0x20000380ul);
	return 0;
}