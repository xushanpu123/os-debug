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
memcpy((void*)0x20000080, "logon\000", 6);
memcpy((void*)0x200000c0, "fscrypt:", 8);
memcpy((void*)0x200000c8, "0000111122223333", 16);
*(uint8_t*)0x200000d8 = 0;
*(uint32_t*)0x20000140 = 0;
memcpy((void*)0x20000144, "\x76\xa8\xb3\xcf\x9f\x83\x80\xda\xc0\x1f\x99\x87\xd6\x4a\x27\xe6\xd7\x70\xa3\x8b\x45\xf9\x21\x15\xbb\x29\x16\xeb\x6b\xd5\xbe\x7c\x92\xca\x6a\x37\xdd\x45\xa1\xee\x68\x52\xd3\x5e\x9a\xcd\x3d\xbb\xaa\x0f\x24\x9b\x59\x19\xaa\x23\x27\xae\x1f\x49\x30\xce\xb4\xbf", 64);
*(uint32_t*)0x20000184 = 0;
	res = syscall(__NR_add_key, 0x20000080ul, 0x200000c0ul, 0x20000140ul, 0x48ul, 0xfffffffe);
	if (res != -1)
		r[0] = res;
memset((void*)0x20000100, 195, 1);
	syscall(__NR_keyctl, 2ul, r[0], 0x20000100ul, 1ul, 0);
	return 0;
}