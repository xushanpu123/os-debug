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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200097c0 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e23);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint32_t*)0x200097c8 = 0x10;
*(uint64_t*)0x200097d0 = 0x20000140;
*(uint64_t*)0x20000140 = 0x20000040;
memset((void*)0x20000040, 242, 1);
*(uint64_t*)0x20000148 = 1;
*(uint64_t*)0x200097d8 = 1;
*(uint64_t*)0x200097e0 = 0;
*(uint64_t*)0x200097e8 = 0;
*(uint32_t*)0x200097f0 = 0;
*(uint32_t*)0x200097f8 = 0;
*(uint64_t*)0x20009800 = 0x20000380;
*(uint16_t*)0x20000380 = 2;
*(uint16_t*)0x20000382 = htobe16(0);
*(uint32_t*)0x20000384 = htobe32(-1);
*(uint32_t*)0x20009808 = 0x10;
*(uint64_t*)0x20009810 = 0x20000700;
*(uint64_t*)0x20000700 = 0x200004c0;
memset((void*)0x200004c0, 249, 1);
*(uint64_t*)0x20000708 = 1;
*(uint64_t*)0x20000710 = 0x200005c0;
memset((void*)0x200005c0, 163, 1);
*(uint64_t*)0x20000718 = 1;
*(uint64_t*)0x20009818 = 2;
*(uint64_t*)0x20009820 = 0;
*(uint64_t*)0x20009828 = 0;
*(uint32_t*)0x20009830 = 0;
*(uint32_t*)0x20009838 = 0;
*(uint64_t*)0x20009840 = 0x200007c0;
*(uint16_t*)0x200007c0 = 2;
*(uint16_t*)0x200007c2 = htobe16(0);
*(uint32_t*)0x200007c4 = htobe32(0);
*(uint32_t*)0x20009848 = 0x10;
*(uint64_t*)0x20009850 = 0;
*(uint64_t*)0x20009858 = 0;
*(uint64_t*)0x20009860 = 0;
*(uint64_t*)0x20009868 = 0;
*(uint32_t*)0x20009870 = 0;
*(uint32_t*)0x20009878 = 0;
*(uint64_t*)0x20009880 = 0;
*(uint32_t*)0x20009888 = 0;
*(uint64_t*)0x20009890 = 0x20004100;
*(uint64_t*)0x20004100 = 0;
*(uint64_t*)0x20004108 = 0;
*(uint64_t*)0x20004110 = 0x20001f40;
memset((void*)0x20001f40, 13, 1);
*(uint64_t*)0x20004118 = 1;
*(uint64_t*)0x20009898 = 2;
*(uint64_t*)0x200098a0 = 0;
*(uint64_t*)0x200098a8 = 0;
*(uint32_t*)0x200098b0 = 0;
*(uint32_t*)0x200098b8 = 0;
*(uint64_t*)0x200098c0 = 0;
*(uint32_t*)0x200098c8 = 0;
*(uint64_t*)0x200098d0 = 0x20006d00;
*(uint64_t*)0x20006d00 = 0;
*(uint64_t*)0x20006d08 = 0;
*(uint64_t*)0x20006d10 = 0;
*(uint64_t*)0x20006d18 = 0;
*(uint64_t*)0x20006d20 = 0;
*(uint64_t*)0x20006d28 = 0;
*(uint64_t*)0x20006d30 = 0;
*(uint64_t*)0x20006d38 = 0;
*(uint64_t*)0x20006d40 = 0;
*(uint64_t*)0x20006d48 = 0;
*(uint64_t*)0x20006d50 = 0;
*(uint64_t*)0x20006d58 = 0;
*(uint64_t*)0x20006d60 = 0;
*(uint64_t*)0x20006d68 = 0;
*(uint64_t*)0x20006d70 = 0;
*(uint64_t*)0x20006d78 = 0;
*(uint64_t*)0x20006d80 = 0;
*(uint64_t*)0x20006d88 = 0;
*(uint64_t*)0x200098d8 = 9;
*(uint64_t*)0x200098e0 = 0;
*(uint64_t*)0x200098e8 = 0;
*(uint32_t*)0x200098f0 = 0;
*(uint32_t*)0x200098f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200097c0ul, 5ul, 0x20048000ul);
	return 0;
}
