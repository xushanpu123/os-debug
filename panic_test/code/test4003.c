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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x200002c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[1], 0x8933, 0x200002c0ul);
	if (res != -1)
r[2] = *(uint32_t*)0x200002d0;
*(uint64_t*)0x200045c0 = 0x200000c0;
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0x4e20);
*(uint32_t*)0x200000c4 = htobe32(0);
*(uint32_t*)0x200045c8 = 0x10;
*(uint64_t*)0x200045d0 = 0;
*(uint64_t*)0x200045d8 = 0;
*(uint64_t*)0x200045e0 = 0;
*(uint64_t*)0x200045e8 = 0;
*(uint32_t*)0x200045f0 = 0;
*(uint32_t*)0x200045f8 = 0;
*(uint64_t*)0x20004600 = 0x20000f00;
*(uint16_t*)0x20000f00 = 2;
*(uint16_t*)0x20000f02 = htobe16(0x4e24);
*(uint32_t*)0x20000f04 = htobe32(-1);
*(uint32_t*)0x20004608 = 0x10;
*(uint64_t*)0x20004610 = 0;
*(uint64_t*)0x20004618 = 0;
*(uint64_t*)0x20004620 = 0x200021c0;
*(uint64_t*)0x200021c0 = 0x1c;
*(uint32_t*)0x200021c8 = 0;
*(uint32_t*)0x200021cc = 8;
*(uint32_t*)0x200021d0 = r[2];
*(uint8_t*)0x200021d4 = 0xac;
*(uint8_t*)0x200021d5 = 0x14;
*(uint8_t*)0x200021d6 = 0x14;
*(uint8_t*)0x200021d7 = 0xbb;
*(uint32_t*)0x200021d8 = htobe32(0);
*(uint64_t*)0x20004628 = 0x20;
*(uint32_t*)0x20004630 = 0;
*(uint32_t*)0x20004638 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200045c0ul, 2ul, 0ul);
	return 0;
}
