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
	res = syscall(__NR_socket, 0x10ul, 3ul, 4);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000d80 = 0;
*(uint32_t*)0x20000d88 = 0;
*(uint64_t*)0x20000d90 = 0x20000d40;
*(uint64_t*)0x20000d40 = 0x20000980;
*(uint32_t*)0x20000980 = 0x14;
*(uint16_t*)0x20000984 = 0x15;
*(uint16_t*)0x20000986 = 1;
*(uint32_t*)0x20000988 = 0;
*(uint32_t*)0x2000098c = 0;
*(uint8_t*)0x20000990 = 0x10;
*(uint8_t*)0x20000991 = 0;
*(uint64_t*)0x20000d48 = 0x14;
*(uint64_t*)0x20000d98 = 1;
*(uint64_t*)0x20000da0 = 0;
*(uint64_t*)0x20000da8 = 0;
*(uint32_t*)0x20000db0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000d80ul, 0ul);
	return 0;
}
