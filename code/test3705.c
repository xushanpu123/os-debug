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
*(uint16_t*)0x20000780 = 2;
*(uint64_t*)0x20000788 = 0x20000740;
*(uint16_t*)0x20000740 = 0x40;
*(uint8_t*)0x20000742 = 0;
*(uint8_t*)0x20000743 = 0;
*(uint32_t*)0x20000744 = 0;
*(uint16_t*)0x20000748 = 6;
*(uint8_t*)0x2000074a = 0;
*(uint8_t*)0x2000074b = 0;
*(uint32_t*)0x2000074c = 0;
	syscall(__NR_setsockopt, r[0], 1, 0x1a, 0x20000780ul, 0x10ul);
	return 0;
}
