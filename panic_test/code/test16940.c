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
*(uint32_t*)0x20000180 = htobe32(0);
*(uint32_t*)0x20000184 = htobe32(0);
*(uint16_t*)0x20000188 = 0;
memcpy((void*)0x2000018a, "\xd4\x13\xf3\x22\xbd\x11\x41\x8f\x34\xc2\x92\x45\xea\xd3\xe4\x9d\xf3\x9b\xe0\xd4\xc2\xe9\x89\x48\x3e\xb3\x75\x54\xd4\x69\x40\xf2", 32);
*(uint32_t*)0x200001ac = 0x10001;
*(uint32_t*)0x200001b0 = 5;
*(uint32_t*)0x200001b4 = 0xa812;
*(uint32_t*)0x200001b8 = 0xffffb217;
	syscall(__NR_setsockopt, r[0], 0, 0xcd, 0x20000180ul, 0x3cul);
	return 0;
}
