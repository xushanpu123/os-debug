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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000000 = 0;
*(uint16_t*)0x20000002 = 0x34;
memcpy((void*)0x20000004, "\xfe\x87\x21\x97\x71\xd1\x2a\x42", 8);
memcpy((void*)0x2000000c, "\xc9\x32\xbf\xde\xa6\x07\x12\x36\xde\x7a\x26\xc1\xa7\x01\x16\xe6\xe1\x3d\x44\xc5\xae\xf1\xde\xc5\xae\x49\x11\xac\x87\x99\x67\xf9", 32);
memcpy((void*)0x2000002c, "\x77\x12\x61\x1d", 4);
memcpy((void*)0x20000030, "\xf2\x45\x86\x69\xb5\xbf\xae\xb7", 8);
	syscall(__NR_setsockopt, r[0], 6, 2, 0x20000000ul, 0x38ul);
	return 0;
}
