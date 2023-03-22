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
*(uint32_t*)0x20000440 = 0;
*(uint32_t*)0x20000444 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint32_t*)0x20000450 = 0;
*(uint64_t*)0x20000458 = 0x20000040;
memcpy((void*)0x20000040, "\x91\x4c\x42\x85\x0e\xc2\x2b\xe3\xf4\x87\xaf\x4c\x40\xce\xc5\x18\xd2\x56\x95\xe1\x70\x7e\x8f\x30\x24\x57\x08\x09\xb5\xfe\x71\x09\xdc\x61\xa0\x94\xaa\x69\x31\x35\x8c\xce\x42\xa9\xdc\xae\x13\xcc\xac\xd2\xa1\xc3\xf3\xa5\xf5\x73\x20\xa0\xb0\x62\x4c\xb0\xcd\xfc\xaf\x07\xec\x86\x44\xbe\xa4\xb6\xf2\x52\x25\xcb\xdf\x17\xcd\x3e\x03\x29\xf8\x51\x5c\x76\x8c\x3a\xc3\x51\x42\x34\xdf\x31\x76\xcb\x8a\xd7\x93\x1f\x79\xbd\xc0\x97\xf2\x87\x78\x69\xef\xa4\x52\x09\x1b\x6f\x9f\x58\xaa\x91\x97\xcd\xd2\xc9\xce\xe3\x1e\xbc\xb4\x31\x3d\xad\x22\xa8\xee\x6a\x5f\xf4\x62\x58\x62\x6e\xaa\x66\xdd\x7d\x9d\xc2\x06\x42\xc9\xd6\x1e\x63\x80\x78\x31\xf6\xf6\x69\x43\x3b\xe9\xe6\xaa\xd9\x67\x8c\x96\x15\xb5\x3f\x02\x89\x38\x3e\xc7\x27\xfb\x8e\xbb\x31\x9f\xad\x9d\xff\xf1\x41\x5a\x4e\x9c\x31\x89\x2f\xd7\x22\x09\x96\x12\x74\x38\x6a\xe6\xe2\xa5\x3e\xda\xaf\xe6\x9b\xb0\xc0\x03\x7a\x3a\xfb\x07\x85\x13\x49\x5a\xfc\x0f\x18\xf1\xc1\x52\xef\x70\x52\x02\x2b\xb4\xc4\x2f\xfa\x1a\x47\xb4\xa9\x4c\x6c\xdb\x73\xdc\x16\x28\xed\xcc\x2a\x60\x5d\xe6\x2b\xd1\x76\x0f\xce\x35\x4b\x3a\x26\xcc\xdf\xf2\x3c\xdc\xfa\x73\xca\x29\x53\x43\x57\x82\x13\xe6\xcb\xa2\x96\xa3\x4b\xa8\x2a\x4f\x7c\xbe\xb3\x83\x53\x53\xe8\x2c\x0c\x99\x68\x30\x89\x70\x09\x9e\xfe\xc2\x6b\xb6\x20\x2e\x1d\xec\xb6\x9c\x65\xc5\xba\xeb\xd7\x0c\x97\x4b\x88\x75\x4c\xae\x23\x4d\xfc\x59\x36\x6a\x22\x47\xb0\x42\x3c\x35\xe5\x1b\x4c\xc6\x97\xcc\x1d\x03\xc8\xac\x97\x19\x3c\xcb\x7d\xe0\x5b\x78\x5f\x80\x79\xb6\x0e\x2e\x35\xfa\xef\xb4\x79\xc2\x29\x8a\x37\x08\x8f\x8a\x38\x34\x52\xfb\x37\x7e\xb0\xd8\x2e\x17\x83\xe0\xa9\x94\x7d\x10\x40\x98\x35\x40\x6c\x02\x37\x35\xe1\x66\x16\xf6\xf9\x55\xc8\xc3\x95\x22\x78\xe0\x8a\xe5\xe1\x29\xf4\x69\xcd\xb3\x0a\x2f\xbf\xfb\xa3\xc6\x6b\x98\x6f\xfc\xa8\x45\x16\xb5\xdc\xb7\x86\xe3\x33\xfe\x8a\xee\xc9\x49\x74\x33\x09\x46\x57\xe3\xb4\x95\xc1\x76\x4d\x96\x10\x77\x36\x77\xad\x85\x93\x7e\xf6\x94\x5b\x2a\xee\x9a\xdd\xcb\x5b\x67\x88\x97\xe6\xc3\x77\x29\xb7\xba\xb6\x35\x18\xf8\x8e\xa7\xe4\x0c\xae\x8e\xff\x69\x4c\x36\x42\x2b\x63\x12\x84\xfe\xa0\xe3\x5b\xf2\x06\x9b\x08\x9a\x17\x9b\x75\x16\x8b\x7f\xac\x83\x43\xf6\xdd\xdc\xb6\xc2\xf7\xe8\xf8\xb5\x3b\xda\xb6\xce\xae\xbe\xb4\xce\x7c\x0a\x48\x41\x49\xb9\xde\x97\xb1\xbc\x78\x48\x94\x60\xe5\x20\x90\xb8\x90\x3f\xaa\x11\xd5\xac\xa9\x27\xe3\x8d\xc8\x4d\x61\xba\x34\xf6\xb0\xe2\xc4\x00\x7d\x68\xab\xfc\x18\xa6\xcd\x86\x88\xf2\x58\x82\x15\x85\x46\xd0\xf0\x5d\x9b\x57\xa4\xe8\x06\xdf\x91\xd6\x0c\x2f\x26\xc0\x96\x23\xb7\x0c\xce\x46\xeb\xdf\xe4\x34\xad\x99\x09\x1d\xdb\xdf\x2f\xac\xa0\x1f\xc9\x89\x0b\x4c\xa5\x74\x4a\xb6\x15\x5a\x27\x8c\xbe\x65\x1e\x46\xbd\x82\x78\x28\xfb\x41\xe5\xf1\x2a\xcc\xdf\xbc\x2d\x6c\x0a\x7f\x1b\xd8\xf4\x32\xf4\x76\x41\x50\xb1\x04\x8b\xdb\x35\xe0\x23\xd8\xe5\x44\xb3\xc7\xc3\xf6\x04\xcf\xb0\x1b\x66\x36\x85\x41\xd8\x33\x4e\xbf\x48\xe4\x81\x48\x32\xe8\xf4\xf5\x23\xe2\x24\xa9\xc0\xfa\x87\x4b\x95\x0d\x2e\x51\x6d\x0a\x92\xa9\x68\x87\x0a\x0c\x25\x91\xbe\xc1\xd2\x59\xe7\xcb\x92\xbc\x36\x68\x21\xc8\x0e\x7a\x57\x5c\x4c\xda\xb3\x18\xdf\x20\xd8\x8a\xee\x04\x56\xf2\xf7\xda\x26\xcf\x8b\x26\x64\x1c\x13\x95\x96\x51\xad\x26\xd5\x85\xad\x63\xe9\xc4\x67\x39\x22\xcd\x55\xbf\xe8\x87\x8e\x35\x5a\x92\x32\x1e\x50\x56\x9d\xfe\x4f\xca\x47\xd4\x7f\xd1\xb2\x0e\x7b\x64\x5f\xf6\xd9\x3a\x0f\x8a\x77\xe7\x57\xde\x95\xd6\xd8\x13\x1c\xbc\x79\xb3\x9f\xc0\x3c\xef\x96\x28\x2f\x30\x10\xa5\x23\x0b\xf3\x8b\x46\x30\x25\x1e\x07\xa5\x36\xfc\x7e\x8a\x9f\x51\x2a\x86\xf8\xdc\x96\x89\x2f\x78\x83\xf2\xb0\xc2\xf2\x39\x62\xfb\xcf\x6f\xab\x03\x52\x70\x30\x4d\x43\xc6\x28\x1b\xf7\xd4\x15\xdd\x11\x32\xfb\x06\xb2\xd2\xff\xb1\x7f\x99\x70\x3e\x22\x3b\xb7\xc1\x80\xd4\xbf\x71\x83\x7a\x55\xcb\x6e\x45\x47\xbf\xcf\xf9\xc7\x33\xe2\x22\xf4\x8f\xbd\x47\xd6\x27\xe5\xbb\x44\xe4\xde\x1c\x70\x02\xde\xe1\x69\x44\x81\xe7\x58\xe1\x8b\xb3\x23\x7d\xa7\x40\x24\x64\x9e\xad\x5d\xc1\x46\x57\x27\xd3\x1a\x21\x79\x98\xe2\x10\xbc\x9b\x9c\xcd\x1f\x2e\xe3\x1c\x5a\x14\xff\xcc\xa0\xa4\x5d\xe1\xc9\xab\x9e\x02\x24\x59\xdc\x14\x5e\x3a\xbd\xb1\xd5\xcc\x16\xbe\xdc\xa5\x3f\xe5\xa4\x9f\x05\xbb\xe4\x54\xa8\x41\xa2\x7c\xed\x65\xdb\xd3\x54\x6c\xa8\x8e\xcb\x45\xaf\x39\xc3\x63\xd0\xad\x6d\xa7\xe3\x6d\xac\x66\xe4\xe0\xd8\xd8\x03\x1a\x39\x58\xda\x6e\x4c\xd2\x91", 1024);
	syscall(__NR_ioctl, r[0], 0x4b72, 0x20000440ul);
	return 0;
}
