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
memcpy((void*)0x20000080, "keyring\000", 8);
memcpy((void*)0x200000c0, "syz", 3);
*(uint8_t*)0x200000c3 = 0x22;
*(uint8_t*)0x200000c4 = 0;
	res = syscall(__NR_add_key, 0x20000080ul, 0x200000c0ul, 0ul, 0ul, -1);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000100, "keyring\000", 8);
memcpy((void*)0x20000140, "syz", 3);
*(uint8_t*)0x20000143 = 0x20;
*(uint8_t*)0x20000144 = 0;
	syscall(__NR_add_key, 0x20000100ul, 0x20000140ul, 0ul, 0ul, r[0]);
	syscall(__NR_keyctl, 3ul, r[0], 0, 0, 0);
	return 0;
}