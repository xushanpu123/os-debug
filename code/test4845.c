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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000540 = 0x200004c0;
*(uint16_t*)0x200004c0 = 0x10;
*(uint16_t*)0x200004c2 = 0;
*(uint32_t*)0x200004c4 = 0;
*(uint32_t*)0x200004c8 = 0x100;
*(uint32_t*)0x20000548 = 0xc;
*(uint64_t*)0x20000550 = 0x20000500;
*(uint64_t*)0x20000500 = 0x20001100;
*(uint32_t*)0x20001100 = 0xec4;
*(uint16_t*)0x20001104 = 0;
*(uint16_t*)0x20001106 = 0;
*(uint32_t*)0x20001108 = 0;
*(uint32_t*)0x2000110c = 0;
*(uint8_t*)0x20001110 = 0xe;
*(uint8_t*)0x20001111 = 0;
*(uint16_t*)0x20001112 = 0;
*(uint16_t*)0x20001114 = 8;
*(uint16_t*)0x20001116 = 3;
*(uint32_t*)0x20001118 = 0;
*(uint16_t*)0x2000111c = 0xa4;
STORE_BY_BITMASK(uint16_t, , 0x2000111e, 0x10e, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000111f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000111f, 1, 7, 1);
*(uint16_t*)0x20001120 = 0x9d;
*(uint16_t*)0x20001122 = 3;
memcpy((void*)0x20001124, "\xf3\xe9\x57\x43\x9a\xab\xd6\x08\xcf\xbe\x5c\xf5\x30\xf8\x0d\xe3\x50\x9c\x0d\xfd\x47\xbc\xc9\x22\xcb\x38\x74\xac\x70\xb4\xab\xf4\x31\x6b\xa9\xed\x44\xc3\xd5\xc3\xb5\x75\x8c\xf9\xe1\xf4\x55\x4f\xef\x35\x68\xd6\xe0\xcc\x7e\x7f\xe2\x67\x97\xdb\xed\x76\x9c\x0e\x27\xab\xd4\x14\xd9\x8b\x76\x8a\xe5\x2c\xcf\xe0\xf3\xee\x0d\x83\x0b\xa1\x4c\x3e\x34\x74\x29\x1c\x3e\x3c\xcf\x32\x26\x7a\x12\xcf\xee\x7c\xcd\x0c\xcd\x25\x13\x9c\x57\x4c\x42\x87\xa1\x4c\xfd\x1e\xb4\xec\x95\x5b\x87\x99\x59\xd8\xdb\x31\x61\x60\xac\x63\x61\x91\x73\xe7\x59\x17\x91\xa1\x70\x44\x63\x6d\xe2\x9f\x37\x13\x6b\xa3\x54\x99\x86\xea\xbf\x15\x2f\x5d\x4e", 153);
*(uint16_t*)0x200011c0 = 0x141;
*(uint16_t*)0x200011c2 = 0x80;
*(uint8_t*)0x200011c4 = 0x65;
*(uint8_t*)0x200011c5 = 0x12;
*(uint8_t*)0x200011c6 = 8;
*(uint8_t*)0x200011c7 = 2;
*(uint8_t*)0x200011c8 = 0x11;
*(uint8_t*)0x200011c9 = 0;
*(uint8_t*)0x200011ca = 0;
*(uint8_t*)0x200011cb = 1;
*(uint8_t*)0x200011cc = 8;
*(uint8_t*)0x200011cd = 2;
*(uint8_t*)0x200011ce = 0x11;
*(uint8_t*)0x200011cf = 0;
*(uint8_t*)0x200011d0 = 0;
*(uint8_t*)0x200011d1 = 0;
memset((void*)0x200011d2, 255, 6);
*(uint8_t*)0x200011d8 = 0x75;
*(uint8_t*)0x200011d9 = 6;
*(uint16_t*)0x200011da = 0;
*(uint16_t*)0x200011dc = 0;
*(uint16_t*)0x200011de = 0;
*(uint8_t*)0x200011e0 = 0x37;
*(uint8_t*)0x200011e1 = 0xce;
*(uint8_t*)0x200011e2 = 0;
*(uint8_t*)0x200011e3 = 5;
memcpy((void*)0x200011e4, "\x63\x7e\x28\xf8\xe4\x4f\x4c\x31\xb6\xe6\x9e\x71\xe9\x2e\xfb\x17", 16);
memcpy((void*)0x200011f4, "\x47\xf8\xf5\xb0\x2f\x31\x9b\x69\x52\xad\xed\xd9\xf3\xbc\x2a\x03\xde\xf8\x2b\x4d\x01\x1e\xf3\xc8\x91\x2d\x00\x3f\xbd\xa6\xc9\xba", 32);
memcpy((void*)0x20001214, "\xb6\xbd\xe7\xe6\xd6\xf4\xea\x57\xa7\xf9\x4b\x44\xe6\xa8\x0e\x79\x07\xd7\x2a\xe1\x45\xe6\x9a\xdc\x82\x34\xfc\x79\x90\x4c\x54\x18", 32);
*(uint8_t*)0x20001234 = 0;
*(uint8_t*)0x20001235 = 0x26;
memcpy((void*)0x20001236, "\x8d\xdf\x63\x12\xc5\xfe\x5c\x2e\x8c\xe3\x53\x02\xee\x65\xaf\xbb\x19\xf1\x7d\x6c\x63\x48\x57\x9f\xa7\x19\x3e\x13\x3f\xa5\x59\x47\x5d\x96\xff\x11\x5a\xdd", 38);
*(uint8_t*)0x2000125c = 0;
*(uint8_t*)0x2000125d = 0x10;
memcpy((void*)0x2000125e, "\x86\x6f\xde\x2b\x5f\x4b\x91\x57\xfb\x47\x91\x6f\xce\x3a\x4e\x51", 16);
*(uint8_t*)0x2000126e = 0;
*(uint8_t*)0x2000126f = 0x23;
memcpy((void*)0x20001270, "\x74\xc0\xab\x43\x46\xf9\x3c\x4f\x09\xdb\xcb\x7d\x6f\x59\x24\xa3\xc7\xde\x00\x3c\x06\x97\xff\x37\x25\x66\x8d\xc9\x68\x9e\xca\x41\x69\xbb\xdb", 35);
*(uint8_t*)0x20001293 = 0;
*(uint8_t*)0x20001294 = 0x18;
memcpy((void*)0x20001295, "\x5d\xaf\xfa\xfa\xcb\x78\x23\x43\x5f\xfc\xf0\x2c\x16\xec\x88\x93\x02\xa3\x93\xf6\x8e\xf7\x1d\x00", 24);
*(uint8_t*)0x200012ad = 0;
*(uint8_t*)0x200012ae = 1;
memset((void*)0x200012af, 166, 1);
*(uint8_t*)0x200012b0 = 3;
*(uint8_t*)0x200012b1 = 1;
*(uint8_t*)0x200012b2 = 0;
*(uint8_t*)0x200012b3 = 0x82;
*(uint8_t*)0x200012b4 = 0x4c;
STORE_BY_BITMASK(uint8_t, , 0x200012b5, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012b5, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012b5, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012b5, 0, 3, 3);
STORE_BY_BITMASK(uint8_t, , 0x200012b5, 1, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012b5, 0, 7, 1);
*(uint8_t*)0x200012b6 = 0;
*(uint8_t*)0x200012b7 = 0;
*(uint32_t*)0x200012b8 = 0;
memset((void*)0x200012bc, 255, 6);
*(uint32_t*)0x200012c2 = 0;
*(uint8_t*)0x200012c6 = 8;
*(uint8_t*)0x200012c7 = 2;
*(uint8_t*)0x200012c8 = 0x11;
*(uint8_t*)0x200012c9 = 0;
*(uint8_t*)0x200012ca = 0;
*(uint8_t*)0x200012cb = 1;
*(uint32_t*)0x200012cc = 0;
*(uint32_t*)0x200012d0 = 0;
*(uint8_t*)0x200012d4 = 4;
STORE_BY_BITMASK(uint8_t, , 0x200012d5, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012d5, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012d5, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012d5, 0, 3, 5);
*(uint8_t*)0x200012d6 = 8;
*(uint8_t*)0x200012d7 = 2;
*(uint8_t*)0x200012d8 = 0x11;
*(uint8_t*)0x200012d9 = 0;
*(uint8_t*)0x200012da = 0;
*(uint8_t*)0x200012db = 0;
*(uint32_t*)0x200012dc = 0;
STORE_BY_BITMASK(uint8_t, , 0x200012e0, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012e0, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012e0, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012e0, 0, 3, 5);
*(uint8_t*)0x200012e1 = 8;
*(uint8_t*)0x200012e2 = 2;
*(uint8_t*)0x200012e3 = 0x11;
*(uint8_t*)0x200012e4 = 0;
*(uint8_t*)0x200012e5 = 0;
*(uint8_t*)0x200012e6 = 0;
*(uint32_t*)0x200012e7 = 0;
STORE_BY_BITMASK(uint8_t, , 0x200012eb, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012eb, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012eb, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012eb, 0, 3, 5);
*(uint8_t*)0x200012ec = 8;
*(uint8_t*)0x200012ed = 2;
*(uint8_t*)0x200012ee = 0x11;
*(uint8_t*)0x200012ef = 0;
*(uint8_t*)0x200012f0 = 0;
*(uint8_t*)0x200012f1 = 0;
*(uint32_t*)0x200012f2 = 0;
STORE_BY_BITMASK(uint8_t, , 0x200012f6, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012f6, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012f6, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x200012f6, 0, 3, 5);
*(uint8_t*)0x200012f7 = 8;
*(uint8_t*)0x200012f8 = 2;
*(uint8_t*)0x200012f9 = 0x11;
*(uint8_t*)0x200012fa = 0;
*(uint8_t*)0x200012fb = 0;
*(uint8_t*)0x200012fc = 1;
*(uint32_t*)0x200012fd = 0;
*(uint16_t*)0x20001304 = 0x4f9;
*(uint16_t*)0x20001306 = 0xe;
STORE_BY_BITMASK(uint8_t, , 0x20001308, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001308, 0, 2, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001308, 8, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 3, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 4, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 5, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001309, 1, 7, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000130a, 0, 0, 15);
STORE_BY_BITMASK(uint16_t, , 0x2000130b, 0, 7, 1);
*(uint8_t*)0x2000130c = 8;
*(uint8_t*)0x2000130d = 2;
*(uint8_t*)0x2000130e = 0x11;
*(uint8_t*)0x2000130f = 0;
*(uint8_t*)0x20001310 = 0;
*(uint8_t*)0x20001311 = 0;
memset((void*)0x20001312, 255, 6);
memset((void*)0x20001318, 255, 6);
STORE_BY_BITMASK(uint16_t, , 0x2000131e, 0, 0, 4);
STORE_BY_BITMASK(uint16_t, , 0x2000131e, 0, 4, 12);
STORE_BY_BITMASK(uint16_t, , 0x20001320, 0, 0, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001320, 0, 1, 15);
STORE_BY_BITMASK(uint8_t, , 0x20001322, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001322, 0, 2, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001322, 0, 4, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001322, 0, 6, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001323, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001323, 0, 1, 5);
STORE_BY_BITMASK(uint8_t, , 0x20001323, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001323, 0, 7, 1);
*(uint64_t*)0x20001324 = 0;
*(uint16_t*)0x2000132c = 0x64;
*(uint16_t*)0x2000132e = 0;
*(uint8_t*)0x20001330 = 3;
*(uint8_t*)0x20001331 = 1;
*(uint8_t*)0x20001332 = 0;
*(uint8_t*)0x20001333 = 6;
*(uint8_t*)0x20001334 = 2;
*(uint16_t*)0x20001335 = 0;
*(uint8_t*)0x20001337 = 5;
*(uint8_t*)0x20001338 = 0xc9;
*(uint8_t*)0x20001339 = 0;
*(uint8_t*)0x2000133a = 0;
*(uint8_t*)0x2000133b = 0;
memcpy((void*)0x2000133c, "\x7a\xdd\x14\x86\x4a\x6c\xe2\xc1\xc6\x74\x59\x53\xfc\x33\xce\x23\x9a\xc7\xa4\x63\xe6\xd8\xeb\x35\x77\x6c\x36\xe2\x77\x66\xf7\xcf\xaf\xde\xa7\xfc\x37\x05\x11\x9a\x0f\xd6\x39\x3d\x1f\xbb\x6c\x48\xd4\x1c\x0e\x71\xe4\xbe\xf4\x5a\xdf\x68\x18\xe0\x3e\xb2\x18\x48\xa2\x31\xb7\x90\xb5\xf8\x56\x21\x22\x87\x32\x64\xbe\xdd\x73\x9b\xdc\x41\xf4\xf8\x4f\x1b\xef\xa8\x27\xad\xe5\x75\x46\xce\xb2\x45\x67\xda\x85\x66\x18\xe7\xe3\x86\x1e\x53\x78\xef\xeb\x97\x20\xe9\x7f\x14\x95\x3b\xd1\x84\x02\x70\x5f\x3a\xe0\xf3\xdf\xf3\xb8\x74\x69\x73\xed\x48\xd3\x02\xf2\xcc\x6a\x61\xba\x13\xf3\xc8\x27\xf2\xaa\x8f\xa2\x1e\x37\xd8\x5e\xa6\x5c\x33\x31\x6b\x1b\x4d\xa1\x83\xe4\x41\xe5\xac\xf9\xa7\xfd\x52\x57\xe8\x0e\x28\x32\xb4\x79\x85\xbe\x9f\x82\x1c\x9f\x06\x9a\x4f\x3f\xa2\x3a\xe7\x3f\xd7\xfa\x66\xe5\x79\xca\xe2\xdf\xac", 198);
*(uint8_t*)0x20001402 = 0x25;
*(uint8_t*)0x20001403 = 3;
*(uint8_t*)0x20001404 = 0;
*(uint8_t*)0x20001405 = 0;
*(uint8_t*)0x20001406 = 0;
*(uint8_t*)0x20001407 = 0x2a;
*(uint8_t*)0x20001408 = 1;
STORE_BY_BITMASK(uint8_t, , 0x20001409, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001409, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001409, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001409, 0, 3, 5);
*(uint8_t*)0x2000140a = 0x71;
*(uint8_t*)0x2000140b = 7;
*(uint8_t*)0x2000140c = 0;
*(uint8_t*)0x2000140d = 0;
*(uint8_t*)0x2000140e = 0;
*(uint8_t*)0x2000140f = 0;
*(uint8_t*)0x20001410 = 0;
*(uint8_t*)0x20001411 = 0;
*(uint8_t*)0x20001412 = 0;
*(uint8_t*)0x20001413 = 0x76;
*(uint8_t*)0x20001414 = 6;
*(uint8_t*)0x20001415 = 0;
*(uint8_t*)0x20001416 = 0;
*(uint16_t*)0x20001417 = 0;
*(uint16_t*)0x20001419 = 0;
*(uint8_t*)0x2000141b = 0xdd;
*(uint8_t*)0x2000141c = 0x85;
memcpy((void*)0x2000141d, "\xdd\x47\xf1\x50\x80\x2a\xf9\x6f\x95\xc3\x4b\x3b\xd8\x3e\xdb\x47\xc1\x33\x31\xfd\x76\x89\x1d\xb3\x3f\x72\x5a\x64\x8a\x10\x0b\xfd\x67\x43\x6b\x0b\xf0\xc3\x76\xfa\xcf\x35\x9b\xf0\xce\xe7\x35\xed\xc4\x52\xab\x9c\x1d\x78\x29\xa9\xab\xdc\x7d\x29\x9a\x9e\xd2\xbb\xee\x50\x51\xd9\x83\x24\xb6\xc5\x29\x8f\xb4\xda\xd5\xeb\xdb\x8e\x34\x31\xb9\x63\x42\xff\xa4\x84\x97\x8a\x16\x22\x99\xab\x69\x52\x9b\x2e\x59\x9a\x5e\xcf\x6d\x28\x26\xe3\x17\xd4\x11\x3f\xba\x9d\x72\xb2\x01\xaf\xad\x63\x92\xf9\x0e\x23\x61\xef\x29\xd4\xc9\x84\x37\x11\xdd\x86\x59", 133);
*(uint8_t*)0x200014a2 = 0xdd;
*(uint8_t*)0x200014a3 = 0xb2;
memcpy((void*)0x200014a4, "\x78\xad\x62\x1d\x24\x76\x10\x6b\x86\x8a\xff\xd0\x48\x7a\x3b\x43\xb4\xfd\xb3\xfc\x97\xad\xbb\x7e\x6e\xeb\x9b\x52\x45\xaf\x51\xc8\xd7\xe6\x82\x85\x31\xca\x3b\xad\xa1\xc7\x47\xd4\xa0\x50\x73\x53\x2f\xa0\xb5\x39\xed\xc6\x86\x19\x14\xc0\x8c\xf5\x29\x38\x35\x53\x0c\xb8\x42\x57\x56\x86\xf1\x16\x60\x31\x15\x36\x3e\xf9\xcc\x1a\xec\x7c\xf7\xcf\x00\x16\x50\x73\xfa\x68\xe5\x7b\x8a\x5b\xce\xd2\x9c\x82\x5c\x58\xc1\x41\xa3\xf9\x43\x0d\xf9\x8c\xc8\xe1\x92\xef\x4e\xc4\xaa\x16\xfb\x2a\x8f\x4f\xc7\xa6\xf9\x4d\xbc\xdf\x0f\x54\x4b\xf2\xcb\xa2\x9f\x9b\xb5\x15\xf6\xab\x6b\x8c\x18\x24\x8e\xdf\x47\x80\xf9\xc2\xa8\x0e\x21\x53\xad\xb8\x02\xe1\xdc\x1d\x86\x54\xb8\x51\x0c\x69\x3b\xc3\x4d\x2a\xb9\xd3\x8b\x40\x28\xff\x34\x5b\xb9\xc4", 178);
*(uint8_t*)0x20001556 = 0xdd;
*(uint8_t*)0x20001557 = 0x3c;
memcpy((void*)0x20001558, "\xe6\xc7\x74\x9f\xdc\x9b\x4e\xcd\xd4\x09\xde\xa2\x02\xfd\x9f\xb1\xcd\x02\x90\x99\x61\xec\x2d\x1b\x77\x1d\x06\xe0\x19\x37\xdc\x87\xbb\x61\x22\x5c\xe7\x76\x20\x3e\xc7\x65\xbd\x6b\x7a\x10\x34\x76\x12\x9b\x54\xe9\xbb\x17\xd8\xaf\xf4\x0b\x3e\xad", 60);
*(uint8_t*)0x20001594 = 0xdd;
*(uint8_t*)0x20001595 = 0x97;
memcpy((void*)0x20001596, "\x0f\xf2\x32\x9a\x91\x2b\x26\x6b\x22\x9a\xab\x65\xfc\x01\xf0\xcb\x50\xe3\xe7\xbc\x4d\x5f\x04\x87\x15\xfb\xc1\x02\xb3\xd6\x54\xbf\x50\x55\xe2\x2c\xb9\x27\x0d\xe4\x12\x2e\x26\x35\xea\xb2\x4f\x0b\xe5\xa5\xd5\xee\x33\xe7\x70\x5a\xf2\xc7\xcb\xf1\xce\x72\x36\xc1\x28\x6c\xb1\x7b\x85\x9c\x2e\x2d\x4e\x6a\x32\x53\xff\x7c\xf8\x5b\xe5\x9e\xc2\xfe\xf4\x05\xc3\x56\x6f\xd3\x61\xb5\x60\xcd\xd5\x2e\x91\x5a\x05\xd4\xb3\x24\x92\x5d\x09\x26\x04\x8e\xb6\x49\x08\xea\x44\x7b\x95\xc2\x11\x34\xf0\x15\xba\x2b\xfc\x78\xda\x7c\xd5\x6d\xe2\x7b\x3d\x07\x4a\x04\x94\x23\x39\x60\x41\x47\x61\x25\x59\x15\xcd\x53\x8d\x61\x51\xe8\x7f", 151);
*(uint8_t*)0x2000162d = 0xdd;
*(uint8_t*)0x2000162e = 0x9f;
memcpy((void*)0x2000162f, "\x2a\xbc\x05\x45\x9f\xf6\x06\xde\x36\x71\xcd\x05\x92\xdf\x06\x74\xdf\xdf\x30\x34\x5d\x8c\xea\x0f\x3f\xcf\x43\x37\xf3\x31\x8d\xab\xf1\x9a\x78\x46\xf6\xaa\x1c\xa4\xf2\x19\x40\x92\x40\x5c\x27\x81\x41\xe1\x0a\x72\x8c\xfb\x00\x83\x8d\xd1\x1c\x72\xbb\x66\xd6\xd8\xb3\x19\xe8\x7e\x2d\x40\x01\xca\x90\xe0\xd8\x8b\xb2\x6c\x58\x14\xe6\xb2\xc9\x2c\x54\x0f\x1b\x63\x02\x22\x56\x8e\xe4\xec\xaa\x5b\x7b\xa4\x2f\xc5\xdf\x9b\x45\x81\x10\x02\x98\x55\xc6\x08\x9c\x26\xee\xdb\x74\x48\x19\x22\x5e\x45\xdf\xf6\xed\x3c\xc7\x44\xe3\x4b\x44\x57\x42\x79\x2b\x8a\x6a\x23\x9f\xd5\x0d\x9e\x38\x87\xab\xcc\xc0\xeb\x92\x68\xb0\x29\xab\x2c\xe3\x17\x5d\x72\x8b\x4f\xe3", 159);
*(uint8_t*)0x200016ce = 0xdd;
*(uint8_t*)0x200016cf = 0x41;
memcpy((void*)0x200016d0, "\xbf\x00\xd4\xe9\xb7\x4f\xf8\x71\x1c\x8c\x82\xcf\x29\x5f\xef\xf1\xd5\xe6\x47\x48\x00\xe2\x09\x24\x2d\x87\x4b\xdb\x90\xe0\x63\x41\x77\x60\x6c\x21\x30\xae\x23\xfa\x10\xd1\x8b\x1d\xf9\x3b\xae\xd9\x63\xc3\xea\xf9\xa5\xa2\xc5\x8b\x5e\xb2\xf4\xdb\xd8\x45\x69\xb9\x8c", 65);
*(uint8_t*)0x20001711 = 0xdd;
*(uint8_t*)0x20001712 = 0xea;
memcpy((void*)0x20001713, "\x97\x00\xfa\x03\xad\xac\x86\x35\xc4\x0c\xf4\xd4\x5e\x5c\x02\x06\x38\x1e\x29\xdf\xce\x92\xd8\x34\x73\xad\xb3\x70\xe7\x16\x5f\x46\xdc\x54\x6d\xa2\x22\xde\xdd\xa9\x89\x94\xed\x37\x74\x47\x9c\xf5\x7c\xf7\xf4\x97\xa3\xe3\x3b\xd0\xd8\xd2\x8e\xcb\x5c\x28\x04\x5d\xa3\x3b\x82\x3a\x37\x28\xb2\x7d\x8d\x5c\x7d\x8d\x1c\xd4\x9f\xb7\xeb\xc0\x9e\x36\x27\x3a\x1e\x08\x3d\xb9\x71\x8f\xa6\xb5\x89\x87\x26\x90\xd2\x55\x78\x15\xbf\x77\x45\xe6\x2d\xff\x0b\xb4\x20\xcd\xdc\xb6\xdf\x87\x8c\x43\x17\xcb\x91\xe7\xf3\x2e\x32\xc3\xef\xfc\x1e\x3c\xb6\xb0\xdb\x59\x70\xc0\x0a\x31\xb0\x33\xf6\x3c\x2f\x1a\x5e\x92\xab\xca\xd6\x23\x95\xef\x07\xd0\x82\xa7\x9f\x03\xc2\x72\x08\x26\xb9\x7f\xd2\x88\x8a\x95\x18\xed\x2a\xe6\x5a\x40\x19\xdc\x58\x6c\xb4\x38\x37\xf9\xcc\x54\xfe\xc9\xd2\xa1\x04\xca\x45\x38\xe4\x0c\x4f\x40\xfe\xd4\x93\xc9\x17\x48\x74\x1e\x38\xd0\x35\x4b\xfc\x52\xa4\xe1\x2c\x34\x65\x31\xc4\x35\x9d\x9c\x1a\x29\x5d\x57\x3b\x32\x7d\x9a\x4f\x54\xf2\x6e\x76\x3c", 234);
*(uint16_t*)0x20001800 = 0xa1;
*(uint16_t*)0x20001802 = 0x80;
*(uint8_t*)0x20001804 = 0x84;
*(uint8_t*)0x20001805 = 0x95;
*(uint8_t*)0x20001806 = 0;
*(uint8_t*)0x20001807 = 9;
STORE_BY_BITMASK(uint8_t, , 0x20001808, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x20001808, 1, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001808, 0, 7, 1);
*(uint8_t*)0x20001809 = 8;
*(uint8_t*)0x2000180a = 2;
*(uint8_t*)0x2000180b = 0x11;
*(uint8_t*)0x2000180c = 0;
*(uint8_t*)0x2000180d = 0;
*(uint8_t*)0x2000180e = 1;
*(uint32_t*)0x2000180f = 0;
*(uint8_t*)0x20001813 = 8;
*(uint8_t*)0x20001814 = 2;
*(uint8_t*)0x20001815 = 0x11;
*(uint8_t*)0x20001816 = 0;
*(uint8_t*)0x20001817 = 0;
*(uint8_t*)0x20001818 = 0;
*(uint16_t*)0x20001819 = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000181b, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x2000181b, 1, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000181b, 0, 7, 1);
*(uint8_t*)0x2000181c = 8;
*(uint8_t*)0x2000181d = 2;
*(uint8_t*)0x2000181e = 0x11;
*(uint8_t*)0x2000181f = 0;
*(uint8_t*)0x20001820 = 0;
*(uint8_t*)0x20001821 = 0;
*(uint32_t*)0x20001822 = 0;
*(uint8_t*)0x20001826 = 8;
*(uint8_t*)0x20001827 = 2;
*(uint8_t*)0x20001828 = 0x11;
*(uint8_t*)0x20001829 = 0;
*(uint8_t*)0x2000182a = 0;
*(uint8_t*)0x2000182b = 0;
*(uint16_t*)0x2000182c = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000182e, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x2000182e, 1, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000182e, 0, 7, 1);
*(uint8_t*)0x2000182f = 8;
*(uint8_t*)0x20001830 = 2;
*(uint8_t*)0x20001831 = 0x11;
*(uint8_t*)0x20001832 = 0;
*(uint8_t*)0x20001833 = 0;
*(uint8_t*)0x20001834 = 0;
*(uint32_t*)0x20001835 = 0;
memset((void*)0x20001839, 255, 6);
*(uint16_t*)0x2000183f = 0;
STORE_BY_BITMASK(uint8_t, , 0x20001841, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x20001841, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001841, 0, 7, 1);
memset((void*)0x20001842, 255, 6);
*(uint32_t*)0x20001848 = 0;
*(uint16_t*)0x2000184c = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000184e, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x2000184e, 1, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000184e, 0, 7, 1);
*(uint8_t*)0x2000184f = 8;
*(uint8_t*)0x20001850 = 2;
*(uint8_t*)0x20001851 = 0x11;
*(uint8_t*)0x20001852 = 0;
*(uint8_t*)0x20001853 = 0;
*(uint8_t*)0x20001854 = 0;
*(uint32_t*)0x20001855 = 0;
memset((void*)0x20001859, 255, 6);
*(uint16_t*)0x2000185f = 0;
STORE_BY_BITMASK(uint8_t, , 0x20001861, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x20001861, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001861, 0, 7, 1);
memset((void*)0x20001862, 255, 6);
*(uint32_t*)0x20001868 = 0;
*(uint16_t*)0x2000186c = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000186e, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x2000186e, 1, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000186e, 0, 7, 1);
*(uint8_t*)0x2000186f = 8;
*(uint8_t*)0x20001870 = 2;
*(uint8_t*)0x20001871 = 0x11;
*(uint8_t*)0x20001872 = 0;
*(uint8_t*)0x20001873 = 0;
*(uint8_t*)0x20001874 = 1;
*(uint32_t*)0x20001875 = 0;
memset((void*)0x20001879, 255, 6);
*(uint16_t*)0x2000187f = 0;
STORE_BY_BITMASK(uint8_t, , 0x20001881, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x20001881, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001881, 0, 7, 1);
memset((void*)0x20001882, 255, 6);
*(uint32_t*)0x20001888 = 0;
*(uint16_t*)0x2000188c = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000188e, 0, 0, 6);
STORE_BY_BITMASK(uint8_t, , 0x2000188e, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000188e, 0, 7, 1);
memset((void*)0x2000188f, 255, 6);
*(uint32_t*)0x20001895 = 0;
*(uint16_t*)0x20001899 = 0;
*(uint8_t*)0x2000189b = 0x68;
*(uint8_t*)0x2000189c = 4;
*(uint16_t*)0x2000189d = 0;
*(uint16_t*)0x2000189f = 0;
*(uint16_t*)0x200018a4 = 0x209;
*(uint16_t*)0x200018a6 = 0xf;
*(uint8_t*)0x200018a8 = 0x8c;
*(uint8_t*)0x200018a9 = 0x18;
*(uint16_t*)0x200018aa = 0;
memcpy((void*)0x200018ac, "\x96\xf8\xd5\xf2\x8d\xee", 6);
memcpy((void*)0x200018b2, "\x12\x65\x88\x81\x1b\xa6\xe8\x4d\x8c\xc3\xe9\x65\x25\x68\xe5\x7b", 16);
*(uint8_t*)0x200018c2 = 0x76;
*(uint8_t*)0x200018c3 = 6;
*(uint8_t*)0x200018c4 = 0;
*(uint8_t*)0x200018c5 = 0;
*(uint16_t*)0x200018c6 = 0;
*(uint16_t*)0x200018c8 = 0;
*(uint8_t*)0x200018ca = 0x2d;
*(uint8_t*)0x200018cb = 0x1a;
*(uint16_t*)0x200018cc = 0;
STORE_BY_BITMASK(uint8_t, , 0x200018ce, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200018ce, 0, 2, 3);
STORE_BY_BITMASK(uint8_t, , 0x200018ce, 0, 5, 3);
*(uint64_t*)0x200018cf = 0;
STORE_BY_BITMASK(uint64_t, , 0x200018d7, 0, 0, 13);
STORE_BY_BITMASK(uint64_t, , 0x200018d8, 0, 5, 3);
STORE_BY_BITMASK(uint64_t, , 0x200018d9, 0, 0, 10);
STORE_BY_BITMASK(uint64_t, , 0x200018da, 0, 2, 6);
STORE_BY_BITMASK(uint64_t, , 0x200018db, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200018db, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200018db, 0, 2, 2);
STORE_BY_BITMASK(uint64_t, , 0x200018db, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200018db, 0, 5, 27);
*(uint16_t*)0x200018df = 0;
*(uint32_t*)0x200018e1 = 0;
*(uint8_t*)0x200018e5 = 0;
*(uint8_t*)0x200018e6 = 0x26;
*(uint8_t*)0x200018e7 = 0xca;
*(uint8_t*)0x200018e8 = 0;
*(uint8_t*)0x200018e9 = 0;
*(uint8_t*)0x200018ea = 0;
memcpy((void*)0x200018eb, "\x35\xc7\xd8\x50\x07\x03\xe7\x79\x14\x59\x01\xa2\xf3\x08\x9a\x62\x33\x32\x03\x2e\x88\x2c\xc4\xad\x11\xef\x43\x1b\xd1\x15\x0d\x2a\x5a\xaf\x11\x19\x8b\x60\x96\xed\xaf\x5a\x04\xaa\x49\xd4\x3d\xab\x41\xf6\x5d\x01\x79\x9d\x5d\x33\xb4\x0c\xf8\x7b\xa0\x5c\x08\x96\x7c\x13\xf0\xd1\x05\x1d\xef\xe8\xea\x13\x46\xa8\xab\x48\x55\x14\x03\x1a\xa1\xef\xb3\xfd\xa7\x16\x79\xe1\xa0\x26\x1f\x9f\xaa\xcc\x91\xc8\xef\xfb\xf0\xcf\x3b\x22\x4b\x67\xed\xf3\x14\x8e\x99\x44\x22\x99\x4b\x17\x5a\xe9\x8a\xe7\xfe\x19\xa4\xd2\x0c\x5d\x86\xd3\x27\x7b\x1f\xbe\x77\xe2\xd8\x58\x42\xa4\xb3\x25\x53\xc8\xeb\x70\xea\xb1\x05\x34\x47\x9b\xcb\x12\xc6\x86\x55\x5d\xd2\x86\x70\xd9\xd0\xdb\xb4\xf6\x0c\x5c\x13\xae\x5f\xbc\x54\xf9\x9d\x52\x98\x0b\xfe\x3f\xa3\xcb\x6f\xd6\xc6\xe3\xe0\x13\x32\xca\x0e\x78\xd7\x2b\x60\xcd\xe2\x45\xd1\xda\x5a", 199);
*(uint8_t*)0x200019b2 = 5;
*(uint8_t*)0x200019b3 = 0xf6;
*(uint8_t*)0x200019b4 = 0;
*(uint8_t*)0x200019b5 = 0;
*(uint8_t*)0x200019b6 = 0;
memcpy((void*)0x200019b7, "\x4a\x4a\x03\x94\xde\x23\x72\xdb\xe7\x9a\xce\x40\x7a\xab\x9a\x0f\x99\xc5\x3a\xb7\x73\x9c\x01\x85\x08\xd3\xc2\x31\xda\xf5\x0b\x8b\x8b\xc2\x7e\x20\x20\x0c\x40\x1f\x9e\xb2\x66\x76\x88\x9b\xfc\x07\xe5\x19\x51\x8a\x16\x5f\x1b\x27\x35\x4f\x8c\x4d\x63\x2a\xe0\x40\x15\x07\xba\x5e\x78\xf3\x77\x8d\xd3\x1b\xea\xc6\x8e\x74\x64\x93\x2b\x92\xa2\xa0\x94\xc0\x97\xf1\xb6\x1a\x18\x06\xb5\x01\xc9\x24\x86\x4a\x18\x37\x02\x28\xca\x48\x6f\x5a\x90\x76\x60\xa4\xc9\xd2\x37\x6b\x65\x39\x0a\x84\x93\x3b\x39\x8f\x77\x07\xd0\xdc\xc8\x5c\x58\x2b\x47\xfd\xa9\xfd\xfb\x37\x67\x1f\xda\xfe\x4b\xac\x60\xef\x10\xef\xa8\xec\x47\x65\x02\xd2\x0e\xe6\xd8\x52\x14\x50\x87\x5e\xb0\xc7\x2c\x11\x22\x08\x6c\x5f\x06\xf5\xa1\x2e\x41\x94\xd9\x40\x9b\xd7\xfb\xd3\x47\xc1\x8e\x84\xd4\x88\x3d\x78\xb5\x8c\x57\x0d\xfb\x8e\xd9\x45\xec\x28\x69\x50\xd1\x15\xa4\xea\xce\x10\xbd\x71\xad\x01\x70\xfa\x33\xfc\xf7\xf3\xf9\xf4\x66\xd2\x80\x76\x3e\xaf\x95\x60\x57\xaa\x4c\x7f\xd9\x88\x3c\x10\xc8\x3a\xff\x40\xd0\xc7\x60\xf2\x1b", 243);
*(uint8_t*)0x20001aaa = 0x10;
*(uint8_t*)0x20001aab = 1;
*(uint8_t*)0x20001aac = 0;
*(uint16_t*)0x20001ab0 = 0x109;
*(uint16_t*)0x20001ab2 = 0x7f;
*(uint8_t*)0x20001ab4 = 0x26;
*(uint8_t*)0x20001ab5 = 0xf4;
*(uint8_t*)0x20001ab6 = 0;
*(uint8_t*)0x20001ab7 = 0;
*(uint8_t*)0x20001ab8 = 0;
memcpy((void*)0x20001ab9, "\x33\x51\x21\xa2\x0d\xd8\x00\x50\x7f\x4a\xdc\x48\x03\x74\x70\x34\xad\x6a\x5c\x42\x7f\xc2\xc4\x2e\x66\xaf\xd5\xbe\x0d\x77\x06\x58\xcf\xd3\x5c\x57\xff\x7d\x21\xf7\x64\x76\x88\x6c\xcf\x48\xc3\x82\x34\x7b\xf4\xee\x76\xb4\xfe\xef\x09\x20\xd6\x3d\x98\xd3\xd7\xf6\xac\xa6\xd7\x87\x86\x13\x92\x40\xf4\x91\x96\x59\xd5\x45\xc1\x94\xc5\x41\xcc\x86\xff\x53\x6b\x74\xd6\xd5\x41\x0a\x41\x8f\x50\x02\x88\xf7\x43\xbd\x95\xb8\x79\x47\x45\x11\x49\x0a\x33\xa7\xf1\x44\xe7\x74\x00\x40\x4b\x6c\x8c\x40\x92\x5e\x80\xe4\x36\xc9\xff\x4b\x34\xe1\x60\xdd\x2f\xfe\x66\xef\x4b\x9f\xab\x5c\x9c\xa4\x0a\xe1\x04\xb5\x16\xa2\x15\x13\xec\x99\x47\x6f\x3f\xc3\xaa\x8c\x08\xf9\x9c\x69\xbd\x63\xfe\xc9\x61\x7f\x92\xff\x61\xf6\xa1\xd1\xbb\x3b\x33\x04\x69\xc3\xd4\x7e\x56\xda\xa5\x2d\x61\x9f\xa0\x9e\xb5\xa6\xd6\x2f\x5a\xf0\x43\x0a\x40\x85\x13\x4c\x00\x48\xf2\x5d\x97\xcd\xa1\x1a\xc7\xc5\xc5\xe6\xef\xe9\xc3\xa2\xf5\xcc\xdd\x2c\xa2\xa9\xee\xf1\xee\x6f\x19\x25\xa0\x96\xfa\x52\x22\xfd\x5a\x75\x99\x6d\x4f", 241);
*(uint8_t*)0x20001baa = 0x72;
*(uint8_t*)0x20001bab = 6;
memset((void*)0x20001bac, 3, 6);
*(uint8_t*)0x20001bb2 = 0x2a;
*(uint8_t*)0x20001bb3 = 1;
STORE_BY_BITMASK(uint8_t, , 0x20001bb4, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bb4, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bb4, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bb4, 0, 3, 5);
*(uint8_t*)0x20001bb5 = 6;
*(uint8_t*)0x20001bb6 = 2;
*(uint16_t*)0x20001bb7 = 0;
*(uint16_t*)0x20001bbc = 0x1cd;
*(uint16_t*)0x20001bbe = 0xe;
STORE_BY_BITMASK(uint8_t, , 0x20001bc0, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001bc0, 0, 2, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001bc0, 8, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 3, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 4, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 5, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bc1, 0, 7, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001bc2, 0, 0, 15);
STORE_BY_BITMASK(uint16_t, , 0x20001bc3, 0, 7, 1);
memset((void*)0x20001bc4, 255, 6);
memset((void*)0x20001bca, 255, 6);
memset((void*)0x20001bd0, 80, 6);
STORE_BY_BITMASK(uint16_t, , 0x20001bd6, 0, 0, 4);
STORE_BY_BITMASK(uint16_t, , 0x20001bd6, 0, 4, 12);
*(uint64_t*)0x20001bd8 = 0;
*(uint16_t*)0x20001be0 = 0;
*(uint16_t*)0x20001be2 = 0;
*(uint8_t*)0x20001be4 = 1;
*(uint8_t*)0x20001be5 = 4;
STORE_BY_BITMASK(uint8_t, , 0x20001be6, 0, 0, 7);
STORE_BY_BITMASK(uint8_t, , 0x20001be6, 0, 7, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001be7, 0, 0, 7);
STORE_BY_BITMASK(uint8_t, , 0x20001be7, 0, 7, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001be8, 0, 0, 7);
STORE_BY_BITMASK(uint8_t, , 0x20001be8, 0, 7, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001be9, 0, 0, 7);
STORE_BY_BITMASK(uint8_t, , 0x20001be9, 0, 7, 1);
*(uint8_t*)0x20001bea = 3;
*(uint8_t*)0x20001beb = 1;
*(uint8_t*)0x20001bec = 0;
*(uint8_t*)0x20001bed = 6;
*(uint8_t*)0x20001bee = 2;
*(uint16_t*)0x20001bef = 0;
*(uint8_t*)0x20001bf1 = 0x25;
*(uint8_t*)0x20001bf2 = 3;
*(uint8_t*)0x20001bf3 = 0;
*(uint8_t*)0x20001bf4 = 0;
*(uint8_t*)0x20001bf5 = 0;
*(uint8_t*)0x20001bf6 = 0x2a;
*(uint8_t*)0x20001bf7 = 1;
STORE_BY_BITMASK(uint8_t, , 0x20001bf8, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bf8, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bf8, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001bf8, 0, 3, 5);
*(uint8_t*)0x20001bf9 = 0x2d;
*(uint8_t*)0x20001bfa = 0x1a;
*(uint16_t*)0x20001bfb = 0;
STORE_BY_BITMASK(uint8_t, , 0x20001bfd, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001bfd, 0, 2, 3);
STORE_BY_BITMASK(uint8_t, , 0x20001bfd, 0, 5, 3);
*(uint64_t*)0x20001bfe = 0;
STORE_BY_BITMASK(uint64_t, , 0x20001c06, 0, 0, 13);
STORE_BY_BITMASK(uint64_t, , 0x20001c07, 0, 5, 3);
STORE_BY_BITMASK(uint64_t, , 0x20001c08, 0, 0, 10);
STORE_BY_BITMASK(uint64_t, , 0x20001c09, 0, 2, 6);
STORE_BY_BITMASK(uint64_t, , 0x20001c0a, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20001c0a, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20001c0a, 0, 2, 2);
STORE_BY_BITMASK(uint64_t, , 0x20001c0a, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20001c0a, 0, 5, 27);
*(uint16_t*)0x20001c0e = 0;
*(uint32_t*)0x20001c10 = 0;
*(uint8_t*)0x20001c14 = 0;
*(uint8_t*)0x20001c15 = 0x72;
*(uint8_t*)0x20001c16 = 6;
memset((void*)0x20001c17, 3, 6);
*(uint8_t*)0x20001c1d = 0x71;
*(uint8_t*)0x20001c1e = 7;
*(uint8_t*)0x20001c1f = 0;
*(uint8_t*)0x20001c20 = 0;
*(uint8_t*)0x20001c21 = 0;
*(uint8_t*)0x20001c22 = 0;
*(uint8_t*)0x20001c23 = 0;
*(uint8_t*)0x20001c24 = 0;
*(uint8_t*)0x20001c25 = 0;
*(uint8_t*)0x20001c26 = 0xdd;
*(uint8_t*)0x20001c27 = 0xc7;
memcpy((void*)0x20001c28, "\x2c\xab\x5d\xb7\x3f\xa6\xd9\xa3\xb9\x67\xa8\x7b\x5e\x90\xd0\x36\x8c\xde\x7c\x6f\xd7\xc5\x9c\x25\x21\xa2\x7e\x00\x03\x01\xfe\x2b\xcf\x56\x45\x3a\x7d\x8f\xd5\x9b\xf5\xbe\xc3\xec\x4a\xd0\x66\x70\xc4\x39\x64\x32\x21\x34\xfd\x42\x7e\x60\x81\x34\x5b\xeb\xfd\x44\x0e\xe2\x4c\x32\xea\x56\xb2\x5c\xfc\xef\x4e\x1f\x75\x01\x00\x40\x05\xd9\xe1\x06\xb2\x99\x39\x33\x5f\x18\x75\x5c\x27\x3f\x24\xb5\x69\x03\x40\xfd\xd6\xd2\xba\x1c\x24\x96\x75\x7e\xd3\x69\x8b\x4f\xa0\x2c\x61\x5a\x40\xf3\xfc\x44\xfd\xde\x04\x5d\x5c\x54\x8e\x99\x75\xbb\x2e\xbb\x95\x06\x42\xe4\x51\xf5\xd0\x8b\x94\xdd\x84\x6d\x14\x37\x7b\x9c\x9d\x09\x33\x88\x90\x38\x78\x75\xf9\x23\x30\x9f\xad\x41\x26\x32\x88\xcd\xfa\x32\x80\x99\xaa\x5a\x38\x9a\x67\x5e\x90\x0a\xda\x8b\x92\xd2\x6d\xbb\xf5\x43\x5e\x41\x42\xbf\xa7\x95\xb8\x06\xf6\xcd\x4d\xf6\xc6", 199);
*(uint8_t*)0x20001cef = 0xdd;
*(uint8_t*)0x20001cf0 = 0x75;
memcpy((void*)0x20001cf1, "\xa2\x70\x66\x09\xd6\x60\x7a\xd8\xd5\xfa\xe7\x64\x8f\x43\xa7\xb7\xa6\x42\xde\x75\x84\x55\x2e\xa9\x90\x02\xc7\xd9\x17\xa0\x82\xff\x5c\xc3\x8a\xa4\x3e\xb0\x6c\xb7\x54\xe3\x4d\x93\xed\x3c\x76\x5f\xcd\x19\x9b\x90\xde\x20\xf8\x2d\x67\x89\x3c\x51\x92\x20\x4b\xf5\x57\x9f\xaa\x99\xf0\x70\x6a\xc0\xa4\x9a\xbb\x97\x14\xe7\x2a\xfe\xdd\x03\xfd\x82\x1e\x04\x3b\xb9\x71\x32\x42\x18\x07\xb0\xf7\xc8\xa2\x3c\x25\xe6\xc4\xf1\xfd\x8e\x7d\xe3\x4e\xf3\x2c\x7c\x73\xc4\x35\xab\x3d\x6f\x35", 117);
*(uint8_t*)0x20001d66 = 0xdd;
*(uint8_t*)0x20001d67 = 0x21;
memcpy((void*)0x20001d68, "\x48\x04\x63\x03\x53\xd9\xcd\x09\x2b\xcb\x97\xc9\x98\x5e\xc5\x7e\x1e\x7d\x9b\x59\x62\xaf\xa7\x35\xcd\x1c\x2b\x7d\x27\x2e\xe6\xb5\xa4", 33);
*(uint16_t*)0x20001d8c = 0x235;
*(uint16_t*)0x20001d8e = 0x91;
memcpy((void*)0x20001d90, "\x1b\xf8\x3a\x5b\xa9\x04\x73\x37\xb0\x86\x0f\xef\x93\xfe\xeb\x22\x69\x91\xe7\x54\x25\xa4\xdd\x96\xb5\xc2\x80\x8c\xc4\xb6\xee\xaa\xb3\xdc\xc8\x5f\x6e\xde\x4f\x4f\xcf\x3f\xac\x5d\x3d\xf0\x66\xea\x6a\x7e\x1f\x60\x0c\x89\x0d\x10\xa8\x85\x84\xce\xe0\x54\xba\x2f\xca\xff\x21\x67\x47\x21\x95\xa0\xe4\x51\xfb\x60\x0a\x1c\xa7\xbe\x22\xa8\x59\x46\xa8\x35\x3f\x07\x14\x04\x87\x8b\x9c\x6a\x5f\x76\x70\xb4\x69\xec\xe9\xc3\x18\x17\xff\x58\x05\x50\x43\x06\xc1\x56\xb3\x6c\x08\x3a\xd6\x9e\x9c\x52\xca\x53\x25\x75\x58\x5e\xff\xb8\xb1\x00\x11\xfe\x8f\xc6\x1a\x6a\x90\x8c\x40\xbd\x25\xac\xe1\x19\x62\x78\xd5\x0e\x8f\x1b\x29\x58\xa9\x89\x9a\x62\xb2\x02\x3f\xc7\x5e\x82\x80\xab\x35\x98\x16\x7e\x87\x01\xb8\x77\x1e\xab\xfc\xf6\x96\x79\x85\x21\x4f\x26\x50\x97\xc9\xdc\x86\x56\x50\xda\x9f\xfe\xc3\x2c\xe7\xbb\xb6\x75\x72\x3f\x26\xd5\xaf\x74\x4a\x64\x7f\x2e\xa3\xe4\xdc\xd4\x1c\x15\x69\x37\xc3\x80\x96\xcc\x05\xb4\xfd\x77\x21\x37\x73\x51\xaf\x19\xb3\x10\x1f\xce\xef\xa2\xd7\xa4\x06\x79\x36\x03\xed\xfa\x86\xc5\x0a\x23\x35\x5e\x23\x75\xfc\x1b\x16\x50\xb1\x2b\xad\xfb\xb3\xb4\x0d\x63\x25\x7c\xf3\x38\xa5\x0d\xab\xd4\x09\x1e\xf9\x38\x86\x79\x5a\xb9\x72\x2d\x16\xe5\x8b\x88\xbc\xaf\x0e\xb4\x62\x4d\xc4\xe9\xde\x42\xc8\xd6\xf7\x7e\xce\x43\x17\x70\xde\x0f\xc7\xc5\xa3\x7d\xc0\x9b\x82\xba\x95\x5e\xba\x39\xdf\xb5\x09\xdf\x7f\x20\xa1\x11\x63\xee\x17\x5a\x1e\xbd\x01\x3f\x6c\x2f\x8c\xf1\x3f\x46\x1c\xb0\x25\xd6\x9e\xbb\x23\xb6\x7d\x2e\xb2\x1d\x3d\xf6\x11\xe4\x96\x48\x61\xa0\x61\x54\xf8\x84\xcf\x9a\x48\x64\xd4\xcc\x08\xf7\x86\x5f\x7e\x47\xd3\x94\x5e\x48\x34\x95\xfb\x91\xe2\x47\x4a\x8c\xa7\xea\xd6\x17\xee\x67\x5d\x58\xfd\xe9\x97\x78\x2e\xaa\x24\x41\x9d\x3d\x07\x41\x9c\x19\x59\x3b\xef\xa6\x46\x8b\x73\x9b\x12\x3c\x6c\x1f\x25\x04\xe3\x3c\x5c\x07\x1e\xa8\x46\x9e\x09\xa0\x41\x27\x40\xed\x9e\x0d\x4c\xd5\xf8\x7f\x7e\x8c\xde\x9f\x67\xfc\x82\x5b\x81\xc9\xfe\x26\x91\xb0\x40\x16\x9a\xf7\x91\x46\x41\xa2\xa1\x6b\x11\xe4\x1e\x03\x41\xed\xae\xc6\x15\xcd\x63\xdb\xf1\x2d\x88\x1a\x84\x89\xcc\xbe\x1a\x10\x13\x84\x08\x7b\x13\xcb\x90\xbc\xc7\x52\x72\xa7\x46\x1b\x9a\x5c\x1f\x82\xc3\x23\x9a\x5d\x18\xe1\x9c\xde\x6b\xf0\x85\xae\xbd\xf1\xf5\x37\x5c\x27\x1a\xf3\x54\xae\xad\xcb\xff\xee\x6d\x7f\x95\x67\x94\xfa\xe8\x9c\xd5\x4d\x11\x2e\x04\xbe\x2a\x84\x08\xd7\x9c\xc0\x21\x42\x61\xff\x4d\xf2\x5a", 561);
*(uint64_t*)0x20000508 = 0xec4;
*(uint64_t*)0x20000558 = 1;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint32_t*)0x20000570 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000540ul, 0ul);
	return 0;
}
