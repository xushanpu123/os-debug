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

memcpy((void*)0x20000100, "logon\000", 6);
	syscall(__NR_add_key, 0x20000100ul, 0ul, 0ul, 0ul, -1);
memcpy((void*)0x20000140, "logon\000", 6);
memcpy((void*)0x20000180, "fscrypt:", 8);
*(uint8_t*)0x20000188 = 0;
*(uint8_t*)0x20000189 = 0;
*(uint8_t*)0x2000018a = 0;
*(uint8_t*)0x2000018b = 0;
*(uint8_t*)0x2000018c = 0;
*(uint8_t*)0x2000018d = 0;
*(uint8_t*)0x2000018e = 0;
*(uint8_t*)0x2000018f = 0;
*(uint8_t*)0x20000190 = 0;
*(uint8_t*)0x20000191 = 0;
*(uint8_t*)0x20000192 = 0;
*(uint8_t*)0x20000193 = 0;
*(uint8_t*)0x20000194 = 0;
*(uint8_t*)0x20000195 = 0;
*(uint8_t*)0x20000196 = 0;
*(uint8_t*)0x20000197 = 0;
*(uint8_t*)0x20000198 = 0;
*(uint32_t*)0x20000280 = 0;
memcpy((void*)0x20000284, "\xb5\xc3\x5c\x9e\xf0\x00\x56\x88\xd7\xf3\x3c\xc2\xb9\xa3\xf3\x14\x24\x97\x8d\xa9\xd6\x1e\x87\xf9\x5a\x93\x3c\x46\x05\x00\x87\xb9\x0f\x06\xc6\x46\xd1\xa3\xfc\x5f\x3a\x4f\xcf\x51\x94\x13\x8f\xfc\xc1\xd7\xc1\x3b\xcd\x3c\x5b\x88\xe6\x0d\xc3\x20\x31\x0a\xd4\x99", 64);
*(uint32_t*)0x200002c4 = 0;
	syscall(__NR_add_key, 0x20000140ul, 0x20000180ul, 0x20000280ul, 0x48ul, 0xfffffffe);
	return 0;
}
