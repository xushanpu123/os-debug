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

const int kInitNetNsFd = 201;

static long syz_init_net_socket(volatile long domain, volatile long type, volatile long proto)
{
	return syscall(__NR_socket, domain, type, proto);
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = -1;
res = syz_init_net_socket(0x10, 3, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0x20000180;
*(uint64_t*)0x20000180 = 0x20000080;
*(uint32_t*)0x20000080 = 0x14;
*(uint16_t*)0x20000084 = 0;
*(uint16_t*)0x20000086 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint8_t*)0x20000090 = 3;
*(uint8_t*)0x20000091 = 0;
*(uint16_t*)0x20000092 = 0;
*(uint64_t*)0x20000188 = 0x14;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 0ul);
*(uint64_t*)0x20000400 = 0;
*(uint32_t*)0x20000408 = 0;
*(uint64_t*)0x20000410 = 0x200003c0;
*(uint64_t*)0x200003c0 = 0x20000380;
*(uint32_t*)0x20000380 = 0x14;
*(uint16_t*)0x20000384 = 0;
*(uint16_t*)0x20000386 = 4;
*(uint32_t*)0x20000388 = 0;
*(uint32_t*)0x2000038c = 0;
*(uint8_t*)0x20000390 = 4;
*(uint8_t*)0x20000391 = 0;
*(uint16_t*)0x20000392 = 0;
*(uint64_t*)0x200003c8 = 0x14;
*(uint64_t*)0x20000418 = 1;
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
*(uint32_t*)0x20000430 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000400ul, 0ul);
	return 0;
}
