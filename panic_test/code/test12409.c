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
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0x20000100;
*(uint64_t*)0x20000100 = 0x200003c0;
*(uint32_t*)0x200003c0 = 0xd0;
*(uint16_t*)0x200003c4 = 0x1c;
*(uint16_t*)0x200003c6 = 1;
*(uint32_t*)0x200003c8 = 0x70bd26;
*(uint32_t*)0x200003cc = 0x25dfdbfb;
*(uint8_t*)0x200003d0 = 0x3c;
*(uint16_t*)0x200003d1 = 0x1c;
*(uint16_t*)0x200003d3 = 4;
*(uint16_t*)0x200003d5 = 0xfffd;
*(uint16_t*)0x200003d7 = htobe16(0x4e22);
*(uint16_t*)0x200003d9 = htobe16(0x4e21);
*(uint8_t*)0x200003dd = 0xac;
*(uint8_t*)0x200003de = 0x14;
*(uint8_t*)0x200003df = 0x14;
*(uint8_t*)0x200003e0 = 0xaa;
*(uint16_t*)0x200003ed = 0x2c;
*(uint16_t*)0x200003ef = 0x13;
*(uint8_t*)0x200003f1 = 0xfc;
*(uint8_t*)0x200003f2 = 1;
memset((void*)0x200003f3, 0, 13);
*(uint8_t*)0x20000400 = 0;
*(uint8_t*)0x20000401 = 0xfe;
*(uint8_t*)0x20000402 = 0x88;
memset((void*)0x20000403, 0, 12);
*(uint8_t*)0x2000040f = 1;
*(uint8_t*)0x20000410 = 1;
*(uint32_t*)0x20000411 = 0;
*(uint16_t*)0x20000415 = 2;
*(uint16_t*)0x20000419 = 0xa;
*(uint16_t*)0x2000041b = 0x10;
*(uint8_t*)0x2000041d = 1;
*(uint16_t*)0x2000041f = 0;
*(uint8_t*)0x20000421 = 0;
*(uint16_t*)0x20000425 = 0xc;
*(uint16_t*)0x20000427 = 0xf;
*(uint64_t*)0x20000429 = -1;
*(uint16_t*)0x20000431 = 0x50;
*(uint16_t*)0x20000433 = 0x11;
*(uint8_t*)0x20000435 = 0xfc;
*(uint8_t*)0x20000436 = 1;
memset((void*)0x20000437, 0, 13);
*(uint8_t*)0x20000444 = 0;
*(uint8_t*)0x20000445 = 0xfe;
*(uint8_t*)0x20000446 = 0x80;
memset((void*)0x20000447, 0, 13);
*(uint8_t*)0x20000454 = 0xbb;
memset((void*)0x20000455, 0, 16);
*(uint32_t*)0x20000465 = htobe32(0xe0000002);
*(uint8_t*)0x20000475 = 0x6c;
*(uint8_t*)0x20000476 = 7;
*(uint16_t*)0x20000477 = 0;
*(uint32_t*)0x20000479 = 0x3503;
*(uint16_t*)0x2000047d = 0xa;
*(uint16_t*)0x2000047f = 0xa;
*(uint16_t*)0x20000481 = 0xc;
*(uint16_t*)0x20000483 = 0xf;
*(uint64_t*)0x20000485 = 0xfffffffffffffffe;
*(uint64_t*)0x20000108 = 0xd0;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0xf525731c;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 0x20040040ul);
	return 0;
}