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
memcpy((void*)0x20000040, "/sys/power/pm_test", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x8002ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "\x22\x06\x26\x38\x05\x77\x19\xec\xd5\x4a\x58\x85\x58\xff\x03\x91\x32\x4d\x91\x46\x48\xe5\xeb\xf5\x76\xc7\xd6\x46\xab\xba\xc3\xd2\xc7\x02\xb7\xb4\x5e\xbe\x28\xec\x5c\x50\xd3\x86\x45\xb2\xaf\x6e\x29\xf9\xad\x1c\x44\x64\x13\xf4\x3b\xf2\xd7\x6a\xb4\xae\xbf\x3c\x56\xb0\xbc\xa3\x65\x67\xe9\x94\xcf\x3b\x4c\xd4\x47\xd9\x18\xc9\xbb\x9f\x32\xe9\x86\xb7\xd2\xb5\xea\x0a", 90);
	syscall(__NR_write, r[0], 0x20000080ul, 0x5aul);
	return 0;
}