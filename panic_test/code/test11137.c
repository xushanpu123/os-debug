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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 3ul, 0x7d);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "lo\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[0], 0x8933, 0x20000080ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20000090;
*(uint64_t*)0x200000c0 = htobe64(0);
*(uint64_t*)0x200000c8 = htobe64(1);
*(uint8_t*)0x200000d0 = -1;
*(uint8_t*)0x200000d1 = 2;
memset((void*)0x200000d2, 0, 13);
*(uint8_t*)0x200000df = 1;
*(uint8_t*)0x200000e0 = 0xfc;
*(uint8_t*)0x200000e1 = 0;
memset((void*)0x200000e2, 0, 13);
*(uint8_t*)0x200000ef = 0;
*(uint32_t*)0x200000f0 = 0;
*(uint16_t*)0x200000f4 = 0;
*(uint16_t*)0x200000f6 = 0;
*(uint32_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0x8205006e;
*(uint32_t*)0x2000010c = r[1];
	syscall(__NR_ioctl, r[0], 0x890b, 0x200000c0ul);
	return 0;
}