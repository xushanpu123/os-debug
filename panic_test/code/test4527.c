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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002ec0 = 0;
*(uint32_t*)0x20002ec8 = 0;
*(uint64_t*)0x20002ed0 = 0x20002e80;
*(uint64_t*)0x20002e80 = 0x20001880;
*(uint32_t*)0x20001880 = 0x10;
*(uint16_t*)0x20001884 = 0;
*(uint16_t*)0x20001886 = 0;
*(uint32_t*)0x20001888 = 0;
*(uint32_t*)0x2000188c = 0;
*(uint64_t*)0x20002e88 = 0x10;
*(uint64_t*)0x20002e90 = 0x20001a40;
*(uint64_t*)0x20002e98 = 0x1404;
*(uint64_t*)0x20002ed8 = 2;
*(uint64_t*)0x20002ee0 = 0;
*(uint64_t*)0x20002ee8 = 0;
*(uint32_t*)0x20002ef0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20002ec0ul, 0ul);
	return 0;
}
