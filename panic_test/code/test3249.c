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
memcpy((void*)0x20000000, "logon\000", 6);
memcpy((void*)0x20000080, "fscrypt:", 8);
memcpy((void*)0x20000088, "85baa174f0cb1142", 16);
*(uint8_t*)0x20000098 = 0;
*(uint32_t*)0x20000100 = 0;
memcpy((void*)0x20000104, "\x7e\x7f\xd9\x7c\xfc\x88\xb6\x9a\x5f\xaa\x88\x34\x13\xaa\x02\x70\x37\xd3\x8d\xa9\xe5\xcb\x7e\x0c\x8c\xda\xe7\xb8\x84\x05\xcf\x16\xf5\xd0\xef\xd5\x53\x3d\xd8\xe0\xfa\x2b\x84\x84\xb3\xe6\x35\x07\xdd\x5b\xde\xa0\x27\x4a\xb5\x2a\x92\x60\xdb\xa3\xd8\x8c\x29\xfd", 64);
*(uint32_t*)0x20000144 = 0;
	res = syscall(__NR_add_key, 0x20000000ul, 0x20000080ul, 0x20000100ul, 0x48ul, -1);
	if (res != -1)
		r[0] = res;
	syscall(__NR_keyctl, 3ul, r[0], 0, 0, 0);
	syscall(__NR_keyctl, 0xful, r[0], 0ul, 0, 0);
	return 0;
}