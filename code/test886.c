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

#ifndef __NR_close_range
#define __NR_close_range 436
#endif

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
	syscall(__NR_close_range, -1, -1, 2ul);
*(uint64_t*)0x200004c0 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0x20000480;
*(uint64_t*)0x20000480 = 0x20000440;
*(uint32_t*)0x20000440 = 0x14;
*(uint16_t*)0x20000444 = 0;
*(uint16_t*)0x20000446 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint8_t*)0x20000450 = 0xd;
*(uint8_t*)0x20000451 = 0;
*(uint16_t*)0x20000452 = 0;
*(uint64_t*)0x20000488 = 0x14;
*(uint64_t*)0x200004d8 = 1;
*(uint64_t*)0x200004e0 = 0;
*(uint64_t*)0x200004e8 = 0;
*(uint32_t*)0x200004f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200004c0ul, 0ul);
	return 0;
}
