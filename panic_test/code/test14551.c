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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "/dev/cdrom\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x8c86ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20001480, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20001480ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000180, "/dev/cdrom\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000180ul, 0x8ae00ul, 0ul);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x20000040, "/sys/module/pata_oldpiix", 24);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0x10ul);
	syscall(__NR_ioctl, -1, 0x530c, 0ul);
	syscall(__NR_ioctl, r[2], 0x530d, 0ul);
	syscall(__NR_dup2, r[1], r[0]);
	return 0;
}
