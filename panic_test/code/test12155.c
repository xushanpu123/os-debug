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

uint64_t r[5] = {0xffffffffffffffff, 0x0, 0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000d40, "keyring\000", 8);
memcpy((void*)0x20000d80, "syz", 3);
*(uint8_t*)0x20000d83 = 0x21;
*(uint8_t*)0x20000d84 = 0;
	res = syscall(__NR_add_key, 0x20000d40ul, 0x20000d80ul, 0ul, 0ul, 0xfffffffb);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x400000ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000dc0 = r[1];
*(uint32_t*)0x20000dc4 = 0;
*(uint32_t*)0x20000dc8 = 0;
memset((void*)0x20000dcc, 0, 28);
memcpy((void*)0x20000500, "\x65\x6e\x63\x3d\x6f\x61\x65\x70\x20\x68\x61\x73\x68\x3d\x33\x68\x61\x31\x5f\x6d\x62\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe8\x16\x17\x89\x00", 82);
	syscall(__NR_keyctl, 0x1bul, 0x20000dc0ul, 0x20000500ul, 0ul, 0ul);
*(uint64_t*)0x20000700 = 0;
*(uint32_t*)0x20000708 = 0;
*(uint64_t*)0x20000710 = 0x20000100;
*(uint64_t*)0x20000100 = 0x20000140;
sprintf((char*)0x20000140, "%020llu", (long long)r[2]);
memcpy((void*)0x20000154, "\xba\x48\xfa\xa6\x17\x81\xb7\x9b\x49\x81\xee\xa7\x9b\x8a\x22\xc4\x60\x09\xe5\xfc\x46\x29\x8d\x02\xf4\xd3", 26);
memcpy((void*)0x2000016e, "\x45\xa6\xdd\xb1\x38\xbf\x56\x88\x5f\xa8\xa5\x00\x05\x7b\x15\x61\x9f\xf3\x8c\x8a\xd1\xde\x2b\x1d\x3b\x7c\x69\x6e\x04\x31\x42\x43\xf5\x67\xe8\xf0\x6a\xf5\x89\x3f\xd4\x7c\xb8\x2b\x18\xb7\x20\xe3\x39\x79\x86\x5d\x6e\xd4\xca\xd2\xf3\x48\x1f\x8a\x60\x7c\x16\xe0\x2d\xb1\x3f\xd0\x9d\x81\x1e\x3c\x72\x97\x13\xef\xb3\x97\xef\xbc\xba\xb0\xa3\xfd\xf8\x1b\x61\x5c\x6b\xeb\x14\x32\x9a\x31\xa2\x54\x7e\xdd\x6a\xfa\x08\xf5\x9a\x91\xc0\xa1\xb9\xaf\x50\x27\x8a\xc3\xb6\xcf\x86\x79\x46\x1a\xe8\xf2\x06\x90\xbb\x8b\x3f\x76\xb6\x8b\x6c\xa6\xde\x8a\x8d\x26\x32\xf1\x54\x55\x97\x6d\x42\x2c\xd2\x15", 144);
*(uint16_t*)0x200001fe = r[0];
*(uint8_t*)0x20000200 = r[0];
*(uint64_t*)0x20000108 = 0xb8;
*(uint64_t*)0x20000718 = 1;
*(uint64_t*)0x20000720 = 0;
*(uint64_t*)0x20000728 = 0;
*(uint32_t*)0x20000730 = 0x48004;
	syscall(__NR_sendmsg, r[0], 0x20000700ul, 1ul);
memcpy((void*)0x20000040, "keyring\000", 8);
memcpy((void*)0x20000080, "syz", 3);
*(uint8_t*)0x20000083 = 0x23;
*(uint8_t*)0x20000084 = 0;
	res = syscall(__NR_add_key, 0x20000040ul, 0x20000080ul, 0ul, 0ul, r[1]);
	if (res != -1)
		r[3] = res;
