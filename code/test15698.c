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
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000600 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint8_t*)0x20000008 = 0xfe;
*(uint8_t*)0x20000009 = 0x80;
memset((void*)0x2000000a, 0, 13);
*(uint8_t*)0x20000017 = 0xbb;
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x20000608 = 0x1c;
*(uint64_t*)0x20000610 = 0;
*(uint64_t*)0x20000618 = 0;
*(uint64_t*)0x20000620 = 0;
*(uint64_t*)0x20000628 = 0;
*(uint32_t*)0x20000630 = 0;
*(uint32_t*)0x20000638 = 0;
*(uint64_t*)0x20000640 = 0x20000080;
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0);
*(uint32_t*)0x20000084 = htobe32(0);
memcpy((void*)0x20000088, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\001", 16);
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x20000648 = 0x17;
*(uint64_t*)0x20000650 = 0;
*(uint64_t*)0x20000658 = 0;
*(uint64_t*)0x20000660 = 0;
*(uint64_t*)0x20000668 = 0;
*(uint32_t*)0x20000670 = 0;
*(uint32_t*)0x20000678 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000600ul, 2ul, 0ul);
	return 0;
}