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
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0x20000140;
*(uint64_t*)0x20000140 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x44;
*(uint16_t*)0x200000c4 = 0;
*(uint16_t*)0x200000c6 = 0x300;
*(uint32_t*)0x200000c8 = 0x70bd25;
*(uint32_t*)0x200000cc = 0x25dfdbfe;
*(uint8_t*)0x200000d0 = 7;
*(uint8_t*)0x200000d1 = 0;
*(uint16_t*)0x200000d2 = 0;
*(uint16_t*)0x200000d4 = 5;
*(uint16_t*)0x200000d6 = 0x2e;
*(uint8_t*)0x200000d8 = 0;
*(uint16_t*)0x200000dc = 5;
*(uint16_t*)0x200000de = 0x30;
*(uint8_t*)0x200000e0 = 0;
*(uint16_t*)0x200000e4 = 6;
*(uint16_t*)0x200000e6 = 0x28;
*(uint16_t*)0x200000e8 = 2;
*(uint16_t*)0x200000ec = 8;
*(uint16_t*)0x200000ee = 0x2c;
*(uint32_t*)0x200000f0 = 0x4be;
*(uint16_t*)0x200000f4 = 8;
*(uint16_t*)0x200000f6 = 0x34;
*(uint32_t*)0x200000f8 = 3;
*(uint16_t*)0x200000fc = 5;
*(uint16_t*)0x200000fe = 0x2d;
*(uint8_t*)0x20000100 = 0;
*(uint64_t*)0x20000148 = 0x44;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	syscall(__NR_socket, 0ul, 0ul, 0x9a87);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
	return 0;
}