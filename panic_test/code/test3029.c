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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "\x46\x46\xba\x27\x46\x97\xa8\xd0\xc1\x2b\x90\x42\x0c\xfa\x3c\xb7\xd3\x59\xa8\xfb\xd3\xe5\xd8\x71\x56\x70\xbc\xb0\x5c\x82\xdb\x01\xd2\x3b\x0f\xf8\xb8\xda\xaf\x34\xfe\xca\x72\x82\xb1\x34\xda\x72\x00\x37\x3f\x98\xf2\x79\x31\xdd\xad\x97\x95\x4d\xcf\x83\x08\xa8\xbe\xd4\xc8\x58\x23\xb8\xd2\x71\x67\x0f\x06\x7d\x33\x9b\x2e\x16\xe4\x26\x99\x42\x0d\x2e\x59\xc8\xc0\xaa\x54\x77\x25\x46\xc1\x64\xa8\x3b\x53\x49\x7d\x6a\x7f\xb3\x27\x2e\x75\xbf\x20\x60\x92\x86\xa5\xad\xb8\x95\x6d\x24\x5d\x6d\xe3\x1b\xca\x82\x83\x65\x9c\x32\x1f\x11\xf1\x55\x68\xf4\x45\xbf\xff\xa3\x99\xe4\x62\x8a\xa4\x01", 144);
	syscall(__NR_setsockopt, r[0], 0, 0x30, 0x20000000ul, 0x90ul);
	return 0;
}
