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
memcpy((void*)0x20000280, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000280ul, 1ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000380 = htobe32(0x67446698);
*(uint32_t*)0x20000384 = 0;
*(uint16_t*)0x20000388 = 0;
*(uint16_t*)0x2000038a = 0;
*(uint32_t*)0x2000038c = 0;
memcpy((void*)0x20000390, "\x25\x04\x4b\x83\x33\xb9\xa9\xc5\x38\x2a\x2f\xac\x9a\x0f\xe5\x0b\xf2\xc9\x18\x3b\x16\x79\x4e\x8c\x4f\x31\xee\xc8\xa5\x48\x90\x98\xef\x3e\xdd\x8c\x4b\x39\x64\xe7\xc9\x12\x3d\x79\xf0\x05\xce\xc3\x2b\x54\x33\x64\x30\x61\xea\xf8\xf4\x97\x78\x3c\x0a\xa8\x65\x36\x64", 65);
	syscall(__NR_write, r[0], 0x20000380ul, 0xfffffe4bul);
	return 0;
}