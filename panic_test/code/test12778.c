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

memcpy((void*)0x20000240, "logon\000", 6);
memcpy((void*)0x20000280, "fscrypt:", 8);
*(uint8_t*)0x20000288 = 0;
*(uint8_t*)0x20000289 = 0;
*(uint8_t*)0x2000028a = 0;
*(uint8_t*)0x2000028b = 0;
*(uint8_t*)0x2000028c = 0;
*(uint8_t*)0x2000028d = 0;
*(uint8_t*)0x2000028e = 0;
*(uint8_t*)0x2000028f = 0;
*(uint8_t*)0x20000290 = 0;
*(uint8_t*)0x20000291 = 0;
*(uint8_t*)0x20000292 = 0;
*(uint8_t*)0x20000293 = 0;
*(uint8_t*)0x20000294 = 0;
*(uint8_t*)0x20000295 = 0;
*(uint8_t*)0x20000296 = 0;
*(uint8_t*)0x20000297 = 0;
*(uint8_t*)0x20000298 = 0;
*(uint32_t*)0x200002c0 = 0;
memcpy((void*)0x200002c4, "\xc9\xd5\xf2\xa4\x61\xf5\x6c\xca\x82\xbb\xef\x8d\xbd\x29\xc1\xd3\xea\xa7\x84\xc4\x53\xa7\xcc\x29\xd1\xca\x93\x5b\xc0\xde\xc7\x7c\x86\x3d\x37\x3b\x6d\xd3\x00\xe9\xe3\x3d\x3a\x97\x22\xec\xeb\x5c\x77\x0a\x2c\x98\xbd\x44\x47\x4c\xaa\xb2\x5b\x30\x58\x3c\x23\x4b", 64);
*(uint32_t*)0x20000304 = 0;
	syscall(__NR_add_key, 0x20000240ul, 0x20000280ul, 0x200002c0ul, 0x48ul, 0xfffffffb);
	return 0;
}
