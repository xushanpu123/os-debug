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
memcpy((void*)0x20000400, "/dev/ptmx\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000400ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x540a, 2ul);
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint8_t*)0x20000090 = 0;
memcpy((void*)0x20000091, "\xc0\x72\x71\x9a\xd3\x21\x34\x1e\xf3\x80\xab\xd6\x14\xba\xb5\x3b\xfd\x0f\x17", 19);
*(uint32_t*)0x200000a4 = 0;
*(uint32_t*)0x200000a8 = 0;
	syscall(__NR_ioctl, r[0], 0x402c542b, 0x20000080ul);
	return 0;
}