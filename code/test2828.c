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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_keyctl, 0xeul, 3ul, 0, 0, 0);
memcpy((void*)0x200003c0, "logon\000", 6);
memcpy((void*)0x20000000, "syz", 3);
*(uint8_t*)0x20000003 = 0x21;
*(uint8_t*)0x20000004 = 0;
memcpy((void*)0x20000440, "*^@[\246\000", 6);
	syscall(__NR_request_key, 0x200003c0ul, 0x20000000ul, 0x20000440ul, 0);
	return 0;
}
