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
memcpy((void*)0x20000180, "keyring\000", 8);
memcpy((void*)0x200001c0, "syz", 3);
*(uint8_t*)0x200001c3 = 0x23;
*(uint8_t*)0x200001c4 = 0;
	res = syscall(__NR_add_key, 0x20000180ul, 0x200001c0ul, 0ul, 0ul, 0xfffffffc);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000440, "keyring\000", 8);
memcpy((void*)0x20000480, "syz", 3);
*(uint8_t*)0x20000483 = 0x22;
*(uint8_t*)0x20000484 = 0;
	res = syscall(__NR_add_key, 0x20000440ul, 0x20000480ul, 0ul, 0ul, r[0]);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000640, "keyring\000", 8);
memcpy((void*)0x20000680, "syz", 3);
*(uint8_t*)0x20000683 = 0x23;
*(uint8_t*)0x20000684 = 0;
	res = syscall(__NR_add_key, 0x20000640ul, 0x20000680ul, 0ul, 0ul, 0xfffffffe);
	if (res != -1)
		r[2] = res;
	syscall(__NR_keyctl, 8ul, r[1], r[2], 0, 0);
memcpy((void*)0x20000140, "keyring\000", 8);
memcpy((void*)0x20000400, "syz", 3);
*(uint8_t*)0x20000403 = 0x23;
*(uint8_t*)0x20000404 = 0;
	syscall(__NR_add_key, 0x20000140ul, 0x20000400ul, 0ul, 0ul, r[1]);
memcpy((void*)0x20000000, "keyring\000", 8);
memcpy((void*)0x20000040, "syz", 3);
*(uint8_t*)0x20000043 = 0x23;
*(uint8_t*)0x20000044 = 0;
	syscall(__NR_request_key, 0x20000000ul, 0x20000040ul, 0ul, r[0]);
	return 0;
}