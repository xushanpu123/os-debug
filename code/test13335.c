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
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20005200 = 0x20000200;
*(uint16_t*)0x20000200 = 0xa;
*(uint16_t*)0x20000202 = htobe16(0x4e24);
*(uint32_t*)0x20000204 = htobe32(0);
memset((void*)0x20000208, 0, 16);
*(uint32_t*)0x20000218 = 0;
*(uint32_t*)0x20005208 = 0x1c;
*(uint64_t*)0x20005210 = 0;
*(uint64_t*)0x20005218 = 0;
*(uint64_t*)0x20005220 = 0x20001800;
*(uint64_t*)0x20001800 = 0x18;
*(uint32_t*)0x20001808 = 0x29;
*(uint32_t*)0x2000180c = 0x37;
*(uint8_t*)0x20001810 = 0;
*(uint8_t*)0x20001811 = 0;
memset((void*)0x20001812, 0, 6);
*(uint64_t*)0x20001818 = 0x14;
*(uint32_t*)0x20001820 = 0x29;
*(uint32_t*)0x20001824 = 8;
*(uint32_t*)0x20001828 = 0;
*(uint64_t*)0x20001830 = 0x18;
*(uint32_t*)0x20001838 = 0x29;
*(uint32_t*)0x2000183c = 0x36;
*(uint8_t*)0x20001840 = 0;
*(uint8_t*)0x20001841 = 0;
memset((void*)0x20001842, 0, 6);
*(uint64_t*)0x20001848 = 0x14;
*(uint32_t*)0x20001850 = 0x29;
*(uint32_t*)0x20001854 = 0x3e;
*(uint32_t*)0x20001858 = 0;
*(uint64_t*)0x20001860 = 0x14;
*(uint32_t*)0x20001868 = 0x29;
*(uint32_t*)0x2000186c = 0x43;
*(uint32_t*)0x20001870 = 0;
*(uint64_t*)0x20005228 = 0x78;
*(uint32_t*)0x20005230 = 0;
*(uint32_t*)0x20005238 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20005200ul, 1ul, 0ul);
	return 0;
}