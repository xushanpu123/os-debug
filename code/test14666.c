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
memcpy((void*)0x20002800, "/dev/cdrom\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20002800ul, 0x902ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000100, "\x1e\xcc\x77\xd7\xbb\x74\xa2\xba\x83\x75\x45\x54", 12);
*(uint64_t*)0x20000110 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x2000011c = 0;
*(uint64_t*)0x20000120 = 0;
*(uint8_t*)0x20000128 = 3;
*(uint32_t*)0x2000012c = 0;
*(uint32_t*)0x20000130 = 0;
*(uint64_t*)0x20000138 = 0;
	syscall(__NR_ioctl, r[0], 0x5393, 0x20000100ul);
	return 0;
}
