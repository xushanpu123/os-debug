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

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000180, "#! ", 3);
memcpy((void*)0x20000183, "./file0", 7);
*(uint8_t*)0x2000018a = 0x20;
memcpy((void*)0x2000018b, "\276\216\245\333\'~\235\201\315\335\330\334G\na\030\3257\270\303\nR.\023\002\0008\231\263u\257\363\324\246)\262\314\244\251\\O:R\367\2725 A\000c2\231\360\a/s\220\262L[%R%\266\022Nb%z=\003\2312\236w\252\201\213\3219\213\002\b\017\223\331\340\250Z:\\\360\276\337b\024k\b\374\002%D\316\331\215`\227\037\351\276|V\215T+\357\323Q\2610\025{;\033\vct \033\336i\275\321\232\331w\b\247S?\b\374\246\335\027\0012x\020FR\363\216\004nJ\246DUp\206{\275\017\215H\346\243|\033M:\374\004e\361d\242\n&v5\311\0309\354R\256\307\222\372\b\000\000\0003\235\016\177 \362Fn\206\362t\215\237\224.\v.\314yr\025\326\375\312\253\224\342]+P\345\206\v\214z\272ST\215\360\312\020@u\035t\325\350\330I+\001\000\000\000\000\000\000\000\\A\342\211\346M\313}:\253V\025\0353*??\000\000\000t\361\243c\fQ\205\340\0043\234\335\027\374E\240-7\317^\203\366\207|\021-;\201\240\320\265\211pC\346d=\211+9\321\340\336\367f\350\334\253$\311\340\323\256\201-\002\340\003\341\270]#\367}\266\003\363\225T\342\377\b$[-\257\324W\000\000\000\000\000\000\000\000\000\000", 362);
*(uint8_t*)0x200002f5 = 0xa;
	syscall(__NR_write, r[0], 0x20000180ul, 0x176ul);
	return 0;
}