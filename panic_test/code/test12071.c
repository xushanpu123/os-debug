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
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "\x1a\xb3\xce\x21\x23\x8c\xb9\x32\x5d\x15\x29\x77\x76\x3b\x3f\x24\x0f\x85\x92\xd9\x96\x4a\x88\xd4\x37\xa7\x0d\x16\xa8\x0a\x74\x48\xcd\xd4\x7a\xa9\x8f\x5d\x8b\x0a\x2a\x23\x51\x80\x22\x8a\x02\x92\x2c\xaf\x7e\x21\x54\x6d\x7c\xdb\x93\x07\xce\x24\x1b\x6b\x93\x05\x7f\x0b\xbb\x17\xde\x8e\x20\x19\xed\x83\x84\x44\x5b\xc1\x9f\x35\xea\x01\x00\x45\x57\x54\xda\x08\x00\x00\x00\xbf\x9e\x3d\xd7\xf1\x74\x07\xf5\x76\x27\x71\xd0\xce\x23\x05\x97\x92\x60\x22\x8b\x9e\xbc\xc3\x76\x69\x44\xd7\xae\xb6\x80\xe3\xa3\x6c\xdc\x00\x0d\xe4\x6e\xd3\x7c\x72\x3a\x02\xe7\xcb\x63\xbe\x32\x42\x00\x00\x00\x00", 144);
	syscall(__NR_setsockopt, r[0], 0, 0x30, 0x20000040ul, 0x90ul);
	return 0;
}