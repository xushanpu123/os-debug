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
*(uint32_t*)0x20000000 = 0x20;
*(uint32_t*)0x20000004 = 8;
*(uint32_t*)0x20000008 = htobe32(0xfffffffb);
*(uint32_t*)0x2000000c = htobe32(0);
*(uint32_t*)0x20000010 = htobe32(0);
*(uint32_t*)0x20000014 = htobe32(0);
*(uint32_t*)0x20000018 = htobe32(0x3bd4);
*(uint32_t*)0x2000001c = htobe32(0);
*(uint32_t*)0x20000020 = htobe32(0);
*(uint32_t*)0x20000024 = htobe32(0);
	syscall(__NR_open_by_handle_at, -1, 0x20000000ul, 0ul);
	res = syscall(__NR_socket, 0xaul, 3ul, 0xff);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20001780 = 0x20000000;
*(uint16_t*)0x20000000 = 0;
*(uint8_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20001788 = 0x6e;
*(uint64_t*)0x20001790 = 0;
*(uint64_t*)0x20001798 = 0;
*(uint64_t*)0x200017a0 = 0;
*(uint64_t*)0x200017a8 = 0;
*(uint32_t*)0x200017b0 = 0;
	syscall(__NR_sendmsg, r[1], 0x20001780ul, 0ul);
	return 0;
}