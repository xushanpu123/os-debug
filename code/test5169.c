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
memcpy((void*)0x20000100, "/dev/vcsa\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0xa01ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000140 = 0x208;
*(uint8_t*)0x20000144 = 0x75;
*(uint16_t*)0x20000145 = 0;
*(uint32_t*)0x20000147 = 0x1fd;
memcpy((void*)0x2000014b, "\x32\x44\xe8\xbc\xd6\x79\xe8\xd5\xfc\xbe\x4f\xbe\x04\xe6\xa2\xe4\xbd\x10\x12\xd3\xb9\x98\x15\x94\xaa\xa8\xf3\x8e\xab\x1d\x49\xe3\xc6\x08\x8d\x22\xeb\x2d\x97\xff\xe9\xe2\xa8\xbb\xfb\x98\xf4\x6d\x49\x55\xaf\x39\x82\x3f\xfe\x6d\xe2\xda\x51\xfb\xf9\x5a\xb9\x99\xdf\x4a\xf6\x9e\x42\x1d\xf4\xd5\xe6\x8d\x95\xae\xa3\x13\x54\xdf\x25\x81\xcd\xb9\xff\x29\xc5\x41\xd7\x7a\x75\xa4\x0d\xea\x97\xed\xed\xa3\x8f\xad\x76\xa1\xf8\x98\xbc\xb2\x51\xbe\x27\x02\x1b\xcf\x2a\x0e\x3a\xed\xdd\xed\x4b\x1e\xa3\x5d\x02\x41\xa8\xbf\xd4\x58\xa7\x8c\x6e\x1e\x0a\x5b\xb5\x97\x3a\xd1\xff\xd7\x40\x67\xd2\x18\xf4\x3f\xac\x0a\x48\xb1\x85\xf0\xa4\xc0\x2c\x2b\x53\x63\x11\xd0\x80\xc3\x50\x12\x3a\x5e\xda\xad\x7d\x8a\x95\x8d\x66\x87\x63\xc3\xc4\xf4\xa3\x00\x61\x89\x68\x75\x04\xd7\xe3\xd3\x34\xa8\x6b\x1d\x75\x26\x1e\xad\xc7\xee\xdc\xbd\xb6\x7d\x3a\x52\x05\xd3\x46\x7c\xee\x76\x6c\xf0\x9c\x14\x55\xfe\x06\xad\xfb\xd2\x25\x05\x5c\xed\xe1\xb0\x2b\xbd\x5f\x3b\x9b\x4d\xe5\x43\x3b\xae\xcd\x0c\xa5\x69\xe1\xd8\x01\x86\x1b\x6e\x60\xba\x38\x79\xfe\x8c\x1c\x92\x83\xb9\x29\x7c\xd7\x9d\x86\x1b\xe9\x21\x79\x97\x5c\xf6\x48\x34\xc8\x26\xe8\xa9\x19\xe8\x81\x53\xd1\x7c\x1c\x29\x53\xd1\xdb\x47\x38\x77\xdc\x8e\xe9\x81\x95\x65\xf7\x53\xe2\x6f\x81\xbf\xf2\x3f\x29\xda\x56\x8d\x94\xa4\x63\xa6\xd9\xaa\xeb\xb6\xe2\x44\xdd\xbf\x1d\x2b\x52\xf1\x3d\x8f\xd8\x12\xd9\xa2\x54\x26\xb0\x4b\xf1\x6b\xcb\x87\x5a\xdb\x91\xcf\x89\xaf\xdf\xec\xfe\x06\xaf\xc5\x52\xdb\xa4\x28\x6a\xe3\xdb\x79\x26\xa8\x1c\x59\xd4\x90\x5b\xb0\xc1\x7c\xb0\x30\x86\x74\x6d\xea\x8f\xe8\xf9\xf8\xa3\xcc\xe0\xcb\x9d\xe3\x16\xf5\x3c\xa6\xcb\x62\x17\x56\xd5\x5f\xd6\x7b\xb3\xd3\x3c\xfe\xab\xeb\x2c\x1b\xa5\xe1\x3a\xee\xbe\xb6\x10\xbc\xbc\x85\x84\x27\xe0\x27\xd8\x19\x05\x89\x8e\x11\x1b\x3a\x7b\xf8\x49\x8b\x60\xb7\xe8\xd9\x55\x36\xb6\x0e\x63\xfc\x3e\xa6\x10\x93\x09\x62\x06\x8f\x95\xf6\x38\x61\x6a\x6a\x56\x2c\x94\xea\x5f\x33\x4e\xb4\x58\x5c\xb5\x52\xee\xfa\xd4\xf3\x4b\x2f\x5c\x9c\x62\x86\xca\x55\x68\x56\x75\x18\x05\x75\x9e\x29\x53\xc0\x55\x40\x2b\xfd\x42\xf9\xad\x51\x8e\x29\x78\x9f\x4c\x0a\xb3\xed\x9b\xc3\x5b\x95\x37\xb1\x50", 509);
	syscall(__NR_write, r[0], 0x20000140ul, 0x208ul);
	return 0;
}
