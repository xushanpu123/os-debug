// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = -1;
res = syz_open_dev(0xc, 4, 0x14);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000500 = 0;
*(uint32_t*)0x20000504 = 0;
*(uint32_t*)0x20000508 = 0;
*(uint32_t*)0x2000050c = 0;
*(uint32_t*)0x20000510 = 0xfffffbff;
*(uint64_t*)0x20000518 = 0x20000540;
memcpy((void*)0x20000540, "\xa8\xf3\x9c\x07\x72\xe2\xc6\x17\x75\x2d\x54\x85\x4e\x06\x18\xbe\xa9\xaa\x2d\x09\x98\x63\xd4\xd6\xa3\x64\xb0\x72\x75\x3c\x45\x11\xc5\xe1\x0d\xf7\x1e\x79\x9a\xaa\xdc\x20\xef\x22\x3b\x93\x26\x77\x6a\xf5\x79\x65\xf9\x49\xb6\xfc\xf9\xe8\xe2\xbf\xae\x3f\xec\x61\xb1\xed\xe0\x7b\x85\x41\xc8\x19\xfa\xab\x14\xfe\xb8\x47\x4a\x81\x74\x03\x97\xad\x4d\x5a\x4b\x37\xfc\x62\xf8\x8f\x0a\x90\x49\xcd\x77\xe5\x7e\x31\xd9\x83\x86\x5c\x53\x38\x2c\xb9\xbb\xbc\xa1\xf2\xba\xc6\x4a\x90\x3f\x73\x4f\xa5\xe5\xb2\xbe\xf8\x1a\x0a\x46\x48\xdc\xee\x2b\x4e\xab\xa4\x40\xfc\x64\xc4\xe3\x1a\x3e\x3d\x37\x31\x51\xcf\x3f\xf0\x71\x41\x8d\x6c\x2d\xfd\x2b\x20\xeb\xbc\x56\xca\x84\x17\x45\xa6\x5b\x1d\x38\x48\x2c\x10\xfc\x23\xc3\x7b\x50\x1f\x17\x4c\x91\xfb\xc1\x91\xdc\x72\xcb\xd3\x3d\xde\x6a\x57\x16\x11\xc2\x34\x03\x34\x92\x35\xe5\x78\xef\x99\x07\xac\x50\x81\x2b\xf1\xe0\x23\x22\xdd\xcc\x4e\xda\xfe\x7f\x38\xe3\x99\xbb\x39\x09\x8d\x4d\xa4\x85\xa4\x44\x0f\x77\x90\x55\xac\x24\x13\xd3\xe8\x70\x1d\x6d\x05\x79\x9e\xf1\x1d\x50\xb4\x55\x96\x72\x7b\x9c\xb5\xee\x92\x62\xae\x2b\xc2\xbb\x22\x11\xc7\x9a\xce\x65\x23\x4b\x7d\x9e\x28\x6d\xa3\xa8\x4f\xa3\xb4\x75\xb2\x1b\x47\xc0\x70\xae\xa1\x61\x94\x80\x5a\x67\x86\x46\x35\xd7\x08\xa2\x0c\xcb\x84\xd8\x4a\x47\x4c\xd8\x05\x94\x8e\x65\x44\x57\x86\xb2\x79\x81\x6b\xc7\x09\xd7\x5e\xf5\x31\x17\x6f\x6e\x1c\x1d\xd8\xfe\x5a\xe4\x1e\x37\xf0\x5f\xd4\x28\x01\x04\x0f\x56\xea\x7b\x5e\x61\x14\x8b\xf7\x21\x48\x88\x0f\xca\xd5\xc0\x90\xd5\x3b\x91\x5d\x26\x33\x2c\xdb\xdf\xee\x8a\x3b\xc2\x6c\x6a\x76\xc5\x86\xff\x34\x4b\x82\xef\x4d\x4a\x7f\xd9\x8c\x5b\x78\x1c\x0d\x64\x08\x62\x5b\x75\xe5\x13\x6b\x41\x2d\x69\xd6\xd1\x69\xbc\xda\x0c\x49\xdf\x63\xc4\x6a\x8a\x1b\xce\x58\x39\x66\x68\x60\x51\x38\x3f\xdc\x20\x36\x6f\x65\x6a\x96\x45\xdc\x3d\xc2\x30\xd5\x01\xde\x6f\x64\xa1\x0a\xc8\xcb\x20\xf2\x5a\x29\x54\x82\x20\x96\xc0\xbc\xaf\x97\xed\xfe\x2c\x6a\x97\xff\xa3\x55\x23\x57\xd9\x6f\x6d\x1d\x42\x91\x4c\x1d\x63\x14\x0d\x34\x72\x34\x6a\x72\xe5\x5f\xa9\xc5\xf8\x00\xfa\x1a\x0d\xda\xbb\xdd\xeb\xf5\x3a\x95\xfe\x95\x2c\x25\xb5\x80\xcf\xa8\x46\x0c\xe9\xae\xfa\x47\xb0\xb4\x30\x54\x70\x95\x2f\x7c\x3f\x52\x8e\x2d\x13\x6e\x81\x56\xab\xec\x06\x31\x7a\xf2\x14\xa4\x26\x0d\x72\x01\x6b\x36\xd9\x40\xca\x35\x29\x40\x63\x83\x95\xa8\x9e\xc8\xa0\xd1\x8c\xc5\x1e\xbe\x42\x85\xfa\x72\x26\x30\xec\x27\x2e\x27\x62\x17\x05\x56\x24\x16\xa4\x10\x32\x73\xa3\xb9\x5a\x79\xd4\x75\x2d\xbc\x0f\xe0\xc5\xb8\xaf\x48\x06\x54\x26\x25\xbc\xd8\xa6\xde\x86\x92\x4e\xa5\x19\xd2\xd7\x07\xc8\xc5\x08\x77\xf1\x1d\x02\xf1\x8c\xb5\x99\xd9\xfd\x3a\x07\x32\xb9\xf7\xde\x58\xf3\xaa\x12\x35\xc1\xd7\xa5\xa2\x18\x24\xff\x50\x1c\xd0\x63\x89\xef\x60\x31\xdc\x54\x3a\xa5\x2b\xe0\x71\xf6\x43\x82\xd4\xdd\x16\x57\x1b\x05\x5c\x43\x57\xa5\xc2\xaa\x2d\x8f\x1b\xc3\xb2\xe4\x42\x1b\xd5\x62\xda\x0e\xd8\x69\x42\x62\x18\xd9\xae\x69\x00\x0e\x9e\x92\x8b\x13\x1d\x98\x67\xf5\x75\x27\x8f\xaa\xb4\xa7\xae\x06\xda\x61\xf6\xc1\xf4\x43\xf4\x85\xdc\xae\xfc\x1b\x0f\x48\x6a\x27\xff\x30\xff\x3d\xd3\xb1\xea\x63\xb2\x09\xea\x9d\x00\x45\x04\xbd\x19\xc2\x82\x8d\xb1\xe1\x47\x2e\x4c\x71\xaa\x66\xbb\x42\x25\x50\x1a\x06\x85\x6c\x27\x18\x38\xfb\xa6\x9a\x42\xc0\xbf\xac\x44\x3c\x87\x42\xee\xc9\xfc\xb9\x43\x2f\xac\x29\x4b\x66\xc8\x00\xc1\x4f\x31\x27\x0c\xee\x0a\x25\xcb\x0b\x7e\xc6\x97\x67\x6d\x21\x0a\x66\x0d\x27\xf9\x1c\x15\xa7\x79\xad\xbc\xb7\x04\x32\xab\x58\x4b\x1d\x2f\xd1\x70\xa7\x1e\x01\x84\x6b\x47\xfe\x28\x4b\x8f\x2a\x7f\x16\x6a\x3f\x64\xb7\x83\xd4\x87\x2a\xd9\x3f\x95\x34\x12\x15\xac\x12\x94\xd7\xaa\x2e\x29\x0c\x9f\x37\xac\x96\xb3\x4b\x11\xf6\x32\x16\xe2\x48\xce\xa0\x40\xac\xec\xb6\x9a\x22\xb8\xfa\x45\xab\x71\x15\xac\x2b\x67\xcf\x1e\x38\x4c\x25\x48\x7b\x5f\xcf\x88\x8d\x21\x7e\x25\x8d\xcb\xb3\xb4\x42\x8d\x5c\x7d\xed\x60\x70\xd7\x56\xb1\x5e\xc8\xcd\x47\xe6\xe3\x55\xd6\xa5\x6d\x34\xb8\xd0\xec\x75\x9a\x44\x4c\x32\x75\xf3\x04\xb7\x28\x75\xdc\xb2\x09\x02\xb7\x1c\xc7\xc1\x3b\x2c\x96\x33\xc4\xef\x9a\xd0\x8a\x8b\xeb\x28\xa3\x83\x2a\x90\xe3\xda\x24\xe9\x3a\x50\xc5\x43\xd4\x63\xb1\xcb\x6c\x20\x12\x24\xcc\x61\x61\x2b\x0c\x77\x32\x42\xcf\x5b\x88\x88\x76\x87\x65\x78\x8c\x08\x93\x5a\xb2\xb8\xc4\x55\xa4\xdf\x73\xc0\x6f\x69\x02\xdf\xca\x62\xa1\xe6\x52\x1c\x6c\x62\xfd\xa4\xab\x11\xcf", 1024);
	syscall(__NR_ioctl, r[0], 0x4b72, 0x20000500ul);
	return 0;
}