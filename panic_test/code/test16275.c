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
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
*(uint64_t*)0x200006c0 = 0;
*(uint32_t*)0x200006c8 = 0;
*(uint64_t*)0x200006d0 = 0x200005c0;
*(uint64_t*)0x200005c0 = 0x20000040;
memcpy((void*)0x20000040, "\x77\xc8", 2);
*(uint64_t*)0x200005c8 = 2;
*(uint64_t*)0x200006d8 = 1;
*(uint64_t*)0x200006e0 = 0;
*(uint64_t*)0x200006e8 = 0;
*(uint32_t*)0x200006f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200006c0ul, 0x48000ul);
*(uint64_t*)0x20000640 = 0;
*(uint32_t*)0x20000648 = 0;
*(uint64_t*)0x20000650 = 0x20000340;
*(uint64_t*)0x20000340 = 0x20000740;
memcpy((void*)0x20000740, "\x9b\x16", 2);
*(uint64_t*)0x20000348 = 2;
*(uint64_t*)0x20000658 = 1;
*(uint64_t*)0x20000660 = 0;
*(uint64_t*)0x20000668 = 0;
*(uint32_t*)0x20000670 = 0;
*(uint32_t*)0x20000678 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000640ul, 1ul, 0ul);
	return 0;
}
