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
*(uint64_t*)0x200007c0 = 0;
*(uint32_t*)0x200007c8 = 0;
*(uint64_t*)0x200007d0 = 0x20000040;
*(uint64_t*)0x20000040 = 0x200000c0;
memcpy((void*)0x200000c0, "\x70\xf3\x07\x14\x4f\x45\x0e\x45\xf8\x68\x79\x28\x35\x64\x7b\xa6\x66\x55\x2d\x59\x23\x8c\x7f\x0d\x9a\x3a\x24\x78\x97\x30\x6a\x84\xcb\x7d\x4c\x5f\x37\x10\xc0\x91\xab\xec\x45\xac\x17\x0c\x66\x55\xec\xce\x61\xe3\xb0\x5a\x40\xb8\x4f\x95\x74", 59);
*(uint64_t*)0x20000048 = 0x3b;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0x20000200;
memcpy((void*)0x20000200, "\x9f\xee\xe7\xfb\x7e\xe7\x21\xde\xf6\xae\x90\xb5\x08\x4e\x1a\x5f\xda\x32\xa8\xf1\xe3\x8d\x46\x2a\x28\x9d\x4a\x0d\xac\xbc\x82\xac\xd1\xc7\xfb\xf4\x84\x37\xd8\x4b\x8f\xca\xb5\xb6\xd9\x54\xf1\xab\xee\x8c\x34\x90\xb7\x6a\xfe\x42\xa5\x36\x6a\xf1\x93\x82\xbd\x6c\x54\xc7\xa0\xca\x73\x56\xd0\x6e\xcf\xa1\xc7\x73\xc7\x4e\x5f\x77\xe8\x31\xbf\x97\xa4\xf3\xba\x94\xe1\xf6\x15\x28\xba\x28\xc3\x7b\xde\x31\xe6\xa4\x2b\x55\x88\x55\x8e\x98\x3a\xba\x38\x48\xd7\x86\x70", 113);
*(uint64_t*)0x20000068 = 0x71;
*(uint64_t*)0x200007d8 = 3;
*(uint64_t*)0x200007e0 = 0;
*(uint64_t*)0x200007e8 = 0;
*(uint32_t*)0x200007f0 = 0;
*(uint32_t*)0x200007f8 = 0;
	syscall(__NR_sendmmsg, -1, 0x200007c0ul, 1ul, 0ul);
*(uint64_t*)0x20001300 = 0;
*(uint32_t*)0x20001308 = 0;
*(uint64_t*)0x20001310 = 0x200012c0;
*(uint64_t*)0x200012c0 = 0x20000080;
memcpy((void*)0x20000080, "8\000\000\000", 4);
*(uint16_t*)0x20000084 = 0;
memcpy((void*)0x20000086, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0e\x00\x00\x00\x08", 15);
*(uint64_t*)0x200012c8 = 0x38;
*(uint64_t*)0x20001318 = 1;
*(uint64_t*)0x20001320 = 0;
*(uint64_t*)0x20001328 = 0;
*(uint32_t*)0x20001330 = 0;
	syscall(__NR_sendmsg, -1, 0x20001300ul, 0ul);
	syscall(__NR_setsockopt, r[0], 0, 0x40, 0x20000040ul, 0ul);
	return 0;
}
