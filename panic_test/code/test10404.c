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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000000 = 0xfe;
*(uint8_t*)0x20000001 = 0x80;
memset((void*)0x20000002, 0, 13);
*(uint8_t*)0x2000000f = 0xaa;
*(uint32_t*)0x20000010 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x1b, 0x20000000ul, 0x14ul);
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000040, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[1], 0x8933, 0x20000040ul);
	if (res != -1)
r[2] = *(uint32_t*)0x20000050;
*(uint8_t*)0x20000080 = 0xfe;
*(uint8_t*)0x20000081 = 0x80;
memset((void*)0x20000082, 0, 13);
*(uint8_t*)0x2000008f = 0xaa;
*(uint32_t*)0x20000090 = r[2];
	syscall(__NR_setsockopt, r[1], 0x29, 0x1b, 0x20000080ul, 0x14ul);
	return 0;
}
