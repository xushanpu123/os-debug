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
*(uint32_t*)0x20000180 = 8;
	syscall(__NR_setsockopt, r[0], 1, 0x41, 0x20000180ul, 4ul);
*(uint64_t*)0x20001fc0 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0x7f000001);
*(uint32_t*)0x20001fc8 = 0x10;
*(uint64_t*)0x20001fd0 = 0x20000140;
*(uint64_t*)0x20000140 = 0x200000c0;
memcpy((void*)0x200000c0, "\xde\x0c\xcb\xa2\xa1\xe1\x68\xd7\xb1\x59\x86\x26\x6d\x56\x30\x69\xd0\xe6\x8b\xf7\x0f\xee\x9e\xaf\x27\xbd\x51\x34\xfd\x9a\x87\x24\x74\x18\x7d\x41\xc9\xcd\xcb\x9a\x94\x7b\x05\x66\x09\x53\xaa\x60\x1c\x65\x05\x82\x42\x7c\x5a\x0a", 56);
*(uint64_t*)0x20000148 = 0x38;
*(uint64_t*)0x20001fd8 = 1;
*(uint64_t*)0x20001fe0 = 0;
*(uint64_t*)0x20001fe8 = 0;
*(uint32_t*)0x20001ff0 = 0;
*(uint32_t*)0x20001ff8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20001fc0ul, 1ul, 0ul);
	return 0;
}
