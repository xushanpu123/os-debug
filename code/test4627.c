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
*(uint32_t*)0x20000340 = r[0];
*(uint32_t*)0x20000344 = 0;
*(uint32_t*)0x20000348 = 0;
memset((void*)0x2000034c, 0, 28);
memcpy((void*)0x20000380, "enc=", 4);
memcpy((void*)0x20000384, "pkcs1", 5);
memcpy((void*)0x20000389, " hash=", 6);
memcpy((void*)0x2000038f, "crct10dif-generic\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
	syscall(__NR_keyctl, 0x1aul, 0x20000340ul, 0x20000380ul, 0ul, 0ul);
	return 0;
}