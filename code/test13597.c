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
*(uint16_t*)0x200003c0 = 0xa;
*(uint16_t*)0x200003c2 = htobe16(0);
*(uint32_t*)0x200003c4 = htobe32(0);
*(uint64_t*)0x200003c8 = htobe64(0);
*(uint64_t*)0x200003d0 = htobe64(1);
*(uint32_t*)0x200003d8 = 0;
*(uint8_t*)0x20000440 = 0;
*(uint8_t*)0x20000441 = 0;
*(uint16_t*)0x20000442 = 0x2f;
*(uint32_t*)0x20000444 = 0;
memcpy((void*)0x20000448, "\xc1\x13\x42\x5a\xbb\x1b\x1a\x6d\xa4\xe5\x3b\x73\xf1\xee\x23\xc2\xbf\x10\xda\xb9\x8a\xe9\x81\x48\x1d\x7d\xce\xa8\x8b\x34\x9a\xf8\x46\xeb\xdc\x1f\x98\x79\x04\x6d\x5d\x98\xb0\x01\x39\x7a\xaa\xf0\xe0\xcc\xc4\x34\xb4\x5e\x71\x01\x45\x7d\x17\x1b\x61\x00\xf9\x13\x72\xf9\x9e\x30\xe0\xad\x10\xbd\xee\xc2\x63\xff\xd1\x7a\xbf\xcd", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x200003c0ul, 0xd8ul);
*(uint16_t*)0x20000680 = 0xa;
*(uint16_t*)0x20000682 = htobe16(0);
*(uint32_t*)0x20000684 = htobe32(0);
*(uint64_t*)0x20000688 = htobe64(0);
*(uint64_t*)0x20000690 = htobe64(1);
*(uint32_t*)0x20000698 = 0;
*(uint8_t*)0x20000700 = 0;
*(uint8_t*)0x20000701 = 0;
*(uint16_t*)0x20000702 = 0x19;
*(uint32_t*)0x20000704 = 0;
memcpy((void*)0x20000708, "\x4f\x1d\xae\x7d\x10\xa7\x5b\xdb\x80\xa2\x3d\x45\xbe\x01\x8b\x8b\x4b\x4c\x13\xee\xbe\x4a\x52\x20\xd7\xb3\x37\xc4\x28\xa1\xb2\xd0\x0e\x5a\xd9\xb6\xb8\x03\xf7\xed\xfc\xec\xb0\x3c\xe8\x4c\xf1\x96\x74\xa3\x44\x69\xc8\x42\x6b\x10\x22\x0c\x20\xc5\x30\xd3\xd8\x6b\xcb\xaa\x42\x84\xfc\x45\xe7\x89\x4c\xa8\xa2\x9f\xdc\x11\x48\x10", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000680ul, 0xd8ul);
	return 0;
}
