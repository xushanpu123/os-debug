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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20006540 = 0x200000c0;
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0);
*(uint32_t*)0x200000c4 = htobe32(0x7f000001);
*(uint32_t*)0x20006548 = 0x10;
*(uint64_t*)0x20006550 = 0;
*(uint64_t*)0x20006558 = 0;
*(uint64_t*)0x20006560 = 0;
*(uint64_t*)0x20006568 = 0;
*(uint32_t*)0x20006570 = 0;
*(uint32_t*)0x20006578 = 0;
*(uint64_t*)0x20006580 = 0x20000540;
*(uint16_t*)0x20000540 = 2;
*(uint16_t*)0x20000542 = htobe16(0);
*(uint32_t*)0x20000544 = htobe32(0);
*(uint32_t*)0x20006588 = 0x10;
*(uint64_t*)0x20006590 = 0;
*(uint64_t*)0x20006598 = 0;
*(uint64_t*)0x200065a0 = 0x20004a00;
*(uint64_t*)0x20004a00 = 0x14;
*(uint32_t*)0x20004a08 = 0;
*(uint32_t*)0x20004a0c = 7;
*(uint8_t*)0x20004a10 = 0x83;
*(uint8_t*)0x20004a11 = 3;
*(uint8_t*)0x20004a12 = 0xe7;
*(uint64_t*)0x200065a8 = 0x18;
*(uint32_t*)0x200065b0 = 0;
*(uint32_t*)0x200065b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20006540ul, 2ul, 0ul);
	return 0;
}
