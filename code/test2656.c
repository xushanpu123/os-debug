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
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0x4e20);
*(uint32_t*)0x20000084 = htobe32(0);
memset((void*)0x20000088, 0, 10);
memset((void*)0x20000092, 255, 2);
*(uint8_t*)0x20000094 = 0xac;
*(uint8_t*)0x20000095 = 0x14;
*(uint8_t*)0x20000096 = 0x14;
*(uint8_t*)0x20000097 = 0xbb;
*(uint32_t*)0x20000098 = 0;
	syscall(__NR_connect, r[0], 0x20000080ul, 0x1cul);
*(uint64_t*)0x20001480 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0x4e21);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 10);
memset((void*)0x20000012, 255, 2);
*(uint32_t*)0x20000014 = htobe32(0xe0000002);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x20001488 = 0x1c;
*(uint64_t*)0x20001490 = 0;
*(uint64_t*)0x20001498 = 0;
*(uint64_t*)0x200014a0 = 0;
*(uint64_t*)0x200014a8 = 0;
*(uint32_t*)0x200014b0 = 0;
*(uint32_t*)0x200014b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20001480ul, 1ul, 0ul);
	return 0;
}
