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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_semget, 0x798e2636ul, 0ul, 0x7baul);
	res = syscall(__NR_semget, 0x798e2636ul, 4ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000040ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000080 = 0;
	syscall(__NR_ioctl, r[1], 0x4004662b, 0x20000080ul);
*(uint16_t*)0x20000140 = 0;
*(uint16_t*)0x20000142 = 7;
*(uint16_t*)0x20000144 = 0x800;
*(uint16_t*)0x20000146 = 3;
*(uint16_t*)0x20000148 = 0;
*(uint16_t*)0x2000014a = 0x1000;
*(uint16_t*)0x2000014c = 0;
*(uint16_t*)0x2000014e = 0;
*(uint16_t*)0x20000150 = 0;
*(uint16_t*)0x20000152 = 2;
*(uint16_t*)0x20000154 = 2;
*(uint16_t*)0x20000156 = 0;
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0x989680;
	syscall(__NR_semtimedop, r[0], 0x20000140ul, 4ul, 0x20000180ul);
	syscall(__NR_semctl, r[0], 4ul, 0x12ul, 0x20000000ul);
	return 0;
}
