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
memcpy((void*)0x20000200, "/dev/rtc0\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000200ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000040 = 0;
*(uint8_t*)0x20000041 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0xc;
*(uint32_t*)0x20000054 = 0;
*(uint32_t*)0x20000058 = 0xfff;
*(uint32_t*)0x2000005c = 0;
*(uint32_t*)0x20000060 = 0;
*(uint32_t*)0x20000064 = 0;
	syscall(__NR_ioctl, r[0], 0x4028700f, 0x20000040ul);
	return 0;
}
