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

uint64_t r[3] = {0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200000c0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_ioctl, r[0], 0x4c82, 0);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[0], 0x4c81, r[1]);
memcpy((void*)0x20004780, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20004780ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_accept, r[2], 0ul, 0ul);
memcpy((void*)0x20000500, "wlan1\000\000\000\000\000\000\000\000\000\000\000", 16);
	syscall(__NR_ioctl, r[2], 0x8933, 0x20000500ul);
memcpy((void*)0x200001c0, "keyring\000", 8);
memcpy((void*)0x20000200, "syz", 3);
*(uint8_t*)0x20000203 = 0x21;
*(uint8_t*)0x20000204 = 0;
	syscall(__NR_add_key, 0x200001c0ul, 0x20000200ul, 0ul, 0ul, 0);
memcpy((void*)0x20000000, ".dead\000", 6);
memcpy((void*)0x20000040, "syz", 3);
*(uint8_t*)0x20000043 = 0x22;
*(uint8_t*)0x20000044 = 0;
memcpy((void*)0x20000100, "\x0f\x20\xd9\x74\x65\x69\x4d\x13\x3b\x03\x1f\x5d\x9e\x01\x00\xdc\x60\x46\x9e\x5b\x5b\xf4\x9f\xf5\x9d\xcc\x97\x5f\xea\xbe\x67\x93\x95\x15\x19", 35);
	syscall(__NR_add_key, 0x20000000ul, 0x20000040ul, 0x20000100ul, 0x23ul, 0);
memcpy((void*)0x200001c0, "keyring\000", 8);
memcpy((void*)0x20000200, "syz", 3);
*(uint8_t*)0x20000203 = 0x21;
*(uint8_t*)0x20000204 = 0;
	syscall(__NR_add_key, 0x200001c0ul, 0x20000200ul, 0ul, 0ul, 0);
	syscall(__NR_keyctl, 7ul, 0, 0, 0, 0);
memcpy((void*)0x200001c0, "keyring\000", 8);
memcpy((void*)0x20000200, "syz", 3);
*(uint8_t*)0x20000203 = 0x21;
*(uint8_t*)0x20000204 = 0;
	syscall(__NR_add_key, 0x200001c0ul, 0x20000200ul, 0ul, 0ul, 0);
memcpy((void*)0x20000080, "logon\000", 6);
memcpy((void*)0x20000280, "fscrypt:", 8);
memcpy((void*)0x20000288, "e8dab99234bb312e", 16);
*(uint8_t*)0x20000298 = 0;
*(uint32_t*)0x200002c0 = 0;
memcpy((void*)0x200002c4, "\x21\x7d\x1c\x4a\x06\xfb\x1c\xee\xe8\xe2\xfe\xf2\x9e\x25\xa8\x96\xf4\xee\xe7\xaa\xb2\xec\x95\x37\x14\xbd\xdb\x22\x0c\xcf\xfd\xad\x58\xc5\x2d\xe5\x3f\x84\x03\x04\xa5\x71\x06\x63\x47\x2f\xfe\x1a\x1c\xe9\xa7\xa8\x26\x50\xdb\x43\x9f\x41\x5d\x48\x4a\x10\xc1\x8b", 64);
*(uint32_t*)0x20000304 = 0x2a;
	syscall(__NR_add_key, 0x20000080ul, 0x20000280ul, 0x200002c0ul, 0x48ul, 0);
	return 0;
}