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
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 0x28;
*(uint64_t*)0x200001c8 = 0x20000100;
memcpy((void*)0x20000100, "\xb8\xdc\xb0\xa6\x87\x94\xdb\x3d\x6b\xb2\xcc\x9c\xd7\xff\xa4\x76\x9f\x5d\x69\x97\x26\xd3\xd7\x06\x2a\x4a\x53\x7e\x0a\x51\x1e\x87\x3d\x42\x58\x8b\x2a\x22\xbd\x0c", 40);
	syscall(__NR_ioctl, r[0], 0x8912, 0x200001c0ul);
	return 0;
}