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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0xa;
	syscall(__NR_setsockopt, r[0], 0, 3, 0x20000080ul, 4ul);
memcpy((void*)0x20000100, "\x47\x3c\xb9\x1f\x00\x00\xfc\x18\x6a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 28);
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0);
*(uint8_t*)0x200000c4 = 0xac;
*(uint8_t*)0x200000c5 = 0x14;
*(uint8_t*)0x200000c6 = 0x14;
*(uint8_t*)0x200000c7 = 0xaa;
	syscall(__NR_sendto, r[0], 0x20000100ul, 0x1cul, 0ul, 0x200000c0ul, 0x10ul);
	return 0;
}
