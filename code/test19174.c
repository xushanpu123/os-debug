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

uint64_t r[2] = {0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000400, "keyring\000", 8);
memcpy((void*)0x20000440, "syz", 3);
*(uint8_t*)0x20000443 = 0x23;
*(uint8_t*)0x20000444 = 0;
	res = syscall(__NR_add_key, 0x20000400ul, 0x20000440ul, 0ul, 0ul, 0xfffffffd);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000280, "logon\000", 6);
memcpy((void*)0x200002c0, "fscrypt:", 8);
memcpy((void*)0x200002c8, "0000111122223333", 16);
*(uint8_t*)0x200002d8 = 0;
*(uint32_t*)0x20000300 = 0;
memcpy((void*)0x20000304, "\xff\x66\xdb\x63\x26\x6c\xab\x73\xa9\x74\x38\x6f\xe6\x1d\x61\xc5\x5e\xb0\xfc\x1c\xf5\x9d\xef\x28\xa9\x1a\xeb\x72\xa8\x24\xb6\x99\xcd\x45\xe3\x6b\x0c\x62\x5a\xc7\x8f\xe7\x8f\xd5\x2d\xba\xb4\x78\x12\x62\x30\x98\xda\x68\x65\xda\x74\x92\x3c\x89\xa3\x35\x18\xe5", 64);
*(uint32_t*)0x20000344 = 0;
	res = syscall(__NR_add_key, 0x20000280ul, 0x200002c0ul, 0x20000300ul, 0x48ul, r[0]);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000380, "dns_resolver\000", 13);
memcpy((void*)0x200003c0, "syz", 3);
*(uint8_t*)0x200003c3 = 0x23;
*(uint8_t*)0x200003c4 = 0;
	syscall(__NR_keyctl, 0xaul, r[1], 0x20000380ul, 0x200003c0ul, 0);
	return 0;
}
