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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200002c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[0], 0x8933, 0x200002c0ul);
	if (res != -1)
r[1] = *(uint32_t*)0x200002d0;
memcpy((void*)0x20000580, "\x63\x15\xb2\x80\x00\x00\x00\xf6\x8a\x9a\x84\xac\xa3\xa2\x53\x2d\x48\xd8\x5e\xdc\x55\x84\x22\xa7\x9e\x8a\x60\x7b\x8c\xf2\x2e\x46\x07\x96\x82\xa8\x6c\x14\x97\xc3", 40);
*(uint16_t*)0x20000240 = 0x11;
*(uint16_t*)0x20000242 = htobe16(0);
*(uint32_t*)0x20000244 = r[1];
*(uint16_t*)0x20000248 = 1;
*(uint8_t*)0x2000024a = 0;
*(uint8_t*)0x2000024b = 6;
memset((void*)0x2000024c, 0, 6);
memset((void*)0x20000252, 0, 2);
	syscall(__NR_sendto, r[0], 0x20000580ul, 0xadul, 0ul, 0x20000240ul, 0x14ul);
	return 0;
}