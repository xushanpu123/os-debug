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

#ifndef __NR_finit_module
#define __NR_finit_module 313
#endif

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

uint64_t r[5] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000040ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000340 = 1;
*(uint32_t*)0x20000344 = 3;
*(uint32_t*)0x20000348 = 0x1000;
*(uint32_t*)0x2000034c = 0xe2;
*(uint64_t*)0x20000350 = 0x20000140;
memcpy((void*)0x20000140, "\x4c\x2d\xa0\x8b\x20\x33\x52\xef\x16\x47\x46\x8d\xf6\x22\x3b\xa2\xfa\x7e\x68\xcc\x0e\xd5\x9c\x29\xf6\x50\x93\x7d\xe0\xde\xd1\x9c\xc8\xae\xdd\xab\x20\x50\xaa\x10\x88\xc1\x99\xf0\x54\x38\x95\xcc\x07\x23\xa5\x1b\x2c\x2c\x3c\x14\xd3\x84\xc6\x46\x06\xf8\xbe\x3b\xf0\xe5\x1d\x39\x61\xc7\xee\x53\xef\xb7\xe8\xc2\x7b\x4e\x47\xd1\xe8\xda\xe2\x00\x3b\xd1\xf4\x86\x8e\xdf\xed\x68\x6f\x84\x98\x33\xca\x19\x60\xe7\xf1\x10\xd2\xc8\x3c\x9c\x86\xb1\x0b\xcf\x1b\x35\x34\x2e\xd3\x40\xe8\x2b\x5b\x15\xcb\x2a\x7c\x06\xc5\xd8\x3a\x29\x0b\xc2\xef\x4f\x38\x82\x0f\x07\xa6\xd8\xb5\xe7\x4d\x93\x7f\x4a\x39\x74\x42\xe7\x7a\x87\x54\x13\x15\x34\x05\x4f\xc9\x96\x46\xc2\x07\x2b\x76\xb9\x24\x7c\xbf\x4b\x7c\x64\xa8\x46\x14\xca\xdc\xba\x55\x73\xd0\xec\xe1\x10\xa8\x12\xbe\x1a\x69\xcd\x90\xf6\xa6\xef\x7f\xaf\xdd\x0f\xd2\xb0\xd2\xee\x15\xc8\x8d\xec\x08\xc8\x64\x92\x0d\x38\xd5\xa8\xdf\xc1\x22\x0f\x50\x07\x21\x01\xd9\x1b\xad\x4a\x7e\x9a", 226);
*(uint32_t*)0x20000358 = 0xed;
*(uint32_t*)0x2000035c = 0;
*(uint64_t*)0x20000360 = 0x20000240;
memcpy((void*)0x20000240, "\xc3\x17\xd4\x11\x21\xbe\xa3\x20\x7d\xd8\x1b\xc6\x3a\x8d\x1c\x9b\x39\xce\x92\xb5\xc7\x4d\xa3\x3a\x0b\x23\x21\xfc\xdb\xbb\x4c\x04\x2e\x0d\xbb\x92\x5e\x14\x5b\xaf\xec\x68\x1b\xa0\xa6\x29\xd0\x01\x73\x57\xd6\x1c\x9b\xaf\x6c\xe1\x88\xa5\x2c\x97\x4a\xe8\xa7\x8b\xa7\xf8\x4d\xc1\x20\x03\x3d\xbe\xac\x87\x6a\x73\x26\xf1\x12\x1d\x01\x44\xe4\x66\x62\x25\x3c\xcb\xee\xb6\x10\x79\xd5\x54\x03\x0a\xd7\xad\x34\xd5\xda\xb5\x96\xf9\x72\xfe\x9e\x9b\x56\x03\x71\xb5\xfe\x55\x45\xb5\x4f\x1c\x90\x39\xfc\x88\x65\x38\x58\x2a\x89\x19\x69\x42\x47\xf5\xeb\x9b\x05\xa2\x2d\x94\xd7\xa8\x73\x8e\x88\x76\x5a\x4c\x2e\x22\x7c\x5d\xb3\x80\x46\xef\xf3\xef\x04\x69\xa2\x2f\x5d\x32\x82\x30\x6a\x4f\x5c\x4c\x13\x28\x6c\x67\xb6\x38\x46\xa9\xad\xee\x54\x10\x86\x95\x14\xbe\xb2\xa5\xcb\xe7\x50\xf8\x90\xa8\x51\x5f\xce\xec\x1f\x4d\x22\xef\xab\x2a\xc2\x2a\xaa\x73\x36\x32\x26\xbb\xd5\x34\xb8\x8f\x05\x36\xc8\xbf\x5b\x19\xdb\x80\x4a\x58\x4d\x62\xca\x75\xb3\x17\x62\xf2\xd1\x04\x1b\xe7\x20", 237);
memset((void*)0x20000368, 0, 88);
	syscall(__NR_ioctl, -1, 0x40806685, 0x20000340ul);
	syscall(__NR_socketpair, 0x10ul, 2ul, 0xfffffe01, 0x200000c0ul);
	syscall(__NR_syncfs, r[0]);
