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
memcpy((void*)0x20000500, "/dev/vcsa\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000500ul, 0x80002ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "\x00\xfa\x49\x4e\x46\x2f\x55\xf5\x2e\x45\xd8\x18\x9f\xe5\x87\x37\x06\xf8\xbc\x94\x19\x75\xf6\x56\x50\x21\x58\xce\x61\x08\x2b\xc1\x68\xdb\x32\x25\x3c\x97\x97\x3e\xc6\x47\x90\xe6\xa8\x9f\xd4\xf0\xa0\x36\x2e\xc4\xe9\x40\x1a\xf9\xc7\xcd\x81\x9f\x5f\x7d\xa8\x95\xaf\x6c\x54\x9e\x61\xca\x7b\xe1\x5c\xc1\x13\x43\xba\x7d\xfe\xaa\xc6\x66\x33\xc0\x20\x4f\xec\x0e\x90\xd6\x05\x87\x0e\xf6\x9d\x23\x27\x46\x5c\x3e\x7e\x08\x55\x83\x9b\x03\x33\x7c\xd8\x81\xf0\x16\x10\xe0\x2d\x66\xb5\x19\x21", 119);
	syscall(__NR_pwrite64, r[0], 0x20000080ul, 0xffffff4ful, 0ul);
	return 0;
}
