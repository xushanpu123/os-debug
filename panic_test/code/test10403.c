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

uint64_t r[3] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 6, 0x20000000ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000000;
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000040, "/dev/random\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000140 = 0x20000180;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint16_t*)0x20000190 = 0;
*(uint16_t*)0x20000192 = 0;
*(uint32_t*)0x20000194 = r[1];
*(uint64_t*)0x20000198 = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint64_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b8 = 0;
*(uint32_t*)0x200001bc = -1;
*(uint64_t*)0x20000148 = 0x20000100;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint16_t*)0x20000110 = 5;
*(uint16_t*)0x20000112 = 0;
*(uint32_t*)0x20000114 = r[2];
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint32_t*)0x2000013c = -1;
	syscall(__NR_io_submit, r[0], 2ul, 0x20000140ul);
	return 0;
}