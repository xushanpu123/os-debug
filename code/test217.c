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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000100, ",/@]$\000\a\223\316\241\266Q\032\033\'\374\265x\337\374\024\3228\3151\037\362\331\217\227\225T\031\023B\356\031:D\250T\341\346\244\324\227,v\244r\334\n\215\366\336?}]\355@\220\232!UH\244\244/\246\031\372\204\3548\235\234\353\333A\202\265J\005\252N\002\242\266\337v\300f\260\264[\035\237\205AM\206mQg\200\312@%\035b\274\340\244\017L/\262i\220_\340\030\370C0\002\273\226H]\361IN`\253P\212\312", 138);
	syscall(__NR_prctl, 0xful, 0x20000100ul, 0, 0, 0);
	return 0;
}
