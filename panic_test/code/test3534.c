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

#ifndef __NR_copy_file_range
#define __NR_copy_file_range 326
#endif
#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000280, "\220\325ZMlZU\222F\006\222\314\205\214u\333\227\024\030\315\273:\272Y \\\214\271>\322D\303G\221wC\255\366F\244+\025\"\336n@\317\374 \331\f\244\307Vj\232!^\000$\025\330\270& \265T\314\331v\316\243\271M\365\211%\0179\321.\216`\000\000\000", 86);
	res = syscall(__NR_memfd_create, 0x20000280ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_memfd_create, 0x20000000ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_copy_file_range, r[1], 0ul, r[0], 0ul, 0ul, 0ul);
	return 0;
}