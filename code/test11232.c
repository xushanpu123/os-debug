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

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000040 = 2;
*(uint32_t*)0x20000044 = 0x69;
*(uint8_t*)0x20000048 = 0xc0;
*(uint8_t*)0x20000049 = 0;
*(uint8_t*)0x2000004a = 0;
*(uint8_t*)0x2000004b = 0;
*(uint32_t*)0x2000004c = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 38, 26);
*(uint32_t*)0x20000070 = 0;
*(uint32_t*)0x20000074 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x2000009c = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint32_t*)0x200000a8 = 0;
*(uint16_t*)0x200000ac = 0;
*(uint16_t*)0x200000ae = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint64_t*)0x200000b8 = 0;
	res = syscall(__NR_perf_event_open, 0x20000040ul, -1, 0ul, -1, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000140, "+\316]\267\016\"\364\026\017\003\361N\240o\250\333\224n3\244\205\330\255\345\206z\246\245\261\254w\253[\242z\a\253\357\317\332\367\263\020\264+2\037\264\t\305\257\276\256\300\022q\033\374\317n\361%\345|\2400\210=&x}DR\333\265\223\364w\254>*\270\322\230*\251\345AF\240\206\230?\361e\363-(g\033z\304\017\271\217\310\002fa\307\372\370\177\3653\327\352\001\270\345\t\316s\232\326(\370\336]i\037\026So\324hiv3\325\034\'\365\302G\325\322\033g\334\263@\203E\253A\030\241G\347rW\367\312E\325\361\026\310\201F\327\264t", 174);
	syscall(__NR_ioctl, r[0], 0x40082406, 0x20000140ul);
	return 0;
}
