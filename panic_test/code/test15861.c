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
memcpy((void*)0x20000100, "/dev/vcsu\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 5, 0x20000000ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000000;
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x200013c0 = 0x20000040;
*(uint64_t*)0x20000040 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint16_t*)0x20000050 = 1;
*(uint16_t*)0x20000052 = 0;
*(uint32_t*)0x20000054 = r[2];
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0x5b9;
*(uint64_t*)0x20000070 = 0;
*(uint32_t*)0x20000078 = 0;
*(uint32_t*)0x2000007c = -1;
*(uint64_t*)0x200013c8 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint16_t*)0x200000d0 = 8;
*(uint16_t*)0x200000d2 = 0;
*(uint32_t*)0x200000d4 = r[0];
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f8 = 0;
*(uint32_t*)0x200000fc = -1;
*(uint64_t*)0x200013d0 = 0;
	syscall(__NR_io_submit, r[1], 3ul, 0x200013c0ul);
	return 0;
}