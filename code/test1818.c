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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20004c80 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0x4e23);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x20004c88 = 0x1c;
*(uint64_t*)0x20004c90 = 0;
*(uint64_t*)0x20004c98 = 0;
*(uint64_t*)0x20004ca0 = 0;
*(uint64_t*)0x20004ca8 = 0;
*(uint32_t*)0x20004cb0 = 0;
*(uint32_t*)0x20004cb8 = 0;
*(uint64_t*)0x20004cc0 = 0x20001180;
*(uint16_t*)0x20001180 = 0xa;
*(uint16_t*)0x20001182 = htobe16(0x4e21);
*(uint32_t*)0x20001184 = htobe32(0);
memcpy((void*)0x20001188, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20001198 = 0;
*(uint32_t*)0x20004cc8 = 0x1c;
*(uint64_t*)0x20004cd0 = 0;
*(uint64_t*)0x20004cd8 = 0;
*(uint64_t*)0x20004ce0 = 0x20000040;
*(uint64_t*)0x20000040 = r[1];
*(uint64_t*)0x20004ce8 = 0x18;
*(uint32_t*)0x20004cf0 = 0;
*(uint32_t*)0x20004cf8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20004c80ul, 2ul, 0ul);
	return 0;
}
