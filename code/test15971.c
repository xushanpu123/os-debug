// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

static long syz_open_procfs(volatile long a0, volatile long a1)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	if (a0 == 0) {
		snprintf(buf, sizeof(buf), "/proc/self/%s", (char*)a1);
	} else if (a0 == -1) {
		snprintf(buf, sizeof(buf), "/proc/thread-self/%s", (char*)a1);
	} else {
		snprintf(buf, sizeof(buf), "/proc/self/task/%d/%s", (int)a0, (char*)a1);
	}
	int fd = open(buf, O_RDWR);
	if (fd == -1)
		fd = open(buf, O_RDONLY);
	return fd;
}

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 10);
memset((void*)0x20000012, 255, 2);
*(uint8_t*)0x20000014 = 0xac;
*(uint8_t*)0x20000015 = 0x14;
*(uint8_t*)0x20000016 = 0x14;
*(uint8_t*)0x20000017 = 0xaa;
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_bind, r[0], 0x20000000ul, 0x1cul);
memcpy((void*)0x200000c0, "net/udplite6\000", 13);
	res = -1;
res = syz_open_procfs(0, 0x200000c0);
	if (res != -1)
		r[1] = res;
	syscall(__NR_pread64, r[1], 0x200001c0ul, 0xc5ul, 0ul);
	return 0;
}