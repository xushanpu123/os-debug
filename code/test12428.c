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
memcpy((void*)0x20000040, "/sys/power/resume", 17);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x8002ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 0x31;
*(uint8_t*)0x200000c4 = 0x75;
*(uint16_t*)0x200000c5 = 0;
*(uint32_t*)0x200000c7 = 0x26;
memcpy((void*)0x200000cb, "\x5c\xd1\x8e\xb7\xa2\xba\x59\x58\x18\xba\x6a\x32\x41\x77\x39\x45\x48\x52\xbc\x3a\xca\x64\xf8\x65\xd7\x87\xa2\xf4\xab\x05\xb8\x65\x91\x83\xd6\x93\x96\xa9", 38);
	syscall(__NR_write, r[0], 0x200000c0ul, 0x31ul);
	return 0;
}