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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000004;
memcpy((void*)0x20000100, "lo\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000110 = 0x20000140;
*(uint32_t*)0x20000140 = 4;
*(uint32_t*)0x20000144 = 0;
*(uint32_t*)0x20000148 = 0;
	syscall(__NR_ioctl, r[0], 0x8946, 0x20000100ul);
	return 0;
}
