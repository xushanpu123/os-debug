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
memcpy((void*)0x20000040, "./file0\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x26e1ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000600 = 0x20;
*(uint32_t*)0x20000604 = 0;
*(uint32_t*)0x20000608 = 0;
*(uint32_t*)0x2000060c = 0;
*(uint32_t*)0x20000610 = 0;
memset((void*)0x20000614, 0, 8);
	syscall(__NR_ioctl, r[0], 0x401c5820, 0x20000600ul);
memcpy((void*)0x20000200, "./file0\000", 8);
	syscall(__NR_unlink, 0x20000200ul);
	syscall(__NR_close, r[0]);
	return 0;
}