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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000740 = 0x20000640;
*(uint16_t*)0x20000640 = 0x10;
*(uint16_t*)0x20000642 = 0;
*(uint32_t*)0x20000644 = 0;
*(uint32_t*)0x20000648 = 0;
*(uint32_t*)0x20000748 = 0xc;
*(uint64_t*)0x20000750 = 0x20000700;
*(uint64_t*)0x20000700 = 0x20000680;
*(uint32_t*)0x20000680 = 0x14;
*(uint8_t*)0x20000684 = 5;
*(uint8_t*)0x20000685 = 6;
*(uint16_t*)0x20000686 = 0x101;
*(uint32_t*)0x20000688 = 0;
*(uint32_t*)0x2000068c = 0;
*(uint8_t*)0x20000690 = 0;
*(uint8_t*)0x20000691 = 0;
*(uint16_t*)0x20000692 = htobe16(0);
*(uint64_t*)0x20000708 = 0x14;
*(uint64_t*)0x20000758 = 1;
*(uint64_t*)0x20000760 = 0;
*(uint64_t*)0x20000768 = 0;
*(uint32_t*)0x20000770 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000740ul, 0ul);
	return 0;
}
