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

#ifndef __NR_io_pgetevents
#define __NR_io_pgetevents 333
#endif

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 0x2a, 0x20000940ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000940;
	syscall(__NR_io_pgetevents, r[0], 1ul, 1ul, 0x20000040ul, 0ul, 0ul);
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x200006c0 = 0x20000000;
*(uint64_t*)0x20000000 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint16_t*)0x20000010 = 0;
*(uint16_t*)0x20000012 = 0;
*(uint32_t*)0x20000014 = r[1];
*(uint64_t*)0x20000018 = 0;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint64_t*)0x20000030 = 0;
*(uint32_t*)0x20000038 = 0;
*(uint32_t*)0x2000003c = -1;
	syscall(__NR_io_submit, r[0], 1ul, 0x200006c0ul);
	return 0;
}
