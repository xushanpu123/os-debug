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

#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000340 = 1;
*(uint64_t*)0x20000348 = 0x20000300;
*(uint16_t*)0x20000300 = 6;
*(uint8_t*)0x20000302 = 0;
*(uint8_t*)0x20000303 = 0;
*(uint32_t*)0x20000304 = 0x7fc00002;
	res = syscall(__NR_seccomp, 1ul, 8ul, 0x20000340ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_pipe2, 0ul, 0x80ul);
	syscall(__NR_ioctl, r[0], 0xc0502100, 0x20000040ul);
*(uint32_t*)0x20000100 = r[0];
*(uint16_t*)0x20000104 = 0;
*(uint16_t*)0x20000106 = 0;
	syscall(__NR_poll, 0x20000100ul, 1ul, 0);
	return 0;
}
