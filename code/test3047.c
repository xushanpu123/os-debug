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
	res = syscall(__NR_socket, 0xaul, 3ul, 0x3a);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000140, "\x24\x69\xd2\xa8\x01\x00\x00\x00\x6d\x21\xaa\x0a\x62\x3a\xc5\x19\xd7\x0c\x76\xfb\x66\xfc\x2b\x7f\x21\x98\xf3\x1f\x88\x41\xa5\x98\xc4\xd7\x1e\x02\x7f\x56\xf0\x04\x49\x83\xed\x68\x30\x54\x9b\x72\x3d\xe5\x22\xee\xd3\x81\x00\x00\x00\x00\x00\x00\x00\x81\x61\xe4\x1f\x9c\x70\x56\xba\xc3\x17\x3f\x2a\x9f\xdb\x0a\xfb\xd1\xc2\xf6\xcf\x8d\xdf\x0f\x56\xa6\xcd\x01\x3c\xc2\x81\x21\xe7\x8d\xae\xe3\x98\x99\xc7\x2e\x72\xb1\xf4\xb2\xaa\xab\x3f\xfd\x5f\x8e\xbf\x49\x76\xdb\x7b\xa8\x4f\xcb\x83\x68\x74\x18\xc3\x4d\xcd\xa2\xa8\xc3\xa2\x4f\x56\x59\xbd\x88\x51\xb4\x29\xa4\x1e\x5e\xba\xa4\x39\x79", 144);
	syscall(__NR_setsockopt, r[0], 0x29, 0x30, 0x20000140ul, 0x90ul);
	return 0;
}
