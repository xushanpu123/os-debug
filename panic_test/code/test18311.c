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
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000400 = 0x20000600;
*(uint16_t*)0x20000600 = 2;
*(uint16_t*)0x20000602 = htobe16(0x4e24);
*(uint32_t*)0x20000604 = htobe32(0x7f000001);
*(uint32_t*)0x20000408 = 0x80;
*(uint64_t*)0x20000410 = 0;
*(uint64_t*)0x20000418 = 0;
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
*(uint32_t*)0x20000430 = 0;
*(uint32_t*)0x20000438 = 0;
*(uint64_t*)0x20000440 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint64_t*)0x20000450 = 0x20000000;
*(uint64_t*)0x20000000 = 0x20000080;
memset((void*)0x20000080, 1, 1);
*(uint64_t*)0x20000008 = 1;
*(uint64_t*)0x20000458 = 1;
*(uint64_t*)0x20000460 = 0;
*(uint64_t*)0x20000468 = 0;
*(uint32_t*)0x20000470 = 0;
*(uint32_t*)0x20000478 = 0;
*(uint64_t*)0x20000480 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint64_t*)0x20000490 = 0x20000040;
*(uint64_t*)0x20000040 = 0x20000200;
memcpy((void*)0x20000200, "\xb6\xb6\xfc\x03\x3d\x6e\xbe\xc4\x78\xc1\x55\x35\x08\x32\x25\xe7\x9a\xfa\xe9\x9b\xa6\xc6\x2d\xb7\x3b\x19\x00\x99\xd6\x16\x25\x7c\x01\xa7\x9c\x95\x4d\xf7\xe0\xad\x3c\x5f\xc8\x75\x8c\x42\xf1\x8e\xb1\x3d\xe3\x28\xc7\xa1\x51\xc8\x33\xa0\xa0\xdd\xd3\x9e\xb7", 63);
*(uint64_t*)0x20000048 = 0x3f;
*(uint64_t*)0x20000050 = 0x20000340;
memcpy((void*)0x20000340, "\xae\x16", 2);
*(uint64_t*)0x20000058 = 2;
*(uint64_t*)0x20000498 = 2;
*(uint64_t*)0x200004a0 = 0;
*(uint64_t*)0x200004a8 = 0;
*(uint32_t*)0x200004b0 = 0;
*(uint32_t*)0x200004b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000400ul, 3ul, 0xc804ul);
*(uint64_t*)0x20003300 = 0;
*(uint32_t*)0x20003308 = 0;
*(uint64_t*)0x20003310 = 0;
*(uint64_t*)0x20003318 = 0;
*(uint64_t*)0x20003320 = 0;
*(uint64_t*)0x20003328 = 0;
*(uint32_t*)0x20003330 = 0;
*(uint32_t*)0x20003338 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003300ul, 1ul, 0ul);
	return 0;
}
