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
	res = syscall(__NR_socket, 0x10ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200001c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200001d0 = 0x200000c0;
memcpy((void*)0x200000c0, "\x67\x72\x30\x3a\x00\x8e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 16);
*(uint32_t*)0x200000d0 = 0;
memcpy((void*)0x200000d4, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x45\x00\x00\xd4\x00\x00\x00\x00\x00\x00\x90\x78\xe0", 25);
	syscall(__NR_ioctl, r[0], 0x89f1, 0x200001c0ul);
	return 0;
}