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

#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

const int kInitNetNsFd = 201;

static long syz_init_net_socket(volatile long domain, volatile long type, volatile long proto)
{
	return syscall(__NR_socket, domain, type, proto);
}

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000100 = 1;
*(uint64_t*)0x20000108 = 0x200000c0;
*(uint16_t*)0x200000c0 = 6;
*(uint8_t*)0x200000c2 = 0;
*(uint8_t*)0x200000c3 = 0;
*(uint32_t*)0x200000c4 = 0;
	res = syscall(__NR_seccomp, 1ul, 0xcul, 0x20000100ul);
	if (res != -1)
		r[0] = res;
syz_init_net_socket(0x10, 3, 0x10);
	res = syscall(__NR_epoll_create1, 0ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000000 = 0;
*(uint64_t*)0x20000004 = 0;
	syscall(__NR_epoll_ctl, r[1], 1ul, r[0], 0x20000000ul);
	return 0;
}
