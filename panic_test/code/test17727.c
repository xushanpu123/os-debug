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
*(uint64_t*)0x20000080 = 0x20000880;
*(uint32_t*)0x20000880 = 0xb8;
*(uint16_t*)0x20000884 = 0x13;
*(uint16_t*)0x20000886 = 1;
*(uint32_t*)0x20000888 = 0;
*(uint32_t*)0x2000088c = 0;
*(uint32_t*)0x20000890 = htobe32(0);
*(uint32_t*)0x200008a0 = htobe32(0);
*(uint16_t*)0x200008b0 = htobe16(0);
*(uint16_t*)0x200008b2 = htobe16(0);
*(uint16_t*)0x200008b4 = htobe16(0);
*(uint16_t*)0x200008b6 = htobe16(0);
*(uint16_t*)0x200008b8 = 0xa;
*(uint8_t*)0x200008ba = 0;
*(uint8_t*)0x200008bb = 0;
*(uint8_t*)0x200008bc = 0;
*(uint32_t*)0x200008c0 = 0;
*(uint32_t*)0x200008c4 = 0xee00;
*(uint64_t*)0x200008c8 = 0;
*(uint64_t*)0x200008d0 = 0;
*(uint64_t*)0x200008d8 = 0;
*(uint64_t*)0x200008e0 = 0;
*(uint64_t*)0x200008e8 = 0;
*(uint64_t*)0x200008f0 = 0;
*(uint64_t*)0x200008f8 = 0;
*(uint64_t*)0x20000900 = 0;
*(uint64_t*)0x20000908 = 0;
*(uint64_t*)0x20000910 = 0;
*(uint64_t*)0x20000918 = 0;
*(uint64_t*)0x20000920 = 0;
*(uint32_t*)0x20000928 = 0;
*(uint32_t*)0x2000092c = 0;
*(uint8_t*)0x20000930 = 0;
*(uint8_t*)0x20000931 = 0;
*(uint8_t*)0x20000932 = 0;
*(uint8_t*)0x20000933 = 0;
*(uint64_t*)0x20000088 = 0xb8;
*(uint64_t*)0x200000d8 = 1;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200000c0ul, 0ul);
	return 0;
}
