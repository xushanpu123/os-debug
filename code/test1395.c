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
memcpy((void*)0x20000000, "/dev/random\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x182ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000780 = 0x200008c0;
memcpy((void*)0x200008c0, "\x7e\xb5\x97\xad\x5c\x0d\xac\x88\xa7\xdc\x43\x10\x9f\xdb\xa4\xa0\x73\x5c\xbf\x65\xf1\xe2\xba\xf3\x20\x59\x0d\x94\x5c\xb6\x84\x5c\x6e\x49\x25\x97\x78\x81\x86\xae\x5c\xef\x7e\x89\x4b\x0d\xd5\x07\xbd\x8b\xd0\x99\x35\x4f\xda\x56\xce\x69\xba\x27\x31\xa8\x9f\x78\x13", 65);
*(uint64_t*)0x20000788 = 0x41;
	syscall(__NR_pwritev, r[0], 0x20000780ul, 1ul, 0, 0);
	return 0;
}