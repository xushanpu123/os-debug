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

memcpy((void*)0x20000000, "logon\000", 6);
memcpy((void*)0x20000040, "fscrypt:", 8);
*(uint8_t*)0x20000048 = 0;
*(uint8_t*)0x20000049 = 0;
*(uint8_t*)0x2000004a = 0;
*(uint8_t*)0x2000004b = 0;
*(uint8_t*)0x2000004c = 0;
*(uint8_t*)0x2000004d = 0;
*(uint8_t*)0x2000004e = 0;
*(uint8_t*)0x2000004f = 0;
*(uint8_t*)0x20000050 = 0;
*(uint8_t*)0x20000051 = 0;
*(uint8_t*)0x20000052 = 0;
*(uint8_t*)0x20000053 = 0;
*(uint8_t*)0x20000054 = 0;
*(uint8_t*)0x20000055 = 0;
*(uint8_t*)0x20000056 = 0;
*(uint8_t*)0x20000057 = 0;
*(uint8_t*)0x20000058 = 0;
*(uint32_t*)0x20000080 = 0;
memcpy((void*)0x20000084, "\xf9\x39\x33\x6d\x2a\x4b\x61\x00\xc8\xc9\xc8\x39\xac\x8f\xc8\xcf\xc6\x86\x68\x61\xee\x3a\xad\xc3\x85\x7b\x16\xea\xb7\x53\x65\xf7\x5c\x4e\xf5\x47\x06\xa2\x38\x58\x27\x18\xce\x29\x0d\xf1\x35\x74\x5d\x32\xfa\x3d\x5d\x0a\xbf\x30\xae\xae\x25\x96\xad\xa7\x79\x99", 64);
*(uint32_t*)0x200000c4 = 0;
	syscall(__NR_add_key, 0x20000000ul, 0x20000040ul, 0x20000080ul, 0x48ul, 0xfffffffd);
	return 0;
}
