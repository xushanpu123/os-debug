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
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0x20000040;
*(uint64_t*)0x20000040 = 0x20000200;
*(uint32_t*)0x20000200 = 0x14;
*(uint8_t*)0x20000204 = 0;
*(uint8_t*)0x20000205 = 9;
*(uint16_t*)0x20000206 = 5;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint8_t*)0x20000210 = 0;
*(uint8_t*)0x20000211 = 0;
*(uint16_t*)0x20000212 = htobe16(0);
*(uint64_t*)0x20000048 = 0x14;
*(uint64_t*)0x20000098 = 1;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000080ul, 0ul);
	return 0;
}
