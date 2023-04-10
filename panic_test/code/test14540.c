// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/sched.h>

#ifndef __NR_clone3
#define __NR_clone3 435
#endif
#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

#define USLEEP_FORKED_CHILD (3 * 50 *1000)

static long handle_clone_ret(long ret)
{
	if (ret != 0) {
		return ret;
	}
	usleep(USLEEP_FORKED_CHILD);
	syscall(__NR_exit, 0);
	while (1) {
	}
}

#define MAX_CLONE_ARGS_BYTES 256
static long syz_clone3(volatile long a0, volatile long a1)
{
	unsigned long copy_size = a1;
	if (copy_size < sizeof(uint64_t) || copy_size > MAX_CLONE_ARGS_BYTES)
		return -1;
	char clone_args[MAX_CLONE_ARGS_BYTES];
	memcpy(&clone_args, (void*)a0, copy_size);
	uint64_t* flags = (uint64_t*)&clone_args;
	*flags &= ~CLONE_VM;
	return handle_clone_ret((long)syscall(__NR_clone3, &clone_args, copy_size));
}

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
*(uint64_t*)0x20000298 = 0;
*(uint32_t*)0x200002a0 = 7;
*(uint64_t*)0x200002a8 = 0;
*(uint64_t*)0x200002b0 = 0;
*(uint64_t*)0x200002b8 = 0;
*(uint64_t*)0x200002c0 = 0;
*(uint64_t*)0x200002c8 = 0;
*(uint32_t*)0x200002d0 = -1;
syz_clone3(0x20000280, 0x58);
memcpy((void*)0x200000c0, "\352\347\322\244\317\227\317\246\tt\300T=\313\203\366\251\031#JV\325\265Rs{\354z\242\'\261\322\271t!\367q\317(w-\347b\300\372y\343\244M\242*h$\202\bRe\232\260\374z%\017\006\272\246\004\216\346\244$]\215\220m\317s\253\240|nK\210\034\327\251\324\315\355\351\231\263\027\026\204\321\254\213\006\220", 100);
	res = syscall(__NR_memfd_create, 0x200000c0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[1] = res;
	syscall(__NR_dup3, r[1], r[0], 0ul);
	res = syscall(__NR_pipe, 0x20000340ul);
	if (res != -1)
r[2] = *(uint32_t*)0x20000344;
	syscall(__NR_sendfile, r[2], r[0], 0ul, 0x2000007ul);
	return 0;
}