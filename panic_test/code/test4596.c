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

#ifndef __NR_pidfd_open
#define __NR_pidfd_open 434
#endif

uint64_t r[3] = {0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "./file0\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x200000c0ul, 0x101240ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_getpgrp, -1);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_pidfd_open, r[1], 0ul);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x20000100, "./file0\000", 8);
memcpy((void*)0x20000140, "9p\000", 3);
memcpy((void*)0x20000180, "trans=fd,", 9);
memcpy((void*)0x20000189, "rfdno", 5);
*(uint8_t*)0x2000018e = 0x3d;
sprintf((char*)0x2000018f, "0x%016llx", (long long)r[0]);
*(uint8_t*)0x200001a1 = 0x2c;
memcpy((void*)0x200001a2, "wfdno", 5);
*(uint8_t*)0x200001a7 = 0x3d;
sprintf((char*)0x200001a8, "0x%016llx", (long long)r[2]);
*(uint8_t*)0x200001ba = 0x2c;
*(uint8_t*)0x200001bb = 0;
	syscall(__NR_mount, 0ul, 0x20000100ul, 0x20000140ul, 0ul, 0x20000180ul);
	return 0;
}