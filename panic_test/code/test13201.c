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
	res = syscall(__NR_socket, 2ul, 3ul, 0x9a);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = htobe32(0xe0000002);
*(uint8_t*)0x20000104 = 0xac;
*(uint8_t*)0x20000105 = 0x14;
*(uint8_t*)0x20000106 = 0x14;
*(uint8_t*)0x20000107 = 0xbb;
*(uint8_t*)0x20000108 = 0xac;
*(uint8_t*)0x20000109 = 0x14;
*(uint8_t*)0x2000010a = 0x14;
*(uint8_t*)0x2000010b = 0xbb;
	syscall(__NR_setsockopt, r[0], 0, 0x27, 0x20000100ul, 0xcul);
*(uint32_t*)0x20000140 = 0;
*(uint16_t*)0x20000148 = 2;
*(uint16_t*)0x2000014a = htobe16(0);
*(uint32_t*)0x2000014c = htobe32(0xe0000002);
*(uint16_t*)0x200001c8 = 2;
*(uint16_t*)0x200001ca = htobe16(0);
*(uint32_t*)0x200001cc = htobe32(0x7f000001);
	syscall(__NR_setsockopt, r[0], 0, 0x2e, 0x20000140ul, 0x108ul);
*(uint32_t*)0x20000140 = 0;
*(uint16_t*)0x20000148 = 2;
*(uint16_t*)0x2000014a = htobe16(0);
*(uint32_t*)0x2000014c = htobe32(0xe0000002);
*(uint16_t*)0x200001c8 = 2;
*(uint16_t*)0x200001ca = htobe16(0);
*(uint32_t*)0x200001cc = htobe32(0x7f000001);
	syscall(__NR_setsockopt, r[0], 0, 0x2e, 0x20000140ul, 0x108ul);
	return 0;
}
