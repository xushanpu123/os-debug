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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000380, "/dev/snd/timer\000", 15);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000380ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000400 = 1;
*(uint32_t*)0x20000404 = 0;
*(uint32_t*)0x20000408 = 0;
*(uint32_t*)0x2000040c = 0;
*(uint32_t*)0x20000410 = 0;
memset((void*)0x20000414, 0, 32);
	syscall(__NR_ioctl, r[0], 0x40345410, 0x20000400ul);
	syscall(__NR_ioctl, r[0], 0x54a2, 0);
	syscall(__NR_ioctl, r[0], 0x54a3, 0);
	syscall(__NR_ioctl, r[0], 0x54a2, 0);
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000040ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20000044;
memcpy((void*)0x20000000, "wg2\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	syscall(__NR_ioctl, r[1], 0x8933, 0x20000000ul);
	syscall(__NR_ioctl, r[0], 0x54a2, 0);
	return 0;
}
