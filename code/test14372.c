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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200017c0 = 0;
*(uint32_t*)0x200017c8 = 0;
*(uint64_t*)0x200017d0 = 0;
*(uint64_t*)0x200017d8 = 0;
*(uint64_t*)0x200017e0 = 0;
*(uint64_t*)0x200017e8 = 0;
*(uint32_t*)0x200017f0 = 0;
*(uint32_t*)0x200017f8 = 0;
*(uint64_t*)0x20001800 = 0x20000000;
*(uint16_t*)0x20000000 = 0x18;
*(uint32_t*)0x20000002 = 1;
*(uint32_t*)0x20000006 = 0;
*(uint32_t*)0x2000000a = -1;
*(uint16_t*)0x2000000e = 2;
*(uint16_t*)0x20000010 = htobe16(0);
*(uint8_t*)0x20000012 = 0xac;
*(uint8_t*)0x20000013 = 0x14;
*(uint8_t*)0x20000014 = 0x14;
*(uint8_t*)0x20000015 = 0xaa;
*(uint16_t*)0x2000001e = 0;
*(uint16_t*)0x20000020 = 0;
*(uint16_t*)0x20000022 = 0;
*(uint16_t*)0x20000024 = 0;
*(uint32_t*)0x20001808 = 0x80;
*(uint64_t*)0x20001810 = 0;
*(uint64_t*)0x20001818 = 0;
*(uint64_t*)0x20001820 = 0x200016c0;
*(uint64_t*)0x200016c0 = 0x28;
*(uint32_t*)0x200016c8 = 0;
*(uint32_t*)0x200016cc = 0;
memcpy((void*)0x200016d0, "\x25\xf7\xfe\x0c\x07\x4b\x86\x8b\x76\x7b\xa9\x78\x45\xa3\xc6\xc5\x7e", 17);
*(uint64_t*)0x20001828 = 0x28;
*(uint32_t*)0x20001830 = 0;
*(uint32_t*)0x20001838 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200017c0ul, 2ul, 0ul);
	return 0;
}