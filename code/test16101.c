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
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000080 = 0;
*(uint16_t*)0x20000088 = 2;
*(uint16_t*)0x2000008a = 0;
*(uint32_t*)0x2000008c = htobe32(0xe0000002);
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
*(uint16_t*)0x20000098 = 0x1f;
memset((void*)0x2000009a, 170, 5);
*(uint8_t*)0x2000009f = 0;
*(uint16_t*)0x200000a8 = 0x27;
*(uint32_t*)0x200000ac = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint16_t*)0x200000b8 = 7;
*(uint16_t*)0x200000ba = 0;
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint16_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint16_t*)0x200000f0 = 0;
	syscall(__NR_ioctl, r[0], 0x890b, 0x20000080ul);
	return 0;
}