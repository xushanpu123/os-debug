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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000980 = 0;
*(uint32_t*)0x20000988 = 0;
*(uint64_t*)0x20000990 = 0x20000940;
*(uint64_t*)0x20000940 = 0x20000000;
memcpy((void*)0x20000000, "\x1c\x00\x00\x00\x76\x00\x1f\x0a", 8);
*(uint64_t*)0x20000948 = 0x1c;
*(uint64_t*)0x20000998 = 1;
*(uint64_t*)0x200009a0 = 0;
*(uint64_t*)0x200009a8 = 0;
*(uint32_t*)0x200009b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000980ul, 0ul);
	return 0;
}
