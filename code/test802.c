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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000100, "logon\000", 6);
memcpy((void*)0x20000140, "fscrypt:", 8);
memcpy((void*)0x20000148, "e8dab99234bb312e", 16);
*(uint8_t*)0x20000158 = 0;
*(uint32_t*)0x20000180 = 0;
memcpy((void*)0x20000184, "\xaf\x3f\xad\x15\x34\xcf\x45\xde\x5b\xe4\xc8\x86\x00\x19\x74\x8f\x4a\x92\xa3\xd2\x5e\x83\x14\xe1\x08\x00\x15\xcd\x39\xd2\x65\x96\x11\xbf\xbc\x31\xbd\xfc\x91\xfe\x69\x76\x57\xfc\x4f\x1d\xbf\xae\xfa\xe3\x56\xe3\x52\x2f\xf9\xe9\x96\x8d\xb0\x03\x62\x4a\xfe\x22", 64);
*(uint32_t*)0x200001c4 = 0;
	res = syscall(__NR_add_key, 0x20000100ul, 0x20000140ul, 0x20000180ul, 0x48ul, -1);
	if (res != -1)
		r[0] = res;
	syscall(__NR_keyctl, 0x15ul, r[0], 0, 0, 0);
	syscall(__NR_keyctl, 3ul, r[0], 0, 0, 0);
	return 0;
}
