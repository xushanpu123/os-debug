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
	res = syscall(__NR_socket, 0x10ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001700 = 0;
*(uint32_t*)0x20001708 = 0;
*(uint64_t*)0x20001710 = 0x200016c0;
*(uint64_t*)0x200016c0 = 0x20000280;
*(uint32_t*)0x20000280 = 0x100;
*(uint16_t*)0x20000284 = 0x12;
*(uint16_t*)0x20000286 = 1;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
*(uint8_t*)0x20000290 = 0;
*(uint8_t*)0x20000291 = 0;
*(uint8_t*)0x20000292 = 0;
*(uint8_t*)0x20000293 = 0;
*(uint16_t*)0x20000294 = htobe16(0);
*(uint16_t*)0x20000296 = htobe16(0);
*(uint32_t*)0x20000298 = 0;
*(uint32_t*)0x2000029c = 0;
*(uint32_t*)0x200002a0 = 0xb8;
*(uint32_t*)0x200002a4 = 0;
*(uint32_t*)0x200002a8 = 0;
*(uint32_t*)0x200002ac = 0;
*(uint32_t*)0x200002b0 = 0;
*(uint32_t*)0x200002b4 = 0;
*(uint32_t*)0x200002b8 = 0;
*(uint32_t*)0x200002bc = 0;
*(uint32_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c4 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint16_t*)0x200002cc = 0x79;
*(uint16_t*)0x200002ce = 1;
memcpy((void*)0x200002d0, "\xce\x1e\x86\x05\x66\x73\x1a\xbc\x9d\x3d\xd8\x9a\x4f\xfd\x0a\xa1\xd4\xe0\x13\x1c\xe3\xb4\x47\xcf\x90\xec\x1e\xd8\x8b\x10\x5a\x0c\x6b\xd7\x74\x36\xda\x2a\xf2\x93\x9d\xcc\x0e\xf6\xf3\xb8\xca\x76\x0b\xcb\xd9\xac\xbf\xba\x49\xdd\x79\x45\xe1\xaf\xc4\x44\x3b\x02\xee\x97\x44\x06\xc0\xc3\x94\x71\x6b\x7f\xcf\xe3\xf8\xf6\x06\xf4\x9c\x84\x27\xbe\xa6\x15\x6f\x70\x92\x80\xc7\x92\x8b\xb4\x88\x7c\xde\xf4\x4b\xdc\x7d\x41\x98\x92\xcb\x22\x53\x64\xe6\xf5\xcf\x55\x11\x05\x13\x4d\x5e", 117);
*(uint16_t*)0x20000348 = 0xd;
*(uint16_t*)0x2000034a = 1;
memcpy((void*)0x2000034c, "\xfc\x07\x17\xf9\x55\x69\xf7\x9d\x90", 9);
*(uint16_t*)0x20000358 = 0x25;
*(uint16_t*)0x2000035a = 1;
memcpy((void*)0x2000035c, "\xb5\x0a\x4e\x3f\x0b\x25\x76\xeb\x8e\x87\xa3\x87\x28\xae\x03\x55\xe0\xaa\x2f\x3b\x70\xc8\x2a\x9d\x6d\xf7\x69\xf9\xf6\xdd\xd4\xa7\x2f", 33);
*(uint64_t*)0x200016c8 = 0x100;
*(uint64_t*)0x20001718 = 1;
*(uint64_t*)0x20001720 = 0;
*(uint64_t*)0x20001728 = 0;
*(uint32_t*)0x20001730 = 0;
	syscall(__NR_sendmsg, r[0], 0x20001700ul, 0ul);
	return 0;
}
