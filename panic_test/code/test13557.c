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

#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
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
*(uint64_t*)0x20000140 = 0x20000000;
memset((void*)0x20000000, 29, 1);
*(uint64_t*)0x20000148 = 1;
	syscall(__NR_vmsplice, r[2], 0x20000140ul, 1ul, 0ul);
	syscall(__NR_fcntl, r[2], 0x407ul, 0ul);
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0x20000300;
*(uint64_t*)0x20000300 = 0x20000180;
*(uint32_t*)0x20000180 = 0x14;
*(uint8_t*)0x20000184 = 0;
*(uint8_t*)0x20000185 = 1;
*(uint16_t*)0x20000186 = 0x801;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint8_t*)0x20000190 = 0;
*(uint8_t*)0x20000191 = 0;
*(uint16_t*)0x20000192 = htobe16(0);
*(uint64_t*)0x20000308 = 0x14;
*(uint64_t*)0x20000398 = 1;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_sendmsg, r[1], 0x20000380ul, 0ul);
	return 0;
}
