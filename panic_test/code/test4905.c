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

#ifndef __NR_pwritev2
#define __NR_pwritev2 328
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200002c0, "./file0\000", 8);
	res = syscall(__NR_creat, 0x200002c0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_ioctl, r[0], 0x40086602, 0x20000040ul);
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_truncate, 0x20000000ul, 0x400ef5dul);
*(uint64_t*)0x20000200 = 0x20000080;
memcpy((void*)0x20000080, "\x7e\xf1\x47\x65\xc0\x30\x0a\x0a\x38\x5d\x6a\xa9\xe2\xe0\xbc\x47\xad\x8d\xac\x28\x89\x7b\xd8\x8f\x23\x7b\x35\x4c\x6f\x79\xe9\x11\x05\x78\x96\x07\x6c\x98\xbf\x3f\x77\x02\x6c\xdd\x98\xdf\x34\x83\x6f\x4b\xc2\xbc\xa8\x8f\xf6\xbd\xcb\xa7\xa9\x47\x9f\xf7\x70\x09\x5f\x85\x67\x64\xf1\x58\xe5\x27\xdf\xb2\xd6\x2d\xac\xd3\x98\x40\x4f\x35\xba\x82", 84);
*(uint64_t*)0x20000208 = 0x54;
*(uint64_t*)0x20000210 = 0x20000100;
memcpy((void*)0x20000100, "\xd2\xb0\x21\xed\x95\x41\x8b\xd8\xe1\xd3\xd8\x0a\x63\xe7\xcb\x5d\x93\xb5\xee\xdc\x5f\xd3\x28\x3b\x79\xe0\xb2\x0a\x8e\x50\xf9\xfd\x10\x0a\xbf\xb4\xad\x31\xdf\x33\x0c\x31\xd0\x9d\xeb\x17\x85\xf2\x69\x87\x9f\x62\xca\x9e\xca\x8f\xd2\xac\x5e\xf6\x6d\x70\x77\xbc", 64);
*(uint64_t*)0x20000218 = 0x40;
*(uint64_t*)0x20000220 = 0x20000140;
memcpy((void*)0x20000140, "\xca\x95\x74\x86\xd3\xba\x22\x01\x46\xa1\xbb\xcb\xd0\x21\x2c\x78", 16);
*(uint64_t*)0x20000228 = 0x10;
	syscall(__NR_pwritev2, r[0], 0x20000200ul, 3ul, 0, 0, 0x15ul);
	syscall(__NR_fallocate, r[1], 3ul, 0ul, 0x80000000ul);
	return 0;
}