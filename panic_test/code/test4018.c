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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000040 = 2;
*(uint16_t*)0x20000042 = htobe16(0x4e21);
*(uint32_t*)0x20000044 = htobe32(0xa010100);
	syscall(__NR_recvfrom, r[0], 0x20000140ul, 0xbbul, 0x10003ul, 0x20000040ul, 0x10ul);
*(uint64_t*)0x200000c0 = 0;
*(uint16_t*)0x200000c8 = 2;
*(uint16_t*)0x200000ca = htobe16(-1);
*(uint32_t*)0x200000cc = htobe32(0);
*(uint16_t*)0x200000d8 = 2;
*(uint16_t*)0x200000da = htobe16(0);
*(uint32_t*)0x200000dc = htobe32(0);
*(uint16_t*)0x200000e8 = 2;
*(uint16_t*)0x200000ea = htobe16(0);
*(uint32_t*)0x200000ec = htobe32(0);
*(uint16_t*)0x200000f8 = 0;
*(uint16_t*)0x200000fa = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint16_t*)0x20000110 = 0;
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint16_t*)0x20000130 = 0;
	syscall(__NR_ioctl, r[0], 0x890c, 0x200000c0ul);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20004500 = 0;
*(uint64_t*)0x20004508 = 0;
	syscall(__NR_recvmmsg, r[1], 0ul, 0ul, 0ul, 0x20004500ul);
memcpy((void*)0x200010c0, "/dev/null\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200010c0ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20004500 = 0;
*(uint64_t*)0x20004508 = 0;
	syscall(__NR_recvmmsg, r[2], 0ul, 0ul, 0ul, 0x20004500ul);
*(uint64_t*)0x20000280 = 0x20000080;
*(uint16_t*)0x20000080 = 0x10;
*(uint16_t*)0x20000082 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0x40000;
*(uint32_t*)0x20000288 = 0xc;
*(uint64_t*)0x20000290 = 0x20000240;
*(uint64_t*)0x20000240 = 0x200002c0;
memcpy((void*)0x200002c0, "8\000\000\000", 4);
*(uint16_t*)0x200002c4 = 0;
memcpy((void*)0x200002c6, "\x00\x02\x28\xbd\x70\x00\xfb\xdb\xdf\x25\xa9\x67\x16\x31\xc8\x03\x00\x00\x00\x08\x00\x08\x00\x7f\x00\x00\x01\x08\x00\x08\x00\xe0\x00\x00\x01\x06\x00\x01\x00\x4e\x22\x00\x00\x81\x94\x89\x8a\x04\x04\x00\x05\x00\x05\x00\x04", 55);
*(uint64_t*)0x20000248 = 0x38;
*(uint64_t*)0x20000298 = 1;
*(uint64_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0;
*(uint32_t*)0x200002b0 = 0;
	syscall(__NR_sendmsg, r[2], 0x20000280ul, 0x4080ul);
	syscall(__NR_socket, 0x10ul, 3ul, 4);
	res = syscall(__NR_epoll_create, 0xef28);
	if (res != -1)
		r[3] = res;
*(uint32_t*)0x20000000 = 0x90000000;
*(uint64_t*)0x20000004 = 0;
	syscall(__NR_epoll_ctl, r[1], 1ul, r[3], 0x20000000ul);
	return 0;
}