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
	res = syscall(__NR_socket, 1ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "security.selinux\000", 17);
memcpy((void*)0x20000100, "\212\207:\336\2664\234r\237\335\241\320n\274\314\230\004\264\216\227W\367\266\333\302\355\217\252yI\215\200~H\307$\037\366\004\305N#\3738\312\035`{\035\034B.\350\376\301\340L\320\250\256 h\257\354\3012\234\245\002\021\320\202\212i\2129A\233\260\221\262\272\355r\321\221\032\023\3604\274\246\n\t^q", 96);
	syscall(__NR_fsetxattr, r[0], 0x20000000ul, 0x20000100ul, 0x60ul, 0ul);
	return 0;
}