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
memcpy((void*)0x20000340, "keyring\000", 8);
memcpy((void*)0x20000380, "syz", 3);
*(uint8_t*)0x20000383 = 0x22;
*(uint8_t*)0x20000384 = 0;
	res = syscall(__NR_add_key, 0x20000340ul, 0x20000380ul, 0ul, 0ul, 0xfffffffe);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "asymmetric\000", 11);
memcpy((void*)0x20000040, "keyring\000", 8);
	syscall(__NR_keyctl, 0x1dul, r[0], 0x20000000ul, 0x20000040ul, 0);
	return 0;
}
