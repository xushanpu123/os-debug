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
memcpy((void*)0x20000400, "keyring\000", 8);
memcpy((void*)0x20000440, "syz", 3);
*(uint8_t*)0x20000443 = 0x23;
*(uint8_t*)0x20000444 = 0;
	res = syscall(__NR_add_key, 0x20000400ul, 0x20000440ul, 0ul, 0ul, 0xfffffffd);
	if (res != -1)
		r[1] = res;
	syscall(__NR_keyctl, 9ul, r[0], r[1], 0, 0);
	return 0;
}
