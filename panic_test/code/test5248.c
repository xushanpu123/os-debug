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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000600 = 0;
*(uint16_t*)0x20000608 = 2;
*(uint16_t*)0x2000060a = htobe16(0);
*(uint32_t*)0x2000060c = htobe32(0);
*(uint16_t*)0x20000618 = 2;
*(uint16_t*)0x2000061a = htobe16(0);
*(uint8_t*)0x2000061c = 0xac;
*(uint8_t*)0x2000061d = 0x14;
*(uint8_t*)0x2000061e = 0x14;
*(uint8_t*)0x2000061f = 0xbb;
*(uint16_t*)0x20000628 = 2;
*(uint16_t*)0x2000062a = htobe16(0);
*(uint8_t*)0x2000062c = 0xac;
*(uint8_t*)0x2000062d = 0x14;
*(uint8_t*)0x2000062e = 0x14;
*(uint8_t*)0x2000062f = 0xaa;
*(uint16_t*)0x20000638 = 0x2f4;
*(uint16_t*)0x2000063a = 0;
*(uint64_t*)0x20000640 = 0;
*(uint64_t*)0x20000648 = 0;
*(uint16_t*)0x20000650 = 0;
*(uint64_t*)0x20000658 = 0;
*(uint64_t*)0x20000660 = 0;
*(uint64_t*)0x20000668 = 0;
*(uint16_t*)0x20000670 = 0;
	syscall(__NR_ioctl, r[0], 0x890b, 0x20000600ul);
	return 0;
}
