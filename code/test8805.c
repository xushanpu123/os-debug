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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001300 = 0;
*(uint32_t*)0x20001308 = 0;
*(uint64_t*)0x20001310 = 0x200012c0;
*(uint64_t*)0x200012c0 = 0x20000240;
*(uint32_t*)0x20000240 = 0x1060;
*(uint8_t*)0x20000244 = 0;
*(uint8_t*)0x20000245 = 5;
*(uint16_t*)0x20000246 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint32_t*)0x2000024c = 0;
*(uint8_t*)0x20000250 = 0;
*(uint8_t*)0x20000251 = 0;
*(uint16_t*)0x20000252 = htobe16(0);
*(uint16_t*)0x20000254 = 0x254;
*(uint16_t*)0x20000256 = 1;
*(uint32_t*)0x20000258 = 0;
*(uint32_t*)0x2000025c = 0;
*(uint8_t*)0x20000260 = 1;
*(uint8_t*)0x20000261 = 0;
*(uint16_t*)0x20000262 = 0;
*(uint16_t*)0x20000264 = 0;
*(uint16_t*)0x20000266 = 0;
memcpy((void*)0x20000268, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000288, "\xdf\xd0\x2e\xc6\x64\x7b\xdc\x6a\x99\x47\x28\xd9\x08\xa7\x5d\x9d\x8a\xf6\x6c\xcc\x04\x3a\xb8\x8e\xce\x2a\x27\xad\x2f\x78\x75\x2c", 32);
memcpy((void*)0x200002a8, "\x63\xdc\x17\xa4\xfd\x04\xf1\xd5\x22\xe4\x7e\xc7\x11\xb2\xc7\xeb\x36\x5d\xbf\x76\xaf\xed\x34\xda\xf4\x08\x01\x8b\xe2\xa9\xa9\x26", 32);
*(uint16_t*)0x200002c8 = 0;
*(uint16_t*)0x200002ca = 0x3f;
*(uint32_t*)0x200002cc = 3;
*(uint32_t*)0x200002d0 = 6;
*(uint16_t*)0x200002d4 = 9;
*(uint16_t*)0x200002d6 = -1;
*(uint32_t*)0x200002d8 = 1;
*(uint32_t*)0x200002dc = 0xffff;
*(uint16_t*)0x200002e0 = 4;
*(uint16_t*)0x200002e2 = 4;
*(uint32_t*)0x200002e4 = 0;
*(uint32_t*)0x200002e8 = 0xfff;
*(uint16_t*)0x200002ec = 0x1ff;
*(uint16_t*)0x200002ee = 7;
*(uint32_t*)0x200002f0 = 3;
*(uint32_t*)0x200002f4 = 0x20;
*(uint16_t*)0x200002f8 = 0x101;
*(uint16_t*)0x200002fa = 0x4448;
*(uint32_t*)0x200002fc = 3;
*(uint32_t*)0x20000300 = 9;
*(uint16_t*)0x20000304 = 4;
*(uint16_t*)0x20000306 = 1;
*(uint32_t*)0x20000308 = 2;
*(uint32_t*)0x2000030c = 7;
*(uint16_t*)0x20000310 = 0xbb28;
*(uint16_t*)0x20000312 = 0x13e;
*(uint32_t*)0x20000314 = 0;
*(uint32_t*)0x20000318 = 2;
*(uint16_t*)0x2000031c = 2;
*(uint16_t*)0x2000031e = 0x3d8e;
*(uint32_t*)0x20000320 = 2;
*(uint32_t*)0x20000324 = 0x101;
*(uint16_t*)0x20000328 = 4;
*(uint16_t*)0x2000032a = 0x3600;
*(uint32_t*)0x2000032c = 2;
*(uint32_t*)0x20000330 = 0xfffff801;
*(uint16_t*)0x20000334 = 2;
*(uint16_t*)0x20000336 = 0x80;
*(uint32_t*)0x20000338 = 0;
*(uint32_t*)0x2000033c = 0xc6;
*(uint16_t*)0x20000340 = 0;
*(uint16_t*)0x20000342 = 8;
*(uint32_t*)0x20000344 = 3;
*(uint32_t*)0x20000348 = 5;
*(uint16_t*)0x2000034c = 7;
*(uint16_t*)0x2000034e = 4;
*(uint32_t*)0x20000350 = 2;
*(uint32_t*)0x20000354 = 3;
*(uint16_t*)0x20000358 = 3;
*(uint16_t*)0x2000035a = 9;
*(uint32_t*)0x2000035c = 3;
*(uint32_t*)0x20000360 = 6;
*(uint16_t*)0x20000364 = 0x8000;
*(uint16_t*)0x20000366 = 0x8001;
*(uint32_t*)0x20000368 = 2;
*(uint32_t*)0x2000036c = 0x7b;
*(uint16_t*)0x20000370 = 0x40;
*(uint16_t*)0x20000372 = 3;
*(uint32_t*)0x20000374 = 2;
*(uint32_t*)0x20000378 = 0x80000001;
*(uint16_t*)0x2000037c = 3;
*(uint16_t*)0x2000037e = 0xff28;
*(uint32_t*)0x20000380 = 3;
*(uint32_t*)0x20000384 = 0x101;
*(uint16_t*)0x20000388 = 0;
*(uint16_t*)0x2000038a = 9;
*(uint32_t*)0x2000038c = 0;
*(uint32_t*)0x20000390 = 0xa7;
*(uint16_t*)0x20000394 = 9;
*(uint16_t*)0x20000396 = 0x80;
*(uint32_t*)0x20000398 = 1;
*(uint32_t*)0x2000039c = 7;
*(uint16_t*)0x200003a0 = 0xac;
*(uint16_t*)0x200003a2 = 1;
*(uint32_t*)0x200003a4 = 1;
*(uint32_t*)0x200003a8 = 5;
*(uint16_t*)0x200003ac = 0x5cac;
*(uint16_t*)0x200003ae = 8;
*(uint32_t*)0x200003b0 = 0;
*(uint32_t*)0x200003b4 = 0x800;
*(uint16_t*)0x200003b8 = 0x6670;
*(uint16_t*)0x200003ba = 4;
*(uint32_t*)0x200003bc = 2;
*(uint32_t*)0x200003c0 = 4;
*(uint16_t*)0x200003c4 = 2;
*(uint16_t*)0x200003c6 = 5;
*(uint32_t*)0x200003c8 = 0;
*(uint32_t*)0x200003cc = 3;
*(uint16_t*)0x200003d0 = 0xcec;
*(uint16_t*)0x200003d2 = 0xfdc4;
*(uint32_t*)0x200003d4 = 3;
*(uint32_t*)0x200003d8 = 4;
*(uint16_t*)0x200003dc = 0x20;
*(uint16_t*)0x200003de = 0x39e3;
*(uint32_t*)0x200003e0 = 1;
*(uint32_t*)0x200003e4 = 2;
*(uint16_t*)0x200003e8 = 0x8000;
*(uint16_t*)0x200003ea = 0x1000;
*(uint32_t*)0x200003ec = 1;
*(uint32_t*)0x200003f0 = 0x8001;
*(uint16_t*)0x200003f4 = 0x8f;
*(uint16_t*)0x200003f6 = 0xfddb;
*(uint32_t*)0x200003f8 = 3;
*(uint32_t*)0x200003fc = 0x88d7;
*(uint16_t*)0x20000400 = 0x401;
*(uint16_t*)0x20000402 = 8;
*(uint32_t*)0x20000404 = 3;
*(uint32_t*)0x20000408 = 7;
*(uint16_t*)0x2000040c = 6;
*(uint16_t*)0x2000040e = 1;
*(uint32_t*)0x20000410 = 0;
*(uint32_t*)0x20000414 = 0x7fff;
*(uint16_t*)0x20000418 = 0xea;
*(uint16_t*)0x2000041a = 0;
*(uint32_t*)0x2000041c = 3;
*(uint32_t*)0x20000420 = 6;
*(uint16_t*)0x20000424 = 5;
*(uint16_t*)0x20000426 = 4;
*(uint32_t*)0x20000428 = 1;
*(uint32_t*)0x2000042c = 1;
*(uint16_t*)0x20000430 = 9;
*(uint16_t*)0x20000432 = 0x1ff;
*(uint32_t*)0x20000434 = 3;
*(uint32_t*)0x20000438 = 0xffff;
*(uint16_t*)0x2000043c = 0;
*(uint16_t*)0x2000043e = 3;
*(uint32_t*)0x20000440 = 0;
*(uint32_t*)0x20000444 = 0x1f;
*(uint16_t*)0x20000448 = 1;
*(uint16_t*)0x2000044a = 4;
*(uint32_t*)0x2000044c = 2;
*(uint32_t*)0x20000450 = 0xfff;
*(uint16_t*)0x20000454 = 6;
*(uint16_t*)0x20000456 = 8;
*(uint32_t*)0x20000458 = 0;
*(uint32_t*)0x2000045c = 0x87b;
*(uint16_t*)0x20000460 = 0x81;
*(uint16_t*)0x20000462 = 0x3ff;
*(uint32_t*)0x20000464 = 2;
*(uint32_t*)0x20000468 = 0xfffffff9;
*(uint16_t*)0x2000046c = 0xfffd;
*(uint16_t*)0x2000046e = 0x4c9f;
*(uint32_t*)0x20000470 = 3;
*(uint32_t*)0x20000474 = 0xfffff640;
*(uint16_t*)0x20000478 = 0;
*(uint16_t*)0x2000047a = 0;
*(uint32_t*)0x2000047c = 0;
*(uint32_t*)0x20000480 = 0;
*(uint16_t*)0x20000484 = 0;
*(uint16_t*)0x20000486 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint32_t*)0x2000048c = 0;
*(uint16_t*)0x20000490 = 0;
*(uint16_t*)0x20000492 = 0;
*(uint32_t*)0x20000494 = 0;
*(uint32_t*)0x20000498 = 0;
*(uint16_t*)0x2000049c = 0;
*(uint16_t*)0x2000049e = 0;
*(uint32_t*)0x200004a0 = 0;
*(uint32_t*)0x200004a4 = 0;
*(uint16_t*)0x200004a8 = 0x254;
*(uint16_t*)0x200004aa = 1;
*(uint32_t*)0x200004ac = 0;
*(uint32_t*)0x200004b0 = 0;
*(uint8_t*)0x200004b4 = 0;
*(uint8_t*)0x200004b5 = 0;
*(uint16_t*)0x200004b6 = 0;
*(uint16_t*)0x200004b8 = 0;
*(uint16_t*)0x200004ba = 0;
memcpy((void*)0x200004bc, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x200004dc, "\x81\xfb\x5b\x0d\x91\x91\xcb\x43\x33\x0a\x91\x86\x73\xbf\x96\xfa\xb2\xfa\x59\x19\xda\x52\x85\xe8\x9c\xdf\x17\x61\x2a\x20\xc0\xc1", 32);
memcpy((void*)0x200004fc, "\x7b\xcd\x51\xd4\xc9\xe4\x84\x29\xd1\x85\x7a\x83\x03\xfd\xfe\x66\xbd\x75\x39\xf2\xb5\x3c\x8a\x25\x32\x60\xe7\x8d\x6f\xca\x3e\xec", 32);
*(uint16_t*)0x2000051c = 0;
*(uint16_t*)0x2000051e = 0;
*(uint32_t*)0x20000520 = 0;
*(uint32_t*)0x20000524 = 0;
*(uint16_t*)0x20000528 = 0;
*(uint16_t*)0x2000052a = 0;
*(uint32_t*)0x2000052c = 0;
*(uint32_t*)0x20000530 = 0;
*(uint16_t*)0x20000534 = 0xfffd;
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
*(uint16_t*)0x200005a0 = 4;
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
*(uint16_t*)0x200005e8 = 0;
*(uint16_t*)0x200005ea = 0;
*(uint32_t*)0x200005ec = 0;
*(uint32_t*)0x200005f0 = 0;
*(uint16_t*)0x200005f4 = 0;
*(uint16_t*)0x200005f6 = 0;
*(uint32_t*)0x200005f8 = 0;
*(uint32_t*)0x200005fc = 0;
*(uint16_t*)0x20000600 = 0;
*(uint16_t*)0x20000602 = 0;
*(uint32_t*)0x20000604 = 0;
*(uint32_t*)0x20000608 = 0;
*(uint16_t*)0x2000060c = 0;
*(uint16_t*)0x2000060e = 0;
*(uint32_t*)0x20000610 = 0;
*(uint32_t*)0x20000614 = 0;
*(uint16_t*)0x20000618 = 0;
*(uint16_t*)0x2000061a = 0;
*(uint32_t*)0x2000061c = 0;
*(uint32_t*)0x20000620 = 0;
*(uint16_t*)0x20000624 = 0;
*(uint16_t*)0x20000626 = 0;
*(uint32_t*)0x20000628 = 0;
*(uint32_t*)0x2000062c = 0;
*(uint16_t*)0x20000630 = 0;
*(uint16_t*)0x20000632 = 0;
*(uint32_t*)0x20000634 = 0;
*(uint32_t*)0x20000638 = 0;
*(uint16_t*)0x2000063c = 0;
*(uint16_t*)0x2000063e = 0;
*(uint32_t*)0x20000640 = 0;
*(uint32_t*)0x20000644 = 0;
*(uint16_t*)0x20000648 = 0;
*(uint16_t*)0x2000064a = 0;
*(uint32_t*)0x2000064c = 0;
*(uint32_t*)0x20000650 = 0;
*(uint16_t*)0x20000654 = 0;
*(uint16_t*)0x20000656 = 0;
*(uint32_t*)0x20000658 = 0;
*(uint32_t*)0x2000065c = 0;
*(uint16_t*)0x20000660 = 0;
*(uint16_t*)0x20000662 = 0;
*(uint32_t*)0x20000664 = 3;
*(uint32_t*)0x20000668 = 0;
*(uint16_t*)0x2000066c = 0;
*(uint16_t*)0x2000066e = 0;
*(uint32_t*)0x20000670 = 0;
*(uint32_t*)0x20000674 = 8;
*(uint16_t*)0x20000678 = 0;
*(uint16_t*)0x2000067a = 0;
*(uint32_t*)0x2000067c = 0;
*(uint32_t*)0x20000680 = 0;
*(uint16_t*)0x20000684 = 0;
*(uint16_t*)0x20000686 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint32_t*)0x2000068c = 0;
*(uint16_t*)0x20000690 = 0;
*(uint16_t*)0x20000692 = 0;
*(uint32_t*)0x20000694 = 0;
*(uint32_t*)0x20000698 = 0;
*(uint16_t*)0x2000069c = 0;
*(uint16_t*)0x2000069e = 0;
*(uint32_t*)0x200006a0 = 0;
*(uint32_t*)0x200006a4 = 0;
*(uint16_t*)0x200006a8 = 9;
*(uint16_t*)0x200006aa = 0;
*(uint32_t*)0x200006ac = 0;
*(uint32_t*)0x200006b0 = 0;
*(uint16_t*)0x200006b4 = 0;
*(uint16_t*)0x200006b6 = 0;
*(uint32_t*)0x200006b8 = 0;
*(uint32_t*)0x200006bc = 0;
*(uint16_t*)0x200006c0 = 0;
*(uint16_t*)0x200006c2 = 0;
*(uint32_t*)0x200006c4 = 0;
*(uint32_t*)0x200006c8 = 0;
*(uint16_t*)0x200006cc = 0;
*(uint16_t*)0x200006ce = 0;
*(uint32_t*)0x200006d0 = 0;
*(uint32_t*)0x200006d4 = 0;
*(uint16_t*)0x200006d8 = 0;
*(uint16_t*)0x200006da = 0;
*(uint32_t*)0x200006dc = 0;
*(uint32_t*)0x200006e0 = 0;
*(uint16_t*)0x200006e4 = 0;
*(uint16_t*)0x200006e6 = 0;
*(uint32_t*)0x200006e8 = 0;
*(uint32_t*)0x200006ec = 0;
*(uint16_t*)0x200006f0 = 0;
*(uint16_t*)0x200006f2 = 0;
*(uint32_t*)0x200006f4 = 0;
*(uint32_t*)0x200006f8 = 0;
*(uint16_t*)0x200006fc = 0x254;
*(uint16_t*)0x200006fe = 1;
*(uint32_t*)0x20000700 = 0;
*(uint32_t*)0x20000704 = 0x400;
*(uint8_t*)0x20000708 = -1;
*(uint8_t*)0x20000709 = 3;
*(uint16_t*)0x2000070a = 4;
*(uint16_t*)0x2000070c = 0;
*(uint16_t*)0x2000070e = 0xa;
memcpy((void*)0x20000710, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000730, "\x19\x2e\xc7\x95\x48\x9d\xa1\x5f\x74\x9b\x46\xa3\xf4\x0c\x70\x3e\x05\x73\x4a\x56\x22\x67\x4a\x46\x5f\x9b\xf2\x80\xfb\xc6\x08\x94", 32);
memcpy((void*)0x20000750, "\xd4\x71\x0f\x58\x2a\xf9\x9c\xc1\xb8\x21\x44\x14\x72\x0b\x01\x88\xeb\x6b\x86\x98\x67\xee\x2f\x89\x92\x8f\x56\x03\x5a\x85\xb3\x6b", 32);
*(uint16_t*)0x20000770 = 0;
*(uint16_t*)0x20000772 = 0;
*(uint32_t*)0x20000774 = 0;
*(uint32_t*)0x20000778 = 0;
*(uint16_t*)0x2000077c = 2;
*(uint16_t*)0x2000077e = 0x401;
*(uint32_t*)0x20000780 = 0;
*(uint32_t*)0x20000784 = 0;
*(uint16_t*)0x20000788 = 2;
*(uint16_t*)0x2000078a = 0x400;
*(uint32_t*)0x2000078c = 0;
*(uint32_t*)0x20000790 = 0x970e;
*(uint16_t*)0x20000794 = 6;
*(uint16_t*)0x20000796 = 0x8001;
*(uint32_t*)0x20000798 = 3;
*(uint32_t*)0x2000079c = 2;
*(uint16_t*)0x200007a0 = 2;
*(uint16_t*)0x200007a2 = 3;
*(uint32_t*)0x200007a4 = 2;
*(uint32_t*)0x200007a8 = 9;
*(uint16_t*)0x200007ac = 0x1784;
*(uint16_t*)0x200007ae = 1;
*(uint32_t*)0x200007b0 = 0;
*(uint32_t*)0x200007b4 = 7;
*(uint16_t*)0x200007b8 = 0;
*(uint16_t*)0x200007ba = 0xf0;
*(uint32_t*)0x200007bc = 2;
*(uint32_t*)0x200007c0 = 0;
*(uint16_t*)0x200007c4 = 0xff;
*(uint16_t*)0x200007c6 = 8;
*(uint32_t*)0x200007c8 = 2;
*(uint32_t*)0x200007cc = 9;
*(uint16_t*)0x200007d0 = 0;
*(uint16_t*)0x200007d2 = 0x3b8;
*(uint32_t*)0x200007d4 = 0;
*(uint32_t*)0x200007d8 = 2;
*(uint16_t*)0x200007dc = 0x8000;
*(uint16_t*)0x200007de = 8;
*(uint32_t*)0x200007e0 = 1;
*(uint32_t*)0x200007e4 = 8;
*(uint16_t*)0x200007e8 = 0x1000;
*(uint16_t*)0x200007ea = 4;
*(uint32_t*)0x200007ec = 3;
*(uint32_t*)0x200007f0 = 0xc2;
*(uint16_t*)0x200007f4 = 0x7fff;
*(uint16_t*)0x200007f6 = 8;
*(uint32_t*)0x200007f8 = 0;
*(uint32_t*)0x200007fc = 0x401;
*(uint16_t*)0x20000800 = 0x387b;
*(uint16_t*)0x20000802 = 5;
*(uint32_t*)0x20000804 = 1;
*(uint32_t*)0x20000808 = 0x2358;
*(uint16_t*)0x2000080c = 9;
*(uint16_t*)0x2000080e = 5;
*(uint32_t*)0x20000810 = 0;
*(uint32_t*)0x20000814 = 0x1ff;
*(uint16_t*)0x20000818 = 0x62;
*(uint16_t*)0x2000081a = 2;
*(uint32_t*)0x2000081c = 0;
*(uint32_t*)0x20000820 = 0xe;
*(uint16_t*)0x20000824 = 0x9aa9;
*(uint16_t*)0x20000826 = 1;
*(uint32_t*)0x20000828 = 3;
*(uint32_t*)0x2000082c = 0xffff;
*(uint16_t*)0x20000830 = 0x1f;
*(uint16_t*)0x20000832 = 5;
*(uint32_t*)0x20000834 = 3;
*(uint32_t*)0x20000838 = 4;
*(uint16_t*)0x2000083c = 1;
*(uint16_t*)0x2000083e = 0x401;
*(uint32_t*)0x20000840 = 3;
*(uint32_t*)0x20000844 = 3;
*(uint16_t*)0x20000848 = 4;
*(uint16_t*)0x2000084a = 0x20;
*(uint32_t*)0x2000084c = 3;
*(uint32_t*)0x20000850 = 0xb3a;
*(uint16_t*)0x20000854 = 0xff;
*(uint16_t*)0x20000856 = 1;
*(uint32_t*)0x20000858 = 3;
*(uint32_t*)0x2000085c = 5;
*(uint16_t*)0x20000860 = 1;
*(uint16_t*)0x20000862 = 0xe06;
*(uint32_t*)0x20000864 = 2;
*(uint32_t*)0x20000868 = 1;
*(uint16_t*)0x2000086c = 8;
*(uint16_t*)0x2000086e = 0x20;
*(uint32_t*)0x20000870 = 3;
*(uint32_t*)0x20000874 = 4;
*(uint16_t*)0x20000878 = 1;
*(uint16_t*)0x2000087a = 3;
*(uint32_t*)0x2000087c = 3;
*(uint32_t*)0x20000880 = 0;
*(uint16_t*)0x20000884 = 0x8000;
*(uint16_t*)0x20000886 = 0x7fff;
*(uint32_t*)0x20000888 = 2;
*(uint32_t*)0x2000088c = 0x19;
*(uint16_t*)0x20000890 = 5;
*(uint16_t*)0x20000892 = 8;
*(uint32_t*)0x20000894 = 1;
*(uint32_t*)0x20000898 = 0x10000;
*(uint16_t*)0x2000089c = 5;
*(uint16_t*)0x2000089e = 0x3f;
*(uint32_t*)0x200008a0 = 3;
*(uint32_t*)0x200008a4 = 0;
*(uint16_t*)0x200008a8 = 1;
*(uint16_t*)0x200008aa = 0x3ff;
*(uint32_t*)0x200008ac = 1;
*(uint32_t*)0x200008b0 = 0;
*(uint16_t*)0x200008b4 = 0x22e;
*(uint16_t*)0x200008b6 = 0x81;
*(uint32_t*)0x200008b8 = 2;
*(uint32_t*)0x200008bc = 5;
*(uint16_t*)0x200008c0 = 6;
*(uint16_t*)0x200008c2 = 0xfff;
*(uint32_t*)0x200008c4 = 2;
*(uint32_t*)0x200008c8 = 8;
*(uint16_t*)0x200008cc = 2;
*(uint16_t*)0x200008ce = 7;
*(uint32_t*)0x200008d0 = 1;
*(uint32_t*)0x200008d4 = 0xb4;
*(uint16_t*)0x200008d8 = 0x1ff;
*(uint16_t*)0x200008da = 0x40;
*(uint32_t*)0x200008dc = 2;
*(uint32_t*)0x200008e0 = 0x3ff;
*(uint16_t*)0x200008e4 = -1;
*(uint16_t*)0x200008e6 = 0;
*(uint32_t*)0x200008e8 = 3;
*(uint32_t*)0x200008ec = 0x401;
*(uint16_t*)0x200008f0 = 0x77;
*(uint16_t*)0x200008f2 = 8;
*(uint32_t*)0x200008f4 = 1;
*(uint32_t*)0x200008f8 = -1;
*(uint16_t*)0x200008fc = 0x1ff;
*(uint16_t*)0x200008fe = 3;
*(uint32_t*)0x20000900 = 3;
*(uint32_t*)0x20000904 = 3;
*(uint16_t*)0x20000908 = 0x1f;
*(uint16_t*)0x2000090a = 0;
*(uint32_t*)0x2000090c = 3;
*(uint32_t*)0x20000910 = 6;
*(uint16_t*)0x20000914 = -1;
*(uint16_t*)0x20000916 = 0xff00;
*(uint32_t*)0x20000918 = 1;
*(uint32_t*)0x2000091c = 2;
*(uint16_t*)0x20000920 = 1;
*(uint16_t*)0x20000922 = 0xf671;
*(uint32_t*)0x20000924 = 1;
*(uint32_t*)0x20000928 = 1;
*(uint16_t*)0x2000092c = 2;
*(uint16_t*)0x2000092e = 5;
*(uint32_t*)0x20000930 = 0;
*(uint32_t*)0x20000934 = 5;
*(uint16_t*)0x20000938 = 5;
*(uint16_t*)0x2000093a = 0xfffb;
*(uint32_t*)0x2000093c = 3;
*(uint32_t*)0x20000940 = 0x100;
*(uint16_t*)0x20000944 = 0;
*(uint16_t*)0x20000946 = 0x1f;
*(uint32_t*)0x20000948 = 3;
*(uint32_t*)0x2000094c = 0x1200;
*(uint16_t*)0x20000950 = 0x254;
*(uint16_t*)0x20000952 = 1;
*(uint32_t*)0x20000954 = 3;
*(uint32_t*)0x20000958 = 4;
*(uint8_t*)0x2000095c = -1;
*(uint8_t*)0x2000095d = 0xc1;
*(uint16_t*)0x2000095e = 0x400;
*(uint16_t*)0x20000960 = 4;
*(uint16_t*)0x20000962 = 8;
memcpy((void*)0x20000964, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000984, "\xd8\x16\xe6\xbe\xb4\x05\x62\x6b\xba\xa4\x48\xf7\x10\x44\x24\x4a\x6e\x5c\x6c\x8b\x21\xe9\xf8\xc5\x07\xf4\x09\xf0\x89\x33\x45\xe4", 32);
memcpy((void*)0x200009a4, "\xf2\x91\x28\xa6\x0f\x29\x1b\x29\xf5\x63\xa5\xe9\x1a\xf5\x2e\x5d\xce\x40\xc3\xa3\x36\xc9\xb6\xe2\xc1\xbc\xf8\xa5\x5b\xa3\xe7\x05", 32);
*(uint16_t*)0x200009c4 = 0xfffd;
*(uint16_t*)0x200009c6 = 8;
*(uint32_t*)0x200009c8 = 3;
*(uint32_t*)0x200009cc = 8;
*(uint16_t*)0x200009d0 = 6;
*(uint16_t*)0x200009d2 = 8;
*(uint32_t*)0x200009d4 = 0;
*(uint32_t*)0x200009d8 = 2;
*(uint16_t*)0x200009dc = 4;
*(uint16_t*)0x200009de = 0x81;
*(uint32_t*)0x200009e0 = 1;
*(uint32_t*)0x200009e4 = 0;
*(uint16_t*)0x200009e8 = 4;
*(uint16_t*)0x200009ea = 5;
*(uint32_t*)0x200009ec = 2;
*(uint32_t*)0x200009f0 = 0xffff;
*(uint16_t*)0x200009f4 = 7;
*(uint16_t*)0x200009f6 = 0;
*(uint32_t*)0x200009f8 = 1;
*(uint32_t*)0x200009fc = 9;
*(uint16_t*)0x20000a00 = 1;
*(uint16_t*)0x20000a02 = 0x8000;
*(uint32_t*)0x20000a04 = 3;
*(uint32_t*)0x20000a08 = 0xfff;
*(uint16_t*)0x20000a0c = 6;
*(uint16_t*)0x20000a0e = 1;
*(uint32_t*)0x20000a10 = 1;
*(uint32_t*)0x20000a14 = 0x6a71a034;
*(uint16_t*)0x20000a18 = 8;
*(uint16_t*)0x20000a1a = 0x40;
*(uint32_t*)0x20000a1c = 3;
*(uint32_t*)0x20000a20 = 3;
*(uint16_t*)0x20000a24 = 0x8001;
*(uint16_t*)0x20000a26 = 0x800;
*(uint32_t*)0x20000a28 = 0;
*(uint32_t*)0x20000a2c = 0x35973ce7;
*(uint16_t*)0x20000a30 = 0;
*(uint16_t*)0x20000a32 = 7;
*(uint32_t*)0x20000a34 = 2;
*(uint32_t*)0x20000a38 = 0xb76;
*(uint16_t*)0x20000a3c = 0x80;
*(uint16_t*)0x20000a3e = 3;
*(uint32_t*)0x20000a40 = 0;
*(uint32_t*)0x20000a44 = 3;
*(uint16_t*)0x20000a48 = 7;
*(uint16_t*)0x20000a4a = 0xfff7;
*(uint32_t*)0x20000a4c = 3;
*(uint32_t*)0x20000a50 = 0xffff8d85;
*(uint16_t*)0x20000a54 = 7;
*(uint16_t*)0x20000a56 = 0x8001;
*(uint32_t*)0x20000a58 = 0;
*(uint32_t*)0x20000a5c = 5;
*(uint16_t*)0x20000a60 = 9;
*(uint16_t*)0x20000a62 = 5;
*(uint32_t*)0x20000a64 = 1;
*(uint32_t*)0x20000a68 = 6;
*(uint16_t*)0x20000a6c = 0xfff;
*(uint16_t*)0x20000a6e = 1;
*(uint32_t*)0x20000a70 = 0;
*(uint32_t*)0x20000a74 = 5;
*(uint16_t*)0x20000a78 = 5;
*(uint16_t*)0x20000a7a = 0;
*(uint32_t*)0x20000a7c = 1;
*(uint32_t*)0x20000a80 = 6;
*(uint16_t*)0x20000a84 = 0xf012;
*(uint16_t*)0x20000a86 = 4;
*(uint32_t*)0x20000a88 = 2;
*(uint32_t*)0x20000a8c = 0x8000;
*(uint16_t*)0x20000a90 = 0;
*(uint16_t*)0x20000a92 = 0x55;
*(uint32_t*)0x20000a94 = 1;
*(uint32_t*)0x20000a98 = 5;
*(uint16_t*)0x20000a9c = 3;
*(uint16_t*)0x20000a9e = 0x8d;
*(uint32_t*)0x20000aa0 = 1;
*(uint32_t*)0x20000aa4 = 0xe6d00000;
*(uint16_t*)0x20000aa8 = 4;
*(uint16_t*)0x20000aaa = 0x20;
*(uint32_t*)0x20000aac = 0;
*(uint32_t*)0x20000ab0 = 5;
*(uint16_t*)0x20000ab4 = 1;
*(uint16_t*)0x20000ab6 = 1;
*(uint32_t*)0x20000ab8 = 2;
*(uint32_t*)0x20000abc = 1;
*(uint16_t*)0x20000ac0 = 8;
*(uint16_t*)0x20000ac2 = 8;
*(uint32_t*)0x20000ac4 = 3;
*(uint32_t*)0x20000ac8 = 1;
*(uint16_t*)0x20000acc = 0x2979;
*(uint16_t*)0x20000ace = 0xff;
*(uint32_t*)0x20000ad0 = 2;
*(uint32_t*)0x20000ad4 = 2;
*(uint16_t*)0x20000ad8 = 1;
*(uint16_t*)0x20000ada = 0x200;
*(uint32_t*)0x20000adc = 1;
*(uint32_t*)0x20000ae0 = 0x5bf66e25;
*(uint16_t*)0x20000ae4 = 0x80;
*(uint16_t*)0x20000ae6 = 0x762;
*(uint32_t*)0x20000ae8 = 0;
*(uint32_t*)0x20000aec = 0x7ff;
*(uint16_t*)0x20000af0 = 2;
*(uint16_t*)0x20000af2 = 0x7f;
*(uint32_t*)0x20000af4 = 2;
*(uint32_t*)0x20000af8 = 0;
*(uint16_t*)0x20000afc = 0x7f;
*(uint16_t*)0x20000afe = 9;
*(uint32_t*)0x20000b00 = 0;
*(uint32_t*)0x20000b04 = 2;
*(uint16_t*)0x20000b08 = 2;
*(uint16_t*)0x20000b0a = 9;
*(uint32_t*)0x20000b0c = 0;
*(uint32_t*)0x20000b10 = 5;
*(uint16_t*)0x20000b14 = 9;
*(uint16_t*)0x20000b16 = 2;
*(uint32_t*)0x20000b18 = 1;
*(uint32_t*)0x20000b1c = 8;
*(uint16_t*)0x20000b20 = 5;
*(uint16_t*)0x20000b22 = 9;
*(uint32_t*)0x20000b24 = 3;
*(uint32_t*)0x20000b28 = 0x539f;
*(uint16_t*)0x20000b2c = 2;
*(uint16_t*)0x20000b2e = 0x400;
*(uint32_t*)0x20000b30 = 2;
*(uint32_t*)0x20000b34 = 0x8000;
*(uint16_t*)0x20000b38 = 4;
*(uint16_t*)0x20000b3a = 0x5e;
*(uint32_t*)0x20000b3c = 0;
*(uint32_t*)0x20000b40 = 4;
*(uint16_t*)0x20000b44 = 0x9d9;
*(uint16_t*)0x20000b46 = 6;
*(uint32_t*)0x20000b48 = 2;
*(uint32_t*)0x20000b4c = 3;
*(uint16_t*)0x20000b50 = 1;
*(uint16_t*)0x20000b52 = 0xde2c;
*(uint32_t*)0x20000b54 = 0;
*(uint32_t*)0x20000b58 = 6;
*(uint16_t*)0x20000b5c = 0;
*(uint16_t*)0x20000b5e = 4;
*(uint32_t*)0x20000b60 = 1;
*(uint32_t*)0x20000b64 = 0x10001;
*(uint16_t*)0x20000b68 = 9;
*(uint16_t*)0x20000b6a = 3;
*(uint32_t*)0x20000b6c = 2;
*(uint32_t*)0x20000b70 = 0x1000;
*(uint16_t*)0x20000b74 = 6;
*(uint16_t*)0x20000b76 = 3;
*(uint32_t*)0x20000b78 = 0;
*(uint32_t*)0x20000b7c = 1;
*(uint16_t*)0x20000b80 = 0x3ff;
*(uint16_t*)0x20000b82 = 0x20;
*(uint32_t*)0x20000b84 = 1;
*(uint32_t*)0x20000b88 = 2;
*(uint16_t*)0x20000b8c = 1;
*(uint16_t*)0x20000b8e = 7;
*(uint32_t*)0x20000b90 = 3;
*(uint32_t*)0x20000b94 = 9;
*(uint16_t*)0x20000b98 = 3;
*(uint16_t*)0x20000b9a = 0x698b;
*(uint32_t*)0x20000b9c = 2;
*(uint32_t*)0x20000ba0 = 2;
*(uint16_t*)0x20000ba4 = 0x254;
*(uint16_t*)0x20000ba6 = 1;
*(uint32_t*)0x20000ba8 = 2;
*(uint32_t*)0x20000bac = 0x10001;
*(uint8_t*)0x20000bb0 = 4;
*(uint8_t*)0x20000bb1 = 4;
*(uint16_t*)0x20000bb2 = 9;
*(uint16_t*)0x20000bb4 = 1;
*(uint16_t*)0x20000bb6 = 0xd;
memcpy((void*)0x20000bb8, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000bd8, "\x95\x35\xb8\x05\x34\xa7\xcd\x7d\xe7\x66\x00\x44\x25\xea\x1a\x4f\xb6\xdc\x9c\xdb\x5f\x4a\xc5\xfd\x0a\xd0\xf6\x6c\x8a\xab\xf3\xe7", 32);
memcpy((void*)0x20000bf8, "\xe5\xdf\x91\xa9\xc1\x72\xb9\x08\x8f\xa2\xd6\x60\xc5\x69\xd7\x6f\x9b\x53\x51\x6a\x27\xa2\x96\x75\xb6\xa7\xd2\x03\xb1\xee\x27\xcc", 32);
*(uint16_t*)0x20000c18 = 3;
*(uint16_t*)0x20000c1a = 0x7fff;
*(uint32_t*)0x20000c1c = 0;
*(uint32_t*)0x20000c20 = 9;
*(uint16_t*)0x20000c24 = 7;
*(uint16_t*)0x20000c26 = 7;
*(uint32_t*)0x20000c28 = 2;
*(uint32_t*)0x20000c2c = 0x1b7;
*(uint16_t*)0x20000c30 = 0x81;
*(uint16_t*)0x20000c32 = 8;
*(uint32_t*)0x20000c34 = 3;
*(uint32_t*)0x20000c38 = 0x401;
*(uint16_t*)0x20000c3c = 7;
*(uint16_t*)0x20000c3e = 0xfff;
*(uint32_t*)0x20000c40 = 2;
*(uint32_t*)0x20000c44 = 0xaf6a;
*(uint16_t*)0x20000c48 = 0xfffe;
*(uint16_t*)0x20000c4a = 4;
*(uint32_t*)0x20000c4c = 3;
*(uint32_t*)0x20000c50 = 4;
*(uint16_t*)0x20000c54 = 7;
*(uint16_t*)0x20000c56 = 0x400;
*(uint32_t*)0x20000c58 = 3;
*(uint32_t*)0x20000c5c = 9;
*(uint16_t*)0x20000c60 = 0x668;
*(uint16_t*)0x20000c62 = 6;
*(uint32_t*)0x20000c64 = 0;
*(uint32_t*)0x20000c68 = 0x44d;
*(uint16_t*)0x20000c6c = -1;
*(uint16_t*)0x20000c6e = 1;
*(uint32_t*)0x20000c70 = 2;
*(uint32_t*)0x20000c74 = 0x386;
*(uint16_t*)0x20000c78 = 9;
*(uint16_t*)0x20000c7a = 0;
*(uint32_t*)0x20000c7c = 3;
*(uint32_t*)0x20000c80 = 0x10001;
*(uint16_t*)0x20000c84 = 0x800;
*(uint16_t*)0x20000c86 = 9;
*(uint32_t*)0x20000c88 = 3;
*(uint32_t*)0x20000c8c = 3;
*(uint16_t*)0x20000c90 = 2;
*(uint16_t*)0x20000c92 = 0xfb56;
*(uint32_t*)0x20000c94 = 1;
*(uint32_t*)0x20000c98 = 9;
*(uint16_t*)0x20000c9c = 2;
*(uint16_t*)0x20000c9e = 0xff;
*(uint32_t*)0x20000ca0 = 0;
*(uint32_t*)0x20000ca4 = 2;
*(uint16_t*)0x20000ca8 = 0x800;
*(uint16_t*)0x20000caa = 7;
*(uint32_t*)0x20000cac = 2;
*(uint32_t*)0x20000cb0 = 0x81;
*(uint16_t*)0x20000cb4 = -1;
*(uint16_t*)0x20000cb6 = 2;
*(uint32_t*)0x20000cb8 = 1;
*(uint32_t*)0x20000cbc = 3;
*(uint16_t*)0x20000cc0 = 0xff;
*(uint16_t*)0x20000cc2 = 4;
*(uint32_t*)0x20000cc4 = 0;
*(uint32_t*)0x20000cc8 = 0x20;
*(uint16_t*)0x20000ccc = 4;
*(uint16_t*)0x20000cce = 0xfff;
*(uint32_t*)0x20000cd0 = 1;
*(uint32_t*)0x20000cd4 = 8;
*(uint16_t*)0x20000cd8 = 0xbeb;
*(uint16_t*)0x20000cda = 6;
*(uint32_t*)0x20000cdc = 1;
*(uint32_t*)0x20000ce0 = 0xf8000000;
*(uint16_t*)0x20000ce4 = 0x1f;
*(uint16_t*)0x20000ce6 = 1;
*(uint32_t*)0x20000ce8 = 0;
*(uint32_t*)0x20000cec = 0x7fffffff;
*(uint16_t*)0x20000cf0 = 7;
*(uint16_t*)0x20000cf2 = 3;
*(uint32_t*)0x20000cf4 = 0;
*(uint32_t*)0x20000cf8 = 9;
*(uint16_t*)0x20000cfc = 0;
*(uint16_t*)0x20000cfe = 6;
*(uint32_t*)0x20000d00 = 3;
*(uint32_t*)0x20000d04 = 0xfffeffff;
*(uint16_t*)0x20000d08 = 7;
*(uint16_t*)0x20000d0a = 0x401;
*(uint32_t*)0x20000d0c = 0;
*(uint32_t*)0x20000d10 = 0x4ac3;
*(uint16_t*)0x20000d14 = 8;
*(uint16_t*)0x20000d16 = 3;
*(uint32_t*)0x20000d18 = 0;
*(uint32_t*)0x20000d1c = 0xba;
*(uint16_t*)0x20000d20 = 4;
*(uint16_t*)0x20000d22 = 0xa9e;
*(uint32_t*)0x20000d24 = 3;
*(uint32_t*)0x20000d28 = 0xffff0000;
*(uint16_t*)0x20000d2c = 3;
*(uint16_t*)0x20000d2e = 0x9f;
*(uint32_t*)0x20000d30 = 2;
*(uint32_t*)0x20000d34 = 5;
*(uint16_t*)0x20000d38 = 0x8000;
*(uint16_t*)0x20000d3a = 0x19;
*(uint32_t*)0x20000d3c = 1;
*(uint32_t*)0x20000d40 = 4;
*(uint16_t*)0x20000d44 = 0xf800;
*(uint16_t*)0x20000d46 = 0x800;
*(uint32_t*)0x20000d48 = 1;
*(uint32_t*)0x20000d4c = 3;
*(uint16_t*)0x20000d50 = 2;
*(uint16_t*)0x20000d52 = 3;
*(uint32_t*)0x20000d54 = 3;
*(uint32_t*)0x20000d58 = 8;
*(uint16_t*)0x20000d5c = 3;
*(uint16_t*)0x20000d5e = 0x100;
*(uint32_t*)0x20000d60 = 2;
*(uint32_t*)0x20000d64 = 5;
*(uint16_t*)0x20000d68 = 3;
*(uint16_t*)0x20000d6a = 5;
*(uint32_t*)0x20000d6c = 1;
*(uint32_t*)0x20000d70 = 0xffff8000;
*(uint16_t*)0x20000d74 = 8;
*(uint16_t*)0x20000d76 = 2;
*(uint32_t*)0x20000d78 = 2;
*(uint32_t*)0x20000d7c = 0xffff;
*(uint16_t*)0x20000d80 = 0xfff;
*(uint16_t*)0x20000d82 = 0x160;
*(uint32_t*)0x20000d84 = 3;
*(uint32_t*)0x20000d88 = 0;
*(uint16_t*)0x20000d8c = 0x100;
*(uint16_t*)0x20000d8e = 0x400;
*(uint32_t*)0x20000d90 = 2;
*(uint32_t*)0x20000d94 = 6;
*(uint16_t*)0x20000d98 = 5;
*(uint16_t*)0x20000d9a = 9;
*(uint32_t*)0x20000d9c = 3;
*(uint32_t*)0x20000da0 = 0xff;
*(uint16_t*)0x20000da4 = 0x40;
*(uint16_t*)0x20000da6 = 0xa488;
*(uint32_t*)0x20000da8 = 0;
*(uint32_t*)0x20000dac = 4;
*(uint16_t*)0x20000db0 = 2;
*(uint16_t*)0x20000db2 = 0x20;
*(uint32_t*)0x20000db4 = 2;
*(uint32_t*)0x20000db8 = 8;
*(uint16_t*)0x20000dbc = 0x20;
*(uint16_t*)0x20000dbe = 1;
*(uint32_t*)0x20000dc0 = 3;
*(uint32_t*)0x20000dc4 = 0x200;
*(uint16_t*)0x20000dc8 = 0x1f;
*(uint16_t*)0x20000dca = 0x3ff;
*(uint32_t*)0x20000dcc = 2;
*(uint32_t*)0x20000dd0 = 0x1000;
*(uint16_t*)0x20000dd4 = 0x20;
*(uint16_t*)0x20000dd6 = 5;
*(uint32_t*)0x20000dd8 = 0;
*(uint32_t*)0x20000ddc = 9;
*(uint16_t*)0x20000de0 = 0xf3e5;
*(uint16_t*)0x20000de2 = 0;
*(uint32_t*)0x20000de4 = 2;
*(uint32_t*)0x20000de8 = 8;
*(uint16_t*)0x20000dec = 0;
*(uint16_t*)0x20000dee = 6;
*(uint32_t*)0x20000df0 = 3;
*(uint32_t*)0x20000df4 = 4;
*(uint16_t*)0x20000df8 = 0x254;
*(uint16_t*)0x20000dfa = 1;
*(uint32_t*)0x20000dfc = 2;
*(uint32_t*)0x20000e00 = 5;
*(uint8_t*)0x20000e04 = 7;
*(uint8_t*)0x20000e05 = 5;
*(uint16_t*)0x20000e06 = 0xfffa;
*(uint16_t*)0x20000e08 = -1;
*(uint16_t*)0x20000e0a = 0xe;
memcpy((void*)0x20000e0c, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000e2c, "\xea\x59\xe3\xc1\x7f\xe9\x77\x4e\x2c\xaa\xa2\x54\x2c\x9c\x7e\x8c\x8b\xfc\x69\x55\x9b\x31\xf3\xe8\x05\x44\xf4\xb1\x97\x36\x11\x8f", 32);
memcpy((void*)0x20000e4c, "\x03\xdd\xe1\xf5\xa6\xf2\x55\xa0\xbd\x88\x62\x6c\x94\xe1\x91\xd6\xae\xa8\x30\x20\xaf\xc2\x4d\x32\x81\x29\x89\x91\x67\x57\x51\xdf", 32);
*(uint16_t*)0x20000e6c = 5;
*(uint16_t*)0x20000e6e = 9;
*(uint32_t*)0x20000e70 = 0;
*(uint32_t*)0x20000e74 = 0x600000;
*(uint16_t*)0x20000e78 = 7;
*(uint16_t*)0x20000e7a = 0x619b;
*(uint32_t*)0x20000e7c = 1;
*(uint32_t*)0x20000e80 = 0xfffff800;
*(uint16_t*)0x20000e84 = 7;
*(uint16_t*)0x20000e86 = 0xf4;
*(uint32_t*)0x20000e88 = 1;
*(uint32_t*)0x20000e8c = 0x8000;
*(uint16_t*)0x20000e90 = 7;
*(uint16_t*)0x20000e92 = 0x80;
*(uint32_t*)0x20000e94 = 1;
*(uint32_t*)0x20000e98 = 2;
*(uint16_t*)0x20000e9c = 0xf3;
*(uint16_t*)0x20000e9e = 5;
*(uint32_t*)0x20000ea0 = 0;
*(uint32_t*)0x20000ea4 = 0xff;
*(uint16_t*)0x20000ea8 = 0x200;
*(uint16_t*)0x20000eaa = 6;
*(uint32_t*)0x20000eac = 0;
*(uint32_t*)0x20000eb0 = 6;
*(uint16_t*)0x20000eb4 = 0xfff8;
*(uint16_t*)0x20000eb6 = 3;
*(uint32_t*)0x20000eb8 = 1;
*(uint32_t*)0x20000ebc = 0x7d;
*(uint16_t*)0x20000ec0 = 3;
*(uint16_t*)0x20000ec2 = 0x9c;
*(uint32_t*)0x20000ec4 = 2;
*(uint32_t*)0x20000ec8 = 0x7fff;
*(uint16_t*)0x20000ecc = 0xc251;
*(uint16_t*)0x20000ece = 3;
*(uint32_t*)0x20000ed0 = 0;
*(uint32_t*)0x20000ed4 = 0xf8;
*(uint16_t*)0x20000ed8 = 0x400;
*(uint16_t*)0x20000eda = 0x7ff;
*(uint32_t*)0x20000edc = 3;
*(uint32_t*)0x20000ee0 = 8;
*(uint16_t*)0x20000ee4 = 2;
*(uint16_t*)0x20000ee6 = 1;
*(uint32_t*)0x20000ee8 = 0;
*(uint32_t*)0x20000eec = 0x101;
*(uint16_t*)0x20000ef0 = 7;
*(uint16_t*)0x20000ef2 = 0xc4;
*(uint32_t*)0x20000ef4 = 0;
*(uint32_t*)0x20000ef8 = 8;
*(uint16_t*)0x20000efc = 5;
*(uint16_t*)0x20000efe = 0;
*(uint32_t*)0x20000f00 = 2;
*(uint32_t*)0x20000f04 = 0;
*(uint16_t*)0x20000f08 = 0;
*(uint16_t*)0x20000f0a = 3;
*(uint32_t*)0x20000f0c = 3;
*(uint32_t*)0x20000f10 = 0x100;
*(uint16_t*)0x20000f14 = 6;
*(uint16_t*)0x20000f16 = 0x1ff;
*(uint32_t*)0x20000f18 = 1;
*(uint32_t*)0x20000f1c = 0xfffffff8;
*(uint16_t*)0x20000f20 = 1;
*(uint16_t*)0x20000f22 = 0x3d6d;
*(uint32_t*)0x20000f24 = 2;
*(uint32_t*)0x20000f28 = 8;
*(uint16_t*)0x20000f2c = 2;
*(uint16_t*)0x20000f2e = 0xfff8;
*(uint32_t*)0x20000f30 = 2;
*(uint32_t*)0x20000f34 = 3;
*(uint16_t*)0x20000f38 = 7;
*(uint16_t*)0x20000f3a = 0x3ff;
*(uint32_t*)0x20000f3c = 3;
*(uint32_t*)0x20000f40 = 7;
*(uint16_t*)0x20000f44 = 0x88d;
*(uint16_t*)0x20000f46 = 8;
*(uint32_t*)0x20000f48 = 0;
*(uint32_t*)0x20000f4c = 3;
*(uint16_t*)0x20000f50 = 3;
*(uint16_t*)0x20000f52 = 0xff91;
*(uint32_t*)0x20000f54 = 0;
*(uint32_t*)0x20000f58 = 1;
*(uint16_t*)0x20000f5c = 0xc000;
*(uint16_t*)0x20000f5e = 7;
*(uint32_t*)0x20000f60 = 3;
*(uint32_t*)0x20000f64 = 0x96e8;
*(uint16_t*)0x20000f68 = 0x5a;
*(uint16_t*)0x20000f6a = 0x4a;
*(uint32_t*)0x20000f6c = 3;
*(uint32_t*)0x20000f70 = 1;
*(uint16_t*)0x20000f74 = 0;
*(uint16_t*)0x20000f76 = 3;
*(uint32_t*)0x20000f78 = 0;
*(uint32_t*)0x20000f7c = 0x401;
*(uint16_t*)0x20000f80 = 0;
*(uint16_t*)0x20000f82 = 0x6ffb;
*(uint32_t*)0x20000f84 = 1;
*(uint32_t*)0x20000f88 = 0xfffffff7;
*(uint16_t*)0x20000f8c = 0;
*(uint16_t*)0x20000f8e = 2;
*(uint32_t*)0x20000f90 = 1;
*(uint32_t*)0x20000f94 = 0x5e175cea;
*(uint16_t*)0x20000f98 = 6;
*(uint16_t*)0x20000f9a = 0;
*(uint32_t*)0x20000f9c = 2;
*(uint32_t*)0x20000fa0 = 0x100;
*(uint16_t*)0x20000fa4 = 7;
*(uint16_t*)0x20000fa6 = 0x607;
*(uint32_t*)0x20000fa8 = 1;
*(uint32_t*)0x20000fac = 0x7d1a;
*(uint16_t*)0x20000fb0 = 0x4086;
*(uint16_t*)0x20000fb2 = 7;
*(uint32_t*)0x20000fb4 = 1;
*(uint32_t*)0x20000fb8 = 0x7fff;
*(uint16_t*)0x20000fbc = 7;
*(uint16_t*)0x20000fbe = 0;
*(uint32_t*)0x20000fc0 = 2;
*(uint32_t*)0x20000fc4 = 8;
*(uint16_t*)0x20000fc8 = 7;
*(uint16_t*)0x20000fca = 1;
*(uint32_t*)0x20000fcc = 0xf4d219bf;
*(uint32_t*)0x20000fd0 = 0;
*(uint16_t*)0x20000fd4 = 9;
*(uint16_t*)0x20000fd6 = 0;
*(uint32_t*)0x20000fd8 = 0;
*(uint32_t*)0x20000fdc = 0x800;
*(uint16_t*)0x20000fe0 = 0x703;
*(uint16_t*)0x20000fe2 = 9;
*(uint32_t*)0x20000fe4 = 1;
*(uint32_t*)0x20000fe8 = 0x79;
*(uint16_t*)0x20000fec = 0xfff;
*(uint16_t*)0x20000fee = 0;
*(uint32_t*)0x20000ff0 = 2;
*(uint32_t*)0x20000ff4 = 3;
*(uint16_t*)0x20000ff8 = 0xff80;
*(uint16_t*)0x20000ffa = 0x7fff;
*(uint32_t*)0x20000ffc = 3;
*(uint32_t*)0x20001000 = 0x17;
*(uint16_t*)0x20001004 = 0x100;
*(uint16_t*)0x20001006 = 1;
*(uint32_t*)0x20001008 = 3;
*(uint32_t*)0x2000100c = 0x10000;
*(uint16_t*)0x20001010 = 0xfff;
*(uint16_t*)0x20001012 = 0xb50;
*(uint32_t*)0x20001014 = 1;
*(uint32_t*)0x20001018 = 0x40;
*(uint16_t*)0x2000101c = 4;
*(uint16_t*)0x2000101e = 0x100;
*(uint32_t*)0x20001020 = 0;
*(uint32_t*)0x20001024 = 0xa917;
*(uint16_t*)0x20001028 = 5;
*(uint16_t*)0x2000102a = 0xff;
*(uint32_t*)0x2000102c = 2;
*(uint32_t*)0x20001030 = 0x6679;
*(uint16_t*)0x20001034 = 5;
*(uint16_t*)0x20001036 = 3;
*(uint32_t*)0x20001038 = 2;
*(uint32_t*)0x2000103c = 0;
*(uint16_t*)0x20001040 = 5;
*(uint16_t*)0x20001042 = 0x618;
*(uint32_t*)0x20001044 = 0;
*(uint32_t*)0x20001048 = 0x835d;
*(uint16_t*)0x2000104c = 0x254;
*(uint16_t*)0x2000104e = 1;
*(uint32_t*)0x20001050 = 0;
*(uint32_t*)0x20001054 = 0;
*(uint8_t*)0x20001058 = 0;
*(uint8_t*)0x20001059 = 0;
*(uint16_t*)0x2000105a = 0;
*(uint16_t*)0x2000105c = 0;
*(uint16_t*)0x2000105e = 0;
memcpy((void*)0x20001060, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20001080, "\x93\x59\x98\x6b\xa1\xf6\x89\x76\xde\x65\x58\xe6\x96\xa0\x6d\xb0\xbc\x24\x86\xda\xa6\xcc\x7f\x27\x22\xc5\xd6\xc3\xbe\xc9\x79\xec", 32);
memcpy((void*)0x200010a0, "\x64\x57\x86\xf7\xa7\x40\x55\x58\xd6\x23\x1a\xe9\xd9\x5a\xe8\xfd\x28\xdd\x44\xa8\xb8\xc9\x2e\x8c\x2f\x44\xca\xb3\x8a\x77\x87\x13", 32);
*(uint16_t*)0x200010c0 = 0x1ff;
*(uint16_t*)0x200010c2 = 0x3d9d;
*(uint32_t*)0x200010c4 = 3;
*(uint32_t*)0x200010c8 = 6;
*(uint16_t*)0x200010cc = 0xf7;
*(uint16_t*)0x200010ce = 3;
*(uint32_t*)0x200010d0 = 3;
*(uint32_t*)0x200010d4 = 0x8001;
*(uint16_t*)0x200010d8 = 3;
*(uint16_t*)0x200010da = 0x169e;
*(uint32_t*)0x200010dc = 2;
*(uint32_t*)0x200010e0 = 2;
*(uint16_t*)0x200010e4 = 3;
*(uint16_t*)0x200010e6 = 8;
*(uint32_t*)0x200010e8 = 2;
*(uint32_t*)0x200010ec = 2;
*(uint16_t*)0x200010f0 = 5;
*(uint16_t*)0x200010f2 = -1;
*(uint32_t*)0x200010f4 = 2;
*(uint32_t*)0x200010f8 = 0x6b1;
*(uint16_t*)0x200010fc = 7;
*(uint16_t*)0x200010fe = 1;
*(uint32_t*)0x20001100 = 3;
*(uint32_t*)0x20001104 = 0;
*(uint16_t*)0x20001108 = 7;
*(uint16_t*)0x2000110a = 0x80;
*(uint32_t*)0x2000110c = 3;
*(uint32_t*)0x20001110 = 0x8001;
*(uint16_t*)0x20001114 = 8;
*(uint16_t*)0x20001116 = 2;
*(uint32_t*)0x20001118 = 2;
*(uint32_t*)0x2000111c = 0x43;
*(uint16_t*)0x20001120 = 0x1f;
*(uint16_t*)0x20001122 = 0x8001;
*(uint32_t*)0x20001124 = 3;
*(uint32_t*)0x20001128 = 0xf34a;
*(uint16_t*)0x2000112c = 0x40;
*(uint16_t*)0x2000112e = 0xaf;
*(uint32_t*)0x20001130 = 3;
*(uint32_t*)0x20001134 = 0x200;
*(uint16_t*)0x20001138 = 8;
*(uint16_t*)0x2000113a = 7;
*(uint32_t*)0x2000113c = 3;
*(uint32_t*)0x20001140 = 1;
*(uint16_t*)0x20001144 = 3;
*(uint16_t*)0x20001146 = 0x8000;
*(uint32_t*)0x20001148 = 1;
*(uint32_t*)0x2000114c = 0;
*(uint16_t*)0x20001150 = 0x1ff;
*(uint16_t*)0x20001152 = 6;
*(uint32_t*)0x20001154 = 2;
*(uint32_t*)0x20001158 = 0xfd33;
*(uint16_t*)0x2000115c = 0x198;
*(uint16_t*)0x2000115e = 0x164;
*(uint32_t*)0x20001160 = 0;
*(uint32_t*)0x20001164 = 1;
*(uint16_t*)0x20001168 = 0;
*(uint16_t*)0x2000116a = 0x53;
*(uint32_t*)0x2000116c = 3;
*(uint32_t*)0x20001170 = 6;
*(uint16_t*)0x20001174 = 0xa85;
*(uint16_t*)0x20001176 = 0xff81;
*(uint32_t*)0x20001178 = 3;
*(uint32_t*)0x2000117c = 0xfffffffd;
*(uint16_t*)0x20001180 = -1;
*(uint16_t*)0x20001182 = 6;
*(uint32_t*)0x20001184 = 1;
*(uint32_t*)0x20001188 = 0x46;
*(uint16_t*)0x2000118c = 5;
*(uint16_t*)0x2000118e = 0x100;
*(uint32_t*)0x20001190 = 2;
*(uint32_t*)0x20001194 = 5;
*(uint16_t*)0x20001198 = 6;
*(uint16_t*)0x2000119a = 1;
*(uint32_t*)0x2000119c = 2;
*(uint32_t*)0x200011a0 = 0x10001;
*(uint16_t*)0x200011a4 = 0;
*(uint16_t*)0x200011a6 = 1;
*(uint32_t*)0x200011a8 = 1;
*(uint32_t*)0x200011ac = 0x10000;
*(uint16_t*)0x200011b0 = 0xa6;
*(uint16_t*)0x200011b2 = 2;
*(uint32_t*)0x200011b4 = 2;
*(uint32_t*)0x200011b8 = 0x100;
*(uint16_t*)0x200011bc = 0;
*(uint16_t*)0x200011be = 3;
*(uint32_t*)0x200011c0 = 3;
*(uint32_t*)0x200011c4 = 0x100;
*(uint16_t*)0x200011c8 = 0x7ff;
*(uint16_t*)0x200011ca = 2;
*(uint32_t*)0x200011cc = 1;
*(uint32_t*)0x200011d0 = 0x8001;
*(uint16_t*)0x200011d4 = 0xff;
*(uint16_t*)0x200011d6 = 0x8001;
*(uint32_t*)0x200011d8 = 3;
*(uint32_t*)0x200011dc = 0x966d;
*(uint16_t*)0x200011e0 = 3;
*(uint16_t*)0x200011e2 = 0xf3dd;
*(uint32_t*)0x200011e4 = 3;
*(uint32_t*)0x200011e8 = 0xf0;
*(uint16_t*)0x200011ec = 8;
*(uint16_t*)0x200011ee = 0x9b;
*(uint32_t*)0x200011f0 = 2;
*(uint32_t*)0x200011f4 = 0x400;
*(uint16_t*)0x200011f8 = 0x101;
*(uint16_t*)0x200011fa = 7;
*(uint32_t*)0x200011fc = 2;
*(uint32_t*)0x20001200 = 0;
*(uint16_t*)0x20001204 = 0x101;
*(uint16_t*)0x20001206 = 2;
*(uint32_t*)0x20001208 = 0;
*(uint32_t*)0x2000120c = 0x1f;
*(uint16_t*)0x20001210 = 0;
*(uint16_t*)0x20001212 = 0;
*(uint32_t*)0x20001214 = 0;
*(uint32_t*)0x20001218 = 0x81;
*(uint16_t*)0x2000121c = 0;
*(uint16_t*)0x2000121e = 0;
*(uint32_t*)0x20001220 = 0;
*(uint32_t*)0x20001224 = 0;
*(uint16_t*)0x20001228 = 0;
*(uint16_t*)0x2000122a = 0;
*(uint32_t*)0x2000122c = 0;
*(uint32_t*)0x20001230 = 0;
*(uint16_t*)0x20001234 = 0;
*(uint16_t*)0x20001236 = 0;
*(uint32_t*)0x20001238 = 0;
*(uint32_t*)0x2000123c = 0;
*(uint16_t*)0x20001240 = 0;
*(uint16_t*)0x20001242 = 0;
*(uint32_t*)0x20001244 = 0;
*(uint32_t*)0x20001248 = 0;
*(uint16_t*)0x2000124c = 0;
*(uint16_t*)0x2000124e = 0;
*(uint32_t*)0x20001250 = 0;
*(uint32_t*)0x20001254 = 0x20;
*(uint16_t*)0x20001258 = 0;
*(uint16_t*)0x2000125a = 0;
*(uint32_t*)0x2000125c = 0;
*(uint32_t*)0x20001260 = 0;
*(uint16_t*)0x20001264 = 0;
*(uint16_t*)0x20001266 = 0;
*(uint32_t*)0x20001268 = 0;
*(uint32_t*)0x2000126c = 0;
*(uint16_t*)0x20001270 = 0;
*(uint16_t*)0x20001272 = 0;
*(uint32_t*)0x20001274 = 0;
*(uint32_t*)0x20001278 = 0;
*(uint16_t*)0x2000127c = 0;
*(uint16_t*)0x2000127e = 0;
*(uint32_t*)0x20001280 = 0;
*(uint32_t*)0x20001284 = 0;
*(uint16_t*)0x20001288 = 0;
*(uint16_t*)0x2000128a = 0;
*(uint32_t*)0x2000128c = 0;
*(uint32_t*)0x20001290 = 0;
*(uint16_t*)0x20001294 = 0;
*(uint16_t*)0x20001296 = 0;
*(uint32_t*)0x20001298 = 0;
*(uint32_t*)0x2000129c = 0;
*(uint64_t*)0x200012c8 = 0x1060;
*(uint64_t*)0x20001318 = 1;
*(uint64_t*)0x20001320 = 0;
*(uint64_t*)0x20001328 = 0;
*(uint32_t*)0x20001330 = 0;
	syscall(__NR_sendmsg, r[0], 0x20001300ul, 0x8080ul);
	return 0;
}
