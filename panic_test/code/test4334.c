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
*(uint64_t*)0x20000200 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0x20000180;
*(uint64_t*)0x20000180 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x1c;
*(uint16_t*)0x200000c4 = 0;
*(uint16_t*)0x200000c6 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint8_t*)0x200000d0 = 4;
*(uint8_t*)0x200000d1 = 0;
*(uint16_t*)0x200000d2 = 0;
*(uint16_t*)0x200000d4 = 8;
*(uint16_t*)0x200000d6 = 1;
*(uint32_t*)0x200000d8 = 0;
*(uint64_t*)0x20000188 = 0x1c;
*(uint64_t*)0x20000218 = 1;
*(uint64_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0;
*(uint32_t*)0x20000230 = 0;
	syscall(__NR_sendmsg, -1, 0x20000200ul, 0ul);
	res = syscall(__NR_socket, 0x10ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0x20000200;
*(uint64_t*)0x20000200 = 0x200000c0;
memcpy((void*)0x200000c0, "\x4c\x00\x00\x00\x52\x00\x01\x00\x00\x00\x00\x00\x00\x20\x00\x00\x0a", 17);
*(uint64_t*)0x20000208 = 0x4c;
*(uint64_t*)0x20000258 = 1;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint32_t*)0x20000270 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000240ul, 0ul);
	return 0;
}
