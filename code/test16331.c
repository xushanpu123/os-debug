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
memcpy((void*)0x20000000, "/dev/vga_arbiter\000", 17);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x2801ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200023c0 = 0x20000180;
memcpy((void*)0x20000180, "\x2b\x02\xc2\x9f\xce\xaf\x6b\x17\xe5\x7a\x62\xf6\x41\xde\x7f\xae\xb1\xb8\x4f\x0b\x14\x44\xd5\xa5\xf2\x18\xae\x80\x67\xb4\xf8\x97\xb9\xd2\xb3\x95\x69\x46\xf6\xf8\x69\xe5\xa0\x97\x75\x44\x56\x78\x90\x48\x14\x0b\x8b\x3d\xdd\xc8\xc1\x02\xf7\xd3\x90\x01\xe0\xbb", 64);
*(uint64_t*)0x200023c8 = 0x40;
	syscall(__NR_pwritev, r[0], 0x200023c0ul, 1ul, 0, 0);
	return 0;
}