memcpy((void*)0x20000700, "/dev/autofs\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000700ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000700, "/dev/autofs\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000700ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000780 = 0;
	res = syscall(__NR_signalfd, r[2], 0x20000780ul, 8ul);
	if (res != -1)
		r[3] = res;
	syscall(__NR_dup2, -1, r[2]);
memcpy((void*)0x20000600, "([\000", 3);
	syscall(__NR_finit_module, -1, 0x20000600ul, 0ul);
*(uint64_t*)0x20000780 = 0;
	syscall(__NR_signalfd, r[1], 0x20000780ul, 8ul);
memcpy((void*)0x200004c0, "ip6tnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200004d0 = 0x20000440;
memcpy((void*)0x20000440, "ip6tnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000450 = 0;
*(uint8_t*)0x20000454 = 0x2f;
*(uint8_t*)0x20000455 = 0x81;
*(uint8_t*)0x20000456 = 0;
*(uint32_t*)0x20000458 = htobe32(8);
*(uint32_t*)0x2000045c = 8;
*(uint8_t*)0x20000460 = 0xfe;
*(uint8_t*)0x20000461 = 0x80;
memset((void*)0x20000462, 0, 13);
*(uint8_t*)0x2000046f = 0xaa;
memcpy((void*)0x20000470, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint16_t*)0x20000480 = htobe16(0x40);
*(uint16_t*)0x20000482 = htobe16(8);
*(uint32_t*)0x20000484 = htobe32(0x7fffffff);
*(uint32_t*)0x20000488 = htobe32(1);
	res = syscall(__NR_ioctl, r[3], 0x89f0, 0x200004c0ul);
	if (res != -1)
r[4] = *(uint32_t*)0x20000450;
*(uint64_t*)0x200005c0 = 0x20000400;
*(uint16_t*)0x20000400 = 0x10;
*(uint16_t*)0x20000402 = 0;
*(uint32_t*)0x20000404 = 0;
*(uint32_t*)0x20000408 = 0x200000;
*(uint32_t*)0x200005c8 = 0xc;
*(uint64_t*)0x200005d0 = 0x20000580;
*(uint64_t*)0x20000580 = 0x20000500;
*(uint32_t*)0x20000500 = 0x58;
*(uint16_t*)0x20000504 = 0;
*(uint16_t*)0x20000506 = 0x20;
*(uint32_t*)0x20000508 = 0x70bd2d;
*(uint32_t*)0x2000050c = 0x25dfdbfd;
*(uint8_t*)0x20000510 = 6;
*(uint8_t*)0x20000511 = 0;
*(uint16_t*)0x20000512 = 0;
*(uint16_t*)0x20000514 = 8;
*(uint16_t*)0x20000516 = 2;
*(uint32_t*)0x20000518 = 1;
*(uint16_t*)0x2000051c = 0x3c;
STORE_BY_BITMASK(uint16_t, , 0x2000051e, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000051f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000051f, 1, 7, 1);
*(uint16_t*)0x20000520 = 8;
*(uint16_t*)0x20000522 = 3;
*(uint32_t*)0x20000524 = htobe32(0x64010100);
*(uint16_t*)0x20000528 = 8;
*(uint16_t*)0x2000052a = 3;
*(uint32_t*)0x2000052c = htobe32(0);
*(uint16_t*)0x20000530 = 8;
*(uint16_t*)0x20000532 = 7;
*(uint32_t*)0x20000534 = 0;
*(uint16_t*)0x20000538 = 8;
*(uint16_t*)0x2000053a = 7;
*(uint32_t*)0x2000053c = r[4];
*(uint16_t*)0x20000540 = 8;
*(uint16_t*)0x20000542 = 6;
*(uint32_t*)0x20000544 = 3;
*(uint16_t*)0x20000548 = 6;
*(uint16_t*)0x2000054a = 5;
*(uint16_t*)0x2000054c = htobe16(0x4e23);
*(uint16_t*)0x20000550 = 6;
*(uint16_t*)0x20000552 = 1;
*(uint16_t*)0x20000554 = 2;
*(uint64_t*)0x20000588 = 0x58;
*(uint64_t*)0x200005d8 = 1;
*(uint64_t*)0x200005e0 = 0;
*(uint64_t*)0x200005e8 = 0;
*(uint32_t*)0x200005f0 = 0x800;
	syscall(__NR_sendmsg, -1, 0x200005c0ul, 0x2000800ul);
*(uint32_t*)0x200007c0 = -1;
memcpy((void*)0x200007c8, "\x45\xc5\x9f\x9c\xf3\x2e\xe9\x82\x54\x20\x34\x15\xed\x3d\xad\x6a\xbe\xf0\x9b\xb8\xf7\x3d\x5f\x48\x18\x7f\x8a\x8f\xdd\x95\x4b\xec\x4f\xb5\xd7\x85\x4d\x5e\x8c\xad\xfb\xf6\xcd\x79\xa7\xca\x8b\x65\xad\xab\x80\x19\xc4\xf7\x9c\xd3\xc6\x7f\x30\x65\x4f\xee\x27\x63\x7c\x35\xa0\xe8\xf4\x3d\xf8\x3c\x60\x0d\x9d\x42\x47\x21\x70\xfc\x14\xe5\xc0\xad\x5b\xc5\xf9\xb4\xeb\x04\xef\x7b\xae\x4d\xb5\xa1\x7f\xdf\x25\xf2\x8e\x27\x97\x19\xea\x00\xbb\x5e\x4c\x97\x08\x66\xa2\x20\x5d\xf3\x76\x27\x3c\x46\xb0\x5d\x3f\x43\xf2\x61\xa8\xb3\x72\x84\x8c\x71\x41\xc1\x39\x8e\x8f\x0f\x3b\x03\x19\x62\xa6\x81\x9b\xdf\x48\x89\x3c\xc9\x4a\x4d\x1b\x34\xbd\x40\xd4\x8b\xaf\x4c\xb1\xe1\xe7\xa2\x88\x3d\x04\x74\xdf\x7d\x8c\xbb\x93\x87\xfa\x42\x6b\x73\xfa\x5e\x6d\x62\x23\xc3\xf5\x22\xf8\xc6\xa7\xf4\x57\x1c\xb8\x8e\xee\x79\x88\x3b\xb1\xe7\x9e\x0a\xdb\x1a\x87\x38\xb8\x57\xfb\x6a\xb4\x89\x1c\xdd\x45\x5c\x65\x1b\xff\x50\x74\xc0\xe7\x03\x4f\xfd\xbd\x3e\x17\xd6\x19\xf4\x8e\xb8\xaf\xb8\xb9\x2d\x25\x5a\x96\x58\xd1\xca\x37\x12\x5d\x6b\xb6\x88\xd2\xa0\xed\xff\xcb\xc9\xf4\x05\x20\x09\x70\x86\xe3\xb1\x59\x2d\x84\xc2\xde\x07\x12\x43\xdb\x68\x46\xa8\x59\x65\x26\x7f\x63\xe1\x78\x39\xb3\x6a\xa2\x01\xc4\x32\x9c\xa0\x39\x69\x0c\x23\x3b\x7d\x22\x18\x4e\xad\xf6\x2f\x7c\x74\xa9\xd5\xf6\x37\xb3\xf4\x0c\x35\xab\xd2\xc1\x6b\x61\x38\x1b\x11\xb0\x3f\xa5\xb1\xd7\x86\x5f\xa2\x9e\xee\xd3\x7b\x48\xf0\xf4\xb2\x33\x6c\x0f\x38\x9c\x8d\xd9\x7a\x76\x2b\x54\x57\xd9\xac\x31\x62\x74\x71\x2c\xc6\xcd\x55\x08\x05\x6b\x33\x61\x98\x6b\x30\x30\xfc\xaf\xb4\xf4\x23\xa5\xac\x5f\x89\x4e\x45\x83\x51\x78\xe8\xb2\x4a\x27\x17\xa7\x94\xb4\xc9\x9d\x3f\x54\xb0\xd2\x44\x85\xed\xb1\x33\x64\x45\x77\x44\x9f\x43\x44\xb9\x9e\x40\x25\x34\xb3\xb9\xb7\x73\x68\x80\x6e\xb9\xef\x2f\x63\xf1\xc3\x26\xa7\xa2\x48\x86\xcf\x33\xfe\xe3\x23\x2c\xe7\xd8\x4b\x5f\x95\x04\xdc\x3a\x15\xb8\x46\x0b\x21\x97\x41\x3e\xb4\x2d\x08\xc8\xc8\x80\x9d\x9c\x74\x66\x45\x49\x05\x77\x3e\x08\x5f\x55\xda\xe3\xd8\x7f\x60\x70\x31\x4a\xbb\xca\xfd\x19\x4a\x64\xbe\x03\x0d\x3c\xd2\x8d\x4b\x07\xbf\x8b\xa3\xf7\x3e\xb3\xd5\x09\xac\xe7\xb9\x71\xc1\x70\xe8\x38\x75\x17\xf8\x7a\xec\x09\x0f\x99\x4a\x2a\x5c\xa0\x40\x66\x91\x57\x8f\x62\x49\xf6\x52\x11\x62\x8b\x32\x9b\xe2\x78\xe5\x91\x31\x55\x34\x98\x13\x87\xaa\x8a\xbc\xe8\xc1\xb3\x0f\x95\xf6\xba\xf6\x44\x89\xa1\xfa\xaa\x9f\x3c\x0e\x39\x90\x5d\x48\x0b\x9d\x17\xe3\xfb\xc7\x5c\x31\x7b\x92\xbb\x4b\x6c\x3b\x78\x42\xd0\x6d\x29\x0c\x54\x47\x07\x71\xa7\x11\xbe\x7e\x97\xe9\x4f\x24\x20\xcd\x65\x1c\x37\x2e\x8d\xb5\x93\x4f\x27\x9a\xf9\xbb\xf1\xae\x0e\x90\x63\x68\x01\xc1\x98\x9d\xcd\x1b\x6b\xaf\x8c\x0f\xe6\xd4\x93\x95\x49\xc8\xac\x85\xbb\xe6\x08\x82\xfd\x13\x80\xd0\xa0\xa2\x2d\x02\xf5\x0f\x0f\xb7\x25\x93\x32\x63\xeb\x0f\x44\x68\x7b\x48\xcd\xa5\xa3\x9f\xf9\xa7\x02\x22\x51\x1b\x58\x83\x70\x81\x00\x50\xe2\xfc\xe6\x62\x96\x31\xc8\x9f\x78\x21\xc3\x45\x68\x6d\xdb\x33\x52\x6c\x71\x73\x5d\x44\xc7\x65\xf4\x26\x8c\x0a\xba\x45\xd2\xd9\x07\xbe\xe1\x9c\xe5\xa0\xb7\xd8\xa4\xfe\x98\xbf\x7d\x84\x65\x8b\x47\x0b\xba\xe2\x45\x50\xe7\xea\xd1\xbb\x46\x39\x77\x96\xef\x65\x16\xe6\xf2\xe1\x07\xf1\xcd\x29\x03\x53\x3a\xe2\x95\xb1\xd9\x37\xca\x7d\xa6\x18\xfb\x54\x71\x6c\x8b\x9a\xc7\xf0\xd9\x7d\x8c\x64\x45\x2c\x54\xf7\xe3\x7a\xe1\x8a\xf2\xd8\x5a\x6c\x33\x5d\x40\x4d\x55\x66\xe7\x5b\xe9\x73\x47\xf1\x37\x70\xdb\x4c\x14\x73\xd1\xa6\xbd\x93\x6c\xca\xe9\xad\x2f\x02\xc8\x11\xc7\x68\x01\x45\x27\xcf\x0f\xe5\x6a\x7b\xde\x47\xd9\x9f\xb8\xe8\xb6\x13\x27\x2d\x1e\x15\xf7\xc4\x56\x45\x09\x56\x5d\xb5\x02\x46\xca\xce\xa8\xd8\xf2\x01\x15\x70\x5b\x28\xd7\x1d\x3b\x0c\x92\xb1\x81\x45\x62\x49\x43\x7c\xa8\xe2\xac\x6c\x2f\x7b\x0a\xf5\xfb\x3c\xa8\x8c\xc0\x79\x1e\xd2\x26\x48\x44\xce\x0b\x03\x86\xca\x39\x6d\x55\xd4\xbb\xb0\x4b\x63\xf7\xab\xe3\xf6\xbf\xdc\x02\x30\x8f\xde\x78\x34\xc7\x75\xdc\xd6\x4d\x00\xc4\x61\x71\x47\xd3\x37\x44\x72\x09\x9d\xe7\xca\xc7\x1d\xe7\xbb\x78\x1e\xe7\xe9\x9c\xb4\x55\xbd\x2b\x91\x20\xfd\x5b\x7a\xc7\x0e\x50\x3d\x3b\x43\x62\x2b\x13\xe9\x4e\x8a\x13\xbd\x76\xe0\x9e\x85\xcd\x0a\xdf\x8d\x75\xc4\x15\xa9\x1a\xaf\xb0\x67\xa5\x5c\x27\x4c\x41\x33\x14\xcd\x53\x01\x00\xbc\xa5\x2d\x73\x47\x22\xa4\xdf\xf7\xdd\xff\x67\x32\x01\x1a\x4f\x17\x32\x8b\xd8\xbb\xdb\xa8\x03\x56\x0c\x26\x95\xc0\xa9\x41\x92\x83\xc2\xf3\xd2\xc4\x14\xca\xfb\xf1\x24\x49\x61\x81\x23\xa5\x6a\x6e\xbd\xf3\xd8\xb2\xc8\xec\xf9\x49\x09\x8f\x0d\x9b\xc1\xec\xac\x8a\x19\x98\x20\x60\x65\x08\x16\xd5\x03\x83\xd0\x4f\xb8\x90\xf6\xaf\xae\xe3\xac\x6a\x4e\xb4\x7e\x3c\xf4\xdc\xfb\x33\x68\xfa\x00\xe1\x5b\x2b\x26\x05\x52\x63\xa1\x9c\x30\x71\x3b\x69\xea\xd0\xde\x6c\xbe\xc0\xbf\x0e\xe6\x8f\xd6\x68\xac\x8e\xbb\x20\x4e\xd8\xa2\x0b\x56\x63\x19\xd3\x34\x92\x41\x7b\x02\xb2\xb8\x3a\x67\x32\x5f\xa3\x14\x0d\x77\xfe\x2b\xbc\x62\x3a\x14\x01\xa0\xc7\x8e\x92\xa0\x85\xf8\x91\x4e\x74\x88\xb3\xc9\xe1\x3f\x88\x57\xac\xfd\x31\x69\x76\x7b\x8e\x65\x18\xf8\x56\x00\x0f\x8e\xde\xbe\x1b\x0d\x7d\xc2\x4b\x29\xe5\x70\x3f\xb7\xad\x43\x77\x0c\x18\xa8\x78\xb9\x7b\x48\x03\xf0\xa0\x87\x36\xef\xe8\xeb\x4c\xd8\xb0\x4d\x74\x9f\x2f\x03\x7d\x57\x24\x4c\x11\xab\x69\x0b\x2b\x77\x52\xff\xd4\xe0\x2f\x47\x7f\x98\xda\x99\xf9\x92\x09\x75\xe8\x4e\x7a\x90\x9b\x74\x7d\x46\x13\xbc\x9a\x7f\x51\x09\xd2\x5e\x1d\x5c\x51\xeb\x39\x60\x86\x64\xec\xcb\xea\x95\xee\x8f\xf0\x49\x82\x97\xd7\xa7\x69\x54\x52\x36\xa7\x9a\xa2\x0c\xd8\x0c\xbe\xa5\xe9\xb8\xa3\x58\x5e\x60\x21\x62\x55\xc9\x2a\x61\xad\xf8\x67\x37\x6d\x65\x82\x8e\x28\xe7\x17\xcb\xf6\x79\x78\x38\xaa\x8b\xd0\xaa\xdb\xe6\xee\x2f\xc4\x74\x66\xeb\x44\x49\x97\x1d\x86\xec\xac\x14\xd1\xb7\x49\xd4\xb7\x3a\x8a\x4c\x3c\xe8\x25\x7a\x9c\xcf\x64\x9b\x70\x1e\xfb\xce\xc9\x5d\x6b\x4e\x3b\xc4\xf1\xdd\xff\x3c\x1d\xe0\x48\xb5\x2c\xc6\xac\xd6\x75\x6b\xa5\x5d\x97\x3d\x4c\x73\x2b\xbc\x2b\x60\x8f\x09\x9d\xaa\x41\xb0\xfc\x78\x89\xc0\x5a\x21\x89\xf9\x28\xd7\xeb\x25\xff\x2b\x9e\xa2\x3a\xf0\x28\x80\x49\xa4\xe9\x50\xce\x04\xfd\xae\xd0\xca\x57\xa3\x67\xee\xf9\xd6\x75\x43\x97\x99\x33\x5c\x1e\xd0\x30\x4c\xb6\x1a\x20\x89\xa3\xbb\x83\x2e\xf0\x1a\x57\x54\x97\x34\x1b\xd1\x10\xc4\x8c\x1a\xd1\xbe\x62\x40\xcc\x1d\x9e\xa0\xe4\x36\xe4\x85\x4c\x2c\xc9\x48\x53\xea\xca\xb3\x98\xca\x97\xb9\x07\x2b\x58\x6a\x9a\x6b\xac\x0a\x18\x9d\x6b\xe4\xd1\xb2\x4f\xf9\x82\x55\x86\x9f\x19\x9d\x9c\x53\x54\x8a\xe4\x5d\x89\xb4\x58\xdf\x0e\x57\x92\xcb\x03\x5b\xbf\x47\x84\x0f\x5c\x27\x57\xd2\x23\x7f\xce\x98\xbf\x70\xa4\xf8\x6e\x89\xb3\xb4\x5c\x0c\x77\xac\xc2\xa0\x7e\xc1\x43\x1e\xaa\x10\x61\x39\xba\xa0\x67\x53\xd3\xcd\xf5\x26\xf4\xe6\xba\x89\x73\x0a\xb1\xe0\xdc\xe8\xd7\x8d\x97\xed\x05\x77\x45\x10\x03\xec\xfc\xc1\xe5\xa6\x29\xdf\xde\x06\xb3\x1d\xec\x0f\xfa\xbb\x83\xc5\x74\x22\x91\x71\xbd\xde\x3f\x2a\xcb\xa4\xf1\xd0\x1f\x7c\xd5\xd2\x89\xa1\x7e\xc7\xc1\xe0\x56\x45\xd2\xbb\xa8\x97\xb3\xbc\x77\x0a\xef\xef\x10\x2e\x96\xb6\xf1\xca\x38\x0e\x05\x92\x16\xad\xe9\x51\x40\xe3\x29\x99\x35\x49\x06\x38\x6d\x75\xc5\xba\x6d\x2b\xcb\x8a\x57\xcb\xca\x95\x99\xea\x25\x63\x37\x5f\xfd\xac\xa7\x3b\xde\x90\x21\x4e\x50\x1e\x9d\x93\xce\xfd\x23\x26\x44\xab\x00\x31\x17\xca\xca\x38\xff\x93\x14\xff\x28\xd9\xe5\x33\xca\xa5\x97\x88\xbb\x01\x2a\x22\xd8\xe1\x49\xb2\xa2\x13\x04\x58\xc6\xe6\x10\xb7\x83\xf3\x73\x1c\x1a\xef\x33\xa5\xf2\xf5\x82\x48\x20\x50\x58\x1e\x9d\x17\xe5\xef\x40\xd6\xc0\x51\x16\x86\x15\xd2\xdf\x99\x5a\xcf\xba\xea\x0a\x20\x64\x3d\x58\x8d\x25\x1e\xad\xb3\xf1\xd8\x51\x2f\x53\xb7\x09\x8f\x19\x2b\xb9\x6c\x82\x3a\x5d\x98\x43\x36\x9d\x2a\x64\x10\x8d\x4e\x85\xa5\xb8\xc3\xc7\x09\x6a\xcf\xde\x3c\x28\x46\x52\x3a\xb9\xa7\xe9\x0f\x10\xe9\xa4\x44\xf8\xc4\x84\x72\xee\xf3\x60\x72\x22\x28\x68\x85\x85\xcc\x4c\xd1\x5e\xff\x44\x47\x26\xc8\xc6\xea\xd1\xf2\xa3\x8b\x79\xd6\x7b\xe0\x02\x7f\x3c\x7f\x08\xe0\x84\x81\x33\x10\x7e\x80\x26\x7a\xe9\xb0\x65\xd1\x7a\x3d\xfb\x34\x1c\x09\x2a\x60\xee\x7b\x06\xac\x6e\x2f\x73\x4d\x3b\xc9\x77\x89\xd1\x27\x08\x31\x3b\x21\xd4\x99\xec\x14\xea\xbb\x73\x4b\xef\x11\x1c\x99\x6d\x45\xb8\x3b\x90\x43\xaf\x58\x01\xa5\x74\x88\x20\x3e\x95\x01\x1d\x37\x5d\xa1\xd2\xe0\xd4\xd7\xe3\x49\x5b\xb4\xea\x31\x9f\x31\x75\x9b\x15\x62\xb3\x1f\xd6\xd2\x77\x08\x17\x47\x80\x5f\x75\x69\xdc\x5e\x36\x76\x98\x39\x62\x33\x98\x94\x44\x40\x7a\xc9\x8e\x83\x18\x05\xfd\xf1\x70\x14\x3c\x45\xba\x2d\xe8\xf6\x6b\x44\x5e\x31\x6d\xd0\x7f\x6f\x1e\x96\x26\xce\xd0\x30\xb9\x56\xef\xad\x62\xc4\xa4\x70\x94\xa3\xb0\x8d\xc6\x7c\xee\xaa\x20\x0c\x76\x58\x49\x3c\xba\x1f\xe0\x69\x57\x09\xf6\xff\xd6\xe4\xd6\xdc\x48\x2a\x99\x11\x8e\x72\x0e\x5e\x13\xce\xd1\xbc\xb8\xe1\x10\x0f\xa8\x82\x7c\x09\xd1\x29\x19\xbc\xe7\x3c\x9a\x72\x55\xb5\xed\xda\x6b\xb8\xfb\x74\xd4\x1a\x68\x57\x63\x1a\x04\x94\x27\x09\x6f\xc2\x72\x0d\xcc\x9e\x66\x82\xf0\x3d\xf9\xdb\x9c\x3c\x0f\x8f\x7d\x8c\x9e\x46\x5e\xfa\xde\xce\x32\x80\x23\xf0\xb1\x1e\x83\xae\xf9\xc7\x9d\xac\x67\xe0\x88\x6e\x46\xf7\x15\x5e\x33\x05\x95\x5b\x5e\x4a\xd7\x9a\xac\x88\xdd\xf3\x58\x02\x8f\x83\xa1\x41\x83\x89\x50\x48\xd6\xba\xa5\xc1\x02\x98\xea\xa1\x30\x63\xb8\xe6\xdc\x36\xee\xba\x8a\xba\xa7\x7c\x38\x6a\x6a\xf6\xc2\x3c\xed\xc0\xe1\xe0\xe2\x68\x31\xaa\x9b\x90\xa4\x1e\x25\x95\x23\x67\xd1\x46\x45\x06\x1d\xb9\x98\x24\x2b\x92\xc2\x02\xdd\x86\x81\xb0\xe7\x88\xf4\xcf\x58\x56\x6f\x6d\xf7\x14\x54\x06\x0d\xd3\x40\xf3\x49\xa1\x76\x69\xd9\x37\xc3\x56\x31\xfe\x0a\x5b\x26\xf7\x57\xee\x7e\x34\xee\x41\x2b\xf8\xfc\xf2\xd4\x7d\x72\x29\x34\x93\xa7\x61\xdf\x74\x54\xc0\xc0\xff\xa4\x54\x95\x9e\x15\x96\x69\xb5\xb9\x25\xce\x93\x43\x95\xea\x26\x81\xbb\x38\xb9\x90\x6f\x05\x2d\x8e\xd6\xf0\xfd\xdc\xeb\x57\xc8\x47\x55\xe8\x6b\x8a\x0b\x3e\x7d\xfc\x26\x06\x1a\x25\x1b\x8f\xd7\x0d\x5f\xf5\x64\x4a\x8e\x05\x23\x5d\x3c\xa7\xb6\xf0\x82\x87\xa8\x97\x64\x84\xa6\x2c\xa9\x0b\x63\x6f\x89\x50\x9f\xcb\x1c\x9b\xfe\x91\xef\xac\x6e\x90\xef\x0a\x9c\xfc\x56\x0f\x86\xdc\x48\x5a\xc8\xe1\x10\x24\xb1\x8e\xa6\x59\xb0\x8f\x0f\x62\xb1\x0e\xee\x29\xd8\x5c\x58\x31\x68\x1a\x42\x0b\x8b\x0e\x48\x0f\x5f\xd1\x75\x87\x4a\xf7\xf0\x64\x70\x70\xa1\x99\xff\x64\x98\x99\x91\x9e\xd8\x92\xfc\x74\x3b\xab\x3a\xd7\x62\x98\x10\xc6\x57\x8d\x0c\x10\x61\xc5\x79\x8f\x28\xf4\x5e\x69\xeb\xa7\xfb\x8b\xd4\xa7\xb1\xaa\x60\xa8\xdc\xad\xeb\x2d\xca\xa4\xa0\xf0\xf0\xc3\x0e\x0d\x4c\xbf\x26\x28\x08\x31\xf8\x94\x6d\x83\x47\xaa\x9e\x6c\x9f\x48\xd3\xc6\x82\x86\x25\x9a\x1d\xa5\x5f\xa2\x40\x82\x03\x00\x6a\x60\x4d\x59\x6e\x0c\x54\x8a\x8c\x77\x21\x75\x42\x81\x13\x7f\xae\x23\xbd\xef\xb1\x32\x50\xc0\x95\x7d\x3a\x30\x46\x7c\xfb\x91\x44\x03\x68\xef\x61\x8c\x1b\x0a\x19\x8b\x42\xc2\x2b\x64\xc4\xd7\x56\xba\xe0\x19\xc8\x48\xe1\x3d\x39\x55\xb2\xd5\x72\x38\x3b\x96\x8e\xfc\xb1\xdc\x9f\x49\xd5\x58\x21\xec\xad\x54\xa5\xd1\xb9\x4c\x64\xa8\x67\x06\xf3\x33\xd8\x27\xbc\xbe\xc5\xc9\xc0\x81\xd7\xb6\x5e\x59\x9f\xae\x69\x5c\x09\xa1\x9c\xe2\x0e\x69\x48\x7f\x75\x38\x99\x82\x62\xe4\xd9\x79\xf2\xec\xf5\x95\xf2\x76\xac\x19\x29\xf9\x95\x58\x20\xcf\x84\x72\x8b\xac\xf4\xb3\x51\xdf\x25\x93\xba\x2a\xc2\xd2\xfe\x31\xfd\x54\xd1\x20\x2a\x4c\xde\xd1\x6e\x0f\xb0\xb9\x85\x0e\x39\x95\xe5\xcb\x71\x02\xf5\x6a\xbf\xda\x29\xa0\x1f\x5a\xdf\x05\xc8\x40\xe1\x84\x30\xcd\x73\xfa\x35\x9a\x89\x5e\x81\x3c\xff\x0a\xee\x46\x8c\xb3\xfd\xb4\x6f\xb0\x80\x54\x40\xb9\xfb\x2b\xca\xeb\xb4\x16\x80\x24\x38\x86\x5b\xc7\x5a\xe1\x59\x28\xa0\xd7\x27\x11\xb7\x40\x28\xed\x47\x23\x0b\xe5\x0c\x98\xd7\x21\x13\xe0\x74\x2c\x91\xfa\xb8\xed\xc5\xb5\x99\xd8\x1c\xdb\xc9\x3f\xbf\xfc\x9f\xa5\xdd\x2e\x25\xcc\x5d\xc0\x46\xa5\x82\x52\xfa\x43\x12\x86\xa2\xab\xe3\xd7\xaa\xb6\xe2\x0e\x30\x4d\x79\xba\x60\xe4\xb1\x77\x38\x94\xff\xf3\xdd\x6c\xbc\x0b\x68\x12\xb6\xa4\x9a\x3c\x3f\x37\x7e\x04\xe5\x49\xd1\xca\xbe\xc5\xa6\xa9\x2f\x61\xe7\xc1\x88\x2b\xa8\x9d\x00\xe7\x36\x82\xe0\x05\x69\xcb\x18\xb5\xb3\xf8\xb9\xeb\x7e\x16\xf0\x81\x35\xf5\xb9\x43\x4f\x36\x40\xb4\x62\x78\x11\xac\x96\x05\x1e\xd0\xdf\x2b\xf7\x2e\x59\xbb\xc8\x20\xf0\xb8\xd8\xc6\x35\x92\x47\xe0\xda\x62\x59\xfb\x76\x19\x55\x37\x9d\xdc\x27\xd7\x17\x0d\xd6\x22\xa5\xd8\x1d\x47\x82\x94\xaa\x88\xe0\x62\xd2\x4f\xc8\x29\x9b\xb6\xba\xaa\xf4\x46\xe4\xad\x43\xc0\xe4\x52\x21\x90\x1a\xc0\xaf\xea\x88\xc5\x9b\x26\x09\x95\xd6\xe9\x10\xec\x0c\xd6\xc0\xa0\x34\x55\x25\xbd\xd9\xd1\xf8\x5a\xb5\x4d\xdf\x4c\xfe\x5b\x02\x96\xf5\x4a\xc7\x89\x1b\x94\x52\x19\x27\xdf\xa6\xed\xcd\x0b\x8c\x9f\xd6\x0a\xe1\x8a\x44\xec\x61\xde\x41\x6f\x5e\xdc\xb5\x51\x3b\x51\xc7\xfd\x70\x48\x05\x48\xab\x0d\x55\x01\x3a\x09\xb7\xb0\x39\xd9\x20\xa6\x6a\x00\x49\xa0\x54\x74\x00\x4e\xa4\x63\x2f\x5b\xf0\xd4\xfd\x06\x81\x03\xe4\xb6\x19\x0a\x48\xbe\x75\xc9\xa3\x58\x95\x30\x43\xb6\xc1\x21\x40\x99\x6b\x81\x7c\xe5\xeb\x0b\x09\x69\x13\xaf\xbc\x45\x9c\x23\x45\x0b\x02\x8e\xb6\x64\x62\x5b\x6f\x86\x1f\xe9\x3f\x5f\x9c\xba\x1a\xa7\x39\x32\xb6\x56\x95\x8a\x00\x4d\x45\xca\xc3\x0b\x71\xda\xfb\xb6\x59\x13\x2d\x77\x0b\x86\x2d\x28\x74\x7c\x63\x82\x6d\x5c\x1c\xfe\xab\xc9\x6d\x59\x38\xb6\xf9\x24\x4c\xcb\x70\x5f\x8d\x89\x80\x45\xba\x71\xab\x83\x35\x75\xf8\xc0\xcf\x54\xf5\xd0\x03\x30\xeb\x8c\xac\x93\xeb\x0e\x9d\xeb\x4a\x1c\xc9\x9e\x82\xa9\x6d\xf5\x6c\x72\x87\xb8\xdc\x81\x9c\x62\xb3\x7d\x91\xf8\x27\x9f\x6a\x86\x16\x56\x9d\x35\x6a\x1c\xc1\x1b\xf8\x61\x4b\x7a\x05\x3b\x00\x90\x02\x16\x32\x91\x02\xe9\x91\x9e\x9f\x85\x38\x82\xc7\xa3\x1d\x61\xec\x58\xe5\xce\x5f\x97\x6b\xe7\xa3\x6a\x2f\x60\x4e\x9e\xb1\x2f\x5e\x75\xb3\x06\xc3\xfe\xcc\x55\x85\x97\xde\x64\x7b\xce\xc3\xba\x76\x11\x29\x44\x90\xd3\xf9\xcf\xe6\x63\x63\xad\x6e\x5a\x7d\x6d\x36\x38\xa0\xb2\xbd\x66\x02\x19\x06\x78\x24\x39\x82\xc4\x51\x41\x69\x30\x94\x8a\xde\xc4\x11\xea\xc3\x3d\xbf\x73\x6f\x05\x71\xdb\x03\x3f\x0a\x13\x4f\x29\xef\xc3\xbd\x0f\x60\xb8\x14\xde\x8b\xb1\xd1\x58\xb0\x4f\xa5\xd2\x1c\xf6\x06\xa3\x63\x84\x77\xcf\x69\xbe\xd6\xb0\x4a\xeb\xd5\xbc\x9e\xe7\x36\xd3\x54\xc8\xc5\x3c\x6a\xd5\xaa\xa1\xd2\x5d\x6f\x10\x8d\x03\x33\x97\x97\xd6\x2a\x67\x4d\xe3\xdd\x25\x8d\x45\xcb\x8e\x77\xa8\x6b\x75\x79\xd6\xc5\x7c\xf9\x36\x8f\x94\x8e\x76\xee\xf7\xb6\xcb\x83\xcd\xcd\x52\xab\x89\x4f\xcb\x1c\x63\xa3\x2e\x1b\x68\x9c\x4a\x3d\x9b\xd0\x2f\xa2\x1a\x16\x70\x97\xb0\x93\x34\x2c\x0c\x67\xe7\xec\x30\x55\xce\x48\xd2\x3c\xc0\x3c\x54\x9e\x62\x38\x86\x4b\xdc\x22\xc8\x21\xaf\xe7\x54\x73\x2b\xba\x12\x1c\xb6\x1a\xc4\x43\x24\x8e\x5c\x1b\x92\xdf\x5d\x21\x4b\x8c\x80\x22\xb5\xea\x1d\x15\x7b\x07\x76\x77\x3c\xfb\x3b\x31\xb9\xd3\x52\x4c\x73\x46\x64\x62\xa3\x4a\x36\x8b\x57\x53\xa6\xce\x14\x8f\x46\x14\xae\xee\x4f\x50\x44\xad\xd8\xfd\x76\x41\x28\x00\x0a\x2b\xd4\x8f\x09\x3d\x61\xda\xf3\x2c\x9c\xa5\xb4\x86\x20\xa7\xe1\x01\xf8\xa5\xd3\xcd\x70\x35\xcc\x1f\xaf\x8c\xff\x63\x29\x05\x71\xb3\x1b\xe6\xe4\x73\xa2\xb9\x23\xa9\x21\x39\xd3\x24\x0b\x8a\xed\x68\x72\xc5\x6b\x74\xee\xb0\x1d\xc1\x84\xdd\xf3\xc8\x95\xc3\x4b\xad\xfb\x99\xc0\x61\x2f\x76\xed\x1f\xbf\xa5\x56\x03\xdc\x68\xa7\x45\x23\x71\xd7\x2f\x4b\xbf\xea\x01\x92\x42\x39\x8e\x59\x5a\xae\xab\x38\x8e\x8b\x5b\x34\x98\x54\x38\x71\x25\x1c\xc6\x36\x84\x70\x1d\x55\xae\x27\x5f\xaa\x1a\x45\xb3\x6c\x71\xb7\x7d\x94\x68\x96\x83\x32\x9a\x8e\x93\x6f\xf2\xa7\x04\x5c\x49\x76\xdd\x47\x80\xde\xec\xa9\x9f\xd7\x34\x63\xc0\x5a\x23\x19\xfe\x10\x08\x6c\xab\x8f\x65\x88\xe4\x1f\x13\x07\x73\xa5\xb4\x51\x4b\x8c\x75\x3f\x3e\x5b\x7b\x9a\x3f\x4a\x99\x8e\x68\xd7\x6e\x0b\x19\x95\x2e\xe4\x8c\x57\x68\x75\x86\x55\xb8\xcd\x11\x4b\x29\x68\x93\xe5\xbb\x58\x2e\x6f\xe1\x14\x25\x49\x2e\x26\x4b\x70\x4c\x02\xd8\x7f\x15\x4d\xba\x3e\x49\x37\x49\x8f\x0f\x22\xd3\x0e\x9f\x53\x42\xe8\x9c\x88\xc4\xb1\xff\x8e\xc4\xf8\xf7\x7b\xda\x5a\x64\x1a\x8a\x80\x28\x56\xd7\xb9\xa1\x3b\xd9\xff\xbc\x8b\x3b\x9a\x61\x77\x77\x7f\x20\xae\x1d\x6c\x7c\xb2\x8d\x6c\x8b\xd9\xc3\x8d\x71\xbd\x95\xcc\x54\xf1\xa6\xbd\x38\x9f\x2d\x10\xf0\x8e\x8c\x2e\x2d\x6b\x29\x92\x3a\x63\xb9\x08\x88\xe6\xad\xe8\xcd\x05\x40\x58\xa9\xe2\xa3\x00\x76\x42\x6c\x77\x46\x4d\x40\x25\x02\xdf\xd6\x53\x88\xf1\xe4\x2c\x91\x79\xc5\x21\xc0\x60\x01\x5d\xbe\x2e\x84\xfb\x85\xfd\x23\x20\x24\xc7\x97\xde\xb8\x6f\x68\x02\xab\x28\x1b\xa6\x4d\x65\x3f\xb1\x94\x0c\xc6\x91\xe7\x4c\xeb\x4c\xf1\x5d\x4d\x9f\xcd\x5d\xab\xa7\xe1\x18\x77\xed\xa0\xb2\xdf\x8d\xec\x70\x95\xdd\x82\x72\xe0\xe1\xbd\xee\x70\x6b\xd6\x8e\x45\xe9\xb7\x83\x33\xaf\xb6\x65\x14\x5d\x55\x68\xf8\x51\x36\x9d\xf8\x44\xa9\x51\x5a\xc6\xfd\x87\x9d\x75\xe0\x72\x2b\x81\x40\xaf\x74\xba\xdc\xb2\xee\xa9\x79\x08\x1a\x10\xc8\xdf\x14\xe8\xfd\x4d\xf7\xae\x5a\x26\x91\x9b\x6f\x05\xe2\x43\xfd\x7b\xc8\x6a\x7c\xf5\xba\x52\xe4\x30\x75\x7c\xc1\xa2\x3f\x58\x61\xb4\x8f\xbe\x04\x70\x8a\x14\x40\xe4\xf1\xcf\x3d\x19\x54\x83\x08\x64\x19\xd6\xa1\xed\x66\x65\xf8\xab\x6d\x11\xaa\x70\x83\xe5\x02\xb2\xf9\x5c\x61\x93\xc2\xf0\x04\x5e\x63\xc6\x8a\xba\xe8\xd2\x53\x65\x16\x13\x0e\x40\x9d\x11\x85\x08\x68\x5e\x63\x82\x26\x5e\xd4\x93\xd9\xd7\x7f\x99\x69\xa7\x31\xce\xfe\x51\xea\x8c\x50\x75\x2a\x75\x3c\x33\x3d\x5a\x55\x18\x2d\x05\x0a\x93\xa5\xa5\xa8\x24\xce\x6b\x1d\x8d\x5a\xd5\x5a\xf3\x4d\x30\xa9\x8b\x8e\x34\x3a\xf7\xa7\x45\x56\xfb\xbd\x5a\xfb\x2f\x75\x52\x23\x83\x2c\x85\x68\x25\x54\x91\x83\xf0\xf5\x50\x6a\x3f\xbe\x99\x22\xb0\x98\x2a\xb2\xaa\x41\xcb\xa8\x98\xd6\x5e\x43\x35\x72\xe1\xf4\x3a\x56\xda\x64\xa3\xda", 4088);
	syscall(__NR_ioctl, r[1], 0x5000940b, 0x200007c0ul);
	return 0;
}