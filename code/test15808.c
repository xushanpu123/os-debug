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

#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000340 = 1;
*(uint64_t*)0x20000348 = 0x20000300;
*(uint16_t*)0x20000300 = 6;
*(uint8_t*)0x20000302 = 0;
*(uint8_t*)0x20000303 = 0;
*(uint32_t*)0x20000304 = 0x7fffffff;
	res = syscall(__NR_seccomp, 1ul, 0ul, 0x20000340ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "security.selinux\000", 17);
memcpy((void*)0x200000c0, "system_u:object_r:load_policy_exec_t:s0\000", 40);
	syscall(__NR_fsetxattr, r[0], 0x20000080ul, 0x200000c0ul, 0x28ul, 0ul);
	return 0;
}
