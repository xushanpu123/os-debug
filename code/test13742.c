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
*(uint16_t*)0x20000200 = 0xa;
*(uint16_t*)0x20000202 = htobe16(0);
*(uint32_t*)0x20000204 = htobe32(0);
memcpy((void*)0x20000208, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
*(uint32_t*)0x20000218 = 0;
*(uint8_t*)0x20000280 = 0;
*(uint8_t*)0x20000281 = 0;
*(uint16_t*)0x20000282 = 0x4f;
*(uint32_t*)0x20000284 = 0;
memcpy((void*)0x20000288, "\x39\xa6\x29\xf6\x1f\xba\x11\xba\x41\x3a\x11\x6d\x0f\x0a\x6d\xd4\x56\x9f\xe3\xe0\x1b\x5b\x8f\x12\x19\x30\x8f\xd2\x83\x83\x69\xcb\x6c\x62\x93\x27\xe8\x42\xae\x19\xcd\x4b\xfb\xde\xfc\x08\xee\xd9\xb0\x0d\xd6\x46\x36\x6d\x1d\x75\x04\x69\x68\x10\xec\x9a\xc8\xb4\xb3\xea\xcb\xc0\x6a\x78\xb8\x35\xa6\x1f\x82\x79\xd7\xbb\x4a\x62", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000200ul, 0xd8ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memcpy((void*)0x20000008, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
*(uint32_t*)0x20000018 = 0;
*(uint8_t*)0x20000080 = 0;
*(uint8_t*)0x20000081 = 0;
*(uint16_t*)0x20000082 = 0;
*(uint32_t*)0x20000084 = 0;
memcpy((void*)0x20000088, "\x59\xa4\xae\x53\xbd\x7c\x50\x3f\x73\xd9\x98\x7f\x34\x18\xb5\x44\x42\x36\x79\x9a\xd2\x66\x47\xf1\x87\x21\xee\xed\x7f\xa0\xec\x09\xf9\x21\x20\xb3\xe7\x54\x3b\x95\xff\x82\xd5\x67\xd4\x25\xa2\x75\x95\x0e\x84\xd5\x21\xb7\x26\x98\xba\x39\xd3\x8a\x1a\xab\xf1\x05\xd2\xf4\x29\x0e\x00\x69\xe4\xeb\x38\xcb\x1c\xe8\x1c\xda\xdb\x16", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000000ul, 0xd8ul);
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint64_t*)0x20000048 = htobe64(0);
*(uint64_t*)0x20000050 = htobe64(1);
*(uint32_t*)0x20000058 = 0;
	syscall(__NR_connect, r[0], 0x20000040ul, 0x1cul);
	return 0;
}