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
*(uint64_t*)0x20000440 = 0x20000300;
*(uint16_t*)0x20000300 = 0x10;
*(uint16_t*)0x20000302 = 0;
*(uint32_t*)0x20000304 = 0;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x20000448 = 9;
*(uint64_t*)0x20000450 = 0x20000340;
*(uint64_t*)0x20000340 = 0x200002c0;
*(uint32_t*)0x200002c0 = 0x70;
*(uint16_t*)0x200002c4 = 0;
*(uint16_t*)0x200002c6 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
*(uint8_t*)0x200002d0 = 3;
*(uint8_t*)0x200002d1 = 0;
*(uint16_t*)0x200002d2 = 0;
*(uint64_t*)0x20000348 = 0x70;
*(uint64_t*)0x20000458 = 1;
*(uint64_t*)0x20000460 = 0;
*(uint64_t*)0x20000468 = 0;
*(uint32_t*)0x20000470 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000440ul, 0ul);
	return 0;
}
