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
*(uint32_t*)0x20000080 = 0;
	syscall(__NR_setsockopt, r[0], 0x11, 0xa, 0x20000080ul, 4ul);
*(uint64_t*)0x20001540 = 0x20000200;
*(uint16_t*)0x20000200 = 0xa;
*(uint16_t*)0x20000202 = htobe16(0x800);
*(uint32_t*)0x20000204 = htobe32(0);
*(uint8_t*)0x20000208 = 0xfe;
*(uint8_t*)0x20000209 = 0x80;
memset((void*)0x2000020a, 0, 13);
*(uint8_t*)0x20000217 = 0;
*(uint32_t*)0x20000218 = 0;
*(uint32_t*)0x20001548 = 0x80;
*(uint64_t*)0x20001550 = 0;
*(uint64_t*)0x20001558 = 0;
*(uint64_t*)0x20001560 = 0;
*(uint64_t*)0x20001568 = 0;
*(uint32_t*)0x20001570 = 0;
*(uint32_t*)0x20001578 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20001540ul, 1ul, 0ul);
	return 0;
}
