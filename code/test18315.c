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
	syscall(__NR_unshare, 0x48000000ul);
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000200 = 0;
*(uint16_t*)0x20000208 = 2;
*(uint16_t*)0x2000020a = htobe16(0);
*(uint32_t*)0x2000020c = htobe32(0);
*(uint16_t*)0x20000218 = 2;
*(uint16_t*)0x2000021a = htobe16(0);
*(uint8_t*)0x2000021c = 0xac;
*(uint8_t*)0x2000021d = 0x1e;
*(uint8_t*)0x2000021e = 0;
*(uint8_t*)0x2000021f = 1;
*(uint16_t*)0x20000228 = 2;
*(uint16_t*)0x2000022a = htobe16(0);
*(uint8_t*)0x2000022c = 0xac;
*(uint8_t*)0x2000022d = 0x14;
*(uint8_t*)0x2000022e = 0x14;
*(uint8_t*)0x2000022f = 0xbb;
*(uint16_t*)0x20000238 = 7;
*(uint16_t*)0x2000023a = 0;
*(uint64_t*)0x20000240 = 0;
*(uint64_t*)0x20000248 = 0;
*(uint16_t*)0x20000250 = 0;
*(uint64_t*)0x20000258 = 0;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint16_t*)0x20000270 = 0;
	syscall(__NR_ioctl, r[0], 0x890c, 0x20000200ul);
	return 0;
}
