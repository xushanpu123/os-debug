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

*(uint64_t*)0x20002300 = 0;
*(uint32_t*)0x20002308 = 0;
*(uint64_t*)0x20002310 = 0;
*(uint64_t*)0x20002318 = 0;
*(uint64_t*)0x20002320 = 0x20001740;
*(uint64_t*)0x20001740 = 0x18;
*(uint32_t*)0x20001748 = 0x29;
*(uint32_t*)0x2000174c = 0x39;
*(uint8_t*)0x20001750 = 0;
*(uint8_t*)0x20001751 = 0;
*(uint8_t*)0x20001752 = 2;
*(uint8_t*)0x20001753 = 0x20;
*(uint32_t*)0x20001754 = 0;
*(uint64_t*)0x20002328 = 0x18;
*(uint32_t*)0x20002330 = 0;
*(uint32_t*)0x20002338 = 0;
	syscall(__NR_sendmmsg, -1, 0x20002300ul, 1ul, 0ul);
*(uint64_t*)0x20000080 = 0x20ffa000;
	syscall(__NR_move_pages, 0, 0x200000000000023eul, 0x20000080ul, 0ul, 0x20000000ul, 0ul);
	return 0;
}
