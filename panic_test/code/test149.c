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
memcpy((void*)0x20000080, "/dev/snd/timer\000", 15);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c4 = 1;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
memset((void*)0x200000d4, 0, 32);
	syscall(__NR_ioctl, r[0], 0x40345410, 0x200000c0ul);
	syscall(__NR_ioctl, r[0], 0x54a0, 0);
	return 0;
}
