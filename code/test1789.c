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
memcpy((void*)0x20000300, "\245\000\n#:I\316\345\022\031\024\336\201\316(\201\367k\b\003\201\034\377*t\305\032^\343F)i\244\240\307U\211\270\212\003\307(\345\317LaM\231e\320\211/\250\213/q\177\n\331\331\354*jiCdr\310\324\037M\213\371fl\337\266\316\314\246\340\313\\\361\272\344\226G\222b\005G\247\326P\300\036\363p\313\330\317\341\242?p\371\257>M\017?C\373\266\341\024\367\267\377v\262f\236\0374=M\266Z\242\231\363\251\203xR\016>9\313\032\226\032\310+\340\344G\207>\2159\250\b\r\025\233\215z_\204w\232\206 \207cq\345\344\372\004\003\020=\347H\335%\343\272\222\364\346,\310G\302\227\300\231h\235B\374Z\263\270\307\343\307.\220\213\215ES`\222*\370r\3431\351@\266\246,Q\005x<\242\373~=\334\206p\266\340\252\265C\372A\207\021\204\005\031\241\235\'\006\323\364\n\344\267_fz\264\036\363\002\264Ft-\020M\333\233\224o\206\364\331Qy!\376\372W#\005j \344\201)\367|\017\252\336\224]\334_*\2277\023eET\250\345\315\347\225W\037p-\257\235\r\226@\200x\n\272H\210 \025.\374#{z\307T\242\274\263\266\035\204\271\345\037_\304\376\034\323A.\222\022Rv\222!\313=Ap\234\240\220\327\232l9\223\236\223SuH\235\n\022\307\3233\3275\357\332\210\266\341\236\370x\a\314\226\224\332\v\333Iwa\314\r\314\371oUF\237\324T\023e\317\301\313\a\376\315\035\310\360\236\307N\226h\177\200\227\b\333l\3474I\244\305\275\217\'\227^\002G0\276\333D\261\240\034L:Z\360\241e\v\306\255\274\024\322qT\324O\253Jm\263\372\356\377B\016\310F{\rh\276\240\a\023v\250\000\311\034\256\340\312J\243\340\213w\232\270b~\210\374 E\261]\262\035\001\221\000\317\273nB7\367\3127*\3314\220\301\277\225\207=\270\307P)\035\372\336\200M\267\277\227O\367\220\340@\334\237\333\244\237u\322\241", 550);
	res = syscall(__NR_memfd_create, 0x20000300ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_socket, 0x10ul, 3ul, 6);
	syscall(__NR_socket, 0x10ul, 3ul, 6);
	syscall(__NR_ioctl, -1, 0x801c581f, 0ul);
	syscall(__NR_fdatasync, r[0]);
	return 0;
}
