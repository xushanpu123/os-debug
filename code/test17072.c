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

uint64_t r[3] = {0x0, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000140, "keyring\000", 8);
memcpy((void*)0x20000180, "syz", 3);
*(uint8_t*)0x20000183 = 0x21;
*(uint8_t*)0x20000184 = 0;
	res = syscall(__NR_add_key, 0x20000140ul, 0x20000180ul, 0ul, 0ul, 0xfffffffd);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000700, "logon\000", 6);
memcpy((void*)0x20000740, "fscrypt:", 8);
memcpy((void*)0x20000748, "e8dab99234bb312e", 16);
*(uint8_t*)0x20000758 = 0;
*(uint32_t*)0x20000780 = 0;
memcpy((void*)0x20000784, "\xb6\xb7\x0c\x2f\x67\xec\x73\xa5\x62\xde\xc6\x3c\x79\x0c\x38\x83\x57\xc6\x2c\x66\xf1\x6d\x07\x7f\xf2\x61\xef\xc7\x8d\x07\x48\xea\x01\x96\xce\xb4\x38\x73\xcb\xfb\x21\x5a\x2a\x43\x70\xc3\x16\x60\xbc\x33\xd5\x8c\x27\x62\x66\xd9\x31\xae\xc3\xdf\x13\x9f\xc7\xc9", 64);
*(uint32_t*)0x200007c4 = 0;
	res = syscall(__NR_add_key, 0x20000700ul, 0x20000740ul, 0x20000780ul, 0x48ul, r[0]);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000800, "keyring\000", 8);
memcpy((void*)0x20000840, "syz", 3);
*(uint8_t*)0x20000843 = 0x21;
*(uint8_t*)0x20000844 = 0;
	res = syscall(__NR_add_key, 0x20000800ul, 0x20000840ul, 0ul, 0ul, r[0]);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x20000000, "asymmetric\000", 11);
memcpy((void*)0x20000040, "builtin_and_secondary_trusted\000", 30);
	syscall(__NR_keyctl, 0x1dul, r[2], 0x20000000ul, 0x20000040ul, 0);
	syscall(__NR_keyctl, 0x1eul, r[1], r[0], r[2], 0ul);
	return 0;
}
