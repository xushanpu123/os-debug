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
				syscall(__NR_prctl, 0x26ul, 1ul, 0, 0, 0);
	syscall(__NR_keyctl, 7ul, 0xfffffff9, 0, 0, 0);
memcpy((void*)0x20000200, "rxrpc_s\000", 8);
memcpy((void*)0x20000040, "syz", 3);
*(uint8_t*)0x20000043 = 0x22;
*(uint8_t*)0x20000044 = 0;
	syscall(__NR_add_key, 0x20000200ul, 0x20000040ul, 0ul, 0ul, -1);
memcpy((void*)0x20000000, "dns_resolver\000", 13);
memcpy((void*)0x20000240, "syz", 3);
*(uint8_t*)0x20000243 = 0x21;
*(uint8_t*)0x20000244 = 0;
memcpy((void*)0x20000280, "syz", 3);
	syscall(__NR_request_key, 0x20000000ul, 0x20000240ul, 0x20000280ul, 0);
	return 0;
}
