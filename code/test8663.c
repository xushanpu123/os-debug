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

static long syz_open_procfs(volatile long a0, volatile long a1)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	if (a0 == 0) {
		snprintf(buf, sizeof(buf), "/proc/self/%s", (char*)a1);
	} else if (a0 == -1) {
		snprintf(buf, sizeof(buf), "/proc/thread-self/%s", (char*)a1);
	} else {
		snprintf(buf, sizeof(buf), "/proc/self/task/%d/%s", (int)a0, (char*)a1);
	}
	int fd = open(buf, O_RDWR);
	if (fd == -1)
		fd = open(buf, O_RDONLY);
	return fd;
}

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_open, 0x20000000ul, 0xb0c40ul, 0ul);
memcpy((void*)0x20000080, "./file0\000", 8);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 0x143201ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000200, "ns/uts\000", 7);
	res = -1;
res = syz_open_procfs(0, 0x20000200);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_fcntl, r[0], 0ul, r[1]);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000580 = htobe32(0x67446698);
*(uint32_t*)0x20000584 = 0;
*(uint16_t*)0x20000588 = 0;
*(uint16_t*)0x2000058a = 0;
*(uint32_t*)0x2000058c = 0;
	syscall(__NR_write, r[2], 0x20000580ul, 0x10ul);
*(uint32_t*)0x20000240 = 0x5f;
*(uint8_t*)0x20000244 = 0x7d;
*(uint16_t*)0x20000245 = 0;
*(uint16_t*)0x20000247 = 0;
*(uint16_t*)0x20000249 = 0x58;
*(uint16_t*)0x2000024b = 0;
*(uint32_t*)0x2000024d = 0;
*(uint8_t*)0x20000251 = 0;
*(uint32_t*)0x20000252 = 0;
*(uint64_t*)0x20000256 = 0;
*(uint32_t*)0x2000025e = 0;
*(uint32_t*)0x20000262 = 0;
*(uint32_t*)0x20000266 = 0;
*(uint64_t*)0x2000026a = 0;
*(uint16_t*)0x20000272 = 7;
memcpy((void*)0x20000274, "\t\000\000\000ts\000\213%*Z\311\245\326H\302b\031nn\324\350\330r\367jp\035\227x\226\273\332rls.&\023vmFz\331\252F\234\214)\024 \311\333\301zK\n\037\374\002\365\335\2555j\t\036o(KMf\230\246\302-\305\326v\306\253\016\216j[\325\304~\016E},\343\254\344\217\353\316\244!\221Yi-\033\366l\371\005\'\355M\372\364\024\372\006&ATT\227@\274\006\303<\003\352[\312o\253C\242\307\334\304\000u\022\300f\221\274\376\276\351RTB\v\371\n\244\254\272\210*O{\226G\265\223(w\220\006\366\232\353\321\v\214}\370\373)\227\367\200\256i\333\322f\020v-\b\275=", 193);
*(uint16_t*)0x20000335 = 3;
memcpy((void*)0x20000337, "{[#", 3);
*(uint16_t*)0x2000033a = 0x14;
memcpy((void*)0x2000033c, "\316\347\373H#\2700\226\300A<&\231B\000\001\000\000\000\321", 20);
*(uint16_t*)0x20000350 = 7;
memcpy((void*)0x20000352, "ns/uts\000", 7);
	syscall(__NR_write, r[2], 0x20000240ul, 0xfe95ul);
	return 0;
}