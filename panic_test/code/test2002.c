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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 0x5ad, 0x20000080ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000080;
	syscall(__NR_io_destroy, r[0]);
	res = syscall(__NR_socket, 1ul, 2ul, 0);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000a40 = 0;
*(uint32_t*)0x20000a48 = 0;
*(uint64_t*)0x20000a50 = 0;
*(uint64_t*)0x20000a58 = 0;
*(uint64_t*)0x20000a60 = 0;
*(uint64_t*)0x20000a68 = 0;
*(uint32_t*)0x20000a70 = 0;
*(uint32_t*)0x20000a78 = 0;
	syscall(__NR_recvmmsg, r[1], 0x20000a40ul, 1ul, 0ul, 0ul);
	syscall(__NR_io_getevents, r[0], 0ul, 0ul, 0ul, 0ul);
	return 0;
}
