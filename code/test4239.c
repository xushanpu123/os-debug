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

uint64_t r[5] = {0xffffffffffffffff, 0x0, 0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000340, "\x01\x00\x00\x00\x01\x00\x00\x00\x18\x00\x00\x00", 12);
*(uint32_t*)0x2000034c = -1;
memcpy((void*)0x20000350, "\x01\x00\x00\x00\x00\x00\x00\x00\x2e\x2f\x66\x69\x6c\xc1\xfb\xa2\x37\xc0\x34\x16\x91\xce\x10\xbd\x6b\x60\xd9\x8d\x65\x30\x00\xf9\xb5\xed\x00\xcf\x38\xfc\xd2\xfb\x4c\xb5\x3f\xf9\x4e\xc4\x78\xc9\xcc\x04\xa8\x60\xcd\x62\x97\xae\xe1\x55\xa6\x68\xc3\x54\xbc\x46\x6d\xfc\x4e\x41\xb5\x65\x8e\xbf\x05\x21\x43\x00\x3a\x4c\xc3\x51\xc0\x3e\xd0\xbc\x8b\x5e\xba\x9d\xfc\x9e\x56\xc1\xfd\xcc\x73\x61\x96\x5d\x36\xe1\x93\x9f\x9f\xba\x84\xe6\x5a\xc3\xf9\x8e\xa8\xfb\x2f\xe1\xe0\x89\xd9\x6a\x3a\xe8\x7c\x2a\x60\xf6\xb1\xef\xac\xd7\xf7\xd8\xc5\x88\x26\x0b\x4f\xf9\x12\x14\x65\x84\x48\x43\x54\x29\xf7\xf2\xa3\x84\xc4\xb6\x22\x96\x06\xff\x0a\x98\x73\x6a\x4e\x44\xb9\x32\xbb\x95\x3e\x4d\xb3\x17\x3c\xec\xf1\xde\x83\xcc\x9d\x5d\xba\xcd\x41\x6e\xe2\x1d\x09\x0e\xda\x68\x2e\xbe\xe1\xa3\x87\x09\xd0\x35\xf2\x87\x3c", 197);
	res = syscall(__NR_ioctl, -1, 0xc0189373, 0x20000340ul);
	if (res != -1)
r[0] = *(uint32_t*)0x2000034c;
*(uint16_t*)0x20000080 = 0;
*(uint8_t*)0x20000082 = 1;
*(uint8_t*)0x20000083 = 0;
*(uint32_t*)0x20000084 = 0xb278;
*(uint32_t*)0x20000088 = htobe32(-1);
*(uint8_t*)0x2000008c = 0xac;
*(uint8_t*)0x2000008d = 0x1e;
*(uint8_t*)0x2000008e = 0;
*(uint8_t*)0x2000008f = 1;
	syscall(__NR_setsockopt, r[0], 0, 0xca, 0x20000080ul, 0x10ul);
	syscall(__NR_semget, 0x798e2636ul, 4ul, 0x200ul);
	res = syscall(__NR_semget, 0ul, 3ul, 0x43cul);
	if (res != -1)
		r[1] = res;
*(uint8_t*)0x20000100 = 0xfc;
*(uint8_t*)0x20000101 = 1;
memset((void*)0x20000102, 0, 13);
*(uint8_t*)0x2000010f = 1;
*(uint32_t*)0x20000110 = 0x5a;
*(uint32_t*)0x20000114 = 0;
	syscall(__NR_ioctl, r[0], 0x8936, 0x20000100ul);
*(uint16_t*)0x20000000 = 4;
*(uint16_t*)0x20000002 = 0x800;
*(uint16_t*)0x20000004 = 0x1000;
*(uint16_t*)0x20000006 = 4;
*(uint16_t*)0x20000008 = 0x7ff;
*(uint16_t*)0x2000000a = 0x1800;
*(uint16_t*)0x2000000c = 2;
*(uint16_t*)0x2000000e = 0x7ff;
*(uint16_t*)0x20000010 = 0x1000;
*(uint16_t*)0x20000012 = 2;
*(uint16_t*)0x20000014 = 0x1f;
*(uint16_t*)0x20000016 = 0;
*(uint16_t*)0x20000018 = 2;
*(uint16_t*)0x2000001a = 0x81;
*(uint16_t*)0x2000001c = 0;
*(uint16_t*)0x2000001e = 1;
*(uint16_t*)0x20000020 = 0x8001;
*(uint16_t*)0x20000022 = 0x1800;
*(uint16_t*)0x20000024 = 2;
*(uint16_t*)0x20000026 = 5;
*(uint16_t*)0x20000028 = 0x1800;
	syscall(__NR_semop, r[1], 0x20000000ul, 7ul);
	syscall(__NR_keyctl, 0x20ul, 0, -1, 0x76ul, 0);
memcpy((void*)0x200000c0, "/dev/bsg\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200000c0ul, 2ul, 0ul);
	if (res != -1)
		r[2] = res;
	res = syscall(__NR_semget, 0x798e2636ul, 4ul, 0x200ul);
	if (res != -1)
		r[3] = res;
*(uint16_t*)0x20000140 = 0;
*(uint16_t*)0x20000142 = 7;
*(uint16_t*)0x20000144 = 0x800;
*(uint16_t*)0x20000146 = 3;
*(uint16_t*)0x20000148 = 3;
*(uint16_t*)0x2000014a = 0x1000;
*(uint16_t*)0x2000014c = 2;
*(uint16_t*)0x2000014e = 0;
*(uint16_t*)0x20000150 = 0x400;
*(uint16_t*)0x20000152 = 2;
*(uint16_t*)0x20000154 = 4;
*(uint16_t*)0x20000156 = 0x800;
*(uint16_t*)0x20000158 = 0;
*(uint16_t*)0x2000015a = 0x1f;
*(uint16_t*)0x2000015c = 0x1000;
*(uint16_t*)0x2000015e = 2;
*(uint16_t*)0x20000160 = 2;
*(uint16_t*)0x20000162 = 0;
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0x989680;
	syscall(__NR_semtimedop, r[3], 0x20000140ul, 6ul, 0x20000180ul);
*(uint32_t*)0x200001c0 = r[0];
*(uint64_t*)0x200001c8 = 4;
*(uint64_t*)0x200001d0 = 3;
*(uint64_t*)0x200001d8 = 3;
	res = syscall(__NR_ioctl, r[2], 0xc020f509, 0x200001c0ul);
	if (res != -1)
r[4] = *(uint32_t*)0x200001c0;
memcpy((void*)0x20000200, "custom1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 256);
	syscall(__NR_ioctl, r[4], 0xc1086201, 0x20000200ul);
	return 0;
}
