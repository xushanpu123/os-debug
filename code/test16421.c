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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0x20000340;
*(uint64_t*)0x20000340 = 0x20000a40;
*(uint32_t*)0x20000a40 = 0x14;
*(uint16_t*)0x20000a44 = 0x10;
*(uint16_t*)0x20000a46 = 1;
*(uint32_t*)0x20000a48 = 0;
*(uint32_t*)0x20000a4c = 0;
*(uint8_t*)0x20000a50 = 0;
*(uint8_t*)0x20000a51 = 0;
*(uint16_t*)0x20000a52 = htobe16(0xa);
*(uint32_t*)0x20000a54 = 0x3c0;
*(uint8_t*)0x20000a58 = 2;
*(uint8_t*)0x20000a59 = 0xa;
*(uint16_t*)0x20000a5a = 0;
*(uint32_t*)0x20000a5c = 0;
*(uint32_t*)0x20000a60 = 0;
*(uint8_t*)0x20000a64 = 0;
*(uint8_t*)0x20000a65 = 0;
*(uint16_t*)0x20000a66 = htobe16(0);
*(uint16_t*)0x20000a68 = 0xf1;
*(uint16_t*)0x20000a6a = 6;
memcpy((void*)0x20000a6c, "\x5c\xfd\xab\x9c\x1f\xeb\x1c\x3d\x9a\xba\x7f\x34\x9f\x3c\x5c\xdf\x87\xbd\x5e\xba\x1f\x2b\x45\xb9\xc9\x9f\x90\x9b\x08\x9a\x5c\x3f\xde\x01\x14\x44\xaf\x86\xbd\xc5\xfa\xb8\xfe\x2f\x8a\x11\xab\x00\xb9\x9e\xe4\x67\x84\x72\x50\x1d\x6f\x53\x11\x4d\x0b\x89\x35\x2b\x90\x1c\x18\x7c\x56\xdb\x65\xd3\xaf\x1e\xc0\x84\x65\xed\x65\x2a\xe4\x98\x6b\x9c\x4f\xf3\xc0\xcd\xce\xdf\xa8\x23\x34\x6c\x1c\x0a\x68\x2b\x94\x06\xbf\xee\x7a\x4c\x7c\x13\x94\x25\xc3\x02\x3f\xf6\xdb\x41\x64\x97\xd6\x26\x54\xb2\xa2\xf7\x45\xe9\x67\x05\xf6\xfb\xfc\x7d\x73\x15\x4f\x7d\xc7\x54\x12\x83\x2f\xfa\x65\x21\x3b\x7f\x12\x5c\xb6\x9b\x81\xd7\x40\xd7\xb4\x50\xb7\xb1\x45\x01\x51\x7c\xa3\x67\xf2\x1b\xc7\xcf\xf1\x93\x14\xb6\x4b\x23\xa2\xb7\x41\x6f\x3d\xe5\xb1\x6e\xd6\x04\xff\x8a\x47\x37\x08\x0d\x3c\xea\x6b\xe8\xe0\x11\x9a\x8c\x95\xdc\xfd\x65\x5e\x38\x66\xf5\x82\xdd\x92\x31\xb1\x10\xe9\x83\xb4\xbb\xf3\xa9\xda\x53\x08\xff\xd7\x86\xc5\xb3\xdb\x77\xe0\xeb\xe1\x06\xf4\x40\xfc\xb5\x52\x70\xd2", 237);
*(uint16_t*)0x20000b5c = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000b5e, 4, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000b5f, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000b5f, 0, 7, 1);
*(uint64_t*)0x20000b60 = htobe64(0);
*(uint16_t*)0x20000b68 = 0xe5;
*(uint16_t*)0x20000b6a = 6;
memcpy((void*)0x20000b6c, "\x8c\x3c\x86\xa0\x4e\x55\x16\xf2\xcd\x16\xb5\x55\x14\x86\x60\x08\x1d\x53\xbc\xa6\x4d\x5c\x07\x94\xac\x50\xc9\xd4\x77\xa9\xe6\x30\xfe\x5b\xb8\x2f\x8f\xbe\xca\xc7\xc1\xca\x88\xa0\xf3\x96\x30\x2c\xc9\x63\xa5\x45\x27\x46\x91\xd9\xee\x4d\x3d\xe2\xc4\x52\x95\xa7\x69\x6e\x16\xfa\x96\xad\xf8\x96\x46\x9c\x1b\x6c\xc4\xa8\x2a\x22\xbb\x29\xa2\x7a\xf1\xaf\xe4\xd9\x72\xaa\xab\x3d\xc8\xb5\x93\x8a\x0b\xc4\xc0\xe4\x96\xd8\x66\x78\x9f\x05\x9f\x84\x40\x60\x45\xc2\x17\x98\x0c\x59\x06\x83\x56\xbb\x78\xfc\x8c\xf2\x70\xc5\xf3\x63\x26\x85\xb8\xfe\x0e\x7d\x83\x0d\x6c\x33\xba\xe9\xfb\xc8\x46\x2a\x5c\x6b\x8f\x07\x15\xc2\x47\x70\x19\xc2\xbe\x0d\x7d\x09\x04\xe9\x27\xa3\x19\x70\x76\x0a\xdc\x46\x79\xfe\x15\x31\xeb\xa6\x21\x89\x09\xdb\x3b\x59\xc5\x75\xc9\xe1\xa0\xc2\xda\x3f\x2b\xd3\x8d\x49\x51\x4f\x70\x12\x86\x94\xad\xfc\xc9\x52\x70\xbc\x0e\x7d\x25\xf1\x75\x20\x25\x21\x0a\xab\xaa\x90\xc0\x3f\x00\x02\x02\xb9\x71\x9e\xe2", 225);
*(uint16_t*)0x20000c50 = 0xbd;
*(uint16_t*)0x20000c52 = 6;
memcpy((void*)0x20000c54, "\x61\xaf\xa2\x00\x38\xf5\x88\xf9\x84\x37\x83\x39\x97\x85\x04\xc3\xd0\xfd\x42\x68\x83\x65\xc7\x75\xc5\x89\xf4\x33\xbe\xb3\x88\x57\xeb\xe7\x2f\xb7\xe1\x73\x89\xda\x89\xb1\x96\xce\xcf\x8a\x62\x4a\x63\xac\x49\x6c\xcd\x18\x08\x26\x93\x22\x21\xb3\x2d\xe4\x36\xe7\x71\x13\x74\x79\xda\x1d\x98\x3d\x72\x4b\x01\xf8\xf6\x98\xf8\x56\xb3\x9e\x43\x98\xfa\x10\x6c\xb2\xa7\xb6\x72\x19\xfa\x4b\xf5\x7b\x5c\x09\xab\xca\xb7\xcb\xdd\x98\x3a\xce\xa1\x02\x17\xc5\x2c\x81\x56\xbe\x87\x8a\x69\xda\x05\x27\xce\x57\x48\x8e\x97\x2e\x4a\x9e\x59\xa7\x4a\xe7\x99\xa8\x3c\x50\xe8\xc5\xe4\xeb\x29\x50\xa2\x05\x08\x3b\x0d\x3a\xe0\x7f\x3f\x46\xd7\x5b\x48\x93\x17\xcc\x7d\x0f\xba\xa7\x87\x9d\x9e\x70\x7f\x91\x47\x8d\x0a\x2b\x4e\x2c\xed\xd6\x1e\xb9\x3e\x43\x1f\x27\x58\x62\x43", 185);
*(uint16_t*)0x20000d10 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000d12, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000d13, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000d13, 0, 7, 1);
*(uint32_t*)0x20000d14 = htobe32(0);
*(uint16_t*)0x20000d18 = 0xd9;
*(uint16_t*)0x20000d1a = 6;
memcpy((void*)0x20000d1c, "\xc3\xf3\x0c\x31\x43\xd8\xbc\xee\x9c\x32\x81\x4d\xf5\x0e\x4c\x1e\x10\x9b\x29\xd3\x12\xf1\xdc\x75\xc5\x85\xdc\x7f\x22\xaf\xce\xae\xe8\x26\x97\x66\x38\x37\xa4\x42\xb3\xb9\x75\xb3\x09\x79\xa3\x65\x8b\x6f\xa2\xe8\x5e\xbe\x2e\xbf\xbb\xa4\x21\x3e\x82\xcb\xce\x54\x7d\x17\xd2\x23\x5f\x73\xe1\x2b\x12\xf4\xa4\x51\xb4\x98\xef\xeb\xa0\xfe\x53\x2a\x2b\x99\xba\x0e\xf3\x9f\xf9\xa9\xf3\xa2\xac\x26\x33\x5f\xf9\x33\x48\xfb\xc0\x60\xf8\x23\x1a\x22\xc9\x54\x9b\x74\x15\x46\x73\xcc\x35\xe9\x9b\xb0\x58\x2f\x26\xff\xff\xc9\x19\x10\x16\xd7\xdd\xa7\xd7\xbf\x89\xef\x70\xeb\xfb\x3f\x8d\xf8\x0f\x1d\x5d\x2d\x08\xed\x37\x94\xad\xa8\x24\x71\xe6\xef\x1b\x5d\x6d\x79\xf5\xfe\x85\xd2\x13\x06\xbd\xb3\x13\x04\xca\xad\xf8\x73\x69\xd5\xc1\x6f\xf0\x58\x2e\xb7\xf9\x98\x0b\x14\x9b\x11\xc9\xe2\x22\x7a\x8a\xfe\x96\xeb\x9e\xc3\xf6\xef\x22\x7b\xc2\x90\x7f\xd8\x3a\xac\xa0\xf5\x73\xaa\xf4", 213);
*(uint16_t*)0x20000df4 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000df6, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000df7, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000df7, 0, 7, 1);
*(uint32_t*)0x20000df8 = htobe32(0);
*(uint16_t*)0x20000dfc = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000dfe, 4, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000dff, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000dff, 0, 7, 1);
*(uint64_t*)0x20000e00 = htobe64(0);
*(uint16_t*)0x20000e08 = 9;
*(uint16_t*)0x20000e0a = 1;
memcpy((void*)0x20000e0c, "syz1\000", 5);
*(uint32_t*)0x20000e14 = 0xadc;
*(uint8_t*)0x20000e18 = 9;
*(uint8_t*)0x20000e19 = 0xa;
*(uint16_t*)0x20000e1a = 0;
*(uint32_t*)0x20000e1c = 0;
*(uint32_t*)0x20000e20 = 0;
*(uint8_t*)0x20000e24 = 0;
*(uint8_t*)0x20000e25 = 0;
*(uint16_t*)0x20000e26 = htobe16(0);
*(uint16_t*)0x20000e28 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000e2a, 0xc, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000e2b, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000e2b, 0, 7, 1);
*(uint32_t*)0x20000e2c = htobe32(0);
*(uint16_t*)0x20000e30 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000e32, 0xf, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000e33, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000e33, 0, 7, 1);
*(uint32_t*)0x20000e34 = htobe32(0);
*(uint16_t*)0x20000e38 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000e3a, 0x11, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000e3b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000e3b, 1, 7, 1);
*(uint16_t*)0x20000e3c = 8;
*(uint16_t*)0x20000e3e = 1;
memcpy((void*)0x20000e40, "dup\000", 4);
*(uint16_t*)0x20000e44 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000e46, 5, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000e47, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000e47, 0, 7, 1);
*(uint32_t*)0x20000e48 = htobe32(0);
*(uint16_t*)0x20000e4c = 0xaa1;
STORE_BY_BITMASK(uint16_t, , 0x20000e4e, 0xd, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000e4f, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000e4f, 0, 7, 1);
memcpy((void*)0x20000e50, "\x15\xea\x45\xa3\xd7\xfd\x9c\xb5\x3d\xfa\x34\xd6\x0e\xf4\x92\x85\x64\x2f\xce\xd8\xf0\x7e\xc9\x22\x2b\x42\x6b\xf3\x72\x6e\xee\x8e\xdc\x00\xa5\xed\xdf\x40\x44\xdf\x4a\x73\x3e\xa2\xcb\x26\xf9\xc4\xc9\xf4\x0c\x3a\x7c\xe8\x33\xcb\xcd\x37\x3c\xf3\xfc\x96\x45\xe5\x8d\xe0\x45\xc4\x12\xd0\xb4\x31\x98\x48\xbb\xc9\xbb\x99\x37\x51\x1f\x77\xc5\xa9\xda\xb0\x5b\x31\xe0\x71\x9d\xab\xaf\x0b\xfa\x5e\x9c\x38\x4b\x20\x38\x92\x70\x23\xf0\xc7\x86\x7d\x46\xa1\x96\xc4\x8d\xf1\xfa\x65\xaa\xea\x8d\xf4\x4b\xb6\x91\x22\xf6\x6e\x29\xbc\x39\x5a\x6b\xf1\xa4\xe3\xcb\xe5\x3e\x37\xd2\xfc\x1a\x6c\x8f\x3e\x7a\xba\x78\x1a\xa6\xe1\x78\xe2\xb3\x1a\xf0\x75\x45\x9c\x3e\x2b\x7b\x21\x85\x34\x0a\x64\x9c\x56\xdf\x29\xbd\x4a\x85\xae\x99\xeb\x0b\xa2\x4a\xcb\x02\x13\x29\xd6\x11\x3c\xc3\x53\xbf\x1c\x96\x9c\xbb\xd0\x24\x02\x75\x08\xc2\x42\x17\xcd\xcc\x52\xb7\xa1\x60\x9f\x65\x04\xc8\x19\xf2\xf9\xc5\x8f\xdd\xf1\x71\x18\x6b\xd5\x73\xeb\xe1\x64\xef\x1c\x8b\x5b\xc3\x74\x98\x9e\x57\x1a\xbf\x45\x01\xd2\xda\x88\x9d\xc4\xb3\xcf\xc8\x01\xf2\x21\xda\x8e\x81\x2d\xbe\x81\x6e\x29\x3a\x88\x11\x60\xa0\x56\x66\x21\x04\xcc\x62\x5e\x91\x35\x61\x02\xc1\x64\x5d\x15\x40\xbc\xdc\x96\x5d\x77\xaf\xd0\x5e\xff\x6f\xd6\x96\xff\x76\x17\x2b\x3d\xca\x19\xdf\xbf\xb7\x65\x7b\x1f\xd2\xb5\xbc\x93\x89\x12\xc2\x92\xd4\x59\xbf\x5c\xb2\x66\x50\xcd\xd6\xba\xd0\x82\x00\x02\xc5\xb2\xed\x7c\x05\xea\xdc\x22\x2e\xac\x1d\xc4\x85\x87\x77\xcc\x45\x68\x3b\x12\xec\x20\x55\x2b\x3b\x1f\xaf\xde\xa5\x85\x65\x7f\xd2\x9a\xb3\xac\x3f\xf2\x29\xc7\xde\x1e\xbd\x10\x1a\x77\x33\x2d\x37\xc2\xd7\x88\xb7\x72\x1d\x45\xf4\xc1\xef\x27\xac\x08\x59\x4a\xe4\x37\xe7\xee\x62\xb7\x56\x55\x67\x5d\x05\x34\x1a\xcb\xe9\xc7\xfd\xee\xaf\x92\xd3\x47\x12\x61\xdf\x5c\x73\x64\x55\x29\x73\xd5\x08\x77\xe1\x7d\x33\x00\x8c\x1c\x79\xe5\x02\x3a\xab\x75\xa5\xf5\x5f\xdb\xe3\xd7\x38\xda\xa8\xb3\xb6\x86\x22\xa0\x50\xf2\xf0\x74\xfa\x18\xf2\x6f\xaa\x3d\x49\xbd\xa2\x68\xb0\xc1\x8d\xd8\x15\x79\xd3\x6f\x3a\x8a\x36\xa2\x13\x26\x91\xb8\xce\x1d\xfe\x60\x24\x07\x95\xd7\x59\xbf\x14\xec\xa2\x69\x6c\x5e\x8a\xa5\x5b\xde\x3f\x07\x1d\x54\xf4\x71\xd8\x04\xba\xb4\xb8\xab\xc6\xf2\xec\x6d\x55\x90\xd0\x99\x12\x9e\x2a\x84\x0b\x22\x9d\x99\x29\x14\x95\x97\x7f\x9b\xab\x90\x8a\x7e\x0a\x04\x2b\xea\xfe\x6a\x7c\x24\x36\x34\x9f\x84\x18\x2d\x06\x26\xaa\xe9\x5c\x04\x83\x79\x4f\x32\xba\xa7\xdb\x51\x07\x8c\x43\xfb\x12\x40\xd5\x60\xf0\x61\xb6\x8e\x2d\x7e\x22\xa9\x85\xa4\x25\x8c\x7e\xa5\x87\x1c\x08\xfd\xf8\xa4\x24\xa9\x84\xb8\xf8\x68\x25\x72\x52\x59\x51\xc2\x58\x43\x97\x62\x68\x5c\x84\x14\x81\x83\x62\x6f\xe9\xfa\x14\xe7\xb0\xa0\x4f\x7e\xb6\x95\x04\x2e\xa1\xfd\xdc\x1f\xa0\xb1\x61\x17\x56\xba\x1e\x62\xfd\xf9\xb8\x78\x0c\x81\x35\x16\x2b\x82\x99\x17\x09\xbd\xb5\xfc\x61\x29\xf1\x8c\x15\xb2\x6e\x24\xe1\x5f\x4e\x9c\x3b\xf5\x3e\x4a\xf8\x2d\x9c\x9e\xf9\x96\x36\x6a\x5c\x8e\xe0\x49\xb2\xff\xd3\x39\x0d\x30\xda\xcf\x07\xe9\xe8\x7f\x28\xe3\x0b\x86\x7b\x16\x1e\x4e\x5b\xe4\x08\x16\x19\x4f\xa3\x69\x54\x7e\x7c\x3e\x77\x43\x78\x1d\x06\xfa\xdd\x7d\x68\x46\xce\x83\x92\xa1\xac\x72\x79\xdb\xc3\x1c\xb3\x31\xbb\xe1\x5f\x11\xa7\x0c\x87\x51\x0e\xa3\x65\x0c\x73\x47\x37\xa4\x42\x9c\xe9\x49\xf1\x49\x35\x59\x88\xe0\x95\xe7\x80\x0f\xda\x65\x43\xdb\x5d\xfc\x7d\xb2\xbc\x5e\xb2\x53\xa0\xc4\x4d\x10\xbe\xef\x81\x7f\x66\xe2\xd6\xd5\xf1\xe9\xa1\xa1\xbe\x58\x69\x4e\x16\x0a\xa0\x42\xde\xc3\x5d\x57\xd0\xc1\xa5\x8b\x8a\x64\x6e\x45\x3d\x29\x2d\x64\x13\xf5\x1f\x78\x3e\x15\xbf\xd0\xef\x65\xde\x3e\x4e\x45\x02\x9e\xc6\xa0\x2a\x9b\x16\xd1\x85\xd6\x32\xca\xe9\x54\x53\xe0\x4d\xeb\xab\x77\xc5\xff\x1b\xff\xd2\x46\x9d\x77\x27\x33\x2c\x36\x09\x24\x0f\x5e\x89\x29\x3f\xb4\xb7\xe2\xf8\xb9\x45\x58\xc7\xc6\x72\xc5\xd1\x5e\x19\xbf\xe6\x99\xcb\x73\xe6\x20\x76\xe5\x7d\x2c\xad\x2f\x6b\x6b\x16\xbc\xdf\x57\x17\xdd\x36\x28\x70\xda\xf6\x87\x0b\x7a\x0a\xe1\xda\xf5\x72\xde\xe9\xe9\xe4\xe0\x78\x86\x7e\x62\x2c\xb6\x3e\x02\x2e\x73\x0e\xbd\x82\x7d\x48\x58\xba\xc3\xd2\x70\xfa\xe1\x06\x34\xa8\x22\x8a\xb1\xba\x1c\x69\x62\xdd\x78\xbe\x73\xaf\xac\x69\xba\x95\x27\x72\x51\xab\xea\xa4\x39\x26\x38\xc6\x8e\x11\x3f\xd9\xf1\xd8\x5a\xdc\x72\xc3\x71\xff\x67\x6b\x24\x26\x5f\x45\xc1\xb4\x50\x34\x31\x3b\xe8\xf7\x14\xd0\x7f\x0f\xdd\xe8\x9d\xf9\xb9\xcf\x0e\xa4\x7a\x53\x99\xb2\xee\x00\xd9\x70\xc9\x70\xab\x79\x4b\x14\xcb\xc6\x25\x4a\xc2\x76\x02\xc6\x98\x22\x2b\x85\x7f\x5b\xa2\xb7\x40\xd4\xb5\x8d\x64\x11\x68\xd9\xc2\x64\x9d\x03\xae\x63\x7b\x97\x59\x52\x80\x13\x3b\xa6\x43\x0a\x6e\x1a\xf6\x26\x2c\x84\x74\xb1\x18\x4e\x93\xf9\xe4\xe8\x37\x44\x59\x81\x6d\xa6\x62\x30\xc3\x3c\x6c\xb5\x33\x64\xe0\x7f\x2b\x2e\x79\x0a\x39\x1d\x8e\x4c\x1f\xf3\xba\x11\x03\x9f\xd0\x85\x3e\x81\xf8\xbd\xd5\xc1\xa9\x70\x1e\x84\xbd\x15\xef\x83\x26\x21\x6f\xdf\xc7\x8b\xbc\xca\xac\xd2\xb5\xb5\x9a\xdc\x94\x2e\x6a\x9f\xb6\x4d\x75\xde\x7c\x8c\x66\x4a\x8b\xf3\xd7\x84\xc3\xa8\x43\x9d\x4e\xec\x36\x52\x30\x8c\x59\x7d\xb5\xbb\xaf\x67\x29\xfd\xb4\xb7\x07\x3e\xed\xb6\x9d\x59\x18\x30\x91\x1f\x2f\x6d\x59\x9a\xfa\xfa\xf2\xe6\xdc\x85\x9d\x2f\x03\x1a\x24\x1e\x64\x75\x81\xcc\x5f\x80\xda\xc0\xe0\xbb\x23\x20\x57\x85\x7c\x65\x68\xa4\x91\x1d\x9e\x98\x6b\xbc\xb9\xe0\x93\x0e\xc2\xa1\x51\xaa\x46\xda\x35\xd9\xd3\x68\x01\xa5\xc3\x9c\x24\x32\x7e\x06\x1d\xc1\x0f\x07\x03\xdd\x75\x89\xcd\x2f\xb5\x63\xcc\x4e\x17\xeb\x5b\x73\x22\x74\x15\x91\x8a\x84\x32\x09\x0e\xc9\x08\x0b\x84\x3b\xf3\x4f\x05\x78\x00\x08\x34\xe3\x64\xed\xd3\x12\x7e\xf9\x4b\x7a\x80\x34\xfd\x4a\xef\x08\x56\x48\xf2\x18\xe4\xe6\x7d\x0f\x8d\x96\x74\xf1\x5a\xaa\x28\x34\x09\xa2\x89\xac\x51\xdf\x6a\x98\xe0\x2b\xcb\xc1\x66\xdd\xe4\x21\xbf\xad\x20\x1f\xcd\x8a\xcd\x28\xe2\x0d\xe3\x85\x59\x25\xd5\xe5\x08\x88\x4d\x44\xb8\xa0\xb9\x11\xe9\xff\x1a\x0d\x2d\xb6\xeb\x8d\xec\xc1\x15\x12\xae\x89\xe4\x9f\x60\x6a\xa9\x1c\x71\x6d\xce\x61\x51\x24\x25\x02\xcf\x09\x7b\xc4\x43\x28\xd7\x01\x5a\x93\x07\xd8\x25\xc8\xe0\xc7\x48\x15\xa2\xc7\x6b\xee\xb0\x79\x12\xf1\xad\x55\xd4\xf6\x2a\x1a\xbc\xba\x1c\xa5\xba\xcb\x5e\x81\x12\x50\xc2\xd9\x68\x13\x8c\xb3\xcb\x75\xa1\x75\x8f\xf7\x43\x55\xe6\x4a\x7d\xfa\x83\x8a\xe9\xd1\x27\x41\x0a\x7e\xa6\x04\xdc\x08\xe4\x2f\x89\x58\x6d\x40\x98\x6a\x0d\x0f\xb1\xd4\x39\x27\x2a\x82\xa8\x8d\xb4\x35\x83\x42\x78\x94\x06\x38\x82\xe9\x93\x1d\x57\xda\x7e\x27\x8b\x2a\xe9\x11\x7f\x8b\x32\x9e\x5e\xbf\xbb\xf1\x0d\xbd\xc1\x02\xb9\x8d\xf0\xb0\x9f\x29\x15\x9e\x93\xab\x3e\xf9\x11\xff\x9b\x04\x79\xe1\xc7\x5e\x6d\xad\xa8\x3b\xe2\x2e\x7a\xce\x2a\x5d\xa2\x95\x83\xd3\x13\x07\xcd\x8a\xc4\xd2\x9c\x79\x05\x66\x42\x28\xf8\x28\x03\xb1\xc2\x51\x4c\xc6\xca\x4c\xd0\xf1\xa9\xf8\xe3\x3b\xca\x24\xbc\x41\xb3\x40\xed\x2b\x3f\x1d\xad\x0c\x20\xcd\x6f\x66\xca\xb4\x86\x9b\xf8\x7a\xa2\xf0\x17\x76\x06\xc9\xde\xa1\xe0\x1c\xf5\x98\x19\xcd\x18\xd3\x7e\x9f\x2e\xab\x72\x6a\x22\x9b\xdc\xf2\x2a\xd3\x79\x6e\x97\xf6\x88\x26\xb4\x81\x11\x64\x8b\x34\x14\xe5\xd4\x52\x00\xad\x04\xee\x88\xad\x35\xda\x0f\x64\xfb\x03\x22\xea\xf0\x27\xfa\x32\x73\xba\xfe\xe8\x66\x6d\x0c\x2a\x27\xbe\xc0\x31\x53\xdb\xa7\x42\x7f\x68\xd2\x4f\xe1\x3e\x3c\xce\x4c\xdf\xa0\xc9\xc7\xa6\xeb\x92\x3e\x0b\x3a\x83\x9b\x29\x60\x7f\xd6\x7e\x07\xcb\x37\x45\xb4\xa3\x59\x93\x42\x06\xbe\x05\x92\x30\xc1\xaf\xeb\xfe\x67\xe9\xea\x4e\x80\xc1\x0c\xe2\x8f\xfd\x03\xb3\xef\xc5\x88\x9a\x1e\xd4\xb3\xaf\x7a\xdc\x1f\x5f\xf5\xca\xda\x5e\xa6\xef\xdd\xc4\x5f\x3c\xbb\x1e\xd5\x39\x8f\xed\x73\x82\xc5\xe9\x33\x1e\x10\x2f\x5e\x42\xd0\xce\xc7\x37\xfe\xb5\xde\x63\x2b\xb7\x3d\x70\xad\xbc\x25\xea\xff\x6d\x44\xf7\xef\x8c\xe0\xb2\xf7\xac\xdc\xcf\x18\x41\x6c\xf5\x9f\x73\xdc\xb9\x45\x4a\x33\x46\x6a\xe5\x49\x9e\xed\x8e\xd3\x23\x62\xe3\x53\xee\xc7\xad\x46\xe7\xf2\xf4\xfe\x81\xcb\xaa\xcc\x89\x46\xa1\x4a\x2d\x0e\x05\xa7\x5e\x5a\x93\x93\xfb\xa2\x2a\x15\xff\xfe\x90\xaa\xb5\xe5\xb0\xc8\x63\x4f\x2c\x12\x3d\x8e\x7e\x6d\xce\x92\xfb\x24\xc5\xaa\x57\x54\xe3\xc5\x1d\xb5\x39\x15\x02\x90\x0b\x29\xa3\x52\x4a\xdd\x8c\x69\x37\xb6\xf7\xa6\x15\xeb\xe2\x6a\x2a\xdc\xad\x51\xfb\xe4\x5b\x39\x33\x7b\x5c\xde\x0b\x69\x11\x30\xc4\x5b\x56\xf6\xf6\x07\x6c\x94\xb2\xe9\x9d\xfa\x70\xf5\x7c\x94\x19\x5b\x03\xd5\xfd\x66\x50\xc8\xd1\x06\xec\x55\xf3\x7f\x27\x0f\x38\xfc\x66\xf0\x9f\x88\x9f\xd9\xaf\x67\x1e\xdc\x30\x65\xf9\xee\x9d\x8b\xf4\x1a\x8c\x4f\xf3\x23\x54\x3a\x4a\x7e\xf0\x8c\x35\x81\x22\xd3\xa1\x64\x6e\xa6\xf1\x90\xa2\xa5\xf3\x9a\x6b\xcb\x5c\x6c\x35\x4b\x3c\x73\xa6\xc3\xdc\xeb\x0a\xc1\x46\xdb\xc7\xc6\xe3\x2d\x25\xac\xd8\x77\x5b\xa4\x67\x75\x98\x92\x46\x4c\x57\x68\xef\xb6\x0c\x92\x8f\x15\x00\x54\x4b\xa8\x8f\x28\x80\xb5\x91\x9f\x22\x7f\x21\x1b\x39\xe2\x54\xeb\xc9\x2a\x7f\xd8\xba\xaf\x81\xc6\x93\x07\xa3\xe5\x83\xf8\x2e\xc9\x16\xce\xea\x30\x9d\xb0\xb8\xd7\xfd\x70\xf6\x4e\x0c\xb4\x74\x24\x53\x5a\xe4\x1a\xa4\x0d\x74\x20\x96\x1b\x87\x59\xe6\x25\xcc\x83\xce\xe6\xc9\xd0\x85\x11\x55\x5c\x49\xd2\x57\xb4\x2f\xb3\xc9\xb9\x41\xa4\x05\x1d\x15\x85\xa0\xb9\x64\x2c\xce\x8d\xee\x41\x49\xde\xfa\x4e\x5b\x0f\x8d\x25\x24\x3d\x2a\x83\xe7\xaf\x59\x5a\x92\x73\x52\x93\x37\x12\x3f\xec\xdf\x97\xb8\x98\x14\xde\x3d\xab\x1f\xd5\xa1\x5e\x05\xb0\xbc\x5d\xe8\x3e\xe3\x0b\x6e\xdb\x9e\xff\x9e\xc2\xaf\xa7\x0a\x24\x25\x54\xc2\x47\x33\x35\xed\x05\x0f\x96\xe4\x22\x46\x8a\x41\xbe\x09\x6a\x69\xd6\xbf\x31\x1b\xb4\x54\x7e\x77\xed\x7d\xc7\xce\x9b\xe4\x8e\x35\x10\x75\xbf\x28\x05\x15\x39\x6e\x3f\xb7\x4a\x4c\x1a\x89\xb9\xb9\x22\x8f\xcc\x67\x0b\x23\xeb\xa3\xb3\x04\x75\x35\xb9\xc5\x7e\x92\xd6\x60\x88\x82\xd0\xd7\x8f\xec\x1b\xdb\xcb\x9f\x06\xa0\xf7\xbc\x55\xbb\x83\x66\x67\xbf\xf6\x71\x8f\x2a\x49\xf8\x35\xe9\x04\x9c\xf8\x19\xbe\xd4\x68\x2c\x41\x4a\xaa\x86\xa6\xb1\x67\xde\x25\xed\x20\x30\x96\xa1\x9e\xd1\x9b\x4f\x83\xf0\x74\x09\x0f\xfe\xfe\xbd\x5c\xd6\x67\x33\xc4\x74\xcc\x24\x5a\xa9\xcf\xbd\xb0\x9a\x69\x9b\x80\x2d\x7d\xf2\xf1\x66\x44\x04\x11\x58\x13\xd1\x9d\x1f\x63\x38\x52\xf5\xd1\x23\xa5\xc8\xe9\xd3\xd4\x1a\x1e\x35\x42\xc0\x93\xea\x39\x7f\xd2\xd7\xa6\x2f\x20\xb5\xba\xf6\x51\xab\xb2\x04\xa4\x21\x84\xbb\x8c\xa3\x26\x7b\x67\xb2\x7f\x97\xa4\xd0\xbd\x5b\x85\x33\x5d\xde\x4e\x2c\x3c\xd2\xe6\x30\xd6\xbf\xac\x46\x07\xec\x5c\x3e\x65\xaa\x1f\x22\x5b\x8c\x13\xa0\xdd\xa6\x98\xfd\x1c\x5c\xde\xda\x6d\x6a\xdb\xfa\xf7\x32\x2b\x73\xcd\x1b\x88\x51\xf9\xaf\x3d\x28\x92\x0a\x6d\x51\x0f\x25\xcc\x0d\xa3\x69\x0d\x02\x9d\xb7\x21\xf7\xec\x5c\x32\x34\x7d\xb0\xc4\x7c\x94\xea\xaa\xd9\x6d\xd1\x47\xf8\xe8\x44\x8d\xc3\x17\xd9\x19\x28\xcf\x42\x61\x8c\xec\x50\x1d\xa4\x38\xa1\x80\xe8\xcc\x57\x60\x16\xfb\xa8\xee\x01\x43\xc0\x9f\xa5\x9b\x8d\xb9\xa8\x15\x5d\x1e\xcf\xff\xec\x37\xf0\x91\x97\xd1\xe7\xa3\x06\x24\xe3\xd8\xc7\xce\x97\x59\xaf\x8d\xb5\x3c\x01\x11\xec\x39\xea\xd5\xdf\x6a\x3d\xbc\x5c\xc1\x57\xfc\x4f\xe4\x8a\xdd\x84\xc3\x08\x51\xbb\x3b\x58\xcc\xc9\xe9\x84\x35\x0d\xd0\x43\x0e\x8b\xe7\x0e\xcd\x22\x95\xb9\x5d\xeb\x43\xa7\x45\xaf\x53\x8d\xef\x8b\xf3\xde\xf9\x3b\xd4\x29\xe3\x72\x16\xeb\x4b\x74\xb1\x4a\x06\x35\xf7\xec\x63\xc8\x2e\x64\x0c\x07\xe0\xfd\x63\xd5\x17\x79\xe6\x29\x1b\x80\x1b\x7e\xfc\x1d\x24\x8d\x3b\x49\xb2\xb0\x7b\x8f\x17\xfc\xda\xef\x8c\x65\x67\xbb\x2f\x74\x01\x62\x86\x79\x2c\x68\x95\x43\x44\x03\xdc\xa7\xdc\x08\xd0\x52\x7c\xaa\x17\x7d\x8a\x6d\xdd\x4b\xc6\x64\x81\x34\xaf\x34\x00\xb0\x47\xa4\xaa\xdd\xe3\xb7\xa5\x33\x3b\xd6\xa0\x6d\x2f\x0f\x00\x37\xf3\x38\x8b\xb2\xa2\x29\xd1\xff\x70\x89\xf1\x35\xe0\x1c\xfe\xae\x41\xb4\xe4\x58\xd6\x0b\x05\x9a\x72\x65\x62\x21\x81\xc3\xef\x86", 2717);
*(uint32_t*)0x200018f0 = 0x14;
*(uint16_t*)0x200018f4 = 0x11;
*(uint16_t*)0x200018f6 = 1;
*(uint32_t*)0x200018f8 = 0;
*(uint32_t*)0x200018fc = 0;
*(uint8_t*)0x20001900 = 0;
*(uint8_t*)0x20001901 = 0;
*(uint16_t*)0x20001902 = htobe16(0xa);
*(uint64_t*)0x20000348 = 0xec4;
*(uint64_t*)0x20000398 = 1;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000380ul, 0ul);
	return 0;
}