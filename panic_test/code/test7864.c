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
memcpy((void*)0x200000c0, "keyring\000", 8);
memcpy((void*)0x20000200, "syz", 3);
*(uint8_t*)0x20000203 = 0x23;
*(uint8_t*)0x20000204 = 0;
	res = syscall(__NR_add_key, 0x200000c0ul, 0x20000200ul, 0ul, 0ul, -1);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200001c0, "keyring\000", 8);
memcpy((void*)0x20000200, "syz", 3);
*(uint8_t*)0x20000203 = 0x20;
*(uint8_t*)0x20000204 = 0;
	res = syscall(__NR_add_key, 0x200001c0ul, 0x20000200ul, 0ul, 0ul, -1);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20002ac0, "asymmetric\000", 11);
memcpy((void*)0x20000080, "key_or_keyring:", 15);
sprintf((char*)0x2000008f, "0x%016llx", (long long)r[1]);
*(uint8_t*)0x200000a1 = 0;
	syscall(__NR_keyctl, 0x1dul, r[0], 0x20002ac0ul, 0x20000080ul, 0);
	syscall(__NR_keyctl, 8ul, r[1], r[0], 0, 0);
	return 0;
}
