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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 6, 0x20000100ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000100;
*(uint64_t*)0x20001380 = 0x20001140;
*(uint64_t*)0x20001140 = 0;
*(uint32_t*)0x20001148 = 0;
*(uint32_t*)0x2000114c = 0;
*(uint16_t*)0x20001150 = 0;
*(uint16_t*)0x20001152 = 0;
*(uint32_t*)0x20001154 = r[0];
*(uint64_t*)0x20001158 = 0;
*(uint64_t*)0x20001160 = 0;
*(uint64_t*)0x20001168 = 2;
*(uint64_t*)0x20001170 = 0;
*(uint32_t*)0x20001178 = 0;
*(uint32_t*)0x2000117c = -1;
	syscall(__NR_io_submit, r[1], 1ul, 0x20001380ul);
	return 0;
}
