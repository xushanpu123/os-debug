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
*(uint32_t*)0x20000000 = htobe32(0x7f000001);
*(uint32_t*)0x20000004 = htobe32(0x7f000001);
*(uint16_t*)0x20000008 = 0;
memcpy((void*)0x2000000a, "\xdd\xc0\x81\xb3\xc2\xd4\x8b\xb6\x9c\x1c\x65\xfb\x4c\xae\x54\x33\xa8\x9f\x88\xdd\x14\x5b\xcc\x28\xeb\x2e\x55\xed\x08\xda\x52\x8f", 32);
*(uint32_t*)0x2000002c = 0;
*(uint32_t*)0x20000030 = 0;
*(uint32_t*)0x20000034 = 0;
*(uint32_t*)0x20000038 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0xd3, 0x20000000ul, 0x3cul);
	return 0;
}
