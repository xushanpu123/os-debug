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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000010 = 0x20000300;
memcpy((void*)0x20000300, "\xbf\x0d\x24\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x04\xef\x5c\xb6\x1e\x73\xc2\x37\xee\xbc\xb0\xc8\xa5\xd9\x25\x73\x4b\xfb\x7d\x91\x9e\xf6\xce\xf1\x11\x23\xcf\x0d", 42);
	syscall(__NR_ioctl, r[0], 0x89f1, 0x20000000ul);
	return 0;
}