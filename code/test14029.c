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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000600;
*(uint32_t*)0x20000600 = 0x104;
*(uint16_t*)0x20000604 = 0x1a;
*(uint16_t*)0x20000606 = 1;
*(uint32_t*)0x20000608 = 0;
*(uint32_t*)0x2000060c = 0;
*(uint8_t*)0x20000610 = 0xfc;
*(uint8_t*)0x20000611 = 1;
memset((void*)0x20000612, 0, 13);
*(uint8_t*)0x2000061f = 0;
*(uint64_t*)0x20000620 = htobe64(0);
*(uint64_t*)0x20000628 = htobe64(1);
*(uint16_t*)0x20000630 = htobe16(0);
*(uint16_t*)0x20000632 = htobe16(0);
*(uint16_t*)0x20000634 = htobe16(0);
*(uint16_t*)0x20000636 = htobe16(0);
*(uint16_t*)0x20000638 = 0;
*(uint8_t*)0x2000063a = 0;
*(uint8_t*)0x2000063b = 0;
*(uint8_t*)0x2000063c = 0;
*(uint32_t*)0x20000640 = 0;
*(uint32_t*)0x20000644 = 0;
*(uint8_t*)0x20000648 = 0xfe;
*(uint8_t*)0x20000649 = 0x80;
memset((void*)0x2000064a, 0, 13);
*(uint8_t*)0x20000657 = 0xaa;
*(uint32_t*)0x20000658 = htobe32(0);
*(uint8_t*)0x2000065c = 0x3c;
*(uint8_t*)0x20000660 = 0xac;
*(uint8_t*)0x20000661 = 0x14;
*(uint8_t*)0x20000662 = 0x14;
*(uint8_t*)0x20000663 = 0xaa;
*(uint64_t*)0x20000670 = 0;
*(uint64_t*)0x20000678 = 0;
*(uint64_t*)0x20000680 = 0;
*(uint64_t*)0x20000688 = 0;
*(uint64_t*)0x20000690 = 0;
*(uint64_t*)0x20000698 = 0;
*(uint64_t*)0x200006a0 = 0;
*(uint64_t*)0x200006a8 = 0;
*(uint64_t*)0x200006b0 = 0;
*(uint64_t*)0x200006b8 = 0;
*(uint64_t*)0x200006c0 = 0;
*(uint64_t*)0x200006c8 = 0;
*(uint32_t*)0x200006d0 = 0;
*(uint32_t*)0x200006d4 = 0;
*(uint32_t*)0x200006d8 = 0;
*(uint32_t*)0x200006dc = 0;
*(uint32_t*)0x200006e0 = 0;
*(uint16_t*)0x200006e4 = 2;
*(uint8_t*)0x200006e6 = 4;
*(uint8_t*)0x200006e7 = 0;
*(uint8_t*)0x200006e8 = 0x2d;
*(uint16_t*)0x200006f0 = 0x14;
*(uint16_t*)0x200006f2 = 0xe;
*(uint8_t*)0x200006f4 = 0xfc;
*(uint8_t*)0x200006f5 = 0;
memset((void*)0x200006f6, 0, 13);
*(uint8_t*)0x20000703 = 0;
*(uint64_t*)0x200000c8 = 0x104;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	return 0;
}
