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

#ifndef __NR_execveat
#define __NR_execveat 322
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000100, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000100ul, 0x42ul, 0x1fful);
	if (res != -1)
		r[0] = res;
	syscall(__NR_close, r[0]);
memcpy((void*)0x20000200, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000200ul, 2ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000540, "\xf6\x00\x01\x01\x76\xa0\x3c\xd5\x2d\x10\xef\x3e\x8b\x6d\x6a\x55\x76\x7d\x0d\x98\x32\x7c\x6b\x79\x25\x54\x22\x7f\x61\xa2\xaf\xb2\xf9\xf3\xfa\x21\x80\x64\xb7\x4f\xcf\xc1\x39\xbd\x5c\xe3\x19\x8b\xad\xaf\xa1\x61\x17\x65\x99\x24\x1e\x2c\xb3\xba\x49\xe7\x46\x86\x2f\xd3\xb5\x14\x6f\x88\xfc\xfb\xd7\x33\x79\xbb\x84\xe6\x89\xa3\xd5\x91\xa8\x0e\x69\x58\xdb\x72\x6e\xb7\x9b\x44\x3a\xeb\xe9\x3b\xe7\xd9\x12\x57\x87\xd3\x67\x10\xf1\x35\x77\x37\xb2\x2e\xba\xb3\x59\x5e\x21\x3b\x85\x2c\x9f\xb7\x25\x1f\xd1\x0a\xbb\x11\x60\x5b\x97\x6a\x17\x4f\xa8\x77\xd9\xc0\xee\xf3\x0d\x4a\x3d\xba\x51\x55\xcb\x3f\x1d\x9f\xea\xe1\x00\x43\xe8\x07\x15\xe8\x9a\x0a\x87\xbe\x27\x39\xed\x88\x05\xff\xc9\x48\x4b\xf1\x2c\xff\x62\x69\x1f\x82\x9b\x21\x1a\x51\xcc\x33\xc6\xfd\x14\x15\xc4\x14\xea\xf9\x1c\x87\x17\x85\xfc\x7d\x19\x0d\xc3\x42\x43\x7b\xe7\xa9\x9c\x14\x18\x22\xe5\x8a\xa7\x00\x83\xbd\x4d\x2a\x65\xb5\x1e\x52\x75\x9e\xb1\x2b\x26\x88\x42\x98\x14\x2c\x96\x55\x2a\xa6\x13\xa5\xce\x6e\x05\xfb\xf1\xb8\x0d\x4f\x9b\xcd\x61\x3f\x28\x13\x03\xa8\xb5\x3d\x06\xd2", 256);
	syscall(__NR_write, r[1], 0x20000540ul, 0x100ul);
	syscall(__NR_close, r[1]);
memcpy((void*)0x20000280, "./file1\000", 8);
	syscall(__NR_execveat, 0xffffff9c, 0x20000280ul, 0ul, 0ul, 0ul);
	return 0;
}
