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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002f40 = 0x200000c0;
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0x4e23);
*(uint32_t*)0x200000c4 = htobe32(0xe0000001);
*(uint32_t*)0x20002f48 = 0x10;
*(uint64_t*)0x20002f50 = 0;
*(uint64_t*)0x20002f58 = 0;
*(uint64_t*)0x20002f60 = 0x20000600;
*(uint64_t*)0x20000600 = 0x1c;
*(uint32_t*)0x20000608 = 0;
*(uint32_t*)0x2000060c = 8;
*(uint32_t*)0x20000610 = 0;
*(uint32_t*)0x20000614 = htobe32(0x7f000001);
*(uint32_t*)0x20000618 = htobe32(0xe0000002);
*(uint64_t*)0x20002f68 = 0x20;
*(uint32_t*)0x20002f70 = 0;
*(uint32_t*)0x20002f78 = 0;
*(uint64_t*)0x20002f80 = 0x20000640;
*(uint16_t*)0x20000640 = 2;
*(uint16_t*)0x20000642 = htobe16(0x4e22);
*(uint8_t*)0x20000644 = 0xac;
*(uint8_t*)0x20000645 = 0x14;
*(uint8_t*)0x20000646 = 0x14;
*(uint8_t*)0x20000647 = 0xaa;
*(uint32_t*)0x20002f88 = 0x10;
*(uint64_t*)0x20002f90 = 0;
*(uint64_t*)0x20002f98 = 0;
*(uint64_t*)0x20002fa0 = 0x20003000;
*(uint64_t*)0x20003000 = 0x3c;
*(uint32_t*)0x20003008 = 0;
*(uint32_t*)0x2000300c = 7;
*(uint8_t*)0x20003010 = 0x94;
*(uint8_t*)0x20003011 = 4;
*(uint16_t*)0x20003012 = 0;
*(uint8_t*)0x20003014 = 0x94;
*(uint8_t*)0x20003015 = 4;
*(uint16_t*)0x20003016 = 1;
*(uint8_t*)0x20003018 = 0x44;
*(uint8_t*)0x20003019 = 0x14;
*(uint8_t*)0x2000301a = 0xb2;
STORE_BY_BITMASK(uint8_t, , 0x2000301b, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x2000301b, 0, 4, 4);
*(uint8_t*)0x2000301c = 0xac;
*(uint8_t*)0x2000301d = 0x1e;
*(uint8_t*)0x2000301e = 0;
*(uint8_t*)0x2000301f = 1;
*(uint32_t*)0x20003020 = htobe32(0);
*(uint8_t*)0x20003024 = 0xac;
*(uint8_t*)0x20003025 = 0x1e;
*(uint8_t*)0x20003026 = 0;
*(uint8_t*)0x20003027 = 1;
*(uint32_t*)0x20003028 = htobe32(0);
*(uint8_t*)0x2000302c = 0x89;
*(uint8_t*)0x2000302d = 0xf;
*(uint8_t*)0x2000302e = 0;
*(uint32_t*)0x2000302f = htobe32(0xe0000002);
*(uint8_t*)0x20003033 = 0xac;
*(uint8_t*)0x20003034 = 0x14;
*(uint8_t*)0x20003035 = 0x14;
*(uint8_t*)0x20003036 = 0;
*(uint32_t*)0x20003037 = htobe32(0x7f000001);
*(uint64_t*)0x20002fa8 = 0x40;
*(uint32_t*)0x20002fb0 = 0;
*(uint32_t*)0x20002fb8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002f40ul, 2ul, 0ul);
	return 0;
}
