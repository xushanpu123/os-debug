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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0x20000340;
*(uint64_t*)0x20000340 = 0x20000300;
*(uint32_t*)0x20000300 = 0x1c;
*(uint16_t*)0x20000304 = 0x24;
*(uint16_t*)0x20000306 = 1;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 0;
*(uint32_t*)0x20000310 = 0;
*(uint16_t*)0x20000314 = 6;
*(uint16_t*)0x20000316 = 3;
*(uint8_t*)0x20000318 = 0xfe;
*(uint8_t*)0x20000319 = 0;
*(uint64_t*)0x20000348 = 0x1c;
*(uint64_t*)0x20000398 = 1;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000380ul, 0ul);
	return 0;
}
