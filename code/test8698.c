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
memcpy((void*)0x20000100, "/dev/cdrom\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0x105802ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 6;
*(uint8_t*)0x20000004 = 2;
*(uint32_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0;
	syscall(__NR_ioctl, r[0], 0x530e, 0x20000000ul);
	return 0;
}
