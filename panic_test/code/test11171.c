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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000040 = 1;
*(uint64_t*)0x20000048 = 0x20000000;
*(uint16_t*)0x20000000 = 6;
*(uint8_t*)0x20000002 = 0;
*(uint8_t*)0x20000003 = 0;
*(uint32_t*)0x20000004 = 0;
	res = syscall(__NR_seccomp, 1ul, 8ul, 0x20000040ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, -1, 0xc0502100, 0ul);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = r[1];
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
	syscall(__NR_ioctl, r[0], 0x40182103, 0x20000080ul);
	return 0;
}
