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

uint64_t r[7] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[1], 0x4c81, 0ul);
*(uint32_t*)0x200000c0 = 0;
	res = syscall(__NR_accept4, r[0], 0ul, 0x200000c0ul, 0x80000ul);
	if (res != -1)
		r[2] = res;
	res = syscall(__NR_getuid);
	if (res != -1)
		r[3] = res;
*(uint8_t*)0x20000100 = 0xfe;
*(uint8_t*)0x20000101 = 0x80;
memset((void*)0x20000102, 0, 13);
*(uint8_t*)0x2000010f = 0xaa;
memcpy((void*)0x20000110, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
*(uint16_t*)0x20000120 = htobe16(0);
*(uint16_t*)0x20000122 = htobe16(5);
*(uint16_t*)0x20000124 = htobe16(0x4e23);
*(uint16_t*)0x20000126 = htobe16(7);
*(uint16_t*)0x20000128 = 0;
*(uint8_t*)0x2000012a = 0x40;
*(uint8_t*)0x2000012b = 0x20;
*(uint8_t*)0x2000012c = 0x2b;
*(uint32_t*)0x20000130 = 0;
*(uint32_t*)0x20000134 = r[3];
*(uint64_t*)0x20000138 = 0x800;
*(uint64_t*)0x20000140 = 0x7f;
*(uint64_t*)0x20000148 = 5;
*(uint64_t*)0x20000150 = 0x7fff;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 3;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0x10001;
*(uint64_t*)0x20000178 = 0x101;
*(uint64_t*)0x20000180 = 0xfff;
*(uint64_t*)0x20000188 = 0xf4;
*(uint64_t*)0x20000190 = 7;
*(uint32_t*)0x20000198 = 0x8b2c;
*(uint32_t*)0x2000019c = 0;
*(uint8_t*)0x200001a0 = 2;
*(uint8_t*)0x200001a1 = 1;
*(uint8_t*)0x200001a2 = 3;
*(uint8_t*)0x200001a3 = 3;
*(uint32_t*)0x200001a8 = htobe32(0xa010100);
*(uint32_t*)0x200001b8 = htobe32(0x4d4);
*(uint8_t*)0x200001bc = 0x6c;
*(uint16_t*)0x200001c0 = 2;
*(uint8_t*)0x200001c4 = 0xac;
*(uint8_t*)0x200001c5 = 0x14;
*(uint8_t*)0x200001c6 = 0x14;
*(uint8_t*)0x200001c7 = 0xaa;
*(uint32_t*)0x200001d4 = 0x3507;
*(uint8_t*)0x200001d8 = 6;
*(uint8_t*)0x200001d9 = 0;
*(uint8_t*)0x200001da = 0xb;
*(uint32_t*)0x200001dc = 0xee49;
*(uint32_t*)0x200001e0 = 0;
*(uint32_t*)0x200001e4 = 3;
	syscall(__NR_setsockopt, r[2], 0, 0x11, 0x20000100ul, 0xe8ul);
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[4] = res;
memcpy((void*)0x20000440, "mangle\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint32_t*)0x20000460 = 0;
*(uint32_t*)0x20000464 = 0;
*(uint32_t*)0x20000468 = 0;
*(uint32_t*)0x2000046c = 0;
*(uint32_t*)0x20000470 = 0;
*(uint32_t*)0x20000474 = 0;
memset((void*)0x20000478, 0, 20);
*(uint32_t*)0x2000048c = 0;
*(uint32_t*)0x20000490 = 0;
*(uint32_t*)0x200004c0 = 0x54;
	syscall(__NR_getsockopt, r[4], 0, 0x40, 0x20000440ul, 0x200004c0ul);
*(uint64_t*)0x20000040 = 0;
*(uint16_t*)0x20000048 = 2;
*(uint16_t*)0x2000004a = htobe16(0x4e20);
*(uint8_t*)0x2000004c = 0xac;
*(uint8_t*)0x2000004d = 0x14;
*(uint8_t*)0x2000004e = 0x14;
*(uint8_t*)0x2000004f = 0;
*(uint16_t*)0x20000058 = 2;
*(uint16_t*)0x2000005a = htobe16(0x4e24);
*(uint8_t*)0x2000005c = 0xac;
*(uint8_t*)0x2000005d = 0x14;
*(uint8_t*)0x2000005e = 0x14;
*(uint8_t*)0x2000005f = 0xaa;
*(uint16_t*)0x20000068 = 2;
*(uint16_t*)0x2000006a = htobe16(0x4e24);
*(uint32_t*)0x2000006c = htobe32(0xa010105);
*(uint16_t*)0x20000078 = 0x9e;
*(uint16_t*)0x2000007a = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint16_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0xd;
*(uint64_t*)0x200000a8 = 0;
*(uint16_t*)0x200000b0 = 0x3ff;
	syscall(__NR_ioctl, r[4], 0x890b, 0x20000040ul);
	syscall(__NR_ioctl, -1, 0x4c82, 0);
*(uint32_t*)0x200002c0 = 0x10;
	res = syscall(__NR_accept4, r[4], 0x20000280ul, 0x200002c0ul, 0x80000ul);
	if (res != -1)
		r[5] = res;
*(uint16_t*)0x20000300 = 2;
*(uint16_t*)0x20000302 = htobe16(0x4e21);
*(uint8_t*)0x20000304 = 0xac;
*(uint8_t*)0x20000305 = 0x14;
*(uint8_t*)0x20000306 = 0x14;
*(uint8_t*)0x20000307 = 0xb;
	syscall(__NR_bind, r[5], 0x20000300ul, 0x10ul);
	syscall(__NR_ioctl, -1, 0x4c80, 0ul);
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
	if (res != -1)
		r[6] = res;
	syscall(__NR_ioctl, r[6], 0x4c82, 0);
	syscall(__NR_ioctl, r[6], 0x4c82, 0);
	return 0;
}
