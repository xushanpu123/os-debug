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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000000, "./file0\000", 8);
*(uint64_t*)0x20000300 = 0x200000c0;
memcpy((void*)0x200000c0, ":-\000\026:t%p`U\206\246W\337\235\306\2413\224H\337\001s\265\325y\320\000\367y\272I\345\332a\232O\306\005\232\253\330.\263a\301", 46);
	syscall(__NR_execveat, -1, 0x20000000ul, 0x200000c0ul, 0x20000300ul, 0ul);
	return 0;
}
