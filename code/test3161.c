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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xf);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000380;
*(uint32_t*)0x20000380 = 0x964;
*(uint8_t*)0x20000384 = 1;
*(uint8_t*)0x20000385 = 5;
*(uint16_t*)0x20000386 = 0x301;
*(uint32_t*)0x20000388 = 0;
*(uint32_t*)0x2000038c = 0;
*(uint8_t*)0x20000390 = 0;
*(uint8_t*)0x20000391 = 0;
*(uint16_t*)0x20000392 = htobe16(0);
*(uint16_t*)0x20000394 = 0x254;
*(uint16_t*)0x20000396 = 1;
*(uint32_t*)0x20000398 = 0;
*(uint32_t*)0x2000039c = 0;
*(uint8_t*)0x200003a0 = 0;
*(uint8_t*)0x200003a1 = 0;
*(uint16_t*)0x200003a2 = 0;
*(uint16_t*)0x200003a4 = 0;
*(uint16_t*)0x200003a6 = 0;
memcpy((void*)0x200003a8, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x200003c8, "\x70\x14\xc3\xa4\xa9\xab\x59\x4e\x62\x3d\x93\x3c\x87\x1f\x00\xa9\x53\x4a\x0c\x95\xab\x31\x2f\x34\x05\xb3\x44\x1c\x90\x66\x35\x52", 32);
memcpy((void*)0x200003e8, "\xab\xe3\x5a\x93\x18\xf6\xcd\xb2\x60\x10\xb5\xd7\xbe\x42\xd5\xb2\x44\xd4\xbb\xd6\x8d\x0d\x82\x9e\x99\x44\xdf\x91\x83\x15\x51\xfa", 32);
*(uint16_t*)0x20000408 = 0;
*(uint16_t*)0x2000040a = 0;
*(uint32_t*)0x2000040c = 0;
*(uint32_t*)0x20000410 = 0;
*(uint16_t*)0x20000414 = 0;
*(uint16_t*)0x20000416 = 0;
*(uint32_t*)0x20000418 = 0;
*(uint32_t*)0x2000041c = 0;
*(uint16_t*)0x20000420 = 0;
*(uint16_t*)0x20000422 = 0;
*(uint32_t*)0x20000424 = 0;
*(uint32_t*)0x20000428 = 0;
*(uint16_t*)0x2000042c = 0;
*(uint16_t*)0x2000042e = 0;
*(uint32_t*)0x20000430 = 0;
*(uint32_t*)0x20000434 = 0;
*(uint16_t*)0x20000438 = 0;
*(uint16_t*)0x2000043a = 0;
*(uint32_t*)0x2000043c = 0;
*(uint32_t*)0x20000440 = 0;
*(uint16_t*)0x20000444 = 0;
*(uint16_t*)0x20000446 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint16_t*)0x20000450 = 0;
*(uint16_t*)0x20000452 = 0;
*(uint32_t*)0x20000454 = 0;
*(uint32_t*)0x20000458 = 0;
*(uint16_t*)0x2000045c = 0;
*(uint16_t*)0x2000045e = 0;
*(uint32_t*)0x20000460 = 0;
*(uint32_t*)0x20000464 = 0;
*(uint16_t*)0x20000468 = 0;
*(uint16_t*)0x2000046a = 0;
*(uint32_t*)0x2000046c = 0;
*(uint32_t*)0x20000470 = 0;
*(uint16_t*)0x20000474 = 0;
*(uint16_t*)0x20000476 = 0;
*(uint32_t*)0x20000478 = 0;
*(uint32_t*)0x2000047c = 0;
*(uint16_t*)0x20000480 = 0;
*(uint16_t*)0x20000482 = 0;
*(uint32_t*)0x20000484 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint16_t*)0x2000048c = 0;
*(uint16_t*)0x2000048e = 0;
*(uint32_t*)0x20000490 = 0;
*(uint32_t*)0x20000494 = 0;
*(uint16_t*)0x20000498 = 0;
*(uint16_t*)0x2000049a = 0;
*(uint32_t*)0x2000049c = 0;
*(uint32_t*)0x200004a0 = 0;
*(uint16_t*)0x200004a4 = 0;
*(uint16_t*)0x200004a6 = 0;
*(uint32_t*)0x200004a8 = 0;
*(uint32_t*)0x200004ac = 0;
*(uint16_t*)0x200004b0 = 0;
*(uint16_t*)0x200004b2 = 0;
*(uint32_t*)0x200004b4 = 0;
*(uint32_t*)0x200004b8 = 0;
*(uint16_t*)0x200004bc = 0;
*(uint16_t*)0x200004be = 0;
*(uint32_t*)0x200004c0 = 0;
*(uint32_t*)0x200004c4 = 0;
*(uint16_t*)0x200004c8 = 0;
*(uint16_t*)0x200004ca = 0;
*(uint32_t*)0x200004cc = 0;
*(uint32_t*)0x200004d0 = 0;
*(uint16_t*)0x200004d4 = 0;
*(uint16_t*)0x200004d6 = 0;
*(uint32_t*)0x200004d8 = 0;
*(uint32_t*)0x200004dc = 0;
*(uint16_t*)0x200004e0 = 0;
*(uint16_t*)0x200004e2 = 0;
*(uint32_t*)0x200004e4 = 0;
*(uint32_t*)0x200004e8 = 0;
*(uint16_t*)0x200004ec = 0;
*(uint16_t*)0x200004ee = 0;
*(uint32_t*)0x200004f0 = 0;
*(uint32_t*)0x200004f4 = 0;
*(uint16_t*)0x200004f8 = 0;
*(uint16_t*)0x200004fa = 0;
*(uint32_t*)0x200004fc = 0;
*(uint32_t*)0x20000500 = 0;
*(uint16_t*)0x20000504 = 0;
*(uint16_t*)0x20000506 = 0;
*(uint32_t*)0x20000508 = 0;
*(uint32_t*)0x2000050c = 0;
*(uint16_t*)0x20000510 = 0;
*(uint16_t*)0x20000512 = 0;
*(uint32_t*)0x20000514 = 0;
*(uint32_t*)0x20000518 = 0;
*(uint16_t*)0x2000051c = 0;
*(uint16_t*)0x2000051e = 0;
*(uint32_t*)0x20000520 = 0;
*(uint32_t*)0x20000524 = 0;
*(uint16_t*)0x20000528 = 0;
*(uint16_t*)0x2000052a = 0;
*(uint32_t*)0x2000052c = 0;
*(uint32_t*)0x20000530 = 0;
*(uint16_t*)0x20000534 = 0;
*(uint16_t*)0x20000536 = 0;
*(uint32_t*)0x20000538 = 0;
*(uint32_t*)0x2000053c = 0;
*(uint16_t*)0x20000540 = 0;
*(uint16_t*)0x20000542 = 0;
*(uint32_t*)0x20000544 = 0;
*(uint32_t*)0x20000548 = 0;
*(uint16_t*)0x2000054c = 0;
*(uint16_t*)0x2000054e = 0;
*(uint32_t*)0x20000550 = 0;
*(uint32_t*)0x20000554 = 0;
*(uint16_t*)0x20000558 = 0;
*(uint16_t*)0x2000055a = 0;
*(uint32_t*)0x2000055c = 0;
*(uint32_t*)0x20000560 = 0;
*(uint16_t*)0x20000564 = 0;
*(uint16_t*)0x20000566 = 0;
*(uint32_t*)0x20000568 = 0;
*(uint32_t*)0x2000056c = 0;
*(uint16_t*)0x20000570 = 0;
*(uint16_t*)0x20000572 = 0;
*(uint32_t*)0x20000574 = 0;
*(uint32_t*)0x20000578 = 0;
*(uint16_t*)0x2000057c = 0;
*(uint16_t*)0x2000057e = 0;
*(uint32_t*)0x20000580 = 0;
*(uint32_t*)0x20000584 = 0;
*(uint16_t*)0x20000588 = 0;
*(uint16_t*)0x2000058a = 0;
*(uint32_t*)0x2000058c = 0;
*(uint32_t*)0x20000590 = 0;
*(uint16_t*)0x20000594 = 0;
*(uint16_t*)0x20000596 = 0;
*(uint32_t*)0x20000598 = 0;
*(uint32_t*)0x2000059c = 0;
*(uint16_t*)0x200005a0 = 0;
*(uint16_t*)0x200005a2 = 0;
*(uint32_t*)0x200005a4 = 0;
*(uint32_t*)0x200005a8 = 0;
*(uint16_t*)0x200005ac = 0;
*(uint16_t*)0x200005ae = 0;
*(uint32_t*)0x200005b0 = 0;
*(uint32_t*)0x200005b4 = 0;
*(uint16_t*)0x200005b8 = 0;
*(uint16_t*)0x200005ba = 0;
*(uint32_t*)0x200005bc = 0;
*(uint32_t*)0x200005c0 = 0;
*(uint16_t*)0x200005c4 = 0;
*(uint16_t*)0x200005c6 = 0;
*(uint32_t*)0x200005c8 = 0;
*(uint32_t*)0x200005cc = 0;
*(uint16_t*)0x200005d0 = 0;
*(uint16_t*)0x200005d2 = 0;
*(uint32_t*)0x200005d4 = 0;
*(uint32_t*)0x200005d8 = 0;
*(uint16_t*)0x200005dc = 0;
*(uint16_t*)0x200005de = 0;
*(uint32_t*)0x200005e0 = 0;
*(uint32_t*)0x200005e4 = 0;
*(uint16_t*)0x200005e8 = 0x254;
*(uint16_t*)0x200005ea = 1;
*(uint32_t*)0x200005ec = 0;
*(uint32_t*)0x200005f0 = 0;
*(uint8_t*)0x200005f4 = 0;
*(uint8_t*)0x200005f5 = 0;
*(uint16_t*)0x200005f6 = 0;
*(uint16_t*)0x200005f8 = 0;
*(uint16_t*)0x200005fa = 0;
memcpy((void*)0x200005fc, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x2000061c, "\xf9\x8d\x30\x42\xe1\xcd\x2f\xcf\x63\x07\x60\x0c\x93\xba\x9f\x8d\x3f\x81\xe1\xda\x8f\xf9\x64\xd0\xae\xea\x3f\x19\x28\x25\x0f\x62", 32);
memcpy((void*)0x2000063c, "\x2a\x31\xde\xf0\x07\xa4\x2e\x50\x18\xc7\xdd\x2f\x8b\xde\xe9\xa9\xe6\xac\xd1\x8c\x2f\x19\x5f\x9f\xba\xd3\x14\x34\x46\x7f\xa2\x3f", 32);
*(uint16_t*)0x2000065c = 0;
*(uint16_t*)0x2000065e = 0;
*(uint32_t*)0x20000660 = 0;
*(uint32_t*)0x20000664 = 0;
*(uint16_t*)0x20000668 = 0;
*(uint16_t*)0x2000066a = 0;
*(uint32_t*)0x2000066c = 0;
*(uint32_t*)0x20000670 = 0;
*(uint16_t*)0x20000674 = 0;
*(uint16_t*)0x20000676 = 0;
*(uint32_t*)0x20000678 = 0;
*(uint32_t*)0x2000067c = 0;
*(uint16_t*)0x20000680 = 0;
*(uint16_t*)0x20000682 = 0;
*(uint32_t*)0x20000684 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint16_t*)0x2000068c = 0;
*(uint16_t*)0x2000068e = 0;
*(uint32_t*)0x20000690 = 0;
*(uint32_t*)0x20000694 = 0;
*(uint16_t*)0x20000698 = 0;
*(uint16_t*)0x2000069a = 0;
*(uint32_t*)0x2000069c = 0;
*(uint32_t*)0x200006a0 = 0;
*(uint16_t*)0x200006a4 = 0;
*(uint16_t*)0x200006a6 = 0;
*(uint32_t*)0x200006a8 = 0;
*(uint32_t*)0x200006ac = 0;
*(uint16_t*)0x200006b0 = 0;
*(uint16_t*)0x200006b2 = 0;
*(uint32_t*)0x200006b4 = 0;
*(uint32_t*)0x200006b8 = 0;
*(uint16_t*)0x200006bc = 0;
*(uint16_t*)0x200006be = 0;
*(uint32_t*)0x200006c0 = 0;
*(uint32_t*)0x200006c4 = 0;
*(uint16_t*)0x200006c8 = 0;
*(uint16_t*)0x200006ca = 0;
*(uint32_t*)0x200006cc = 0;
*(uint32_t*)0x200006d0 = 0;
*(uint16_t*)0x200006d4 = 0;
*(uint16_t*)0x200006d6 = 0;
*(uint32_t*)0x200006d8 = 0;
*(uint32_t*)0x200006dc = 0;
*(uint16_t*)0x200006e0 = 0;
*(uint16_t*)0x200006e2 = 0;
*(uint32_t*)0x200006e4 = 0;
*(uint32_t*)0x200006e8 = 0;
*(uint16_t*)0x200006ec = 0;
*(uint16_t*)0x200006ee = 0;
*(uint32_t*)0x200006f0 = 0;
*(uint32_t*)0x200006f4 = 0;
*(uint16_t*)0x200006f8 = 0;
*(uint16_t*)0x200006fa = 0;
*(uint32_t*)0x200006fc = 0;
*(uint32_t*)0x20000700 = 0;
*(uint16_t*)0x20000704 = 0;
*(uint16_t*)0x20000706 = 0;
*(uint32_t*)0x20000708 = 0;
*(uint32_t*)0x2000070c = 0;
*(uint16_t*)0x20000710 = 0;
*(uint16_t*)0x20000712 = 0;
*(uint32_t*)0x20000714 = 0;
*(uint32_t*)0x20000718 = 0;
*(uint16_t*)0x2000071c = 0;
*(uint16_t*)0x2000071e = 0;
*(uint32_t*)0x20000720 = 0;
*(uint32_t*)0x20000724 = 0;
*(uint16_t*)0x20000728 = 0;
*(uint16_t*)0x2000072a = 0;
*(uint32_t*)0x2000072c = 0;
*(uint32_t*)0x20000730 = 0;
*(uint16_t*)0x20000734 = 0;
*(uint16_t*)0x20000736 = 0;
*(uint32_t*)0x20000738 = 0;
*(uint32_t*)0x2000073c = 0;
*(uint16_t*)0x20000740 = 0;
*(uint16_t*)0x20000742 = 0;
*(uint32_t*)0x20000744 = 0;
*(uint32_t*)0x20000748 = 0;
*(uint16_t*)0x2000074c = 0;
*(uint16_t*)0x2000074e = 0;
*(uint32_t*)0x20000750 = 0;
*(uint32_t*)0x20000754 = 0;
*(uint16_t*)0x20000758 = 0;
*(uint16_t*)0x2000075a = 0;
*(uint32_t*)0x2000075c = 0;
*(uint32_t*)0x20000760 = 0;
*(uint16_t*)0x20000764 = 0;
*(uint16_t*)0x20000766 = 0;
*(uint32_t*)0x20000768 = 0;
*(uint32_t*)0x2000076c = 0;
*(uint16_t*)0x20000770 = 0;
*(uint16_t*)0x20000772 = 0;
*(uint32_t*)0x20000774 = 0;
*(uint32_t*)0x20000778 = 0;
*(uint16_t*)0x2000077c = 0;
*(uint16_t*)0x2000077e = 0;
*(uint32_t*)0x20000780 = 0;
*(uint32_t*)0x20000784 = 0;
*(uint16_t*)0x20000788 = 0;
*(uint16_t*)0x2000078a = 0;
*(uint32_t*)0x2000078c = 0;
*(uint32_t*)0x20000790 = 0;
*(uint16_t*)0x20000794 = 0;
*(uint16_t*)0x20000796 = 0;
*(uint32_t*)0x20000798 = 0;
*(uint32_t*)0x2000079c = 0;
*(uint16_t*)0x200007a0 = 0;
*(uint16_t*)0x200007a2 = 0;
*(uint32_t*)0x200007a4 = 0;
*(uint32_t*)0x200007a8 = 0;
*(uint16_t*)0x200007ac = 0;
*(uint16_t*)0x200007ae = 0;
*(uint32_t*)0x200007b0 = 0;
*(uint32_t*)0x200007b4 = 0;
*(uint16_t*)0x200007b8 = 0;
*(uint16_t*)0x200007ba = 0;
*(uint32_t*)0x200007bc = 0;
*(uint32_t*)0x200007c0 = 0;
*(uint16_t*)0x200007c4 = 0;
*(uint16_t*)0x200007c6 = 0;
*(uint32_t*)0x200007c8 = 0;
*(uint32_t*)0x200007cc = 0;
*(uint16_t*)0x200007d0 = 0;
*(uint16_t*)0x200007d2 = 0;
*(uint32_t*)0x200007d4 = 0;
*(uint32_t*)0x200007d8 = 0;
*(uint16_t*)0x200007dc = 0;
*(uint16_t*)0x200007de = 0;
*(uint32_t*)0x200007e0 = 0;
*(uint32_t*)0x200007e4 = 0;
*(uint16_t*)0x200007e8 = 0;
*(uint16_t*)0x200007ea = 0;
*(uint32_t*)0x200007ec = 0;
*(uint32_t*)0x200007f0 = 0;
*(uint16_t*)0x200007f4 = 0;
*(uint16_t*)0x200007f6 = 0;
*(uint32_t*)0x200007f8 = 0;
*(uint32_t*)0x200007fc = 0;
*(uint16_t*)0x20000800 = 0;
*(uint16_t*)0x20000802 = 0;
*(uint32_t*)0x20000804 = 0;
*(uint32_t*)0x20000808 = 0;
*(uint16_t*)0x2000080c = 0;
*(uint16_t*)0x2000080e = 0;
*(uint32_t*)0x20000810 = 0;
*(uint32_t*)0x20000814 = 0;
*(uint16_t*)0x20000818 = 0;
*(uint16_t*)0x2000081a = 0;
*(uint32_t*)0x2000081c = 0;
*(uint32_t*)0x20000820 = 0;
*(uint16_t*)0x20000824 = 0;
*(uint16_t*)0x20000826 = 0;
*(uint32_t*)0x20000828 = 0;
*(uint32_t*)0x2000082c = 0;
*(uint16_t*)0x20000830 = 0;
*(uint16_t*)0x20000832 = 0;
*(uint32_t*)0x20000834 = 0;
*(uint32_t*)0x20000838 = 0;
*(uint16_t*)0x2000083c = 0x254;
*(uint16_t*)0x2000083e = 1;
*(uint32_t*)0x20000840 = 0;
*(uint32_t*)0x20000844 = 0;
*(uint8_t*)0x20000848 = 0;
*(uint8_t*)0x20000849 = 0;
*(uint16_t*)0x2000084a = 0;
*(uint16_t*)0x2000084c = 0;
*(uint16_t*)0x2000084e = 0;
memcpy((void*)0x20000850, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000870, "\x79\x5d\xfc\x2e\x7a\x46\x42\x9d\xed\x63\x33\xcf\xca\x88\xfa\x9b\x09\xcb\xee\x32\x32\xef\xb8\x2d\xc0\x33\x90\xc0\xab\x5d\xc0\xfe", 32);
memcpy((void*)0x20000890, "\xa0\x19\x1e\x61\x06\x30\x40\xa5\xf1\x43\xed\x9a\x7d\x8d\x04\xba\xa5\x9c\x07\x81\x89\x36\xec\x72\x7c\xe1\xbd\x52\x54\xe1\xc1\xc9", 32);
*(uint16_t*)0x200008b0 = 0;
*(uint16_t*)0x200008b2 = 0;
*(uint32_t*)0x200008b4 = 0;
*(uint32_t*)0x200008b8 = 0;
*(uint16_t*)0x200008bc = 0;
*(uint16_t*)0x200008be = 0;
*(uint32_t*)0x200008c0 = 0;
*(uint32_t*)0x200008c4 = 0;
*(uint16_t*)0x200008c8 = 0;
*(uint16_t*)0x200008ca = 0;
*(uint32_t*)0x200008cc = 0;
*(uint32_t*)0x200008d0 = 0;
*(uint16_t*)0x200008d4 = 0;
*(uint16_t*)0x200008d6 = 0;
*(uint32_t*)0x200008d8 = 0;
*(uint32_t*)0x200008dc = 0;
*(uint16_t*)0x200008e0 = 0;
*(uint16_t*)0x200008e2 = 0;
*(uint32_t*)0x200008e4 = 0;
*(uint32_t*)0x200008e8 = 0;
*(uint16_t*)0x200008ec = 0;
*(uint16_t*)0x200008ee = 0;
*(uint32_t*)0x200008f0 = 0;
*(uint32_t*)0x200008f4 = 0;
*(uint16_t*)0x200008f8 = 0;
*(uint16_t*)0x200008fa = 0;
*(uint32_t*)0x200008fc = 0;
*(uint32_t*)0x20000900 = 0;
*(uint16_t*)0x20000904 = 0;
*(uint16_t*)0x20000906 = 0;
*(uint32_t*)0x20000908 = 0;
*(uint32_t*)0x2000090c = 0;
*(uint16_t*)0x20000910 = 0;
*(uint16_t*)0x20000912 = 0;
*(uint32_t*)0x20000914 = 0;
*(uint32_t*)0x20000918 = 0;
*(uint16_t*)0x2000091c = 0;
*(uint16_t*)0x2000091e = 0;
*(uint32_t*)0x20000920 = 0;
*(uint32_t*)0x20000924 = 0;
*(uint16_t*)0x20000928 = 0;
*(uint16_t*)0x2000092a = 0;
*(uint32_t*)0x2000092c = 0;
*(uint32_t*)0x20000930 = 0;
*(uint16_t*)0x20000934 = 0;
*(uint16_t*)0x20000936 = 0;
*(uint32_t*)0x20000938 = 0;
*(uint32_t*)0x2000093c = 0;
*(uint16_t*)0x20000940 = 0;
*(uint16_t*)0x20000942 = 0;
*(uint32_t*)0x20000944 = 0;
*(uint32_t*)0x20000948 = 0;
*(uint16_t*)0x2000094c = 0;
*(uint16_t*)0x2000094e = 0;
*(uint32_t*)0x20000950 = 0;
*(uint32_t*)0x20000954 = 0;
*(uint16_t*)0x20000958 = 0;
*(uint16_t*)0x2000095a = 0;
*(uint32_t*)0x2000095c = 0;
*(uint32_t*)0x20000960 = 0;
*(uint16_t*)0x20000964 = 0;
*(uint16_t*)0x20000966 = 0;
*(uint32_t*)0x20000968 = 0;
*(uint32_t*)0x2000096c = 0;
*(uint16_t*)0x20000970 = 0;
*(uint16_t*)0x20000972 = 0;
*(uint32_t*)0x20000974 = 0;
*(uint32_t*)0x20000978 = 0;
*(uint16_t*)0x2000097c = 0;
*(uint16_t*)0x2000097e = 0;
*(uint32_t*)0x20000980 = 0;
*(uint32_t*)0x20000984 = 0;
*(uint16_t*)0x20000988 = 0;
*(uint16_t*)0x2000098a = 0;
*(uint32_t*)0x2000098c = 0;
*(uint32_t*)0x20000990 = 0;
*(uint16_t*)0x20000994 = 0;
*(uint16_t*)0x20000996 = 0;
*(uint32_t*)0x20000998 = 0;
*(uint32_t*)0x2000099c = 0;
*(uint16_t*)0x200009a0 = 0;
*(uint16_t*)0x200009a2 = 0;
*(uint32_t*)0x200009a4 = 0;
*(uint32_t*)0x200009a8 = 0;
*(uint16_t*)0x200009ac = 0;
*(uint16_t*)0x200009ae = 0;
*(uint32_t*)0x200009b0 = 0;
*(uint32_t*)0x200009b4 = 0;
*(uint16_t*)0x200009b8 = 0;
*(uint16_t*)0x200009ba = 0;
*(uint32_t*)0x200009bc = 0;
*(uint32_t*)0x200009c0 = 0;
*(uint16_t*)0x200009c4 = 0;
*(uint16_t*)0x200009c6 = 0;
*(uint32_t*)0x200009c8 = 0;
*(uint32_t*)0x200009cc = 0;
*(uint16_t*)0x200009d0 = 0;
*(uint16_t*)0x200009d2 = 0;
*(uint32_t*)0x200009d4 = 0;
*(uint32_t*)0x200009d8 = 0;
*(uint16_t*)0x200009dc = 0;
*(uint16_t*)0x200009de = 0;
*(uint32_t*)0x200009e0 = 0;
*(uint32_t*)0x200009e4 = 0;
*(uint16_t*)0x200009e8 = 0;
*(uint16_t*)0x200009ea = 0;
*(uint32_t*)0x200009ec = 0;
*(uint32_t*)0x200009f0 = 0;
*(uint16_t*)0x200009f4 = 0;
*(uint16_t*)0x200009f6 = 0;
*(uint32_t*)0x200009f8 = 0;
*(uint32_t*)0x200009fc = 0;
*(uint16_t*)0x20000a00 = 0;
*(uint16_t*)0x20000a02 = 0;
*(uint32_t*)0x20000a04 = 0;
*(uint32_t*)0x20000a08 = 0;
*(uint16_t*)0x20000a0c = 0;
*(uint16_t*)0x20000a0e = 0;
*(uint32_t*)0x20000a10 = 0;
*(uint32_t*)0x20000a14 = 0;
*(uint16_t*)0x20000a18 = 0;
*(uint16_t*)0x20000a1a = 0;
*(uint32_t*)0x20000a1c = 0;
*(uint32_t*)0x20000a20 = 0;
*(uint16_t*)0x20000a24 = 0;
*(uint16_t*)0x20000a26 = 0;
*(uint32_t*)0x20000a28 = 0;
*(uint32_t*)0x20000a2c = 0;
*(uint16_t*)0x20000a30 = 0;
*(uint16_t*)0x20000a32 = 0;
*(uint32_t*)0x20000a34 = 0;
*(uint32_t*)0x20000a38 = 0;
*(uint16_t*)0x20000a3c = 0;
*(uint16_t*)0x20000a3e = 0;
*(uint32_t*)0x20000a40 = 0;
*(uint32_t*)0x20000a44 = 0;
*(uint16_t*)0x20000a48 = 0;
*(uint16_t*)0x20000a4a = 0;
*(uint32_t*)0x20000a4c = 0;
*(uint32_t*)0x20000a50 = 0;
*(uint16_t*)0x20000a54 = 0;
*(uint16_t*)0x20000a56 = 0;
*(uint32_t*)0x20000a58 = 0;
*(uint32_t*)0x20000a5c = 0;
*(uint16_t*)0x20000a60 = 0;
*(uint16_t*)0x20000a62 = 0;
*(uint32_t*)0x20000a64 = 0;
*(uint32_t*)0x20000a68 = 0;
*(uint16_t*)0x20000a6c = 0;
*(uint16_t*)0x20000a6e = 0;
*(uint32_t*)0x20000a70 = 0;
*(uint32_t*)0x20000a74 = 0;
*(uint16_t*)0x20000a78 = 0;
*(uint16_t*)0x20000a7a = 0;
*(uint32_t*)0x20000a7c = 0;
*(uint32_t*)0x20000a80 = 0;
*(uint16_t*)0x20000a84 = 0;
*(uint16_t*)0x20000a86 = 0;
*(uint32_t*)0x20000a88 = 0;
*(uint32_t*)0x20000a8c = 0;
*(uint16_t*)0x20000a90 = 0x254;
*(uint16_t*)0x20000a92 = 1;
*(uint32_t*)0x20000a94 = 0;
*(uint32_t*)0x20000a98 = 0;
*(uint8_t*)0x20000a9c = 0;
*(uint8_t*)0x20000a9d = 0;
*(uint16_t*)0x20000a9e = 0;
*(uint16_t*)0x20000aa0 = 0;
*(uint16_t*)0x20000aa2 = 0;
memcpy((void*)0x20000aa4, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000ac4, "\x6b\xd3\x0a\xc6\xc5\xbd\xc1\x00\xe8\xe8\x89\x34\x78\xa9\xf3\x2a\x2e\xfe\x35\x36\xcf\xa0\x06\xd2\xd7\xae\x28\xda\xe2\xc6\xb4\x66", 32);
memcpy((void*)0x20000ae4, "\x93\x1a\x1b\x8c\x8e\xe1\x65\x45\xb7\x62\x43\x50\xfb\xe2\x34\x48\x5d\xc6\xb1\xf7\x4c\x95\x06\xb4\xbf\x2a\x5d\x2f\x50\x89\xbe\x67", 32);
*(uint16_t*)0x20000b04 = 0;
*(uint16_t*)0x20000b06 = 0;
*(uint32_t*)0x20000b08 = 0;
*(uint32_t*)0x20000b0c = 0;
*(uint16_t*)0x20000b10 = 0;
*(uint16_t*)0x20000b12 = 0;
*(uint32_t*)0x20000b14 = 0;
*(uint32_t*)0x20000b18 = 0;
*(uint16_t*)0x20000b1c = 0;
*(uint16_t*)0x20000b1e = 0;
*(uint32_t*)0x20000b20 = 0;
*(uint32_t*)0x20000b24 = 0;
*(uint16_t*)0x20000b28 = 0;
*(uint16_t*)0x20000b2a = 0;
*(uint32_t*)0x20000b2c = 0;
*(uint32_t*)0x20000b30 = 0;
*(uint16_t*)0x20000b34 = 0;
*(uint16_t*)0x20000b36 = 0;
*(uint32_t*)0x20000b38 = 0;
*(uint32_t*)0x20000b3c = 0;
*(uint16_t*)0x20000b40 = 0;
*(uint16_t*)0x20000b42 = 0;
*(uint32_t*)0x20000b44 = 0;
*(uint32_t*)0x20000b48 = 0;
*(uint16_t*)0x20000b4c = 0;
*(uint16_t*)0x20000b4e = 0;
*(uint32_t*)0x20000b50 = 0;
*(uint32_t*)0x20000b54 = 0;
*(uint16_t*)0x20000b58 = 0;
*(uint16_t*)0x20000b5a = 0;
*(uint32_t*)0x20000b5c = 0;
*(uint32_t*)0x20000b60 = 0;
*(uint16_t*)0x20000b64 = 0;
*(uint16_t*)0x20000b66 = 0;
*(uint32_t*)0x20000b68 = 0;
*(uint32_t*)0x20000b6c = 0;
*(uint16_t*)0x20000b70 = 0;
*(uint16_t*)0x20000b72 = 0;
*(uint32_t*)0x20000b74 = 0;
*(uint32_t*)0x20000b78 = 0;
*(uint16_t*)0x20000b7c = 0;
*(uint16_t*)0x20000b7e = 0;
*(uint32_t*)0x20000b80 = 0;
*(uint32_t*)0x20000b84 = 0;
*(uint16_t*)0x20000b88 = 0;
*(uint16_t*)0x20000b8a = 0;
*(uint32_t*)0x20000b8c = 0;
*(uint32_t*)0x20000b90 = 0;
*(uint16_t*)0x20000b94 = 0;
*(uint16_t*)0x20000b96 = 0;
*(uint32_t*)0x20000b98 = 0;
*(uint32_t*)0x20000b9c = 0;
*(uint16_t*)0x20000ba0 = 0;
*(uint16_t*)0x20000ba2 = 0;
*(uint32_t*)0x20000ba4 = 0;
*(uint32_t*)0x20000ba8 = 0;
*(uint16_t*)0x20000bac = 0;
*(uint16_t*)0x20000bae = 0;
*(uint32_t*)0x20000bb0 = 0;
*(uint32_t*)0x20000bb4 = 0;
*(uint16_t*)0x20000bb8 = 0;
*(uint16_t*)0x20000bba = 0;
*(uint32_t*)0x20000bbc = 0;
*(uint32_t*)0x20000bc0 = 0;
*(uint16_t*)0x20000bc4 = 0;
*(uint16_t*)0x20000bc6 = 0;
*(uint32_t*)0x20000bc8 = 0;
*(uint32_t*)0x20000bcc = 0;
*(uint16_t*)0x20000bd0 = 0;
*(uint16_t*)0x20000bd2 = 0;
*(uint32_t*)0x20000bd4 = 0;
*(uint32_t*)0x20000bd8 = 0;
*(uint16_t*)0x20000bdc = 0;
*(uint16_t*)0x20000bde = 0;
*(uint32_t*)0x20000be0 = 0;
*(uint32_t*)0x20000be4 = 0;
*(uint16_t*)0x20000be8 = 0;
*(uint16_t*)0x20000bea = 0;
*(uint32_t*)0x20000bec = 0;
*(uint32_t*)0x20000bf0 = 0;
*(uint16_t*)0x20000bf4 = 0;
*(uint16_t*)0x20000bf6 = 0;
*(uint32_t*)0x20000bf8 = 0;
*(uint32_t*)0x20000bfc = 0;
*(uint16_t*)0x20000c00 = 0;
*(uint16_t*)0x20000c02 = 0;
*(uint32_t*)0x20000c04 = 0;
*(uint32_t*)0x20000c08 = 0;
*(uint16_t*)0x20000c0c = 0;
*(uint16_t*)0x20000c0e = 0;
*(uint32_t*)0x20000c10 = 0;
*(uint32_t*)0x20000c14 = 0;
*(uint16_t*)0x20000c18 = 0;
*(uint16_t*)0x20000c1a = 0;
*(uint32_t*)0x20000c1c = 0;
*(uint32_t*)0x20000c20 = 0;
*(uint16_t*)0x20000c24 = 0;
*(uint16_t*)0x20000c26 = 0;
*(uint32_t*)0x20000c28 = 0;
*(uint32_t*)0x20000c2c = 0;
*(uint16_t*)0x20000c30 = 0;
*(uint16_t*)0x20000c32 = 0;
*(uint32_t*)0x20000c34 = 0;
*(uint32_t*)0x20000c38 = 0;
*(uint16_t*)0x20000c3c = 0;
*(uint16_t*)0x20000c3e = 0;
*(uint32_t*)0x20000c40 = 0;
*(uint32_t*)0x20000c44 = 0;
*(uint16_t*)0x20000c48 = 0;
*(uint16_t*)0x20000c4a = 0;
*(uint32_t*)0x20000c4c = 0;
*(uint32_t*)0x20000c50 = 0;
*(uint16_t*)0x20000c54 = 0;
*(uint16_t*)0x20000c56 = 0;
*(uint32_t*)0x20000c58 = 0;
*(uint32_t*)0x20000c5c = 0;
*(uint16_t*)0x20000c60 = 0;
*(uint16_t*)0x20000c62 = 0;
*(uint32_t*)0x20000c64 = 0;
*(uint32_t*)0x20000c68 = 0;
*(uint16_t*)0x20000c6c = 0;
*(uint16_t*)0x20000c6e = 0;
*(uint32_t*)0x20000c70 = 0;
*(uint32_t*)0x20000c74 = 0;
*(uint16_t*)0x20000c78 = 0;
*(uint16_t*)0x20000c7a = 0;
*(uint32_t*)0x20000c7c = 0;
*(uint32_t*)0x20000c80 = 0;
*(uint16_t*)0x20000c84 = 0;
*(uint16_t*)0x20000c86 = 0;
*(uint32_t*)0x20000c88 = 0;
*(uint32_t*)0x20000c8c = 0;
*(uint16_t*)0x20000c90 = 0;
*(uint16_t*)0x20000c92 = 0;
*(uint32_t*)0x20000c94 = 0;
*(uint32_t*)0x20000c98 = 0;
*(uint16_t*)0x20000c9c = 0;
*(uint16_t*)0x20000c9e = 0;
*(uint32_t*)0x20000ca0 = 0;
*(uint32_t*)0x20000ca4 = 0;
*(uint16_t*)0x20000ca8 = 0;
*(uint16_t*)0x20000caa = 0;
*(uint32_t*)0x20000cac = 0;
*(uint32_t*)0x20000cb0 = 0;
*(uint16_t*)0x20000cb4 = 0;
*(uint16_t*)0x20000cb6 = 0;
*(uint32_t*)0x20000cb8 = 0;
*(uint32_t*)0x20000cbc = 0;
*(uint16_t*)0x20000cc0 = 0;
*(uint16_t*)0x20000cc2 = 0;
*(uint32_t*)0x20000cc4 = 0;
*(uint32_t*)0x20000cc8 = 0;
*(uint16_t*)0x20000ccc = 0;
*(uint16_t*)0x20000cce = 0;
*(uint32_t*)0x20000cd0 = 0;
*(uint32_t*)0x20000cd4 = 0;
*(uint16_t*)0x20000cd8 = 0;
*(uint16_t*)0x20000cda = 0;
*(uint32_t*)0x20000cdc = 0;
*(uint32_t*)0x20000ce0 = 0;
*(uint64_t*)0x20000088 = 0x964;
*(uint64_t*)0x200000d8 = 1;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200000c0ul, 0ul);
	return 0;
}
