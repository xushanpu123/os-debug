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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_io_setup, 0x8001, 0x20000040ul);
	syscall(__NR_io_setup, 6, 0ul);
*(uint64_t*)0x2007f000 = 0x3ff;
*(uint64_t*)0x2007f008 = 0;
*(uint64_t*)0x2007f010 = 0;
*(uint64_t*)0x2007f018 = 0;
*(uint64_t*)0x2007f020 = 0;
*(uint64_t*)0x2007f028 = 0;
*(uint64_t*)0x2007f030 = 0;
*(uint64_t*)0x2007f038 = 0;
*(uint64_t*)0x2007f040 = 0;
*(uint64_t*)0x2007f048 = 0;
*(uint64_t*)0x2007f050 = 0;
*(uint64_t*)0x2007f058 = 0;
*(uint64_t*)0x2007f060 = 0;
*(uint64_t*)0x2007f068 = 0;
*(uint64_t*)0x2007f070 = 0;
*(uint64_t*)0x2007f078 = 0;
*(uint64_t*)0x2007f080 = 0;
*(uint64_t*)0x2007f088 = 0;
*(uint64_t*)0x2007f090 = 0;
*(uint64_t*)0x2007f098 = 0;
*(uint64_t*)0x2007f0a0 = 0;
*(uint64_t*)0x2007f0a8 = 0;
*(uint64_t*)0x2007f0b0 = 0;
*(uint64_t*)0x2007f0b8 = 0;
*(uint64_t*)0x2007f0c0 = 0;
*(uint64_t*)0x2007f0c8 = 0;
*(uint64_t*)0x2007f0d0 = 0;
*(uint64_t*)0x2007f0d8 = 0;
*(uint64_t*)0x2007f0e0 = 0;
*(uint64_t*)0x2007f0e8 = 0;
*(uint64_t*)0x2007f0f0 = 0;
*(uint64_t*)0x2007f0f8 = 0;
*(uint64_t*)0x2007f100 = 0;
*(uint64_t*)0x2007f108 = 0;
*(uint64_t*)0x2007f110 = 0;
*(uint64_t*)0x2007f118 = 0;
*(uint64_t*)0x2007f120 = 0;
*(uint64_t*)0x2007f128 = 0;
*(uint64_t*)0x2007f130 = 0;
*(uint64_t*)0x2007f138 = 0;
*(uint64_t*)0x2007f140 = 0;
*(uint64_t*)0x2007f148 = 0;
*(uint64_t*)0x2007f150 = 0;
*(uint64_t*)0x2007f158 = 0;
*(uint64_t*)0x2007f160 = 0;
*(uint64_t*)0x2007f168 = 0;
*(uint64_t*)0x2007f170 = 0;
*(uint64_t*)0x2007f178 = 0;
*(uint64_t*)0x2007f180 = 0;
*(uint64_t*)0x2007f188 = 0;
*(uint64_t*)0x2007f190 = 0;
*(uint64_t*)0x2007f198 = 0;
*(uint64_t*)0x2007f1a0 = 0;
*(uint64_t*)0x2007f1a8 = 0;
*(uint64_t*)0x2007f1b0 = 0;
*(uint64_t*)0x2007f1b8 = 0;
*(uint64_t*)0x2007f1c0 = 0;
*(uint64_t*)0x2007f1c8 = 0;
*(uint64_t*)0x2007f1d0 = 0;
*(uint64_t*)0x2007f1d8 = 0;
*(uint64_t*)0x2007f1e0 = 0;
*(uint64_t*)0x2007f1e8 = 0;
*(uint64_t*)0x2007f1f0 = 0;
*(uint64_t*)0x2007f1f8 = 0;
*(uint64_t*)0x2007f200 = 0;
*(uint64_t*)0x2007f208 = 0;
*(uint64_t*)0x2007f210 = 0;
*(uint64_t*)0x2007f218 = 0;
*(uint64_t*)0x2007f220 = 0;
*(uint64_t*)0x2007f228 = 0;
*(uint64_t*)0x2007f230 = 0;
*(uint64_t*)0x2007f238 = 0;
*(uint64_t*)0x2007f240 = 0;
*(uint64_t*)0x2007f248 = 0;
*(uint64_t*)0x2007f250 = 0;
*(uint64_t*)0x2007f258 = 0;
*(uint64_t*)0x2007f260 = 0;
*(uint64_t*)0x2007f268 = 0;
*(uint64_t*)0x2007f270 = 0;
*(uint64_t*)0x2007f278 = 0;
*(uint64_t*)0x2007f280 = 0;
*(uint64_t*)0x2007f288 = 0;
*(uint64_t*)0x2007f290 = 0;
*(uint64_t*)0x2007f298 = 0;
*(uint64_t*)0x2007f2a0 = 0;
*(uint64_t*)0x2007f2a8 = 0;
*(uint64_t*)0x2007f2b0 = 0;
*(uint64_t*)0x2007f2b8 = 0;
*(uint64_t*)0x2007f2c0 = 0;
*(uint64_t*)0x2007f2c8 = 0;
*(uint64_t*)0x2007f2d0 = 0;
*(uint64_t*)0x2007f2d8 = 0;
*(uint64_t*)0x2007f2e0 = 0;
*(uint64_t*)0x2007f2e8 = 0;
*(uint64_t*)0x2007f2f0 = 0;
*(uint64_t*)0x2007f2f8 = 0;
*(uint64_t*)0x2007f300 = 0;
*(uint64_t*)0x2007f308 = 0;
*(uint64_t*)0x2007f310 = 0;
*(uint64_t*)0x2007f318 = 0;
*(uint64_t*)0x2007f320 = 0;
*(uint64_t*)0x2007f328 = 0;
*(uint64_t*)0x2007f330 = 0;
*(uint64_t*)0x2007f338 = 0;
*(uint64_t*)0x2007f340 = 0;
*(uint64_t*)0x2007f348 = 0;
*(uint64_t*)0x2007f350 = 0;
*(uint64_t*)0x2007f358 = 0;
*(uint64_t*)0x2007f360 = 0;
*(uint64_t*)0x2007f368 = 0;
*(uint64_t*)0x2007f370 = 0;
*(uint64_t*)0x2007f378 = 0;
*(uint64_t*)0x2007f380 = 0;
*(uint64_t*)0x2007f388 = 0;
*(uint64_t*)0x2007f390 = 0;
*(uint64_t*)0x2007f398 = 0;
*(uint64_t*)0x2007f3a0 = 0;
*(uint64_t*)0x2007f3a8 = 0;
*(uint64_t*)0x2007f3b0 = 0;
*(uint64_t*)0x2007f3b8 = 0;
*(uint64_t*)0x2007f3c0 = 0;
*(uint64_t*)0x2007f3c8 = 0;
*(uint64_t*)0x2007f3d0 = 0;
*(uint64_t*)0x2007f3d8 = 0;
*(uint64_t*)0x2007f3e0 = 0;
*(uint64_t*)0x2007f3e8 = 0;
*(uint64_t*)0x2007f3f0 = 0;
*(uint64_t*)0x2007f3f8 = 0;
*(uint64_t*)0x2007f400 = 0;
*(uint64_t*)0x2007f408 = 0;
*(uint64_t*)0x2007f410 = 0;
*(uint64_t*)0x2007f418 = 0;
*(uint64_t*)0x2007f420 = 0;
*(uint64_t*)0x2007f428 = 0;
*(uint64_t*)0x2007f430 = 0;
*(uint64_t*)0x2007f438 = 0;
*(uint64_t*)0x2007f440 = 0;
*(uint64_t*)0x2007f448 = 0;
*(uint64_t*)0x2007f450 = 0;
*(uint64_t*)0x2007f458 = 0;
*(uint64_t*)0x2007f460 = 0;
*(uint64_t*)0x2007f468 = 0;
*(uint64_t*)0x2007f470 = 0;
*(uint64_t*)0x2007f478 = 0;
*(uint64_t*)0x2007f480 = 0;
*(uint64_t*)0x2007f488 = 0;
*(uint64_t*)0x2007f490 = 0;
*(uint64_t*)0x2007f498 = 0;
*(uint64_t*)0x2007f4a0 = 0;
*(uint64_t*)0x2007f4a8 = 0;
*(uint64_t*)0x2007f4b0 = 0;
*(uint64_t*)0x2007f4b8 = 0;
*(uint64_t*)0x2007f4c0 = 0;
*(uint64_t*)0x2007f4c8 = 0;
*(uint64_t*)0x2007f4d0 = 0;
*(uint64_t*)0x2007f4d8 = 0;
*(uint64_t*)0x2007f4e0 = 0;
*(uint64_t*)0x2007f4e8 = 0;
*(uint64_t*)0x2007f4f0 = 0;
*(uint64_t*)0x2007f4f8 = 0;
*(uint64_t*)0x2007f500 = 0;
*(uint64_t*)0x2007f508 = 0;
*(uint64_t*)0x2007f510 = 0;
*(uint64_t*)0x2007f518 = 0;
*(uint64_t*)0x2007f520 = 0;
*(uint64_t*)0x2007f528 = 0;
*(uint64_t*)0x2007f530 = 0;
*(uint64_t*)0x2007f538 = 0;
*(uint64_t*)0x2007f540 = 0;
*(uint64_t*)0x2007f548 = 0;
*(uint64_t*)0x2007f550 = 0;
*(uint64_t*)0x2007f558 = 0;
*(uint64_t*)0x2007f560 = 0;
*(uint64_t*)0x2007f568 = 0;
*(uint64_t*)0x2007f570 = 0;
*(uint64_t*)0x2007f578 = 0;
*(uint64_t*)0x2007f580 = 0;
*(uint64_t*)0x2007f588 = 0;
*(uint64_t*)0x2007f590 = 0;
*(uint64_t*)0x2007f598 = 0;
*(uint64_t*)0x2007f5a0 = 0;
*(uint64_t*)0x2007f5a8 = 0;
*(uint64_t*)0x2007f5b0 = 0;
*(uint64_t*)0x2007f5b8 = 0;
*(uint64_t*)0x2007f5c0 = 0;
*(uint64_t*)0x2007f5c8 = 0;
*(uint64_t*)0x2007f5d0 = 0;
*(uint64_t*)0x2007f5d8 = 0;
*(uint64_t*)0x2007f5e0 = 0;
*(uint64_t*)0x2007f5e8 = 0;
*(uint64_t*)0x2007f5f0 = 0;
*(uint64_t*)0x2007f5f8 = 0;
*(uint64_t*)0x2007f600 = 0;
*(uint64_t*)0x2007f608 = 0;
*(uint64_t*)0x2007f610 = 0;
*(uint64_t*)0x2007f618 = 0;
*(uint64_t*)0x2007f620 = 0;
*(uint64_t*)0x2007f628 = 0;
*(uint64_t*)0x2007f630 = 0;
*(uint64_t*)0x2007f638 = 0;
*(uint64_t*)0x2007f640 = 0;
*(uint64_t*)0x2007f648 = 0;
*(uint64_t*)0x2007f650 = 0;
*(uint64_t*)0x2007f658 = 0;
*(uint64_t*)0x2007f660 = 0;
*(uint64_t*)0x2007f668 = 0;
*(uint64_t*)0x2007f670 = 0;
*(uint64_t*)0x2007f678 = 0;
*(uint64_t*)0x2007f680 = 0;
*(uint64_t*)0x2007f688 = 0;
*(uint64_t*)0x2007f690 = 0;
*(uint64_t*)0x2007f698 = 0;
*(uint64_t*)0x2007f6a0 = 0;
*(uint64_t*)0x2007f6a8 = 0;
*(uint64_t*)0x2007f6b0 = 0;
*(uint64_t*)0x2007f6b8 = 0;
*(uint64_t*)0x2007f6c0 = 0;
*(uint64_t*)0x2007f6c8 = 0;
*(uint64_t*)0x2007f6d0 = 0;
*(uint64_t*)0x2007f6d8 = 0;
*(uint64_t*)0x2007f6e0 = 0;
*(uint64_t*)0x2007f6e8 = 0;
*(uint64_t*)0x2007f6f0 = 0;
*(uint64_t*)0x2007f6f8 = 0;
*(uint64_t*)0x2007f700 = 0;
*(uint64_t*)0x2007f708 = 0;
*(uint64_t*)0x2007f710 = 0;
*(uint64_t*)0x2007f718 = 0;
*(uint64_t*)0x2007f720 = 0;
*(uint64_t*)0x2007f728 = 0;
*(uint64_t*)0x2007f730 = 0;
*(uint64_t*)0x2007f738 = 0;
*(uint64_t*)0x2007f740 = 0;
*(uint64_t*)0x2007f748 = 0;
*(uint64_t*)0x2007f750 = 0;
*(uint64_t*)0x2007f758 = 0;
*(uint64_t*)0x2007f760 = 0;
*(uint64_t*)0x2007f768 = 0;
*(uint64_t*)0x2007f770 = 0;
*(uint64_t*)0x2007f778 = 0;
*(uint64_t*)0x2007f780 = 0;
*(uint64_t*)0x2007f788 = 0;
*(uint64_t*)0x2007f790 = 0;
*(uint64_t*)0x2007f798 = 0;
*(uint64_t*)0x2007f7a0 = 0;
*(uint64_t*)0x2007f7a8 = 0;
*(uint64_t*)0x2007f7b0 = 0;
*(uint64_t*)0x2007f7b8 = 0;
*(uint64_t*)0x2007f7c0 = 0;
*(uint64_t*)0x2007f7c8 = 0;
*(uint64_t*)0x2007f7d0 = 0;
*(uint64_t*)0x2007f7d8 = 0;
*(uint64_t*)0x2007f7e0 = 0;
*(uint64_t*)0x2007f7e8 = 0;
*(uint64_t*)0x2007f7f0 = 0;
*(uint64_t*)0x2007f7f8 = 0;
*(uint64_t*)0x2007f800 = 0;
*(uint64_t*)0x2007f808 = 0;
*(uint64_t*)0x2007f810 = 0;
*(uint64_t*)0x2007f818 = 0;
*(uint64_t*)0x2007f820 = 0;
*(uint64_t*)0x2007f828 = 0;
*(uint64_t*)0x2007f830 = 0;
*(uint64_t*)0x2007f838 = 0;
*(uint64_t*)0x2007f840 = 0;
*(uint64_t*)0x2007f848 = 0;
*(uint64_t*)0x2007f850 = 0;
*(uint64_t*)0x2007f858 = 0;
*(uint64_t*)0x2007f860 = 0;
*(uint64_t*)0x2007f868 = 0;
*(uint64_t*)0x2007f870 = 0;
*(uint64_t*)0x2007f878 = 0;
*(uint64_t*)0x2007f880 = 0;
*(uint64_t*)0x2007f888 = 0;
*(uint64_t*)0x2007f890 = 0;
*(uint64_t*)0x2007f898 = 0;
*(uint64_t*)0x2007f8a0 = 0;
*(uint64_t*)0x2007f8a8 = 0;
*(uint64_t*)0x2007f8b0 = 0;
*(uint64_t*)0x2007f8b8 = 0;
*(uint64_t*)0x2007f8c0 = 0;
*(uint64_t*)0x2007f8c8 = 0;
*(uint64_t*)0x2007f8d0 = 0;
*(uint64_t*)0x2007f8d8 = 0;
*(uint64_t*)0x2007f8e0 = 0;
*(uint64_t*)0x2007f8e8 = 0;
*(uint64_t*)0x2007f8f0 = 0;
*(uint64_t*)0x2007f8f8 = 0;
*(uint64_t*)0x2007f900 = 0;
*(uint64_t*)0x2007f908 = 0;
*(uint64_t*)0x2007f910 = 0;
*(uint64_t*)0x2007f918 = 0;
*(uint64_t*)0x2007f920 = 0;
*(uint64_t*)0x2007f928 = 0;
*(uint64_t*)0x2007f930 = 0;
*(uint64_t*)0x2007f938 = 0;
*(uint64_t*)0x2007f940 = 0;
*(uint64_t*)0x2007f948 = 0;
*(uint64_t*)0x2007f950 = 0;
*(uint64_t*)0x2007f958 = 0;
*(uint64_t*)0x2007f960 = 0;
*(uint64_t*)0x2007f968 = 0;
*(uint64_t*)0x2007f970 = 0;
*(uint64_t*)0x2007f978 = 0;
*(uint64_t*)0x2007f980 = 0;
*(uint64_t*)0x2007f988 = 0;
*(uint64_t*)0x2007f990 = 0;
*(uint64_t*)0x2007f998 = 0;
*(uint64_t*)0x2007f9a0 = 0;
*(uint64_t*)0x2007f9a8 = 0;
*(uint64_t*)0x2007f9b0 = 0;
*(uint64_t*)0x2007f9b8 = 0;
*(uint64_t*)0x2007f9c0 = 0;
*(uint64_t*)0x2007f9c8 = 0;
*(uint64_t*)0x2007f9d0 = 0;
*(uint64_t*)0x2007f9d8 = 0;
*(uint64_t*)0x2007f9e0 = 0;
*(uint64_t*)0x2007f9e8 = 0;
*(uint64_t*)0x2007f9f0 = 0;
*(uint64_t*)0x2007f9f8 = 0;
*(uint64_t*)0x2007fa00 = 0;
*(uint64_t*)0x2007fa08 = 0;
*(uint64_t*)0x2007fa10 = 0;
*(uint64_t*)0x2007fa18 = 0;
*(uint64_t*)0x2007fa20 = 0;
*(uint64_t*)0x2007fa28 = 0;
*(uint64_t*)0x2007fa30 = 0;
*(uint64_t*)0x2007fa38 = 0;
*(uint64_t*)0x2007fa40 = 0;
*(uint64_t*)0x2007fa48 = 0;
*(uint64_t*)0x2007fa50 = 0;
*(uint64_t*)0x2007fa58 = 0;
*(uint64_t*)0x2007fa60 = 0;
*(uint64_t*)0x2007fa68 = 0;
*(uint64_t*)0x2007fa70 = 0;
*(uint64_t*)0x2007fa78 = 0;
*(uint64_t*)0x2007fa80 = 0;
*(uint64_t*)0x2007fa88 = 0;
*(uint64_t*)0x2007fa90 = 0;
*(uint64_t*)0x2007fa98 = 0;
*(uint64_t*)0x2007faa0 = 0;
*(uint64_t*)0x2007faa8 = 0;
*(uint64_t*)0x2007fab0 = 0;
*(uint64_t*)0x2007fab8 = 0;
*(uint64_t*)0x2007fac0 = 0;
*(uint64_t*)0x2007fac8 = 0;
*(uint64_t*)0x2007fad0 = 0;
*(uint64_t*)0x2007fad8 = 0;
*(uint64_t*)0x2007fae0 = 0;
*(uint64_t*)0x2007fae8 = 0;
*(uint64_t*)0x2007faf0 = 0;
*(uint64_t*)0x2007faf8 = 0;
*(uint64_t*)0x2007fb00 = 0;
*(uint64_t*)0x2007fb08 = 0;
*(uint64_t*)0x2007fb10 = 0;
*(uint64_t*)0x2007fb18 = 0;
*(uint64_t*)0x2007fb20 = 0;
*(uint64_t*)0x2007fb28 = 0;
*(uint64_t*)0x2007fb30 = 0;
*(uint64_t*)0x2007fb38 = 0;
*(uint64_t*)0x2007fb40 = 0;
*(uint64_t*)0x2007fb48 = 0;
*(uint64_t*)0x2007fb50 = 0;
*(uint64_t*)0x2007fb58 = 0;
*(uint64_t*)0x2007fb60 = 0;
*(uint64_t*)0x2007fb68 = 0;
*(uint64_t*)0x2007fb70 = 0;
*(uint64_t*)0x2007fb78 = 0;
*(uint64_t*)0x2007fb80 = 0;
*(uint64_t*)0x2007fb88 = 0;
*(uint64_t*)0x2007fb90 = 0;
*(uint64_t*)0x2007fb98 = 0;
*(uint64_t*)0x2007fba0 = 0;
*(uint64_t*)0x2007fba8 = 0;
*(uint64_t*)0x2007fbb0 = 0;
*(uint64_t*)0x2007fbb8 = 0;
*(uint64_t*)0x2007fbc0 = 0;
*(uint64_t*)0x2007fbc8 = 0;
*(uint64_t*)0x2007fbd0 = 0;
*(uint64_t*)0x2007fbd8 = 0;
*(uint64_t*)0x2007fbe0 = 0;
*(uint64_t*)0x2007fbe8 = 0;
*(uint64_t*)0x2007fbf0 = 0;
*(uint64_t*)0x2007fbf8 = 0;
*(uint64_t*)0x2007fc00 = 0;
*(uint64_t*)0x2007fc08 = 0;
*(uint64_t*)0x2007fc10 = 0;
*(uint64_t*)0x2007fc18 = 0;
*(uint64_t*)0x2007fc20 = 0;
*(uint64_t*)0x2007fc28 = 0;
*(uint64_t*)0x2007fc30 = 0;
*(uint64_t*)0x2007fc38 = 0;
*(uint64_t*)0x2007fc40 = 0;
*(uint64_t*)0x2007fc48 = 0;
*(uint64_t*)0x2007fc50 = 0;
*(uint64_t*)0x2007fc58 = 0;
*(uint64_t*)0x2007fc60 = 0;
*(uint64_t*)0x2007fc68 = 0;
*(uint64_t*)0x2007fc70 = 0;
*(uint64_t*)0x2007fc78 = 0;
*(uint64_t*)0x2007fc80 = 0;
*(uint64_t*)0x2007fc88 = 0;
*(uint64_t*)0x2007fc90 = 0;
*(uint64_t*)0x2007fc98 = 0;
*(uint64_t*)0x2007fca0 = 0;
*(uint64_t*)0x2007fca8 = 0;
*(uint64_t*)0x2007fcb0 = 0;
*(uint64_t*)0x2007fcb8 = 0;
*(uint64_t*)0x2007fcc0 = 0;
*(uint64_t*)0x2007fcc8 = 0;
*(uint64_t*)0x2007fcd0 = 0;
*(uint64_t*)0x2007fcd8 = 0;
*(uint64_t*)0x2007fce0 = 0;
*(uint64_t*)0x2007fce8 = 0;
*(uint64_t*)0x2007fcf0 = 0;
*(uint64_t*)0x2007fcf8 = 0;
*(uint64_t*)0x2007fd00 = 0;
*(uint64_t*)0x2007fd08 = 0;
*(uint64_t*)0x2007fd10 = 0;
*(uint64_t*)0x2007fd18 = 0;
*(uint64_t*)0x2007fd20 = 0;
*(uint64_t*)0x2007fd28 = 0;
*(uint64_t*)0x2007fd30 = 0;
*(uint64_t*)0x2007fd38 = 0;
*(uint64_t*)0x2007fd40 = 0;
*(uint64_t*)0x2007fd48 = 0;
*(uint64_t*)0x2007fd50 = 0;
*(uint64_t*)0x2007fd58 = 0;
*(uint64_t*)0x2007fd60 = 0;
*(uint64_t*)0x2007fd68 = 0;
*(uint64_t*)0x2007fd70 = 0;
*(uint64_t*)0x2007fd78 = 0;
*(uint64_t*)0x2007fd80 = 0;
*(uint64_t*)0x2007fd88 = 0;
*(uint64_t*)0x2007fd90 = 0;
*(uint64_t*)0x2007fd98 = 0;
*(uint64_t*)0x2007fda0 = 0;
*(uint64_t*)0x2007fda8 = 0;
*(uint64_t*)0x2007fdb0 = 0;
*(uint64_t*)0x2007fdb8 = 0;
*(uint64_t*)0x2007fdc0 = 0;
*(uint64_t*)0x2007fdc8 = 0;
*(uint64_t*)0x2007fdd0 = 0;
*(uint64_t*)0x2007fdd8 = 0;
*(uint64_t*)0x2007fde0 = 0;
*(uint64_t*)0x2007fde8 = 0;
*(uint64_t*)0x2007fdf0 = 0;
*(uint64_t*)0x2007fdf8 = 0;
*(uint64_t*)0x2007fe00 = 0;
*(uint64_t*)0x2007fe08 = 0;
*(uint64_t*)0x2007fe10 = 0;
*(uint64_t*)0x2007fe18 = 0;
*(uint64_t*)0x2007fe20 = 0;
*(uint64_t*)0x2007fe28 = 0;
*(uint64_t*)0x2007fe30 = 0;
*(uint64_t*)0x2007fe38 = 0;
*(uint64_t*)0x2007fe40 = 0;
*(uint64_t*)0x2007fe48 = 0;
*(uint64_t*)0x2007fe50 = 0;
*(uint64_t*)0x2007fe58 = 0;
*(uint64_t*)0x2007fe60 = 0;
*(uint64_t*)0x2007fe68 = 0;
*(uint64_t*)0x2007fe70 = 0;
*(uint64_t*)0x2007fe78 = 0;
*(uint64_t*)0x2007fe80 = 0;
*(uint64_t*)0x2007fe88 = 0;
*(uint64_t*)0x2007fe90 = 0;
*(uint64_t*)0x2007fe98 = 0;
*(uint64_t*)0x2007fea0 = 0;
*(uint64_t*)0x2007fea8 = 0;
*(uint64_t*)0x2007feb0 = 0;
*(uint64_t*)0x2007feb8 = 0;
*(uint64_t*)0x2007fec0 = 0;
*(uint64_t*)0x2007fec8 = 0;
*(uint64_t*)0x2007fed0 = 0;
*(uint64_t*)0x2007fed8 = 0;
*(uint64_t*)0x2007fee0 = 0;
*(uint64_t*)0x2007fee8 = 0;
*(uint64_t*)0x2007fef0 = 0;
*(uint64_t*)0x2007fef8 = 0;
*(uint64_t*)0x2007ff00 = 0;
*(uint64_t*)0x2007ff08 = 0;
*(uint64_t*)0x2007ff10 = 0;
*(uint64_t*)0x2007ff18 = 0;
*(uint64_t*)0x2007ff20 = 0;
*(uint64_t*)0x2007ff28 = 0;
*(uint64_t*)0x2007ff30 = 0;
*(uint64_t*)0x2007ff38 = 0;
*(uint64_t*)0x2007ff40 = 0;
*(uint64_t*)0x2007ff48 = 0;
*(uint64_t*)0x2007ff50 = 0;
*(uint64_t*)0x2007ff58 = 0;
*(uint64_t*)0x2007ff60 = 0;
*(uint64_t*)0x2007ff68 = 0;
*(uint64_t*)0x2007ff70 = 0;
*(uint64_t*)0x2007ff78 = 0;
*(uint64_t*)0x2007ff80 = 0;
*(uint64_t*)0x2007ff88 = 0;
*(uint64_t*)0x2007ff90 = 0;
*(uint64_t*)0x2007ff98 = 0;
*(uint64_t*)0x2007ffa0 = 0;
*(uint64_t*)0x2007ffa8 = 0;
*(uint64_t*)0x2007ffb0 = 0;
*(uint64_t*)0x2007ffb8 = 0;
*(uint64_t*)0x2007ffc0 = 0;
*(uint64_t*)0x2007ffc8 = 0;
*(uint64_t*)0x2007ffd0 = 0;
*(uint64_t*)0x2007ffd8 = 0;
*(uint64_t*)0x2007ffe0 = 0;
*(uint64_t*)0x2007ffe8 = 0;
*(uint64_t*)0x2007fff0 = 0;
*(uint8_t*)0x2007fff8 = 0x7f;
memcpy((void*)0x2007fff9, "\xaf\xa2\x6f\x83\x64\xe2\x21", 7);
	syscall(__NR_ioctl, -1, 0xd000943d, 0x2007f000ul);
	syscall(__NR_io_getevents, 0ul, 0ul, 0ul, 0ul, 0ul);
	res = syscall(__NR_io_setup, 0, 0x20000480ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000480;
	syscall(__NR_io_getevents, r[0], 0ul, 0ul, 0ul, 0ul);
	return 0;
}
