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
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000540 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x24;
*(uint32_t*)0x200000c4 = 2;
*(uint16_t*)0x200000c8 = 0;
*(uint16_t*)0x200000ca = 0;
*(uint32_t*)0x20000548 = 0x80;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 0;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint32_t*)0x20000570 = 0;
*(uint32_t*)0x20000578 = 0;
*(uint64_t*)0x20000580 = 0x20000000;
*(uint16_t*)0x20000000 = 0x1f;
*(uint16_t*)0x20000002 = 0;
*(uint16_t*)0x20000004 = 2;
*(uint32_t*)0x20000588 = 0x80;
*(uint64_t*)0x20000590 = 0;
*(uint64_t*)0x20000598 = 0;
*(uint64_t*)0x200005a0 = 0x200004c0;
*(uint64_t*)0x200004c0 = 0x14;
*(uint32_t*)0x200004c8 = 1;
*(uint32_t*)0x200004cc = 0x24;
*(uint32_t*)0x200004d0 = 0;
*(uint64_t*)0x200004d8 = 0x18;
*(uint32_t*)0x200004e0 = 1;
*(uint32_t*)0x200004e4 = 0x3d;
*(uint64_t*)0x200004e8 = 0;
*(uint64_t*)0x200005a8 = 0x30;
*(uint32_t*)0x200005b0 = 0;
*(uint32_t*)0x200005b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000540ul, 2ul, 0ul);
	return 0;
}