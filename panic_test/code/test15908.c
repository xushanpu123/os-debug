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
*(uint8_t*)0x20000040 = 0xfe;
*(uint8_t*)0x20000041 = 0x80;
memset((void*)0x20000042, 0, 13);
*(uint8_t*)0x2000004f = 0xaa;
*(uint32_t*)0x20000050 = 0;
*(uint8_t*)0x20000054 = 0;
*(uint8_t*)0x20000055 = 0;
*(uint16_t*)0x20000056 = 0xd;
*(uint16_t*)0x20000058 = 0;
*(uint16_t*)0x2000005a = 0;
*(uint32_t*)0x2000005c = 0;
	syscall(__NR_setsockopt, -1, 0x29, 0x20, 0x20000040ul, 0x20ul);
*(uint8_t*)0x20000000 = -1;
*(uint8_t*)0x20000001 = 1;
memset((void*)0x20000002, 0, 13);
*(uint8_t*)0x2000000f = 1;
memcpy((void*)0x20000010, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
*(uint8_t*)0x20000020 = 0xfe;
*(uint8_t*)0x20000021 = 0x80;
memset((void*)0x20000022, 0, 13);
*(uint8_t*)0x2000002f = 0xaa;
*(uint32_t*)0x20000030 = 0;
*(uint16_t*)0x20000034 = 0;
*(uint16_t*)0x20000036 = 0;
*(uint32_t*)0x20000038 = 0;
*(uint64_t*)0x20000040 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
	syscall(__NR_ioctl, -1, 0x890c, 0x20000000ul);
*(uint32_t*)0x20000000 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x40, 0x20000000ul, 4ul);
	return 0;
}
