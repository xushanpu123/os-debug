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

uint64_t r[6] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 3ul, 8);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200001c0 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
	syscall(__NR_recvmsg, r[0], 0x200001c0ul, 0ul, 0);
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[1] = res;
	syscall(__NR_sendmmsg, r[1], 0ul, 0ul, 0ul);
memcpy((void*)0x20000000, "vxcan0\000\000\000\000\000\000\000\000\000\000", 16);
	syscall(__NR_ioctl, r[0], 0x8933, 0x20000000ul);
*(uint32_t*)0x20000200 = 0;
	res = syscall(__NR_accept4, r[0], 0ul, 0x20000200ul, 0x80000ul);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x20000240, "virt_wifi0\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000250 = 4;
*(uint64_t*)0x20000258 = 0x529d;
*(uint16_t*)0x20000260 = 0x7ff;
*(uint8_t*)0x20000262 = 0x1f;
*(uint8_t*)0x20000263 = 7;
*(uint8_t*)0x20000264 = 0;
	syscall(__NR_ioctl, r[2], 0x8913, 0x20000240ul);
*(uint32_t*)0x20000180 = 0x85;
	syscall(__NR_getsockopt, -1, 0, 0xfa2d, 0x200000c0ul, 0x20000180ul);
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[3] = res;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[4] = res;
memcpy((void*)0x200002c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[4], 0x8933, 0x200002c0ul);
	if (res != -1)
r[5] = *(uint32_t*)0x200002d0;
memset((void*)0x20000000, 0, 10);
memset((void*)0x2000000a, 255, 2);
*(uint32_t*)0x2000000c = htobe32(0);
*(uint32_t*)0x20000010 = 0;
*(uint32_t*)0x20000014 = r[5];
	syscall(__NR_ioctl, r[3], 0x8916, 0x20000000ul);
memset((void*)0x20000040, 0, 16);
*(uint8_t*)0x20000050 = 0xfc;
*(uint8_t*)0x20000051 = 2;
memset((void*)0x20000052, 0, 13);
*(uint8_t*)0x2000005f = 1;
*(uint8_t*)0x20000060 = 0xfc;
*(uint8_t*)0x20000061 = 2;
memset((void*)0x20000062, 0, 13);
*(uint8_t*)0x2000006f = 1;
*(uint32_t*)0x20000070 = 0x992;
*(uint16_t*)0x20000074 = 0;
*(uint16_t*)0x20000076 = 0xc33c;
*(uint32_t*)0x20000078 = 0x100;
*(uint64_t*)0x20000080 = 0x1d9e82c4;
*(uint32_t*)0x20000088 = 0x10000;
*(uint32_t*)0x2000008c = r[5];
	syscall(__NR_ioctl, r[1], 0x890c, 0x20000040ul);
*(uint32_t*)0x20000300 = 4;
	syscall(__NR_getsockopt, r[2], 0x29, 0xd1, 0x20000280ul, 0x20000300ul);
	return 0;
}
