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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_fcntl, r[0], 0ul, r[0]);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000000 = 0x1ff;
	syscall(__NR_setsockopt, r[1], 0, 0x14, 0x20000000ul, 4ul);
*(uint16_t*)0x20000040 = 2;
*(uint16_t*)0x20000042 = htobe16(0x4e20);
*(uint32_t*)0x20000044 = htobe32(0);
	syscall(__NR_bind, r[0], 0x20000040ul, 0x10ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[2] = res;
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0x4e20);
*(uint32_t*)0x200000c4 = htobe32(0);
	syscall(__NR_sendto, r[2], 0ul, 0ul, 0ul, 0x200000c0ul, 0x10ul);
*(uint32_t*)0x20000140 = 4;
	syscall(__NR_setsockopt, r[0], 0, 0x17, 0x20000140ul, 4ul);
	syscall(__NR_recvfrom, r[0], 0ul, 0ul, 0ul, 0ul, 0ul);
	return 0;
}