*(uint64_t*)0x200000c0 = 0x20000240;
memcpy((void*)0x20000240, "\x2e\xbb\x90\x36\x9a\x38\x50\xf2\x0a\x79\xc0\xb9\x56\x8a\x8e\x31\x18\x1f\x23\x30\x50\x39\xbf\xf8\x24\xe0\xd0\xc9\x7c\x85\xaf\x1b\xf0\x3a\x6a\xca\xe5\x01\x53\x7a\x6c\x76\xcc\xa1\xba\xa8\xf1\xd1\x65\x8d\x7b\x98\x0d\x45\x22\x4b\xcc\x95\x28\xe6\x27\x0d\x94\x38\xaf\x5d\x84\x2b\x66\xef\x31\x48\xe5\xed\x30\x00\x60\x47\x69\x5e\x5b\x38\x47\xee\x7f\x5d\x01\x69\x1d\x51\x54\xf7\x9e\x8b\xcc\xd3\x76\x0d\x19\xe0\xc4\x9e\x7c\xb4\xe3\x2f\xdc\x4b\x7a\xd0\xe6\x60\x45\x93\xb4\x10\x0b\x97\xdf\x44\xce\x21\xd4\xcd\x12\xbb\xf8\x3e\xdc\x06\x48\x86\x93\x8e\x05\x5d\x95\x50\x41\x64\xaf\x6c\xae\xa0\x88\x59\xaf\xc4\x22\xb5\xb9\x1b\x0c\x53\x89\x31\x50\xe6\xc3\x14\xa1\x7a\xf0\x53\x9b\xee\xeb\x5c\x90\xc6\x52\xe6\xf2\x5e\x53\x43\xb3\xbc\xba\xd3\xe7\x59\x35\x54\x35\xf0\xc4\xfa\x61\xbd\x25\xd2\xb6\x6d\xb2\x5d\xe5\x29\xb8\xdf\xc8\x8a\xda\x61\x83\x4d\xd0\xe7\x5e\x16\x6d\x85\x62\x59\xad\x13\xe4\xf6\x2c\x19\xed\x8e\x93\x4a\x42\x65\x90\x4c\x5a", 229);
*(uint64_t*)0x200000c8 = 0xe5;
*(uint64_t*)0x200000d0 = 0x20000340;
memcpy((void*)0x20000340, "\x3d\xdc\x96\x76\xaf\x8b\x94\x89\x3a\xc8\x1e\x4f\x5c\xe7\xb1\xf3\x40\xc8\xe8\x60\x6a\x2d\xc5\x96\xef\x96\xb0\xb6\x30\x8b\x95\xb9\xef\x37\xa8\xcb\xdd\x7a\x19\xa0\x57\xdd\x71\x6f\x00\xf3\x88\x48\xab\x1e\xb7\x9d\x77\x58\xc8\x58\x80\x1d\xbb\x9c\xb5\xc8\x2e\x36\xb1\xf1\x66\x5a\x6c\x1d\x55\x4d\x8e\xcd\xa8\x51\x90\x7b\x17\xdc\x53\x97\x84\x78\x78\x4c\x76\xbe\x0f\xa5\x4a\x73\x1d\x12\xac\x04\x9e\x65\x75\x64\x29\xae\xc8\xb4\x9c\xe4\x7c\x22\x71\xaf\xbb\xda\x6e\x04\x55\xd6\x11\x62\xcf\x14\x48\x5f\x61\xaf\x34\xcb\xfb\x9d\x74\x81\x47\xed\xf7\x2b\x41\x7a\x67\x87\x2e\x75\x1d\x74\xa6\x07\x8e\x44\xdc\x3e\x9c\x38\xba\xe7\xb4\x94\xf1\xd1\xc7\x30\x85\x4e\xd1", 161);
*(uint64_t*)0x200000d8 = 0xa1;
*(uint64_t*)0x200000e0 = 0x20000400;
memcpy((void*)0x20000400, "\xd9\xbe\x6e\x23\x04\x55\xd3\xa5\x1e\xd9\xdd\x5e\x10\x20\x40\x32\x4e\x0f\x73\xb3\xfb\xdc\xf8\x9a\xcd\xf6\xcc\xf1\xdb\x32\x17\x69\xe9\x72\x94\xa0\xb1\x15\x9e\xa7\xe4\xe1\x94\xc8\x0d\xc9\x86\xa9\x6e\x52\x06\xf9\x44\xb8\x38\xcf\x35\x86\x4c\xc1\xde\x06\xcf\xef\x18\x9d\x39\x8f\x40\xbb\x9f\xf5\xa0\xda\x90\xa0\xcf\x32\x7f\x64\xa1\x57\xca\x88\x13\x77\xcd\x8e\x68\x9b\xd2\x33\x70\x53\xcb\xf7\xec\xe1\xd6\xb3\xd5\xa3\xe2\xa6\x2c\x87\x79\x90\x72\xdb\x5e\xb5\xb2\x22\x23\xa8\x78\xed\x5f\x0e\x0c\x17\x98\x55\xf1\x38\xe3\x49\xbc\xd5\x18\xd9\xc8\x89\xc7\x53\x0a\xae\x69\x00\xb4\xf8\x2c\x43\x5c\x9d\x1b\xd3\x50\xa8\x04\xfb\x32\xb7\xc2\x0f\xc2\xf1\x39\xa0\x90\x7d\xe9\x83\xe4\xbf\x94\x71\x28\x21\x6e\x0d\xc0\x3f\x17\x98\x4c\xc1\x72\xec\xba\xd0\xf9\x7b\x67\x56\x44\x62\xd6\xee\x08\xd0\x03\xf0\x97\xf2\xa6\x37\x35\xb2\x95\x43\x75\xb0\x32\x85\x0d\xeb\x33\xdd\x94\xf6\x6f\x2d\x1a\x16\x5a\xc1\xa2\xc6\x54\x2e\xbd\xab\x61\x9f\x93\xe8\x33\x6b", 230);
*(uint64_t*)0x200000e8 = 0xe6;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
	syscall(__NR_keyctl, 0x14ul, r[3], 0x200000c0ul, 4ul, r[1]);
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x40ul, 0ul);
	if (res != -1)
		r[4] = res;
	syscall(__NR_ioctl, r[4], 0x4c81, 0xaul);
memcpy((void*)0x20000040, "/dev/loop-control\000", 18);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x2000ul, 0ul);
	syscall(__NR_ioctl, r[4], 0x4c82, 0);
	return 0;
}
