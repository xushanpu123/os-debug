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
	syscall(__NR_fcntl, -1, 0x40bul, 0x20000000ul);
	syscall(__NR_mmap, 0x20000000ul, 0x2000ul, 0x2000004ul, 0x32ul, -1, 0ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000300 = 2;
*(uint16_t*)0x20000302 = htobe16(0);
*(uint32_t*)0x20000304 = htobe32(0x7f000001);
	syscall(__NR_sendto, r[0], 0ul, 0ul, 0ul, 0x20000300ul, 0x10ul);
*(uint64_t*)0x20001540 = 0;
*(uint32_t*)0x20001548 = 0;
*(uint64_t*)0x20001550 = 0;
*(uint64_t*)0x20001558 = 0;
*(uint64_t*)0x20001560 = 0;
*(uint64_t*)0x20001568 = 0;
*(uint32_t*)0x20001570 = 0;
	syscall(__NR_recvmsg, r[0], 0x20001540ul, 0ul, 0);
	return 0;
}
