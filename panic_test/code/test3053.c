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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000080 = 0x20000000;
memcpy((void*)0x20000000, "\xc4\xa2\x81\x90\x4c\x81\x00\xd0\xe6\xc4\xe2\x7d\x31\x1b\x66\x44\x0f\x50\xc3\xc4\xc2\x79\x58\x24\x93\xc4\x61\xfe\x5b\x88\x03\x00\x00\x00\x66\xf0\x42\x83\x94\x0a\x01\x00\x00\x00\x3a\xf2\x0f\x2c\x31\x14\x4c\xc4\x62\x35\x93\x6c\xb0\xa1", 58);
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
	syscall(__NR_rt_sigaction, 0xb, 0x20000080ul, 0ul, 8ul, 0x200000c0ul);
	return 0;
}
