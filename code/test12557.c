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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000340 = 1;
*(uint64_t*)0x20000348 = 0x20000300;
*(uint16_t*)0x20000300 = 6;
*(uint8_t*)0x20000302 = 0;
*(uint8_t*)0x20000303 = 0;
*(uint32_t*)0x20000304 = 0x7fffffff;
	syscall(__NR_seccomp, 1ul, 0ul, 0x20000340ul);
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000100 = 0x20000040;
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = 0;
*(uint32_t*)0x20000044 = htobe32(0);
*(uint64_t*)0x20000048 = htobe64(0);
*(uint64_t*)0x20000050 = htobe64(1);
*(uint32_t*)0x20000058 = 0;
*(uint32_t*)0x2000005c = 0;
*(uint32_t*)0x20000108 = 0x80;
*(uint64_t*)0x20000110 = 0;
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000100ul, 0ul);
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[1] = res;
	syscall(__NR_recvmmsg, r[1], 0ul, 0ul, 0ul, 0ul);
	return 0;
}
