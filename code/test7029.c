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
*(uint64_t*)0x20001440 = 0;
*(uint32_t*)0x20001448 = 0;
*(uint64_t*)0x20001450 = 0x20001400;
*(uint64_t*)0x20001400 = 0x20000140;
*(uint32_t*)0x20000140 = 0x1060;
*(uint8_t*)0x20000144 = 0;
*(uint8_t*)0x20000145 = 5;
*(uint16_t*)0x20000146 = 0x101;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 0;
*(uint8_t*)0x20000150 = 0;
*(uint8_t*)0x20000151 = 0;
*(uint16_t*)0x20000152 = htobe16(0);
*(uint16_t*)0x20000154 = 0x254;
*(uint16_t*)0x20000156 = 1;
*(uint32_t*)0x20000158 = 0;
*(uint32_t*)0x2000015c = 0;
*(uint8_t*)0x20000160 = 0;
*(uint8_t*)0x20000161 = 0;
*(uint16_t*)0x20000162 = 0;
*(uint16_t*)0x20000164 = 0;
*(uint16_t*)0x20000166 = 0;
memcpy((void*)0x20000168, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000188, "\xbc\xb8\x7a\xe3\xe4\x5e\xe9\x06\x20\xf3\x8c\x92\xc7\x28\x9c\x25\xa0\xf5\xbc\x3e\x1b\xfd\x72\xb1\x7b\xe6\x3e\x7f\x55\xc2\xe9\x6f", 32);
memcpy((void*)0x200001a8, "\x89\xa7\x3f\xbf\xb4\x6b\x02\xe4\x13\x70\xe9\x46\xc4\xd0\x35\x9e\x28\xf5\x8a\xc7\x74\xbb\x9c\x42\x33\xe9\xc3\xce\x3d\xb8\x5b\xf2", 32);
*(uint16_t*)0x200001c8 = 0;
*(uint16_t*)0x200001ca = 0;
*(uint32_t*)0x200001cc = 0;
*(uint32_t*)0x200001d0 = 0;
*(uint16_t*)0x200001d4 = 0;
*(uint16_t*)0x200001d6 = 0;
*(uint32_t*)0x200001d8 = 0;
*(uint32_t*)0x200001dc = 0;
*(uint16_t*)0x200001e0 = 0;
*(uint16_t*)0x200001e2 = 0;
*(uint32_t*)0x200001e4 = 0;
*(uint32_t*)0x200001e8 = 0;
*(uint16_t*)0x200001ec = 0;
*(uint16_t*)0x200001ee = 0;
*(uint32_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f4 = 0;
*(uint16_t*)0x200001f8 = 0xa9e;
*(uint16_t*)0x200001fa = 0;
*(uint32_t*)0x200001fc = 0;
*(uint32_t*)0x20000200 = 0;
*(uint16_t*)0x20000204 = 0;
*(uint16_t*)0x20000206 = 1;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint16_t*)0x20000210 = 0;
*(uint16_t*)0x20000212 = 0;
*(uint32_t*)0x20000214 = 0;
*(uint32_t*)0x20000218 = 0;
*(uint16_t*)0x2000021c = 0;
*(uint16_t*)0x2000021e = 0;
*(uint32_t*)0x20000220 = 0;
*(uint32_t*)0x20000224 = 0;
*(uint16_t*)0x20000228 = 0;
*(uint16_t*)0x2000022a = 0;
*(uint32_t*)0x2000022c = 0;
*(uint32_t*)0x20000230 = 0xffff;
*(uint16_t*)0x20000234 = 0;
*(uint16_t*)0x20000236 = 0;
*(uint32_t*)0x20000238 = 0;
*(uint32_t*)0x2000023c = 0;
*(uint16_t*)0x20000240 = 0xff00;
*(uint16_t*)0x20000242 = 0;
*(uint32_t*)0x20000244 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint16_t*)0x2000024c = 0;
*(uint16_t*)0x2000024e = 0;
*(uint32_t*)0x20000250 = 0;
*(uint32_t*)0x20000254 = 0;
*(uint16_t*)0x20000258 = 0;
*(uint16_t*)0x2000025a = 0;
*(uint32_t*)0x2000025c = 0;
*(uint32_t*)0x20000260 = 0;
*(uint16_t*)0x20000264 = 0;
*(uint16_t*)0x20000266 = 0;
*(uint32_t*)0x20000268 = 0;
*(uint32_t*)0x2000026c = 0;
*(uint16_t*)0x20000270 = 0;
*(uint16_t*)0x20000272 = 0;
*(uint32_t*)0x20000274 = 0;
*(uint32_t*)0x20000278 = 0;
*(uint16_t*)0x2000027c = 0;
*(uint16_t*)0x2000027e = 0;
*(uint32_t*)0x20000280 = 0;
*(uint32_t*)0x20000284 = 0;
*(uint16_t*)0x20000288 = 0;
*(uint16_t*)0x2000028a = 0;
*(uint32_t*)0x2000028c = 0;
*(uint32_t*)0x20000290 = 0;
*(uint16_t*)0x20000294 = 0;
*(uint16_t*)0x20000296 = 0;
*(uint32_t*)0x20000298 = 0;
*(uint32_t*)0x2000029c = 0;
*(uint16_t*)0x200002a0 = 0;
*(uint16_t*)0x200002a2 = 0;
*(uint32_t*)0x200002a4 = 3;
*(uint32_t*)0x200002a8 = 0;
*(uint16_t*)0x200002ac = 0;
*(uint16_t*)0x200002ae = 0;
*(uint32_t*)0x200002b0 = 0;
*(uint32_t*)0x200002b4 = 0;
*(uint16_t*)0x200002b8 = 0;
*(uint16_t*)0x200002ba = 0;
*(uint32_t*)0x200002bc = 0;
*(uint32_t*)0x200002c0 = 0x18;
*(uint16_t*)0x200002c4 = 0;
*(uint16_t*)0x200002c6 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
*(uint16_t*)0x200002d0 = 0;
*(uint16_t*)0x200002d2 = 0;
*(uint32_t*)0x200002d4 = 0;
*(uint32_t*)0x200002d8 = 0;
*(uint16_t*)0x200002dc = 0;
*(uint16_t*)0x200002de = 0;
*(uint32_t*)0x200002e0 = 0;
*(uint32_t*)0x200002e4 = 0;
*(uint16_t*)0x200002e8 = 0;
*(uint16_t*)0x200002ea = 0;
*(uint32_t*)0x200002ec = 0;
*(uint32_t*)0x200002f0 = 0;
*(uint16_t*)0x200002f4 = 0;
*(uint16_t*)0x200002f6 = 0;
*(uint32_t*)0x200002f8 = 0;
*(uint32_t*)0x200002fc = 0;
*(uint16_t*)0x20000300 = 0;
*(uint16_t*)0x20000302 = 0;
*(uint32_t*)0x20000304 = 0;
*(uint32_t*)0x20000308 = 0;
*(uint16_t*)0x2000030c = 0;
*(uint16_t*)0x2000030e = 0;
*(uint32_t*)0x20000310 = 0;
*(uint32_t*)0x20000314 = 0;
*(uint16_t*)0x20000318 = 0x9ea;
*(uint16_t*)0x2000031a = 0;
*(uint32_t*)0x2000031c = 0;
*(uint32_t*)0x20000320 = 0;
*(uint16_t*)0x20000324 = 0;
*(uint16_t*)0x20000326 = 0;
*(uint32_t*)0x20000328 = 0;
*(uint32_t*)0x2000032c = 2;
*(uint16_t*)0x20000330 = 0;
*(uint16_t*)0x20000332 = 0;
*(uint32_t*)0x20000334 = 0;
*(uint32_t*)0x20000338 = 0;
*(uint16_t*)0x2000033c = 0;
*(uint16_t*)0x2000033e = 0;
*(uint32_t*)0x20000340 = 0;
*(uint32_t*)0x20000344 = 0;
*(uint16_t*)0x20000348 = 0x8000;
*(uint16_t*)0x2000034a = 0;
*(uint32_t*)0x2000034c = 0;
*(uint32_t*)0x20000350 = 0;
*(uint16_t*)0x20000354 = 0;
*(uint16_t*)0x20000356 = 0;
*(uint32_t*)0x20000358 = 0;
*(uint32_t*)0x2000035c = 0;
*(uint16_t*)0x20000360 = 0;
*(uint16_t*)0x20000362 = 0;
*(uint32_t*)0x20000364 = 0;
*(uint32_t*)0x20000368 = 0;
*(uint16_t*)0x2000036c = 0;
*(uint16_t*)0x2000036e = 0;
*(uint32_t*)0x20000370 = 0;
*(uint32_t*)0x20000374 = 0;
*(uint16_t*)0x20000378 = 0x6d;
*(uint16_t*)0x2000037a = 0;
*(uint32_t*)0x2000037c = 0;
*(uint32_t*)0x20000380 = 0;
*(uint16_t*)0x20000384 = 0xf801;
*(uint16_t*)0x20000386 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint32_t*)0x2000038c = 0;
*(uint16_t*)0x20000390 = 0;
*(uint16_t*)0x20000392 = 0;
*(uint32_t*)0x20000394 = 0;
*(uint32_t*)0x20000398 = 0;
*(uint16_t*)0x2000039c = 0;
*(uint16_t*)0x2000039e = 0;
*(uint32_t*)0x200003a0 = 0;
*(uint32_t*)0x200003a4 = 0;
*(uint16_t*)0x200003a8 = 0x254;
*(uint16_t*)0x200003aa = 1;
*(uint32_t*)0x200003ac = 0;
*(uint32_t*)0x200003b0 = 0;
*(uint8_t*)0x200003b4 = 0;
*(uint8_t*)0x200003b5 = 0;
*(uint16_t*)0x200003b6 = 0;
*(uint16_t*)0x200003b8 = 0;
*(uint16_t*)0x200003ba = 0;
memcpy((void*)0x200003bc, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x200003dc, "\x2e\x7d\x8b\x46\xaf\x35\x8b\x6f\x07\xb3\xf1\x05\x99\x47\x00\x11\xbe\xe5\xc8\xba\x9a\xc0\xf3\x17\x9e\xe8\x1b\xb4\x7a\x76\xa2\xc4", 32);
memcpy((void*)0x200003fc, "\x18\x45\x2d\x5b\xe4\xa0\xd8\xb7\xca\xbb\x3f\x33\xd4\x40\xc3\x95\x32\x75\xbb\xa9\xc1\x98\xb8\x87\x84\x91\x9b\xb3\xa7\x27\xe6\xe3", 32);
*(uint16_t*)0x2000041c = 0;
*(uint16_t*)0x2000041e = 0;
*(uint32_t*)0x20000420 = 0;
*(uint32_t*)0x20000424 = 0;
*(uint16_t*)0x20000428 = 0;
*(uint16_t*)0x2000042a = 0;
*(uint32_t*)0x2000042c = 0;
*(uint32_t*)0x20000430 = 0;
*(uint16_t*)0x20000434 = 0x8ff;
*(uint16_t*)0x20000436 = 0x7fe0;
*(uint32_t*)0x20000438 = 0;
*(uint32_t*)0x2000043c = 0x6dc211fd;
*(uint16_t*)0x20000440 = 7;
*(uint16_t*)0x20000442 = 0;
*(uint32_t*)0x20000444 = 0x8fd40e46;
*(uint32_t*)0x20000448 = 0xf86;
*(uint16_t*)0x2000044c = 4;
*(uint16_t*)0x2000044e = 0;
*(uint32_t*)0x20000450 = 0;
*(uint32_t*)0x20000454 = 0;
*(uint16_t*)0x20000458 = 2;
*(uint16_t*)0x2000045a = 3;
*(uint32_t*)0x2000045c = 1;
*(uint32_t*)0x20000460 = 0;
*(uint16_t*)0x20000464 = 0;
*(uint16_t*)0x20000466 = 9;
*(uint32_t*)0x20000468 = 1;
*(uint32_t*)0x2000046c = 0;
*(uint16_t*)0x20000470 = 8;
*(uint16_t*)0x20000472 = 0x85;
*(uint32_t*)0x20000474 = 0;
*(uint32_t*)0x20000478 = 1;
*(uint16_t*)0x2000047c = 9;
*(uint16_t*)0x2000047e = 0xe43;
*(uint32_t*)0x20000480 = 2;
*(uint32_t*)0x20000484 = 0x1f;
*(uint16_t*)0x20000488 = 6;
*(uint16_t*)0x2000048a = 0x68;
*(uint32_t*)0x2000048c = 0;
*(uint32_t*)0x20000490 = 0;
*(uint16_t*)0x20000494 = 0x40;
*(uint16_t*)0x20000496 = 0xe9;
*(uint32_t*)0x20000498 = 0;
*(uint32_t*)0x2000049c = 0x401;
*(uint16_t*)0x200004a0 = 0xf8fd;
*(uint16_t*)0x200004a2 = 8;
*(uint32_t*)0x200004a4 = 2;
*(uint32_t*)0x200004a8 = 0x80;
*(uint16_t*)0x200004ac = 3;
*(uint16_t*)0x200004ae = 0;
*(uint32_t*)0x200004b0 = 1;
*(uint32_t*)0x200004b4 = 0;
*(uint16_t*)0x200004b8 = 0xfff7;
*(uint16_t*)0x200004ba = 0x40;
*(uint32_t*)0x200004bc = 0;
*(uint32_t*)0x200004c0 = 0;
*(uint16_t*)0x200004c4 = 0;
*(uint16_t*)0x200004c6 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint32_t*)0x200004cc = 1;
*(uint16_t*)0x200004d0 = 8;
*(uint16_t*)0x200004d2 = 0;
*(uint32_t*)0x200004d4 = 2;
*(uint32_t*)0x200004d8 = 0xffff;
*(uint16_t*)0x200004dc = 4;
*(uint16_t*)0x200004de = 0xfff;
*(uint32_t*)0x200004e0 = 3;
*(uint32_t*)0x200004e4 = 0;
*(uint16_t*)0x200004e8 = 6;
*(uint16_t*)0x200004ea = 0;
*(uint32_t*)0x200004ec = 0;
*(uint32_t*)0x200004f0 = 8;
*(uint16_t*)0x200004f4 = 4;
*(uint16_t*)0x200004f6 = 0xfffb;
*(uint32_t*)0x200004f8 = 0;
*(uint32_t*)0x200004fc = 0;
*(uint16_t*)0x20000500 = 0x8000;
*(uint16_t*)0x20000502 = 0;
*(uint32_t*)0x20000504 = 1;
*(uint32_t*)0x20000508 = 0;
*(uint16_t*)0x2000050c = 0;
*(uint16_t*)0x2000050e = 0;
*(uint32_t*)0x20000510 = 2;
*(uint32_t*)0x20000514 = 0x10000;
*(uint16_t*)0x20000518 = 0;
*(uint16_t*)0x2000051a = 1;
*(uint32_t*)0x2000051c = 3;
*(uint32_t*)0x20000520 = 0;
*(uint16_t*)0x20000524 = 0;
*(uint16_t*)0x20000526 = 0x100;
*(uint32_t*)0x20000528 = 0;
*(uint32_t*)0x2000052c = 8;
*(uint16_t*)0x20000530 = 0;
*(uint16_t*)0x20000532 = 0;
*(uint32_t*)0x20000534 = 0;
*(uint32_t*)0x20000538 = 0;
*(uint16_t*)0x2000053c = 0;
*(uint16_t*)0x2000053e = 0;
*(uint32_t*)0x20000540 = 0;
*(uint32_t*)0x20000544 = 0;
*(uint16_t*)0x20000548 = 0;
*(uint16_t*)0x2000054a = 0;
*(uint32_t*)0x2000054c = 0;
*(uint32_t*)0x20000550 = 0;
*(uint16_t*)0x20000554 = 0;
*(uint16_t*)0x20000556 = 0;
*(uint32_t*)0x20000558 = 0;
*(uint32_t*)0x2000055c = 0;
*(uint16_t*)0x20000560 = 0;
*(uint16_t*)0x20000562 = 0;
*(uint32_t*)0x20000564 = 0;
*(uint32_t*)0x20000568 = 0;
*(uint16_t*)0x2000056c = 0;
*(uint16_t*)0x2000056e = 0;
*(uint32_t*)0x20000570 = 0;
*(uint32_t*)0x20000574 = 0;
*(uint16_t*)0x20000578 = 0;
*(uint16_t*)0x2000057a = 0;
*(uint32_t*)0x2000057c = 0;
*(uint32_t*)0x20000580 = 0;
*(uint16_t*)0x20000584 = 0;
*(uint16_t*)0x20000586 = 0;
*(uint32_t*)0x20000588 = 0;
*(uint32_t*)0x2000058c = 0;
*(uint16_t*)0x20000590 = 0;
*(uint16_t*)0x20000592 = 0;
*(uint32_t*)0x20000594 = 0;
*(uint32_t*)0x20000598 = 0;
*(uint16_t*)0x2000059c = 0;
*(uint16_t*)0x2000059e = 0;
*(uint32_t*)0x200005a0 = 0;
*(uint32_t*)0x200005a4 = 0;
*(uint16_t*)0x200005a8 = 0;
*(uint16_t*)0x200005aa = 0;
*(uint32_t*)0x200005ac = 0;
*(uint32_t*)0x200005b0 = 0;
*(uint16_t*)0x200005b4 = 0;
*(uint16_t*)0x200005b6 = 0;
*(uint32_t*)0x200005b8 = 0;
*(uint32_t*)0x200005bc = 0;
*(uint16_t*)0x200005c0 = 0;
*(uint16_t*)0x200005c2 = 0;
*(uint32_t*)0x200005c4 = 0;
*(uint32_t*)0x200005c8 = 0;
*(uint16_t*)0x200005cc = 0;
*(uint16_t*)0x200005ce = 0;
*(uint32_t*)0x200005d0 = 0;
*(uint32_t*)0x200005d4 = 0;
*(uint16_t*)0x200005d8 = 0;
*(uint16_t*)0x200005da = 0;
*(uint32_t*)0x200005dc = 0;
*(uint32_t*)0x200005e0 = 0;
*(uint16_t*)0x200005e4 = 0;
*(uint16_t*)0x200005e6 = 0;
*(uint32_t*)0x200005e8 = 0;
*(uint32_t*)0x200005ec = 0;
*(uint16_t*)0x200005f0 = 0;
*(uint16_t*)0x200005f2 = 0;
*(uint32_t*)0x200005f4 = 0;
*(uint32_t*)0x200005f8 = 0;
*(uint16_t*)0x200005fc = 0x254;
*(uint16_t*)0x200005fe = 1;
*(uint32_t*)0x20000600 = 0;
*(uint32_t*)0x20000604 = 1;
*(uint8_t*)0x20000608 = 0;
*(uint8_t*)0x20000609 = 3;
*(uint16_t*)0x2000060a = 0;
*(uint16_t*)0x2000060c = 0;
*(uint16_t*)0x2000060e = 0;
memcpy((void*)0x20000610, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000630, "\x8b\x86\xae\x19\x99\x22\x51\xb9\x98\x6c\xab\xc0\x4b\xbe\xcf\x46\xa0\xe7\xfb\x05\x1b\xca\x29\xdc\x6a\x74\xa6\xaa\x03\x70\x37\x3a", 32);
memcpy((void*)0x20000650, "\xf1\x35\x40\x5a\xc9\x2e\x9d\x9c\xf0\x37\xfd\x19\x03\xa0\xd2\x55\xb4\x22\xef\x9a\xba\x20\x8b\x62\xe9\x78\xf7\xf8\x30\xd7\xbd\x76", 32);
*(uint16_t*)0x20000670 = 0;
*(uint16_t*)0x20000672 = 0;
*(uint32_t*)0x20000674 = 0;
*(uint32_t*)0x20000678 = 0;
*(uint16_t*)0x2000067c = 0;
*(uint16_t*)0x2000067e = 0;
*(uint32_t*)0x20000680 = 0;
*(uint32_t*)0x20000684 = 0;
*(uint16_t*)0x20000688 = 0;
*(uint16_t*)0x2000068a = 0;
*(uint32_t*)0x2000068c = 0;
*(uint32_t*)0x20000690 = 0;
*(uint16_t*)0x20000694 = 0;
*(uint16_t*)0x20000696 = 0;
*(uint32_t*)0x20000698 = 0;
*(uint32_t*)0x2000069c = 0;
*(uint16_t*)0x200006a0 = 0;
*(uint16_t*)0x200006a2 = 0;
*(uint32_t*)0x200006a4 = 0;
*(uint32_t*)0x200006a8 = 0;
*(uint16_t*)0x200006ac = 0;
*(uint16_t*)0x200006ae = 0;
*(uint32_t*)0x200006b0 = 0;
*(uint32_t*)0x200006b4 = 0;
*(uint16_t*)0x200006b8 = 0;
*(uint16_t*)0x200006ba = 0;
*(uint32_t*)0x200006bc = 0;
*(uint32_t*)0x200006c0 = 0;
*(uint16_t*)0x200006c4 = 0;
*(uint16_t*)0x200006c6 = 0;
*(uint32_t*)0x200006c8 = 0;
*(uint32_t*)0x200006cc = 0;
*(uint16_t*)0x200006d0 = 0;
*(uint16_t*)0x200006d2 = 0;
*(uint32_t*)0x200006d4 = 0;
*(uint32_t*)0x200006d8 = 0;
*(uint16_t*)0x200006dc = 0;
*(uint16_t*)0x200006de = 0;
*(uint32_t*)0x200006e0 = 0;
*(uint32_t*)0x200006e4 = 0;
*(uint16_t*)0x200006e8 = 0;
*(uint16_t*)0x200006ea = 0;
*(uint32_t*)0x200006ec = 0;
*(uint32_t*)0x200006f0 = 0;
*(uint16_t*)0x200006f4 = 0;
*(uint16_t*)0x200006f6 = 0;
*(uint32_t*)0x200006f8 = 0;
*(uint32_t*)0x200006fc = 0;
*(uint16_t*)0x20000700 = 0;
*(uint16_t*)0x20000702 = 0;
*(uint32_t*)0x20000704 = 0;
*(uint32_t*)0x20000708 = 0;
*(uint16_t*)0x2000070c = 0;
*(uint16_t*)0x2000070e = 0;
*(uint32_t*)0x20000710 = 0;
*(uint32_t*)0x20000714 = 0;
*(uint16_t*)0x20000718 = 0;
*(uint16_t*)0x2000071a = 0;
*(uint32_t*)0x2000071c = 0;
*(uint32_t*)0x20000720 = 0;
*(uint16_t*)0x20000724 = 0;
*(uint16_t*)0x20000726 = 0;
*(uint32_t*)0x20000728 = 0;
*(uint32_t*)0x2000072c = 0;
*(uint16_t*)0x20000730 = 0;
*(uint16_t*)0x20000732 = 0;
*(uint32_t*)0x20000734 = 0;
*(uint32_t*)0x20000738 = 0;
*(uint16_t*)0x2000073c = 0;
*(uint16_t*)0x2000073e = 0;
*(uint32_t*)0x20000740 = 0;
*(uint32_t*)0x20000744 = 0;
*(uint16_t*)0x20000748 = 0;
*(uint16_t*)0x2000074a = 0;
*(uint32_t*)0x2000074c = 0;
*(uint32_t*)0x20000750 = 0;
*(uint16_t*)0x20000754 = 0;
*(uint16_t*)0x20000756 = 0;
*(uint32_t*)0x20000758 = 0;
*(uint32_t*)0x2000075c = 0;
*(uint16_t*)0x20000760 = 0;
*(uint16_t*)0x20000762 = 0;
*(uint32_t*)0x20000764 = 0;
*(uint32_t*)0x20000768 = 0;
*(uint16_t*)0x2000076c = 0;
*(uint16_t*)0x2000076e = 0;
*(uint32_t*)0x20000770 = 0;
*(uint32_t*)0x20000774 = 0;
*(uint16_t*)0x20000778 = 3;
*(uint16_t*)0x2000077a = 0;
*(uint32_t*)0x2000077c = 0;
*(uint32_t*)0x20000780 = 0;
*(uint16_t*)0x20000784 = 0xfffd;
*(uint16_t*)0x20000786 = 0;
*(uint32_t*)0x20000788 = 0;
*(uint32_t*)0x2000078c = 0;
*(uint16_t*)0x20000790 = 0xe169;
*(uint16_t*)0x20000792 = 0;
*(uint32_t*)0x20000794 = 0;
*(uint32_t*)0x20000798 = 0;
*(uint16_t*)0x2000079c = 0;
*(uint16_t*)0x2000079e = 0;
*(uint32_t*)0x200007a0 = 0;
*(uint32_t*)0x200007a4 = 0;
*(uint16_t*)0x200007a8 = 0;
*(uint16_t*)0x200007aa = 0;
*(uint32_t*)0x200007ac = 0;
*(uint32_t*)0x200007b0 = 0;
*(uint16_t*)0x200007b4 = 0;
*(uint16_t*)0x200007b6 = 0;
*(uint32_t*)0x200007b8 = 0;
*(uint32_t*)0x200007bc = 0;
*(uint16_t*)0x200007c0 = 0;
*(uint16_t*)0x200007c2 = 7;
*(uint32_t*)0x200007c4 = 0;
*(uint32_t*)0x200007c8 = 1;
*(uint16_t*)0x200007cc = 0;
*(uint16_t*)0x200007ce = 0;
*(uint32_t*)0x200007d0 = 0;
*(uint32_t*)0x200007d4 = 0;
*(uint16_t*)0x200007d8 = 0;
*(uint16_t*)0x200007da = 0;
*(uint32_t*)0x200007dc = 3;
*(uint32_t*)0x200007e0 = 0;
*(uint16_t*)0x200007e4 = 0;
*(uint16_t*)0x200007e6 = 0;
*(uint32_t*)0x200007e8 = 0;
*(uint32_t*)0x200007ec = 0x1ff;
*(uint16_t*)0x200007f0 = 0x8ef;
*(uint16_t*)0x200007f2 = 0;
*(uint32_t*)0x200007f4 = 0;
*(uint32_t*)0x200007f8 = 0;
*(uint16_t*)0x200007fc = 0;
*(uint16_t*)0x200007fe = 7;
*(uint32_t*)0x20000800 = 0;
*(uint32_t*)0x20000804 = 0;
*(uint16_t*)0x20000808 = 5;
*(uint16_t*)0x2000080a = 6;
*(uint32_t*)0x2000080c = 0;
*(uint32_t*)0x20000810 = 0;
*(uint16_t*)0x20000814 = 0;
*(uint16_t*)0x20000816 = 4;
*(uint32_t*)0x20000818 = 0;
*(uint32_t*)0x2000081c = 0;
*(uint16_t*)0x20000820 = 0x77fb;
*(uint16_t*)0x20000822 = 0;
*(uint32_t*)0x20000824 = 0;
*(uint32_t*)0x20000828 = 0x3ff;
*(uint16_t*)0x2000082c = 0;
*(uint16_t*)0x2000082e = 0;
*(uint32_t*)0x20000830 = 0;
*(uint32_t*)0x20000834 = 0;
*(uint16_t*)0x20000838 = 0xe853;
*(uint16_t*)0x2000083a = 0;
*(uint32_t*)0x2000083c = 0;
*(uint32_t*)0x20000840 = 0;
*(uint16_t*)0x20000844 = 0;
*(uint16_t*)0x20000846 = 0;
*(uint32_t*)0x20000848 = 2;
*(uint32_t*)0x2000084c = 0;
*(uint16_t*)0x20000850 = 0x254;
*(uint16_t*)0x20000852 = 1;
*(uint32_t*)0x20000854 = 0;
*(uint32_t*)0x20000858 = 0;
*(uint8_t*)0x2000085c = 0;
*(uint8_t*)0x2000085d = 0;
*(uint16_t*)0x2000085e = 0;
*(uint16_t*)0x20000860 = 0;
*(uint16_t*)0x20000862 = 0;
memcpy((void*)0x20000864, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000884, "\x16\x2e\x98\x51\xaa\x0f\x5e\x77\xe4\xa5\xf0\xb5\x5b\x6b\x51\x33\xca\x73\x15\xbc\x4c\x8a\x6d\x71\x42\xfe\xf9\x08\xc0\xac\xa7\x06", 32);
memcpy((void*)0x200008a4, "\xa9\x53\xda\xe0\xd0\xb1\x97\x97\xa6\x3e\xe8\x1c\xab\xb8\x5c\x69\xdb\x08\x0f\x1e\x11\xf2\x38\x66\xd3\x6f\xc7\x9d\x57\xee\x47\xea", 32);
*(uint16_t*)0x200008c4 = 0xfff8;
*(uint16_t*)0x200008c6 = 0;
*(uint32_t*)0x200008c8 = 0;
*(uint32_t*)0x200008cc = 0;
*(uint16_t*)0x200008d0 = 0;
*(uint16_t*)0x200008d2 = 0;
*(uint32_t*)0x200008d4 = 0;
*(uint32_t*)0x200008d8 = 0;
*(uint16_t*)0x200008dc = 0;
*(uint16_t*)0x200008de = 0;
*(uint32_t*)0x200008e0 = 0;
*(uint32_t*)0x200008e4 = 0;
*(uint16_t*)0x200008e8 = 5;
*(uint16_t*)0x200008ea = 0;
*(uint32_t*)0x200008ec = 0;
*(uint32_t*)0x200008f0 = 0;
*(uint16_t*)0x200008f4 = 0;
*(uint16_t*)0x200008f6 = 0;
*(uint32_t*)0x200008f8 = 0;
*(uint32_t*)0x200008fc = 0;
*(uint16_t*)0x20000900 = 0;
*(uint16_t*)0x20000902 = 0;
*(uint32_t*)0x20000904 = 0;
*(uint32_t*)0x20000908 = 0;
*(uint16_t*)0x2000090c = 2;
*(uint16_t*)0x2000090e = 0;
*(uint32_t*)0x20000910 = 0;
*(uint32_t*)0x20000914 = 0;
*(uint16_t*)0x20000918 = 0;
*(uint16_t*)0x2000091a = 0;
*(uint32_t*)0x2000091c = 0;
*(uint32_t*)0x20000920 = 0;
*(uint16_t*)0x20000924 = 0;
*(uint16_t*)0x20000926 = 0;
*(uint32_t*)0x20000928 = 1;
*(uint32_t*)0x2000092c = 0;
*(uint16_t*)0x20000930 = 0x1928;
*(uint16_t*)0x20000932 = 0;
*(uint32_t*)0x20000934 = 0;
*(uint32_t*)0x20000938 = 0;
*(uint16_t*)0x2000093c = 0;
*(uint16_t*)0x2000093e = 0;
*(uint32_t*)0x20000940 = 0;
*(uint32_t*)0x20000944 = 0;
*(uint16_t*)0x20000948 = 0;
*(uint16_t*)0x2000094a = 0;
*(uint32_t*)0x2000094c = 0;
*(uint32_t*)0x20000950 = 0;
*(uint16_t*)0x20000954 = 0;
*(uint16_t*)0x20000956 = 0;
*(uint32_t*)0x20000958 = 0;
*(uint32_t*)0x2000095c = 0;
*(uint16_t*)0x20000960 = 0;
*(uint16_t*)0x20000962 = 0;
*(uint32_t*)0x20000964 = 0;
*(uint32_t*)0x20000968 = 0;
*(uint16_t*)0x2000096c = 0;
*(uint16_t*)0x2000096e = 0;
*(uint32_t*)0x20000970 = 0;
*(uint32_t*)0x20000974 = 0;
*(uint16_t*)0x20000978 = 0;
*(uint16_t*)0x2000097a = 0;
*(uint32_t*)0x2000097c = 0;
*(uint32_t*)0x20000980 = 0;
*(uint16_t*)0x20000984 = 0;
*(uint16_t*)0x20000986 = 0;
*(uint32_t*)0x20000988 = 0;
*(uint32_t*)0x2000098c = 0;
*(uint16_t*)0x20000990 = 0;
*(uint16_t*)0x20000992 = 0;
*(uint32_t*)0x20000994 = 0;
*(uint32_t*)0x20000998 = 0;
*(uint16_t*)0x2000099c = 0;
*(uint16_t*)0x2000099e = 0;
*(uint32_t*)0x200009a0 = 0;
*(uint32_t*)0x200009a4 = 0;
*(uint16_t*)0x200009a8 = 0;
*(uint16_t*)0x200009aa = 0;
*(uint32_t*)0x200009ac = 0;
*(uint32_t*)0x200009b0 = 0;
*(uint16_t*)0x200009b4 = 0;
*(uint16_t*)0x200009b6 = 0;
*(uint32_t*)0x200009b8 = 0;
*(uint32_t*)0x200009bc = 0;
*(uint16_t*)0x200009c0 = 0;
*(uint16_t*)0x200009c2 = 0;
*(uint32_t*)0x200009c4 = 0;
*(uint32_t*)0x200009c8 = 0;
*(uint16_t*)0x200009cc = 0;
*(uint16_t*)0x200009ce = 0;
*(uint32_t*)0x200009d0 = 0;
*(uint32_t*)0x200009d4 = 0;
*(uint16_t*)0x200009d8 = 0;
*(uint16_t*)0x200009da = 0;
*(uint32_t*)0x200009dc = 0;
*(uint32_t*)0x200009e0 = 0;
*(uint16_t*)0x200009e4 = 0;
*(uint16_t*)0x200009e6 = 0;
*(uint32_t*)0x200009e8 = 0;
*(uint32_t*)0x200009ec = 0;
*(uint16_t*)0x200009f0 = 0;
*(uint16_t*)0x200009f2 = 0;
*(uint32_t*)0x200009f4 = 0;
*(uint32_t*)0x200009f8 = 0;
*(uint16_t*)0x200009fc = 0;
*(uint16_t*)0x200009fe = 0;
*(uint32_t*)0x20000a00 = 0;
*(uint32_t*)0x20000a04 = 0;
*(uint16_t*)0x20000a08 = 0;
*(uint16_t*)0x20000a0a = 0;
*(uint32_t*)0x20000a0c = 0;
*(uint32_t*)0x20000a10 = 0;
*(uint16_t*)0x20000a14 = 0;
*(uint16_t*)0x20000a16 = 0;
*(uint32_t*)0x20000a18 = 0;
*(uint32_t*)0x20000a1c = 0;
*(uint16_t*)0x20000a20 = 0;
*(uint16_t*)0x20000a22 = 0;
*(uint32_t*)0x20000a24 = 0;
*(uint32_t*)0x20000a28 = 0;
*(uint16_t*)0x20000a2c = 0;
*(uint16_t*)0x20000a2e = 0;
*(uint32_t*)0x20000a30 = 0;
*(uint32_t*)0x20000a34 = 0;
*(uint16_t*)0x20000a38 = 0;
*(uint16_t*)0x20000a3a = 0;
*(uint32_t*)0x20000a3c = 0;
*(uint32_t*)0x20000a40 = 0;
*(uint16_t*)0x20000a44 = 0;
*(uint16_t*)0x20000a46 = 0;
*(uint32_t*)0x20000a48 = 0;
*(uint32_t*)0x20000a4c = 0;
*(uint16_t*)0x20000a50 = 0;
*(uint16_t*)0x20000a52 = 0;
*(uint32_t*)0x20000a54 = 0;
*(uint32_t*)0x20000a58 = 0;
*(uint16_t*)0x20000a5c = 0;
*(uint16_t*)0x20000a5e = 0;
*(uint32_t*)0x20000a60 = 0;
*(uint32_t*)0x20000a64 = 0;
*(uint16_t*)0x20000a68 = 0;
*(uint16_t*)0x20000a6a = 0;
*(uint32_t*)0x20000a6c = 0;
*(uint32_t*)0x20000a70 = 0;
*(uint16_t*)0x20000a74 = 0;
*(uint16_t*)0x20000a76 = 0;
*(uint32_t*)0x20000a78 = 0;
*(uint32_t*)0x20000a7c = 0;
*(uint16_t*)0x20000a80 = 0;
*(uint16_t*)0x20000a82 = 0;
*(uint32_t*)0x20000a84 = 0;
*(uint32_t*)0x20000a88 = 0;
*(uint16_t*)0x20000a8c = 0;
*(uint16_t*)0x20000a8e = 0;
*(uint32_t*)0x20000a90 = 0;
*(uint32_t*)0x20000a94 = 0;
*(uint16_t*)0x20000a98 = 0;
*(uint16_t*)0x20000a9a = 0;
*(uint32_t*)0x20000a9c = 0;
*(uint32_t*)0x20000aa0 = 0;
*(uint16_t*)0x20000aa4 = 0x254;
*(uint16_t*)0x20000aa6 = 1;
*(uint32_t*)0x20000aa8 = 0;
*(uint32_t*)0x20000aac = 0;
*(uint8_t*)0x20000ab0 = 0;
*(uint8_t*)0x20000ab1 = 0;
*(uint16_t*)0x20000ab2 = 0;
*(uint16_t*)0x20000ab4 = 0;
*(uint16_t*)0x20000ab6 = 0;
memcpy((void*)0x20000ab8, "syz1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000ad8, "\x0b\xd2\x41\xe7\x89\xdb\x43\xe2\x47\xf1\xd4\x2e\x4a\x88\xe9\x4a\xf7\x0e\x93\x25\xfb\x22\x36\x76\xa5\x99\x7c\x45\x6b\x7f\x97\xf4", 32);
memcpy((void*)0x20000af8, "\xe8\x01\x6a\x66\x1e\x0d\x7e\xe8\xd5\x3a\x4b\x8e\x74\x89\x12\x99\x62\x2c\xea\x6f\xb3\x3c\xc9\xb5\x25\x6c\x88\xbc\x07\x99\x16\x38", 32);
*(uint16_t*)0x20000b18 = 0;
*(uint16_t*)0x20000b1a = 0;
*(uint32_t*)0x20000b1c = 0;
*(uint32_t*)0x20000b20 = 0;
*(uint16_t*)0x20000b24 = 0;
*(uint16_t*)0x20000b26 = 0;
*(uint32_t*)0x20000b28 = 0;
*(uint32_t*)0x20000b2c = 0;
*(uint16_t*)0x20000b30 = 0;
*(uint16_t*)0x20000b32 = 0;
*(uint32_t*)0x20000b34 = 0;
*(uint32_t*)0x20000b38 = 0;
*(uint16_t*)0x20000b3c = 0;
*(uint16_t*)0x20000b3e = 0;
*(uint32_t*)0x20000b40 = 0;
*(uint32_t*)0x20000b44 = 0;
*(uint16_t*)0x20000b48 = 0;
*(uint16_t*)0x20000b4a = 0;
*(uint32_t*)0x20000b4c = 0;
*(uint32_t*)0x20000b50 = 0;
*(uint16_t*)0x20000b54 = 0;
*(uint16_t*)0x20000b56 = 0;
*(uint32_t*)0x20000b58 = 0;
*(uint32_t*)0x20000b5c = 0;
*(uint16_t*)0x20000b60 = 0;
*(uint16_t*)0x20000b62 = 0;
*(uint32_t*)0x20000b64 = 0;
*(uint32_t*)0x20000b68 = 0;
*(uint16_t*)0x20000b6c = 0;
*(uint16_t*)0x20000b6e = 0;
*(uint32_t*)0x20000b70 = 0;
*(uint32_t*)0x20000b74 = 0;
*(uint16_t*)0x20000b78 = 0;
*(uint16_t*)0x20000b7a = 0;
*(uint32_t*)0x20000b7c = 0;
*(uint32_t*)0x20000b80 = 0;
*(uint16_t*)0x20000b84 = 0;
*(uint16_t*)0x20000b86 = 0;
*(uint32_t*)0x20000b88 = 0;
*(uint32_t*)0x20000b8c = 0;
*(uint16_t*)0x20000b90 = 0;
*(uint16_t*)0x20000b92 = 0;
*(uint32_t*)0x20000b94 = 0;
*(uint32_t*)0x20000b98 = 0;
*(uint16_t*)0x20000b9c = 0;
*(uint16_t*)0x20000b9e = 7;
*(uint32_t*)0x20000ba0 = 0;
*(uint32_t*)0x20000ba4 = 0;
*(uint16_t*)0x20000ba8 = 0;
*(uint16_t*)0x20000baa = 0;
*(uint32_t*)0x20000bac = 0;
*(uint32_t*)0x20000bb0 = 0;
*(uint16_t*)0x20000bb4 = 0;
*(uint16_t*)0x20000bb6 = 0;
*(uint32_t*)0x20000bb8 = 0;
*(uint32_t*)0x20000bbc = 0;
*(uint16_t*)0x20000bc0 = 0;
*(uint16_t*)0x20000bc2 = 0;
*(uint32_t*)0x20000bc4 = 0;
*(uint32_t*)0x20000bc8 = 0;
*(uint16_t*)0x20000bcc = 0;
*(uint16_t*)0x20000bce = 0;
*(uint32_t*)0x20000bd0 = 0;
*(uint32_t*)0x20000bd4 = 0;
*(uint16_t*)0x20000bd8 = 0x3276;
*(uint16_t*)0x20000bda = 0x7f;
*(uint32_t*)0x20000bdc = 0;
*(uint32_t*)0x20000be0 = 0;
*(uint16_t*)0x20000be4 = 0;
*(uint16_t*)0x20000be6 = 8;
*(uint32_t*)0x20000be8 = 0;
*(uint32_t*)0x20000bec = 0;
*(uint16_t*)0x20000bf0 = 0;
*(uint16_t*)0x20000bf2 = 0;
*(uint32_t*)0x20000bf4 = 0;
*(uint32_t*)0x20000bf8 = 0;
*(uint16_t*)0x20000bfc = 0;
*(uint16_t*)0x20000bfe = 0;
*(uint32_t*)0x20000c00 = 0;
*(uint32_t*)0x20000c04 = 0;
*(uint16_t*)0x20000c08 = 0;
*(uint16_t*)0x20000c0a = 0;
*(uint32_t*)0x20000c0c = 3;
*(uint32_t*)0x20000c10 = 9;
*(uint16_t*)0x20000c14 = 0x40;
*(uint16_t*)0x20000c16 = 0;
*(uint32_t*)0x20000c18 = 0;
*(uint32_t*)0x20000c1c = 0x7ff;
*(uint16_t*)0x20000c20 = 8;
*(uint16_t*)0x20000c22 = 0xfff;
*(uint32_t*)0x20000c24 = 0;
*(uint32_t*)0x20000c28 = 6;
*(uint16_t*)0x20000c2c = 0;
*(uint16_t*)0x20000c2e = 0;
*(uint32_t*)0x20000c30 = 3;
*(uint32_t*)0x20000c34 = 0;
*(uint16_t*)0x20000c38 = 0;
*(uint16_t*)0x20000c3a = 0;
*(uint32_t*)0x20000c3c = 3;
*(uint32_t*)0x20000c40 = 5;
*(uint16_t*)0x20000c44 = 2;
*(uint16_t*)0x20000c46 = 8;
*(uint32_t*)0x20000c48 = 1;
*(uint32_t*)0x20000c4c = 5;
*(uint16_t*)0x20000c50 = 0;
*(uint16_t*)0x20000c52 = 0;
*(uint32_t*)0x20000c54 = 0;
*(uint32_t*)0x20000c58 = 0;
*(uint16_t*)0x20000c5c = 0;
*(uint16_t*)0x20000c5e = 2;
*(uint32_t*)0x20000c60 = 0;
*(uint32_t*)0x20000c64 = 0;
*(uint16_t*)0x20000c68 = 0x8000;
*(uint16_t*)0x20000c6a = 0;
*(uint32_t*)0x20000c6c = 0;
*(uint32_t*)0x20000c70 = 0x80;
*(uint16_t*)0x20000c74 = 0;
*(uint16_t*)0x20000c76 = 0;
*(uint32_t*)0x20000c78 = 2;
*(uint32_t*)0x20000c7c = 0x10000;
*(uint16_t*)0x20000c80 = 0;
*(uint16_t*)0x20000c82 = 0;
*(uint32_t*)0x20000c84 = 2;
*(uint32_t*)0x20000c88 = 3;
*(uint16_t*)0x20000c8c = 0;
*(uint16_t*)0x20000c8e = 0;
*(uint32_t*)0x20000c90 = 0;
*(uint32_t*)0x20000c94 = 0;
*(uint16_t*)0x20000c98 = 0x81;
*(uint16_t*)0x20000c9a = 0x6fd;
*(uint32_t*)0x20000c9c = 0;
*(uint32_t*)0x20000ca0 = 0;
*(uint16_t*)0x20000ca4 = 0;
*(uint16_t*)0x20000ca6 = 0x7f;
*(uint32_t*)0x20000ca8 = 0;
*(uint32_t*)0x20000cac = 6;
*(uint16_t*)0x20000cb0 = 0;
*(uint16_t*)0x20000cb2 = 0;
*(uint32_t*)0x20000cb4 = 0;
*(uint32_t*)0x20000cb8 = 0;
*(uint16_t*)0x20000cbc = 1;
*(uint16_t*)0x20000cbe = 2;
*(uint32_t*)0x20000cc0 = 3;
*(uint32_t*)0x20000cc4 = 0;
*(uint16_t*)0x20000cc8 = 0xff6e;
*(uint16_t*)0x20000cca = 7;
*(uint32_t*)0x20000ccc = 0;
*(uint32_t*)0x20000cd0 = 0;
*(uint16_t*)0x20000cd4 = 0;
*(uint16_t*)0x20000cd6 = 0;
*(uint32_t*)0x20000cd8 = 0;
*(uint32_t*)0x20000cdc = 0;
*(uint16_t*)0x20000ce0 = 0;
*(uint16_t*)0x20000ce2 = 0;
*(uint32_t*)0x20000ce4 = 0;
*(uint32_t*)0x20000ce8 = 0;
*(uint16_t*)0x20000cec = 0;
*(uint16_t*)0x20000cee = 4;
*(uint32_t*)0x20000cf0 = 0;
*(uint32_t*)0x20000cf4 = 9;
*(uint16_t*)0x20000cf8 = 0x254;
*(uint16_t*)0x20000cfa = 1;
*(uint32_t*)0x20000cfc = 0;
*(uint32_t*)0x20000d00 = 8;
*(uint8_t*)0x20000d04 = 0;
*(uint8_t*)0x20000d05 = 2;
*(uint16_t*)0x20000d06 = 0;
*(uint16_t*)0x20000d08 = 0;
*(uint16_t*)0x20000d0a = 0xf;
memcpy((void*)0x20000d0c, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000d2c, "\x11\x9a\xce\x48\xd4\xed\x70\x5d\x3c\xb6\xa2\x59\x4c\x29\x7f\xbf\x17\x15\x31\x97\x70\x64\x5c\x6a\xc5\xb1\x21\x06\x62\x61\xf4\xb5", 32);
memcpy((void*)0x20000d4c, "\x51\x6a\x84\x23\x91\x7d\x7e\xc1\xb8\xee\x05\xa3\x7a\xfa\x4d\xa0\x9b\xe6\xdf\x4e\x0e\xb8\xae\x3e\xd9\x36\x15\x3b\x65\xe8\x2d\x51", 32);
*(uint16_t*)0x20000d6c = 0;
*(uint16_t*)0x20000d6e = 0;
*(uint32_t*)0x20000d70 = 0;
*(uint32_t*)0x20000d74 = 0;
*(uint16_t*)0x20000d78 = 0;
*(uint16_t*)0x20000d7a = 0;
*(uint32_t*)0x20000d7c = 0;
*(uint32_t*)0x20000d80 = 0;
*(uint16_t*)0x20000d84 = 0;
*(uint16_t*)0x20000d86 = 0x414;
*(uint32_t*)0x20000d88 = 0;
*(uint32_t*)0x20000d8c = 0;
*(uint16_t*)0x20000d90 = 0xff01;
*(uint16_t*)0x20000d92 = 0;
*(uint32_t*)0x20000d94 = 0;
*(uint32_t*)0x20000d98 = 0;
*(uint16_t*)0x20000d9c = 0;
*(uint16_t*)0x20000d9e = 0;
*(uint32_t*)0x20000da0 = 0;
*(uint32_t*)0x20000da4 = 0;
*(uint16_t*)0x20000da8 = 3;
*(uint16_t*)0x20000daa = 0;
*(uint32_t*)0x20000dac = 0;
*(uint32_t*)0x20000db0 = 0;
*(uint16_t*)0x20000db4 = 0;
*(uint16_t*)0x20000db6 = 0;
*(uint32_t*)0x20000db8 = 0;
*(uint32_t*)0x20000dbc = 0;
*(uint16_t*)0x20000dc0 = 0;
*(uint16_t*)0x20000dc2 = 0;
*(uint32_t*)0x20000dc4 = 0;
*(uint32_t*)0x20000dc8 = 0;
*(uint16_t*)0x20000dcc = 0;
*(uint16_t*)0x20000dce = 0;
*(uint32_t*)0x20000dd0 = 0;
*(uint32_t*)0x20000dd4 = 0;
*(uint16_t*)0x20000dd8 = 0;
*(uint16_t*)0x20000dda = 1;
*(uint32_t*)0x20000ddc = 0;
*(uint32_t*)0x20000de0 = 0xff;
*(uint16_t*)0x20000de4 = 0;
*(uint16_t*)0x20000de6 = 0xff;
*(uint32_t*)0x20000de8 = 0;
*(uint32_t*)0x20000dec = 0;
*(uint16_t*)0x20000df0 = 8;
*(uint16_t*)0x20000df2 = 0;
*(uint32_t*)0x20000df4 = 0;
*(uint32_t*)0x20000df8 = 1;
*(uint16_t*)0x20000dfc = 0;
*(uint16_t*)0x20000dfe = 0;
*(uint32_t*)0x20000e00 = 0;
*(uint32_t*)0x20000e04 = 0x123b59cb;
*(uint16_t*)0x20000e08 = 0;
*(uint16_t*)0x20000e0a = 0;
*(uint32_t*)0x20000e0c = 2;
*(uint32_t*)0x20000e10 = 0;
*(uint16_t*)0x20000e14 = 0;
*(uint16_t*)0x20000e16 = 8;
*(uint32_t*)0x20000e18 = 0;
*(uint32_t*)0x20000e1c = 0xfffffff7;
*(uint16_t*)0x20000e20 = 0x7d58;
*(uint16_t*)0x20000e22 = 0x83;
*(uint32_t*)0x20000e24 = 3;
*(uint32_t*)0x20000e28 = 0;
*(uint16_t*)0x20000e2c = 0;
*(uint16_t*)0x20000e2e = 0x49;
*(uint32_t*)0x20000e30 = 0;
*(uint32_t*)0x20000e34 = 0;
*(uint16_t*)0x20000e38 = 0;
*(uint16_t*)0x20000e3a = 6;
*(uint32_t*)0x20000e3c = 0;
*(uint32_t*)0x20000e40 = 0;
*(uint16_t*)0x20000e44 = 9;
*(uint16_t*)0x20000e46 = 0;
*(uint32_t*)0x20000e48 = 0;
*(uint32_t*)0x20000e4c = 0;
*(uint16_t*)0x20000e50 = 6;
*(uint16_t*)0x20000e52 = 0xdb;
*(uint32_t*)0x20000e54 = 0;
*(uint32_t*)0x20000e58 = 2;
*(uint16_t*)0x20000e5c = 0x20;
*(uint16_t*)0x20000e5e = 0;
*(uint32_t*)0x20000e60 = 0;
*(uint32_t*)0x20000e64 = 0;
*(uint16_t*)0x20000e68 = 0;
*(uint16_t*)0x20000e6a = 8;
*(uint32_t*)0x20000e6c = 0;
*(uint32_t*)0x20000e70 = 0;
*(uint16_t*)0x20000e74 = 0x2b5;
*(uint16_t*)0x20000e76 = 0;
*(uint32_t*)0x20000e78 = 0;
*(uint32_t*)0x20000e7c = 0x3f;
*(uint16_t*)0x20000e80 = 0;
*(uint16_t*)0x20000e82 = 0;
*(uint32_t*)0x20000e84 = 0;
*(uint32_t*)0x20000e88 = 0;
*(uint16_t*)0x20000e8c = 0x7ff;
*(uint16_t*)0x20000e8e = 0;
*(uint32_t*)0x20000e90 = 0;
*(uint32_t*)0x20000e94 = 0;
*(uint16_t*)0x20000e98 = 0x8000;
*(uint16_t*)0x20000e9a = 0;
*(uint32_t*)0x20000e9c = 0;
*(uint32_t*)0x20000ea0 = 0;
*(uint16_t*)0x20000ea4 = 0;
*(uint16_t*)0x20000ea6 = 0;
*(uint32_t*)0x20000ea8 = 0;
*(uint32_t*)0x20000eac = 0x101;
*(uint16_t*)0x20000eb0 = 0;
*(uint16_t*)0x20000eb2 = 0;
*(uint32_t*)0x20000eb4 = 0;
*(uint32_t*)0x20000eb8 = 0;
*(uint16_t*)0x20000ebc = 0;
*(uint16_t*)0x20000ebe = 0;
*(uint32_t*)0x20000ec0 = 1;
*(uint32_t*)0x20000ec4 = 1;
*(uint16_t*)0x20000ec8 = 1;
*(uint16_t*)0x20000eca = 0;
*(uint32_t*)0x20000ecc = 0;
*(uint32_t*)0x20000ed0 = 0;
*(uint16_t*)0x20000ed4 = 0;
*(uint16_t*)0x20000ed6 = 9;
*(uint32_t*)0x20000ed8 = 0;
*(uint32_t*)0x20000edc = 0;
*(uint16_t*)0x20000ee0 = 0;
*(uint16_t*)0x20000ee2 = 0x200;
*(uint32_t*)0x20000ee4 = 0;
*(uint32_t*)0x20000ee8 = 0;
*(uint16_t*)0x20000eec = 0;
*(uint16_t*)0x20000eee = 0xfff;
*(uint32_t*)0x20000ef0 = 0;
*(uint32_t*)0x20000ef4 = 0;
*(uint16_t*)0x20000ef8 = 0xfffa;
*(uint16_t*)0x20000efa = 0;
*(uint32_t*)0x20000efc = 0;
*(uint32_t*)0x20000f00 = 0;
*(uint16_t*)0x20000f04 = 0;
*(uint16_t*)0x20000f06 = 0;
*(uint32_t*)0x20000f08 = 2;
*(uint32_t*)0x20000f0c = 9;
*(uint16_t*)0x20000f10 = 0;
*(uint16_t*)0x20000f12 = -1;
*(uint32_t*)0x20000f14 = 0;
*(uint32_t*)0x20000f18 = 4;
*(uint16_t*)0x20000f1c = 0;
*(uint16_t*)0x20000f1e = 0;
*(uint32_t*)0x20000f20 = 1;
*(uint32_t*)0x20000f24 = 0;
*(uint16_t*)0x20000f28 = 0;
*(uint16_t*)0x20000f2a = 0;
*(uint32_t*)0x20000f2c = 0;
*(uint32_t*)0x20000f30 = 0;
*(uint16_t*)0x20000f34 = 8;
*(uint16_t*)0x20000f36 = 0;
*(uint32_t*)0x20000f38 = 0;
*(uint32_t*)0x20000f3c = 2;
*(uint16_t*)0x20000f40 = 0;
*(uint16_t*)0x20000f42 = 0;
*(uint32_t*)0x20000f44 = 2;
*(uint32_t*)0x20000f48 = 0x79f6;
*(uint16_t*)0x20000f4c = 0x254;
*(uint16_t*)0x20000f4e = 1;
*(uint32_t*)0x20000f50 = 0;
*(uint32_t*)0x20000f54 = 0;
*(uint8_t*)0x20000f58 = 0;
*(uint8_t*)0x20000f59 = 0;
*(uint16_t*)0x20000f5a = 0;
*(uint16_t*)0x20000f5c = 0;
*(uint16_t*)0x20000f5e = 0;
memcpy((void*)0x20000f60, "syz0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
memcpy((void*)0x20000f80, "\xc5\x72\xee\x01\x16\xf5\x92\x24\x88\x5a\xa3\x7d\xe3\x02\x88\x3c\x3a\xd7\x39\xe2\x8b\xea\x0b\x84\x24\x2e\xb7\x66\x41\x4c\x98\x71", 32);
memcpy((void*)0x20000fa0, "\x47\x38\xd6\x91\x5b\x97\x91\x13\x59\x10\x68\xe3\xda\x81\xbb\xb6\xa1\x8f\xf3\x44\x57\x3a\xe2\xd5\x69\x35\x7c\xfe\x51\x51\x62\x05", 32);
*(uint16_t*)0x20000fc0 = 0;
*(uint16_t*)0x20000fc2 = 0;
*(uint32_t*)0x20000fc4 = 0;
*(uint32_t*)0x20000fc8 = 0;
*(uint16_t*)0x20000fcc = 0;
*(uint16_t*)0x20000fce = 0;
*(uint32_t*)0x20000fd0 = 0;
*(uint32_t*)0x20000fd4 = 0;
*(uint16_t*)0x20000fd8 = 0x7ff;
*(uint16_t*)0x20000fda = 2;
*(uint32_t*)0x20000fdc = 0;
*(uint32_t*)0x20000fe0 = 0;
*(uint16_t*)0x20000fe4 = 0;
*(uint16_t*)0x20000fe6 = 3;
*(uint32_t*)0x20000fe8 = 3;
*(uint32_t*)0x20000fec = 6;
*(uint16_t*)0x20000ff0 = 0;
*(uint16_t*)0x20000ff2 = 0;
*(uint32_t*)0x20000ff4 = 0;
*(uint32_t*)0x20000ff8 = 0;
*(uint16_t*)0x20000ffc = 7;
*(uint16_t*)0x20000ffe = 1;
*(uint32_t*)0x20001000 = 2;
*(uint32_t*)0x20001004 = 6;
*(uint16_t*)0x20001008 = 0xc3;
*(uint16_t*)0x2000100a = 0;
*(uint32_t*)0x2000100c = 0;
*(uint32_t*)0x20001010 = 9;
*(uint16_t*)0x20001014 = 6;
*(uint16_t*)0x20001016 = 0x8001;
*(uint32_t*)0x20001018 = 0;
*(uint32_t*)0x2000101c = 0;
*(uint16_t*)0x20001020 = 0;
*(uint16_t*)0x20001022 = 0;
*(uint32_t*)0x20001024 = 0;
*(uint32_t*)0x20001028 = 0;
*(uint16_t*)0x2000102c = 0x3ff;
*(uint16_t*)0x2000102e = 0;
*(uint32_t*)0x20001030 = 1;
*(uint32_t*)0x20001034 = 0;
*(uint16_t*)0x20001038 = 0;
*(uint16_t*)0x2000103a = 0;
*(uint32_t*)0x2000103c = 0;
*(uint32_t*)0x20001040 = 0;
*(uint16_t*)0x20001044 = 0x401;
*(uint16_t*)0x20001046 = 5;
*(uint32_t*)0x20001048 = 0;
*(uint32_t*)0x2000104c = 0;
*(uint16_t*)0x20001050 = 0;
*(uint16_t*)0x20001052 = 0;
*(uint32_t*)0x20001054 = 0;
*(uint32_t*)0x20001058 = 0;
*(uint16_t*)0x2000105c = 0;
*(uint16_t*)0x2000105e = 0xb8;
*(uint32_t*)0x20001060 = 0;
*(uint32_t*)0x20001064 = 7;
*(uint16_t*)0x20001068 = 0;
*(uint16_t*)0x2000106a = 0;
*(uint32_t*)0x2000106c = 0;
*(uint32_t*)0x20001070 = 0;
*(uint16_t*)0x20001074 = 0;
*(uint16_t*)0x20001076 = 0;
*(uint32_t*)0x20001078 = 0;
*(uint32_t*)0x2000107c = 0;
*(uint16_t*)0x20001080 = 0;
*(uint16_t*)0x20001082 = 0;
*(uint32_t*)0x20001084 = 0;
*(uint32_t*)0x20001088 = 0;
*(uint16_t*)0x2000108c = 0;
*(uint16_t*)0x2000108e = 0;
*(uint32_t*)0x20001090 = 1;
*(uint32_t*)0x20001094 = 0;
*(uint16_t*)0x20001098 = 5;
*(uint16_t*)0x2000109a = 0;
*(uint32_t*)0x2000109c = 0;
*(uint32_t*)0x200010a0 = 0;
*(uint16_t*)0x200010a4 = 0;
*(uint16_t*)0x200010a6 = 0;
*(uint32_t*)0x200010a8 = 0;
*(uint32_t*)0x200010ac = 0;
*(uint16_t*)0x200010b0 = 0;
*(uint16_t*)0x200010b2 = 8;
*(uint32_t*)0x200010b4 = 0;
*(uint32_t*)0x200010b8 = 0x1000;
*(uint16_t*)0x200010bc = 8;
*(uint16_t*)0x200010be = 0;
*(uint32_t*)0x200010c0 = 1;
*(uint32_t*)0x200010c4 = 0;
*(uint16_t*)0x200010c8 = 0;
*(uint16_t*)0x200010ca = 0;
*(uint32_t*)0x200010cc = 0;
*(uint32_t*)0x200010d0 = 0;
*(uint16_t*)0x200010d4 = 0;
*(uint16_t*)0x200010d6 = 0;
*(uint32_t*)0x200010d8 = 0;
*(uint32_t*)0x200010dc = 0;
*(uint16_t*)0x200010e0 = 0;
*(uint16_t*)0x200010e2 = 0xff80;
*(uint32_t*)0x200010e4 = 0;
*(uint32_t*)0x200010e8 = 0;
*(uint16_t*)0x200010ec = 0;
*(uint16_t*)0x200010ee = 0;
*(uint32_t*)0x200010f0 = 0;
*(uint32_t*)0x200010f4 = 0;
*(uint16_t*)0x200010f8 = 5;
*(uint16_t*)0x200010fa = 0;
*(uint32_t*)0x200010fc = 2;
*(uint32_t*)0x20001100 = 0;
*(uint16_t*)0x20001104 = 0;
*(uint16_t*)0x20001106 = 0xa36;
*(uint32_t*)0x20001108 = 0;
*(uint32_t*)0x2000110c = 6;
*(uint16_t*)0x20001110 = 0;
*(uint16_t*)0x20001112 = 0;
*(uint32_t*)0x20001114 = 0;
*(uint32_t*)0x20001118 = 0;
*(uint16_t*)0x2000111c = 0xa70;
*(uint16_t*)0x2000111e = 0;
*(uint32_t*)0x20001120 = 3;
*(uint32_t*)0x20001124 = 0x4a;
*(uint16_t*)0x20001128 = 0x900;
*(uint16_t*)0x2000112a = 0;
*(uint32_t*)0x2000112c = 0;
*(uint32_t*)0x20001130 = 0;
*(uint16_t*)0x20001134 = 0;
*(uint16_t*)0x20001136 = 0;
*(uint32_t*)0x20001138 = 0;
*(uint32_t*)0x2000113c = 0;
*(uint16_t*)0x20001140 = 0;
*(uint16_t*)0x20001142 = 0;
*(uint32_t*)0x20001144 = 0;
*(uint32_t*)0x20001148 = 0;
*(uint16_t*)0x2000114c = 0;
*(uint16_t*)0x2000114e = 0;
*(uint32_t*)0x20001150 = 0;
*(uint32_t*)0x20001154 = 0;
*(uint16_t*)0x20001158 = 0;
*(uint16_t*)0x2000115a = 0;
*(uint32_t*)0x2000115c = 0;
*(uint32_t*)0x20001160 = 0;
*(uint16_t*)0x20001164 = 0;
*(uint16_t*)0x20001166 = 0xfc13;
*(uint32_t*)0x20001168 = 1;
*(uint32_t*)0x2000116c = 0x7f;
*(uint16_t*)0x20001170 = 0;
*(uint16_t*)0x20001172 = 0x3f;
*(uint32_t*)0x20001174 = 0;
*(uint32_t*)0x20001178 = 0;
*(uint16_t*)0x2000117c = 0;
*(uint16_t*)0x2000117e = 0;
*(uint32_t*)0x20001180 = 0;
*(uint32_t*)0x20001184 = 0;
*(uint16_t*)0x20001188 = 0x83;
*(uint16_t*)0x2000118a = 0;
*(uint32_t*)0x2000118c = 0;
*(uint32_t*)0x20001190 = 0;
*(uint16_t*)0x20001194 = 0x200;
*(uint16_t*)0x20001196 = 0;
*(uint32_t*)0x20001198 = 0;
*(uint32_t*)0x2000119c = 0;
*(uint64_t*)0x20001408 = 0x1060;
*(uint64_t*)0x20001458 = 1;
*(uint64_t*)0x20001460 = 0;
*(uint64_t*)0x20001468 = 0;
*(uint32_t*)0x20001470 = 0;
	syscall(__NR_sendmsg, r[0], 0x20001440ul, 0ul);
	return 0;
}
