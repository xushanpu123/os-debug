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
*(uint64_t*)0x20000280 = 2;
	syscall(__NR_msgsnd, 0, 0x20000280ul, 8ul, 0ul);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0ul, 0ul);
	syscall(__NR_ioctl, -1, 0x40383d0c, 0ul);
	syscall(__NR_sendmsg, -1, 0ul, 0x24000000ul);
memcpy((void*)0x20000040, "./cgroup/syz0\000", 14);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x200002ul, 0ul);
memcpy((void*)0x20000b00, "/dev/vcsa\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000b00ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x40383d0c, 0ul);
	return 0;
}
