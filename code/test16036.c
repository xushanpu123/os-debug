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
*(uint64_t*)0x20000840 = 0;
*(uint32_t*)0x20000848 = 0;
*(uint64_t*)0x20000850 = 0x20000800;
*(uint64_t*)0x20000800 = 0x20000580;
*(uint32_t*)0x20000580 = 0x134;
*(uint16_t*)0x20000584 = 0x17;
*(uint16_t*)0x20000586 = 0x309;
*(uint32_t*)0x20000588 = 0;
*(uint32_t*)0x2000058c = 0;
*(uint32_t*)0x20000590 = htobe32(-1);
*(uint32_t*)0x200005a0 = htobe32(0);
*(uint8_t*)0x200005a4 = 0;
*(uint8_t*)0x200005a8 = 0xfc;
*(uint8_t*)0x200005a9 = 2;
memset((void*)0x200005aa, 0, 13);
*(uint8_t*)0x200005b7 = 0;
*(uint32_t*)0x200005b8 = htobe32(0);
*(uint32_t*)0x200005c8 = htobe32(0xe0000002);
*(uint16_t*)0x200005d8 = htobe16(0);
*(uint16_t*)0x200005da = htobe16(0);
*(uint16_t*)0x200005dc = htobe16(0);
*(uint16_t*)0x200005de = htobe16(0);
*(uint16_t*)0x200005e0 = 0;
*(uint8_t*)0x200005e2 = 0;
*(uint8_t*)0x200005e3 = 0;
*(uint8_t*)0x200005e4 = 0;
*(uint32_t*)0x200005e8 = 0;
*(uint32_t*)0x200005ec = 0;
*(uint32_t*)0x200005f0 = htobe32(-1);
*(uint32_t*)0x20000600 = htobe32(-1);
*(uint16_t*)0x20000610 = htobe16(0);
*(uint16_t*)0x20000612 = htobe16(0);
*(uint16_t*)0x20000614 = htobe16(0);
*(uint16_t*)0x20000616 = htobe16(0);
*(uint16_t*)0x20000618 = 0xa;
*(uint8_t*)0x2000061a = 0;
*(uint8_t*)0x2000061b = 0;
*(uint8_t*)0x2000061c = 0;
*(uint32_t*)0x20000620 = 0;
*(uint32_t*)0x20000624 = 0;
*(uint64_t*)0x20000628 = 0;
*(uint64_t*)0x20000630 = 0;
*(uint64_t*)0x20000638 = 0;
*(uint64_t*)0x20000640 = 0;
*(uint64_t*)0x20000648 = 0;
*(uint64_t*)0x20000650 = 0;
*(uint64_t*)0x20000658 = 0;
*(uint64_t*)0x20000660 = 0;
*(uint64_t*)0x20000668 = 0;
*(uint64_t*)0x20000670 = 0;
*(uint64_t*)0x20000678 = 0;
*(uint64_t*)0x20000680 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint32_t*)0x2000068c = 0;
*(uint8_t*)0x20000690 = 0;
*(uint8_t*)0x20000691 = 0;
*(uint8_t*)0x20000692 = 0;
*(uint8_t*)0x20000693 = 0;
*(uint32_t*)0x20000698 = 0;
*(uint32_t*)0x2000069c = 0;
*(uint32_t*)0x200006a0 = 0;
*(uint32_t*)0x200006a4 = 0;
*(uint16_t*)0x200006a8 = 0xc;
*(uint16_t*)0x200006aa = 0x15;
*(uint32_t*)0x200006ac = 0;
*(uint32_t*)0x200006b0 = 0;
*(uint64_t*)0x20000808 = 0x134;
*(uint64_t*)0x20000858 = 1;
*(uint64_t*)0x20000860 = 0;
*(uint64_t*)0x20000868 = 0;
*(uint32_t*)0x20000870 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000840ul, 0ul);
	return 0;
}
