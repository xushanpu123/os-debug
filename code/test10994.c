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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000a00 = 0;
*(uint32_t*)0x20000a08 = 0;
*(uint64_t*)0x20000a10 = 0x200009c0;
*(uint64_t*)0x200009c0 = 0x20000980;
*(uint32_t*)0x20000980 = 0x1c;
*(uint8_t*)0x20000984 = 1;
*(uint8_t*)0x20000985 = 4;
*(uint16_t*)0x20000986 = 0x301;
*(uint32_t*)0x20000988 = 0;
*(uint32_t*)0x2000098c = 0;
*(uint8_t*)0x20000990 = 0;
*(uint8_t*)0x20000991 = 0;
*(uint16_t*)0x20000992 = htobe16(0);
*(uint16_t*)0x20000994 = 5;
*(uint16_t*)0x20000996 = 1;
*(uint8_t*)0x20000998 = 1;
*(uint64_t*)0x200009c8 = 0x1c;
*(uint64_t*)0x20000a18 = 1;
*(uint64_t*)0x20000a20 = 0;
*(uint64_t*)0x20000a28 = 0;
*(uint32_t*)0x20000a30 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000a00ul, 0ul);
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0x20000040;
*(uint64_t*)0x20000040 = 0x20000000;
*(uint32_t*)0x20000000 = 0x20;
*(uint8_t*)0x20000004 = 1;
*(uint8_t*)0x20000005 = 4;
*(uint16_t*)0x20000006 = 0x401;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 0;
*(uint8_t*)0x20000011 = 0;
*(uint16_t*)0x20000012 = htobe16(0);
*(uint16_t*)0x20000014 = 0xa;
*(uint16_t*)0x20000016 = 2;
*(uint32_t*)0x20000018 = htobe32(0);
*(uint8_t*)0x2000001c = 2;
*(uint8_t*)0x2000001d = 0;
*(uint64_t*)0x20000048 = 0x20;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 0ul);
	return 0;
}
