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

#ifndef __NR_execveat
#define __NR_execveat 322
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000080, "/proc/self/exe\000", 15);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000080ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_read, r[0], 0x20000000ul, 0xffffff41ul);
memcpy((void*)0x20000000, "./file0\000", 8);
*(uint64_t*)0x20000300 = 0x20000040;
memset((void*)0x20000040, 0, 1);
*(uint64_t*)0x20000308 = 0x200001c0;
memset((void*)0x200001c0, 124, 1);
*(uint64_t*)0x20000310 = 0x20000200;
memcpy((void*)0x20000200, "/\000", 2);
*(uint64_t*)0x20000318 = 0x20000240;
memcpy((void*)0x20000240, "]\207+*/%[^[*\000", 11);
*(uint64_t*)0x20000320 = 0x20000280;
memset((void*)0x20000280, 0, 1);
*(uint64_t*)0x20000328 = 0x20000480;
memcpy((void*)0x20000480, "nmE[\233\215,\000\356m\261\210\0054M\220\354G\346x(G\220\343+\222\245ss:Jo\0018\221\'\341\177\2434\216  \255\253\234\235*\027N\037\216\334\3420\235Ln?\233\271\306`D\233\314\322\276s\247\217&\342\371\025\336\212\204\265\356\271\202\032$b\377\017\363x*\306gl.\370\264-\001\320\004\202](\274^2\335\244\223+\332\266s\037\355\267)E\354,\226*\256\220\250\3753\340Z\275\002N\341\206\004\364B\335$\223_\272\351\022}\325\246\020\245\341\037\231\350\244s\225\004\362\275\361\232w\304\255x\036\216\212$\031\264\317I\310\246d\222\315\a\252\331y\253ySd[1\301*\004\264\355\016\322\277\031\211c\314\2622\004w\253y\346\233|2=\033\210\220", 214);
	syscall(__NR_execveat, -1, 0x20000000ul, 0x20000300ul, 0x20000440ul, 0ul);
	return 0;
}
