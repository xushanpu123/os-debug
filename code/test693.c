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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe, 0x20000340ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000340;
r[1] = *(uint32_t*)0x20000344;
	}
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[2] = res;
	syscall(__NR_sendfile, r[1], r[2], 0ul, 0x2000007ul);
*(uint64_t*)0x20005140 = 0x20004f40;
memset((void*)0x20004f40, 83, 1);
*(uint64_t*)0x20005148 = 1;
	syscall(__NR_vmsplice, r[0], 0x20005140ul, 1ul, 0ul);
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000100;
memcpy((void*)0x20000100, "\x14\x00\x00\x00\x01\x04\x01", 7);
*(uint64_t*)0x20000088 = 0x14;
*(uint64_t*)0x200000d8 = 1;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
	syscall(__NR_sendmsg, r[2], 0x200000c0ul, 0ul);
	return 0;
}
