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

#ifndef __NR_io_uring_register
#define __NR_io_uring_register 427
#endif

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000100, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 3;
*(uint32_t*)0x20000004 = 2;
STORE_BY_BITMASK(uint32_t, , 0x20000008, 1, 0, 1);
memcpy((void*)0x20000009, "queue0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x2000004c = 2;
memset((void*)0x20000050, 0, 60);
	syscall(__NR_ioctl, r[0], 0xc08c5336, 0x20000000ul);
*(uint8_t*)0x20000140 = 0;
*(uint8_t*)0x20000141 = 0;
*(uint8_t*)0x20000142 = 0;
*(uint8_t*)0x20000143 = 0xfc;
*(uint32_t*)0x20000144 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint8_t*)0x2000014c = 0;
memset((void*)0x2000014d, 0, 3);
memset((void*)0x20000150, 0, 64);
	syscall(__NR_ioctl, r[0], 0x40505330, 0x20000140ul);
memcpy((void*)0x20002000, "/dev/nvram\000", 11);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20002000ul, 0ul, 0ul);
	syscall(__NR_ioctl, -1, 0x80045300, 0ul);
	syscall(__NR_io_uring_register, -1, 9ul, 0ul, 0ul);
*(uint32_t*)0x20000240 = 1;
*(uint32_t*)0x20000244 = 1;
*(uint32_t*)0x20000248 = 0x18;
*(uint32_t*)0x2000024c = r[0];
*(uint32_t*)0x20000250 = 2;
memcpy((void*)0x20000258, "./file0\000", 8);
	res = syscall(__NR_ioctl, -1, 0xc0189373, 0x20000240ul);
	if (res != -1)
r[1] = *(uint32_t*)0x2000024c;
	syscall(__NR_socket, 2ul, 2ul, 0x88);
	syscall(__NR_ioctl, r[1], 0x80045300, 0x20000280ul);
	return 0;
}
