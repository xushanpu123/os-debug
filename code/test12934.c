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
memcpy((void*)0x20000080, "/dev/cdrom\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 0x800ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000140, "\x85\xe5\xfd\x3c\x5c\xd3\x00\x83\xb4\xa1\x6b\xb3", 12);
*(uint64_t*)0x20000150 = 0x20000040;
memset((void*)0x20000040, 37, 1);
*(uint32_t*)0x20000158 = 1;
*(uint32_t*)0x2000015c = 0x4e;
*(uint64_t*)0x20000160 = 0;
*(uint8_t*)0x20000168 = 2;
*(uint32_t*)0x2000016c = 0;
*(uint32_t*)0x20000170 = 0;
*(uint64_t*)0x20000178 = 0;
	syscall(__NR_ioctl, r[0], 0x5393, 0x20000140ul);
	return 0;
}
