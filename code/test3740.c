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
	res = syscall(__NR_socket, 0xaul, 3ul, 0x3a);
	if (res != -1)
		r[0] = res;
memset((void*)0x200000c0, 0, 16);
memset((void*)0x200000d0, 0, 10);
memset((void*)0x200000da, 255, 2);
*(uint8_t*)0x200000dc = 0xac;
*(uint8_t*)0x200000dd = 0x14;
*(uint8_t*)0x200000de = 0x14;
*(uint8_t*)0x200000df = 0;
*(uint8_t*)0x200000e0 = 0xfc;
*(uint8_t*)0x200000e1 = 1;
memset((void*)0x200000e2, 0, 13);
*(uint8_t*)0x200000ef = 0;
*(uint32_t*)0x200000f0 = 0;
*(uint16_t*)0x200000f4 = 0;
*(uint16_t*)0x200000f6 = 0;
*(uint32_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
	syscall(__NR_ioctl, r[0], 0x890b, 0x200000c0ul);
	return 0;
}