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
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000700;
*(uint32_t*)0x20000700 = 0x138;
*(uint16_t*)0x20000704 = 0x1a;
*(uint16_t*)0x20000706 = 0xb11;
*(uint32_t*)0x20000708 = 0;
*(uint32_t*)0x2000070c = 0;
*(uint8_t*)0x20000710 = 0xfc;
*(uint8_t*)0x20000711 = 0;
memset((void*)0x20000712, 0, 13);
*(uint8_t*)0x2000071f = 0;
*(uint8_t*)0x20000720 = 0xfc;
*(uint8_t*)0x20000721 = 2;
memset((void*)0x20000722, 0, 13);
*(uint8_t*)0x2000072f = 0;
*(uint16_t*)0x20000730 = htobe16(0);
*(uint16_t*)0x20000732 = htobe16(0);
*(uint16_t*)0x20000734 = htobe16(0);
*(uint16_t*)0x20000736 = htobe16(0);
*(uint16_t*)0x20000738 = 0;
*(uint8_t*)0x2000073a = 0;
*(uint8_t*)0x2000073b = 0;
*(uint8_t*)0x2000073c = 0;
*(uint32_t*)0x20000740 = 0;
*(uint32_t*)0x20000744 = 0xee00;
*(uint8_t*)0x20000748 = 0xfc;
*(uint8_t*)0x20000749 = 0;
memset((void*)0x2000074a, 0, 13);
*(uint8_t*)0x20000757 = 0;
*(uint32_t*)0x20000758 = htobe32(0);
*(uint8_t*)0x2000075c = 0x32;
*(uint32_t*)0x20000760 = htobe32(0x7f000001);
*(uint64_t*)0x20000770 = 0;
*(uint64_t*)0x20000778 = 0;
*(uint64_t*)0x20000780 = 0;
*(uint64_t*)0x20000788 = 0;
*(uint64_t*)0x20000790 = 0;
*(uint64_t*)0x20000798 = 0;
*(uint64_t*)0x200007a0 = 0;
*(uint64_t*)0x200007a8 = 0;
*(uint64_t*)0x200007b0 = 0;
*(uint64_t*)0x200007b8 = 0;
*(uint64_t*)0x200007c0 = 0;
*(uint64_t*)0x200007c8 = 0;
*(uint32_t*)0x200007d0 = 0;
*(uint32_t*)0x200007d4 = 0;
*(uint32_t*)0x200007d8 = 0;
*(uint32_t*)0x200007dc = 0;
*(uint32_t*)0x200007e0 = 0;
*(uint16_t*)0x200007e4 = 0xa;
*(uint8_t*)0x200007e6 = 1;
*(uint8_t*)0x200007e7 = 0;
*(uint8_t*)0x200007e8 = 0;
*(uint16_t*)0x200007f0 = 0x48;
*(uint16_t*)0x200007f2 = 2;
memcpy((void*)0x200007f4, "ecb(cipher_null)\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x20000834 = 0;
*(uint64_t*)0x200000c8 = 0x138;
*(uint64_t*)0x20000118 = 1;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000100ul, 0ul);
	return 0;
}
