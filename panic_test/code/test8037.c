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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000300, "L]QY;\322\a\246\220\016\250\235\264\'\247\216\000\345\372\270[\220~h4\234\220\254\004\266\023<\266\345\211\236\265:\267\246\241\2554,u\301O9\363\256x\003\270O\274\212\234\261x\v\027W-\346Y\230\317\275O\342\211e}\250\226\216\000\343\220\267\254\377\364 \f\370\344\b\004\030r\374WU\274\032^P\354\005\302\373J\210\334:\373cEL\311\276\343;\bx\022\256\363\213\262\364\277\303\322\000\000\320g!:\027\360\271\376\201\253\334e^X\216\032K\272\356\000\233p\203\241\n5^\373\212U\243\177\t\316R\373*\262\261\323x=\273\213\210u~S\001\207\325#\326\232\3033\343\343\301\002\243\025Zp\263\361\030\n\310\213\267\210D\005\323\366\245f=\214\356L\b\263}d\b\304\344\034\344\0058\275u)[\333\252\357X\033\214\nq?\240\365\332\004\207\357\363\035\tgm\221\341L[\301\316A\264\333}\244\031\030&\034F\201q\300\3725\2654v\310<T\033\325\317\350<\224z/Ir\305\031\332\004\323\a\231\322:\364\366-\342K\027\362\034\213\n\\\035\224\n\367\241\315\201ES\336\324bv\037\257)\276\202\256\220\201\205dtF\307\rlpX;1\325\235/\303\3466\235J\023;\253\373B\021\355Zn%\317\257\276\325\314\235\0002\342!jh\031f\006\\\347y\220[(\271\203\f\306E8\\n\350\260\240\370\223;\'qa\024\370\'\261\302\375\200\2239\b\223*\177\021\253\000\0371\251\272\246\221\370\224N _\360i\343\a\355E\r\345\273\211#\351\364i\372u3\362\215\240\351CE\200\242p\000\243\257}\331\v\207\017ht\237\361\026\3723\365\017k", 460);
	res = syscall(__NR_memfd_create, 0x20000300ul, 3ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_fcntl, r[0], 0x409ul, 0xdul);
*(uint64_t*)0x20000600 = 0x20000140;
memset((void*)0x20000140, 107, 1);
*(uint64_t*)0x20000608 = 1;
	syscall(__NR_writev, r[0], 0x20000600ul, 1ul);
	return 0;
}
