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

#ifndef __NR_mount_setattr
#define __NR_mount_setattr 442
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000180 = 0x20000040;
*(uint16_t*)0x20000040 = 0x10;
*(uint16_t*)0x20000042 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x20000188 = 0xc;
*(uint64_t*)0x20000190 = 0;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000180ul, 0ul);
memcpy((void*)0x20000140, "./file0\000", 8);
*(uint64_t*)0x20000000 = 0;
*(uint64_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0;
*(uint32_t*)0x20000018 = -1;
	syscall(__NR_mount_setattr, -1, 0x20000140ul, 0ul, 0x20000000ul, 0x48ul);
	return 0;
}