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
memcpy((void*)0x20000180, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000180ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_ioctl, -1, 0x4c80, 2ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[0], 0x4c81, r[1]);
memcpy((void*)0x20000480, "memory.swap.events\000", 19);
	res = syscall(__NR_openat, -1, 0x20000480ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000100 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0x40000;
*(uint32_t*)0x20000108 = 0xc;
*(uint64_t*)0x20000110 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x20000118 = 1;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0x24000004;
	syscall(__NR_sendmsg, r[2], 0x20000100ul, 0x80ul);
	return 0;
}
