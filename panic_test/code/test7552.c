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
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001540 = 0x20000200;
memcpy((void*)0x20000200, "\xdd\x43\x74\x42\x88\x37\x8a\xcf\x21\x57\x91\xaf\x20\xfb\x72\x5b\x9c\x4a\x9c\x44\x6d\x7e\x7e\xc9\xb6\xc8\xf4\xc8\x1c\xcc\xad\xc6\x53\x13\x2c\x89\xd7\x3c\x2e\x15\x39\xe6\xe3\x1f\xe9\x9a\xfa\xf1\x34\x44\xd6\xc6\x2e\xf5\x50\xd2\xd7\x1b\x27\xe9\xf0\xa0\x17\xe1\xd7\x58\xa8\x6e\x70\x9a\x6d\xaa\x88\x41\xbc\xfa\xa7\xec\x1a\x0a\x3b\x92\x95\x88\xab\xe2\x8c\x80\xf2\x3d\x81\x61\x80\x97\x70\x71\x42\xba\x48\xb5\x43\x90\xbc\xa5\xc5\x94\xb6\xe6\x77\xea\x9a\xe8\x95\x7e\x27\x6e\xfe\x6c\x46\xf9\x59\xae\xe6\xc0\x56\xf9\x5e\x15\x55\x99\x49\x25\x95\xb4\x98\x6e\xbe\x06\xdf\x17\xb3\x2f\x20\x65\xb1\xa3\x06\x3c\xe1\xe9\xd4\xf6\xfc\x11\x98\xfa\x4a\xc5\x45\x9e\x6a\x8f\xf0\x3d\xf9\x4f\x6d\xb4\x6b\xaf\x23\x62\x33\x56\xab\xd7\x09\x79\xc0\x2f\xf5\x61\xfe\xec\x05\xf0\x47\x55\xb0\xc4\x9a\x63\x26\xf7\xcc\x1b\xc6\x44\xdc\xb7\x3a\xb2\xeb\x33\xe9\x3c\xb0\xa1\x48\x4c\x8b\x04\x3f\xad\x0d\x15\xd5\x26\x2f\x87\xa1\x11\xb1\xb1\xfe\xf8\xfd\x8e\x4e\xec\x10\x63\x23\xe8\x9f\x02\xe5\xc6\x78\x3e\xca\x17\x80\x7e\x14\x2b\x95\x11\x47\x42\x4f\x27\x0b\xab\xf5\x44\x6e\x1d\xcd\x5e\x71\xe6\x2b\xf4\x05\xef\x3d\x6d\x95\x7c\xfb\x29\x07\xfc\x34\x2a\x1d\x2e\xc3\xed\x2f\xad\xa2\x83\xe2\xe9\xac\x89\x04\x94\xe4\xe0\x93\xa3\x83\x7b\x6e\x87\xb8\xd6\xce\x32\x08\xd2\x87\x64\x83\x0e\x22\x58\xe7\x8a\x62\xc8\x3b\x73\x40\x8b\x48\x07\xd3\xa7\xb4\x1b\x06\x3e\x2a\x7a\x34\x8a\x2d\xbc\x29\x97\x3b\xc7\x33\x15\x39\xe0\xeb\xc6\x09\x6a\xb1\xfe\xd3\xe6\x5e\x1f\xc8\xbe\xe0\x57\x4e\xe5\xc4\x97\x32\xcb\x48\xd5\xaa\xac\x5f\xbe\x44\x79\xe1\x1b\x00\x25\x5b\xdd\xbf\xe1\x12\x0f\xe9\xf3\x5f\x83\x61\x27\x36\x6f\x1c\x46\xcf\x10\x8c\xe4\x6f\x16\x4d\x9d\x66\xc8\x96\x28\x0b\x2a\x81\x4f\x89\xac\x75\x01\xc1\xe8\x88\x3f\xca\x59\x7d\x6e\x6a\xf2\xa3\x24\x12\x5a\xa3\x11\xf2\x3d\xef\xd3\xdf\x3f\xe6\x11\xee\x31\x8e\xa7\xb4\xc8\x61\xac\x41\xb9\xb0\x3f\xf6\xa7\x28\x70\x5c\xbf\xa0\x63\x9b\x52\x4e\x61\x10\xd9\xe1\xbc\x66\xe1\x20\x99\x6a\x39\xae\xb5\x73\x92\x4d\x56\xe1\xdd\x35\xc2\xf8\x38\xf7\xff\xe9\xf7\xb4\xa8\x41\x52\x4f\x8c\x61\x6f\x0e\xe3\x56\x92\xcc\xa2\xa8\x3c\x3f\x3d\x47\xab\x30\xe7\xc5\x92\x0c\xb2\x8b\xc7\xb3\xff\x31\xe4\xff\x29\x1a\x92\x2b\x3e\x04\x6e\x47\x87\x01\x29\xf7\xcb\xee\x7e\x04\xf0\x90\x31\x85\x75\x51\xca\xee\x30\xd6\x5d\x19\x8f\x46\x41\xdc\x25\x8a\x34\xb8\xdc\xbf\x24\x24\x17\x2c\x9b\x8f\x95\x97\x83\xb2\xa1\xae\x9e\x60\xd2\xab\x71\xa0\x08\x16\x5d\xf5\x0c\x5a\x68\xf9\x95\x69\x3f\xef\x46\x42\x55\x42\xc8\x54\xd2\xd5\xef\x47\x4d\xfe\x41\xe9\x40\x21\xa1\x3d\x37\x32\xc6\xb9\xd0\x97\x18\x0b\xa7\x57\xc1\x17\x75\x95\x2a\xc2\x43\xad\xf4\xe2\xd1\x7b\x64\x09\x7d\x9b\xbc\x64\x43\x60\xe9\x93\x3c\x9e\xc6\x79\x0c\x84\x97\x8c\x0e\xa5\xd7\x61\x8a\xf2\xf8\xc7\xf5\x2e\xd2\x8d\x59\x74\x96\x6b\x0c\x35\x4b\x3b\x20\xe2\x64\x00\x97\x00\x3e\x3d\x7d\xa9\x6d\x80\xb4\x99\xf2\xe9\xf7\x56\xfe\x43\x7e\xe3\x2f\x2c\xe5\x64\xb8\x01\x00\x7b\x4e\x07\x9f\xdb\x96\x4f\x74\x9f\x6f\x6b\x50\xb0\x28\xcb\x36\xe7\xd1\x38\x71\x6d\x27\x41\xf7\x9f\x28\x29\x90\x90\xbe\xee\x83\x2e\x9e\xcf\xe2\x4b\xa7\x0f\xf7\x99\x38\xb6\xc4\xf6\x76\x32\xb4\x5e\x44\x69\x0b\x01\x0c\x5d\xc0\xf5\xe9\xf2\x19\x9d\xa9\xa2\xef\x33\x95\x92\x16\x49\x4b\x9d\xf9\x69\x59\xa9\x9b\x30\x36\x32\x99\x7a\x39\x8c\xb5\x5f\x9c\x97\xe9\xf5\x3f\x08\x36\x9e\xbd\x79\xf1\x14\xf4\x8a\x19\x7f\x30\x2f\x4b\xc3\xf7\x4c\x9b\x8c\x1d\xc2\xba\x9a\xcb\x35\x6c\xe8\xbf\x28\x3c\xfd\xd7\x6c\x86\xfe\x61\xdb\xd1\x46\x1b\xd3\x98\x49\x8d\x03\xef\xab\xc5\x28\xdd\x4c\x8e\x8d\x95\x11\x00\x8e\xbf\x02\x83\xbb\x4a\x74\x85\xce\x8e\x9c\xc0\x23\xdb\xe6\x0e\xc1\xfe\x50\x37\x88\x92\x7d\x4d\x73\x49\x17\x43\x0c\x14\xac\x70\x27\x15\x35\x26\x91\x7b\xa4\xc7\x43\xb4\xfa\x9f\x15\x3f\xd2\x74\xef\xdb\x62\xc4\xd7\x65\xc6\x90\xde\x8e\x5a\x80\xf9\xed\x5d\x2e\x5f\xe8\xbf\xcf\x71\x4c\x13\x6d\xf9\x81\xdf\x0c\xfc\x10\x1d\xc7\x2f\x49\x14\x55\xc1\x03\x69\x6f\x5d\xd6\x61\x48\x3e\x20\x27\x3b\x8a\x65\x9b\x16\xee\x2d\x54\x29\xd5\x78\x45\xdd\x83\xb9\x94\x84\xb8\xf3\x61\x08\xfc\x17\x65\x42\x4e\xf4\xa4\x44\x0f\x50\xe5\x3f\xe6\x39\x6a\x23\x6b\xf9\x21\xfe\x2d\xaf\xc9\x92\x44\xcc\x5c\x43\xaf\xf7\x52\x7f\x36\x2a\xeb\xfe\xab\x8b\xb7\xc6\x2d\x0b\xc9\xfe\xaf\x5c\xc6\xba\xbe\x5d\x94\xff\x00\x4c\xec\x02\xa0\xb4\x04\xe7\xf1\xdf\x0d\xc2\xf5\xe5\x00\xc0\x42\x6f\x88\x07\x9c\x45\x14\x46\xf0\x35\x28\x3c\x88\x8d\xcd\x49\x98\x8f\xad\x1f\x68\xc0\x40\x2f\x01\xee\x61\xa1\x55\x48\x28\xec\xe7\x31\xa7\xfa\x7d\x1a\x54\xb0\x46\xd8\x7a\x90\x09\x10\x08\x29\xd9\x6d\x34\xf7\x56\x71\x6f\x0d\x5e\x82\xc3\xca\x9d\x5d\xff\xf6\x10\x64\x85\xe7\x58\x90\x7a\x88\x6e\x22\x24\xab\xfd\x11\xd2\x02\x57\xf5\x7f\xf5\xcb\xcc\xd2\x59\xac\xbe\xa7\xc8\x16\xc7\xfd\xff\x4d\x82\x8d\xcd\xa5\x22\x04\x01\xa1\xed\x3d\x55\xa5\xd0\x19\x7e\x76\x6b\x14\x05\xc2\x11\x05\x3c\xa1\xad\x8a\x87\xf1\x80\xab\x7a\x24\x5c\x44\x40\xe0\xf1\x65\x5c\xa8\xa8\xb8\x22\xe9\xfb\x7c\xf2\x2b\x6d\x23\xf2\x03\xac\x8f\x0c\xcd\xbf\xba\x6a\x40\x11\x54\x29\xca\xef\x8e\x3a\x75\xf5\xa6\x86\x07\x1f\x90\x57\xab\x03\xcb\xbd\x41\x32\xc5\xa8\x96\x3c\x62\x11\x7c\xab\x07\xd8\x4e\x21\xf4\x0d\xfa\x6d\x91\x51\x85\xda\x7b\xac\xfa\x4e\x1d\x24\x4b\xaa\x0c\x47\x13\xc9\x59\xad\xc2\xab\x0c\x4a\x83\x47\x23\xfe\x60\x09\xc0\x9a\x0b\xb2\x47\x56\xa1\xea\xa4\xbd\xcd\xa2\xef\x19\x75\x65\xfd\x79\x58\x20\x22\x23\xd2\x62\x57\x05\x1e\x91\xc0\xc7\x52\xbf\x9b\xd1\x7d\xaa\xba\x6d\xb6\x3a\xa6\xee\xde\x48\xdd\x51\x41\xd9\x15\x2c\xa5\xa6\x28\x8a\x08\x17\x94\x1b\xe5\xcc\xcb\x77\xb0\x27\xfc\x38\x99\x48\xb8\x78\x56\x4f\x92\x78\xa0\x6f\x15\xa3\x98\xf5\x70\x52\x7c\x77\xf0\x96\x7e\xac\xb9\x24\x92\x91\x80\x8a\x87\xa3\x49\xbf\xed\xcf\xe3\x67\xab\xb5\xb5\xd9\x19\x5f\x8f\x20\x8b\x92\x47\xf2\x10\xad\x0d\x28\xd7\x8c\x26\x0c\x9f\xb7\x6d\xc2\xa4\x66\x6b\x7b\x9d\x88\x2c\xb2\x8e\x45\x05\x5e\x0e\x0c\x5a\x3e\xb1\x0c\x07\x05\x36\xeb\x40\x07\xbf\xb9\x16\x8f\x1a\x20\x1d\x6c\xa1\x68\xc7\x66\x1a\x03\x89\xd7\xbf\x5c\xdc\x3a\xa9\x89\x6c\xb2\xc4\xee\x58\x18\x01\x23\xbe\x20\x12\x27\x0d\x38\xf5\xf2\x36\xbb\x12\x94\xc1\xa5\xd0\x78\xfb\xb1\x87\x15\xac\x1d\xcc\xcf\x43\x76\xb4\xb5\x97\x23\xb7\x67\xaf\xb1\x15\x5c\x04\x67\x85\x58\x56\x18\xe9\x28\x51\x3f\x07\x58\x76\xd2\xbd\x43\xac\x8a\x26\xb2\xd2\x98\x54\xf2\xe8\x37\xc2\xf4\x0c\xa7\x91\x57\x4f\x6b\x87\x5d\x13\xf5\x8a\x12\x3a\xea\xd5\x6e\x4a\x53\x9b\x1f\xda\x6b\x32\x42\x16\x94\x4a\x73\x76\xba\x1c\xea\xbf\x43\x67\xbe\xb2\xd4\x07\xe2\xf7\xb0\x1c\xde\xd4\x5a\x50\xb9\x69\x60\x43\xfa\x9e\xe1\x6b\xba\xa8\xaf\xf4\xa6\xe8\x71\x4a\xc3\x87\x3d\x27\x4b\xbe\x5f\xe1\x40\x50\xd9\x69\xa6\x1b\x63\x21\x49\xeb\x38\xda\xed\x56\x7a\x55\x50\xef\x37\x71\xd2\x26\x2a\xe8\x63\xdb\xfc\x45\xb2\x93\x41\x70\xf2\xee\x4c\xcd\x84\xf4\x1c\xde\x34\x3d\x1d\xa1\x48\xaa\x68\x81\x59\x4c\x3f\xe8\x1b\xa3\x4a\x0c\xda\xd2\x84\x1b\xb0\x9c\xa6\xb8\x27\x22\x84\x06\x8b\x52\x8a\x62\x99\xb5\xaa\x6e\xec\xd2\x16\x42\xc7\xf4\xf6\x4f\x72\xaf\x03\x0b\x4b\xa7\x94\x72\xce\x75\x07\x4c\x70\xad\xb0\x86\xda\xf8\xee\x37\xde\xe6\xbd\x21\x13\x6a\x5d\x68\x95\xb0\x27\x7d\xa9\x91\xa1\xd4\x4e\xfa\xdf\x48\x2f\x6a\x3b\xbc\x6c\x54\x0a\x10\xc4\xe5\x68\x7c\x87\x0b\x16\xb0\x8d\xaf\x7b\x5b\x19\x9d\x33\xcd\xe5\x97\x19\x9b\x50\x6d\xc7\x7e\x5a\x6e\x59\xdc\x73\x98\x59\x3e\xb1\xb5\xe4\xa6\x45\x35\x55\xd4\x19\x5d\xa5\x55\xc3\xad\xfb\xe8\x03\xa6\xc8\xaa\x1b\x5d\x39\xe3\xc2\x80\x4d\x37\xb1\x39\xc3\x18", 1753);
*(uint64_t*)0x20001548 = 0x6d9;
	syscall(__NR_writev, r[0], 0x20001540ul, 1ul);
	return 0;
}