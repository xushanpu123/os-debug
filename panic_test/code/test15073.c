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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

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
memcpy((void*)0x200000c0, "/dev/nvram\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200000c0ul, 0x22040ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[1], 0x81009431, 0x20000100ul);
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_ioctl, r[0], 0x40086602, 0x20000040ul);
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20002640 = 0x20000080;
memset((void*)0x20000080, 167, 1);
*(uint64_t*)0x20002648 = 1;
	syscall(__NR_pwritev, r[0], 0x20002640ul, 1ul, 0x101ded2, 0);
	syscall(__NR_fallocate, r[2], 3ul, 0ul, 0x80000000ul);
	return 0;
}
