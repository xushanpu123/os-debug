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
memcpy((void*)0x20000d80, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000d80ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 0x80;
*(uint32_t*)0x200001c4 = 0;
memcpy((void*)0x200001c8, "client1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x20000208 = 0;
memcpy((void*)0x2000020c, "\x9d\x37\x04\xcf\xca\xb9\xa8\xa8", 8);
memcpy((void*)0x20000214, "\x62\x90\x43\x9a\xb1\x22\x68\x06\x8c\xc9\xad\x44\x09\x52\x88\x88\x42\x78\x18\xac\xc2\xdc\x62\xee\x30\xbb\x6e\x0b\x6e\xd8\xd2\x8e", 32);
*(uint32_t*)0x20000234 = 0;
*(uint32_t*)0x20000238 = 0;
*(uint32_t*)0x2000023c = 0;
*(uint32_t*)0x20000240 = 0;
memset((void*)0x20000244, 0, 56);
	syscall(__NR_ioctl, r[0], 0x40bc5311, 0x200001c0ul);
	return 0;
}
