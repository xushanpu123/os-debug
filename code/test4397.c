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
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000440;
*(uint32_t*)0x20000440 = 0x128;
*(uint16_t*)0x20000444 = 0x17;
*(uint16_t*)0x20000446 = 1;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
memcpy((void*)0x20000450, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000460 = htobe32(0);
*(uint8_t*)0x20000464 = 0;
*(uint32_t*)0x20000468 = htobe32(0xe0000002);
*(uint8_t*)0x20000478 = -1;
*(uint8_t*)0x20000479 = 2;
memset((void*)0x2000047a, 0, 13);
*(uint8_t*)0x20000487 = 1;
*(uint32_t*)0x20000488 = htobe32(0);
*(uint16_t*)0x20000498 = htobe16(0);
*(uint16_t*)0x2000049a = htobe16(0);
*(uint16_t*)0x2000049c = htobe16(0);
*(uint16_t*)0x2000049e = htobe16(0);
*(uint16_t*)0x200004a0 = 0;
*(uint8_t*)0x200004a2 = 0;
*(uint8_t*)0x200004a3 = 0;
*(uint8_t*)0x200004a4 = 0;
*(uint32_t*)0x200004a8 = 0;
*(uint32_t*)0x200004ac = 0;
*(uint32_t*)0x200004b0 = htobe32(0xe0000002);
*(uint8_t*)0x200004c0 = 0xfc;
*(uint8_t*)0x200004c1 = 0;
memset((void*)0x200004c2, 0, 13);
*(uint8_t*)0x200004cf = 0;
*(uint16_t*)0x200004d0 = htobe16(0);
*(uint16_t*)0x200004d2 = htobe16(0);
*(uint16_t*)0x200004d4 = htobe16(0);
*(uint16_t*)0x200004d6 = htobe16(0);
*(uint16_t*)0x200004d8 = 0;
*(uint8_t*)0x200004da = 0;
*(uint8_t*)0x200004db = 0;
*(uint8_t*)0x200004dc = 0;
*(uint32_t*)0x200004e0 = 0;
*(uint32_t*)0x200004e4 = 0;
*(uint64_t*)0x200004e8 = 0;
*(uint64_t*)0x200004f0 = 0;
*(uint64_t*)0x200004f8 = 0;
*(uint64_t*)0x20000500 = 0;
*(uint64_t*)0x20000508 = 0;
*(uint64_t*)0x20000510 = 0;
*(uint64_t*)0x20000518 = 0;
*(uint64_t*)0x20000520 = 0;
*(uint64_t*)0x20000528 = 0;
*(uint64_t*)0x20000530 = 0;
*(uint64_t*)0x20000538 = 0;
*(uint64_t*)0x20000540 = 0;
*(uint32_t*)0x20000548 = 0;
*(uint32_t*)0x2000054c = 0;
*(uint8_t*)0x20000550 = 0;
*(uint8_t*)0x20000551 = 0;
*(uint8_t*)0x20000552 = 0;
*(uint8_t*)0x20000553 = 0;
*(uint32_t*)0x20000558 = 0;
*(uint32_t*)0x2000055c = 0;
*(uint32_t*)0x20000560 = 0;
*(uint32_t*)0x20000564 = 0;
*(uint64_t*)0x20000088 = 0x128;
*(uint64_t*)0x200000d8 = 1;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200000c0ul, 0ul);
	return 0;
}