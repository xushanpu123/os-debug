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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200001c0, "\x01\x23\x00\x00\x00\x00\x00\x00\xc2\x04\x00\x00\x00\x01\x01\x08\x00\x00\x00\x00\x00\x00\x00\x00\x01\x09\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x07\x21", 40);
	syscall(__NR_setsockopt, r[0], 0x29, 0x36, 0x200001c0ul, 0x128ul);
	syscall(__NR_setsockopt, r[0], 0x29, 0x36, 0ul, 0ul);
	return 0;
}
