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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "keyring\000", 8);
memcpy((void*)0x20000040, "syz", 3);
*(uint8_t*)0x20000043 = 0x20;
*(uint8_t*)0x20000044 = 0;
	res = syscall(__NR_add_key, 0x20000000ul, 0x20000040ul, 0ul, 0ul, -1);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20001500, "logon\000", 6);
memcpy((void*)0x20001540, "fscrypt:", 8);
*(uint8_t*)0x20001548 = 0;
*(uint8_t*)0x20001549 = 0;
*(uint8_t*)0x2000154a = 0;
*(uint8_t*)0x2000154b = 0;
*(uint8_t*)0x2000154c = 0;
*(uint8_t*)0x2000154d = 0;
*(uint8_t*)0x2000154e = 0;
*(uint8_t*)0x2000154f = 0;
*(uint8_t*)0x20001550 = 0;
*(uint8_t*)0x20001551 = 0;
*(uint8_t*)0x20001552 = 0;
*(uint8_t*)0x20001553 = 0;
*(uint8_t*)0x20001554 = 0;
*(uint8_t*)0x20001555 = 0;
*(uint8_t*)0x20001556 = 0;
*(uint8_t*)0x20001557 = 0;
*(uint8_t*)0x20001558 = 0;
*(uint32_t*)0x20001580 = 0;
memcpy((void*)0x20001584, "\x8f\xb8\x8d\xf3\x4f\xe7\x34\x79\xb4\x23\x7f\xf5\x13\x30\x18\xf1\xa7\xca\xa5\xe8\x74\xfb\x89\xed\x75\xe5\xbb\xff\x56\xa6\x70\x68\x5b\x72\x92\x47\xed\x8f\x14\x1e\x35\xad\x92\xa8\x73\xbf\xb5\xeb\x44\xf9\xda\xcc\x81\x40\x51\x02\x35\x8c\xf0\x77\x4e\xe9\x62\xd8", 64);
*(uint32_t*)0x200015c4 = 0;
	syscall(__NR_add_key, 0x20001500ul, 0x20001540ul, 0x20001580ul, 0x48ul, r[0]);
	return 0;
}