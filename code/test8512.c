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
*(uint8_t*)0x20000043 = 0x21;
*(uint8_t*)0x20000044 = 0;
	res = syscall(__NR_add_key, 0x20000000ul, 0x20000040ul, 0ul, 0ul, -1);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = r[0];
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
memset((void*)0x2000008c, 0, 28);
memcpy((void*)0x200000c0, "enc=", 4);
memcpy((void*)0x200000c4, "oaep", 4);
memcpy((void*)0x200000c8, " hash=", 6);
memcpy((void*)0x200000ce, "streebog512\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
	syscall(__NR_keyctl, 0x1aul, 0x20000080ul, 0x200000c0ul, 0ul, 0ul);
	return 0;
}