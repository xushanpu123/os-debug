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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001680 = 0x20000040;
*(uint16_t*)0x20000040 = 2;
*(uint16_t*)0x20000042 = htobe16(0x4e22);
*(uint8_t*)0x20000044 = 0xac;
*(uint8_t*)0x20000045 = 0x14;
*(uint8_t*)0x20000046 = 0x14;
*(uint8_t*)0x20000047 = 0xbb;
*(uint32_t*)0x20001688 = 0x10;
*(uint64_t*)0x20001690 = 0;
*(uint64_t*)0x20001698 = 0;
*(uint64_t*)0x200016a0 = 0;
*(uint64_t*)0x200016a8 = 0;
*(uint32_t*)0x200016b0 = 0;
*(uint32_t*)0x200016b8 = 0;
*(uint64_t*)0x200016c0 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e23);
*(uint32_t*)0x20000004 = htobe32(-1);
*(uint32_t*)0x200016c8 = 0x10;
*(uint64_t*)0x200016d0 = 0;
*(uint64_t*)0x200016d8 = 0;
*(uint64_t*)0x200016e0 = 0x20001740;
*(uint64_t*)0x20001740 = 0x10;
*(uint32_t*)0x20001748 = 0;
*(uint32_t*)0x2000174c = 7;
*(uint64_t*)0x20001750 = 0x1c;
*(uint32_t*)0x20001758 = 0;
*(uint32_t*)0x2000175c = 8;
*(uint32_t*)0x20001760 = 0;
*(uint8_t*)0x20001764 = 0xac;
*(uint8_t*)0x20001765 = 0x14;
*(uint8_t*)0x20001766 = 0x14;
*(uint8_t*)0x20001767 = 0xbb;
*(uint32_t*)0x20001768 = htobe32(0x7f000001);
*(uint64_t*)0x200016e8 = 0x30;
*(uint32_t*)0x200016f0 = 0;
*(uint32_t*)0x200016f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20001680ul, 2ul, 0ul);
	return 0;
}
