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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20001380 = 1;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x20001380ul, 4ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
	syscall(__NR_setsockopt, r[0], 0x29, 0x37, 0x20005780ul, 8ul);
*(uint32_t*)0x20000140 = 0;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x20000140ul, 4ul);
*(uint64_t*)0x20002600 = 0;
*(uint32_t*)0x20002608 = 0;
*(uint64_t*)0x20002610 = 0x200003c0;
*(uint64_t*)0x200003c0 = 0x20000040;
memset((void*)0x20000040, 11, 1);
*(uint64_t*)0x200003c8 = 1;
*(uint64_t*)0x20002618 = 1;
*(uint64_t*)0x20002620 = 0;
*(uint64_t*)0x20002628 = 0;
*(uint32_t*)0x20002630 = 0;
*(uint32_t*)0x20002638 = 0;
*(uint64_t*)0x20002640 = 0;
*(uint32_t*)0x20002648 = 0;
*(uint64_t*)0x20002650 = 0x200006c0;
*(uint64_t*)0x200006c0 = 0x20000600;
memset((void*)0x20000600, 6, 1);
*(uint64_t*)0x200006c8 = 1;
*(uint64_t*)0x20002658 = 1;
*(uint64_t*)0x20002660 = 0;
*(uint64_t*)0x20002668 = 0;
*(uint32_t*)0x20002670 = 0;
*(uint32_t*)0x20002678 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002600ul, 2ul, 0x4000094ul);
	return 0;
}
