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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000000 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0x20000100;
*(uint64_t*)0x20000100 = 0x200002c0;
*(uint32_t*)0x200002c0 = 0x24;
*(uint16_t*)0x200002c4 = 0x66;
*(uint16_t*)0x200002c6 = 0xfff9;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
*(uint8_t*)0x200002d0 = 0;
*(uint8_t*)0x200002d1 = 0;
*(uint16_t*)0x200002d2 = 0;
memcpy((void*)0x200002d4, "\x10\xe6\x36\x99\x27\x80\xef\x27\x0d\x2b\x2a\x01\x7c", 13);
*(uint64_t*)0x20000108 = 0x24;
*(uint64_t*)0x20000018 = 1;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000000ul, 0ul);
	return 0;
}
