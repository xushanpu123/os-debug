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

memcpy((void*)0x20000100, "logon\000", 6);
memcpy((void*)0x20000140, "fscrypt:", 8);
memcpy((void*)0x20000148, "e8dab99234bb312e", 16);
*(uint8_t*)0x20000158 = 0;
*(uint32_t*)0x20000180 = 0;
memcpy((void*)0x20000184, "\x1a\xc3\x30\x70\x44\x0d\x87\x8f\x7f\x63\x50\xc3\x96\xbe\x16\x75\x2f\x62\x1a\xf4\xdc\x66\x4c\x17\x17\x07\x88\xdd\x3a\xa8\x31\xa7\x4b\x06\x5a\x0f\xb9\x5b\x66\x5d\x15\x0b\x92\xaa\x7e\xeb\x37\xa8\x4d\xa9\x03\x61\x98\x1f\x12\xc0\xaf\x64\x74\x30\x36\x91\xc0\xea", 64);
*(uint32_t*)0x200001c4 = 0;
	syscall(__NR_add_key, 0x20000100ul, 0x20000140ul, 0x20000180ul, 0x48ul, 0xfffffffe);
	return 0;
}
