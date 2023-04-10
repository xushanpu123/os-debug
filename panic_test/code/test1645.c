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
memcpy((void*)0x20000000, "#! ", 3);
memcpy((void*)0x20000003, "./file0", 7);
*(uint8_t*)0x2000000a = 0xa;
memcpy((void*)0x2000000b, "\x96\x2e\xdc\xa1\x40\xe0\x9a\xd8\xef\x79\xff\xbc\x09\x34\x2e\x4d\xeb\x30\x93\x47\x2c\x46\xed\xb1\x72\x46\xb9\xac\xba\xc8\x3c\x97\x6a\x6b\x88\xf2\x53\xed\x12\x8b\x4d\x7b\x06\x9f\x36\x0e\x7c\x3d\xf5\x6d\x5b\xd9\x80\xfb\x51\x9e\x8d\x7b\x91\xd7\xd9\xcb\x37\x23\x59\x06\xf9\xfa\x77\x37\xe5\xad\x0a\x1d\xe0\x28\x2f\x00\x81\x43\xd9\x05\xca\xbe\xcb\x46\xd7\xaf\xf5\xb7\xbd\x3a\x67\xe5\x64\xee\x01\x7a\x50\xbf\xd3\xc7\x86\x7e\x56\xce\xab\x14\x17\xb1\x3a\x3e\x64\xc1\x74\xe0\x49\x65\x51\x3a\x4b\xc3\xe4\x11\x22\xe2\xa0\x56\xcd\x20\x35\x74\x33\x96\x32\xfd\xcd\x7f\x12\x21\x57\x15\xbb\x4f\x9c\xb8\xd9\x4b\x19\xf8\x26\xb2\x5e\x66\x63\x90\xac\x9f\x54\x8b\x7a\x2e\x1b\xfb\xb4\xe8\xcd\x66\x91\x7e\x76\xfc\xe5\xcf\xf8\xb4\xba\x22\x3b\xda\x2a\x20\xcc\x00\x15\x2b\x14\xb5\xcb\xd6\xdd\xf9\x63\x12\x95\x9f\x5f\x07\x27\x4f\x28\x3d\x1d\x7f\x62\x13\x14\xf4\x35\x02\xba\xe8\xc3\xc4\x6a\x70\x6a\x91\xd6\x2f\xa2\x30\x16\x77\xa1\x74\xc4\xce\x85\x53\x5e\xbf\xe8\x03\xa1\xc4\x47\x4e\xd3\xe6\xcf\x18\x11\x6e\x1e\xe2\x74\xe2\x97\x18\x42\xd4\x91\x03\x58\xbd\xcf\xf2\x05\x31\x2c\x1f\xed\x1d\x09\x24\xd2\xb3\x24\xe0\xed\x86\x19\x5b\xa4\x8a\x12\xa8\x4e\x5c\x1e\x82\xd1\x6f\xe0\x4b\x8d\x64\xc0\x1a\xa2\x33\x9c\x13\x31\x5d\x4e\x95\x29\xcc\x93\xe3\x07\x2f\xc2\xf4\xcc\x03\x42\x38\x02\x36\x1d\x42\x21\x69\xbe\x82\x22\xa1\xc6\x14\xf4\x52\xe5\x32\x98\x71\x93\x37\x01\xf2\x9b\xdf\x5e\x78\xbe\x7b\xe5\x5c\x8e\xe3\x17\x08\xea\x00\x70\x73\x5f\xc2\x95\xe8\x44\xc0\x7c\xac\x68\x23\xa1\x05\x22\xf8\xd0\x3f\x31\x47\xe9\xec\x79\xfe\x3f\xf9\xd2\xb9\x02\xe4\x59\xe7\x90\xfd\x1d\xc8\xa3\x5e\xd3\x43\xe2\x36\x1d\x94\x6a\xbd\x3d\x6f\xb7\xb7\xae\x82\x6e\x01\x19\x00\xab\x86\xd2\x85\x85\x99\xd2\x96\xd1\x5e\x94\x74\x6d\x27\x6d\xcd\x7e\x0b\x11\x37\x8f\x54\xf0\xcd\xcd\xcb\xa9\xc5\x1f\x72\x56\x78\x4b\x58\xea\x30\xfb\x9b\xf3\xa1\x8f\x3e\xaa\x77\x29\xab\xe0\xfa\x6f\xd5\x4d\x37\xb8\x64\x8c\x33\x8c\x60\xdd\x8b\xa7\x7d\xdb\xd3\xd7\x4d\x75\x95\x78\xc2\x1b\x9d\x65\x94\x47\xac\x80\x3e\x52\x63\x2b\xb0\x63\x8f\x47\x93\x17\x3e\x17\x66\xf4\x68\x7f\x30\x45\x43\x42\xca\xee\xff\x50\x00\x8f\xa1\xc6\xa7\xf3\xd2\x49\x89\x2c\x2a\xab\x7b\xb6\x42\x12\xa1\x9b\x03\x76\x0a\x9d\xa4\x0b\x36\xb5\xa0\x9c\x19\xd7\xbe\x8b\xc7\xd1\x64\xed\x05\xf9\xf2\x2c\xba\x9a\x93\x9e\x24\x9c\x71\x1c\x38\x56\xab\xfc\x1d\x38\x44\x84\x5c\x5d\x80\xf0\xd5\x65\x04\x7a\xc4\xdf\x30\xd4\xdc\xd3\xc1\xe2\x05\x06\xde\x83\x6c\xca\xd2\xe2\xa0\xce\xe7\xe8\xb7\xc6\x85\x2c\x40\x72\xa2\x8f\xdc\xb2\x34\xe8\x37\x74\x0a\xe9\x4d\xa4\x69\x2e\xf4\xa6\x9a\x1c\x25\x3c\x28\xbc\x07\x81\xea\xbd\x7a\xa8\x8d\x10\x81\x19\xd7\x07\xa9\xf3\x55\xd4\x14\x4b\xdc\xa5\x8b\x08\x6e\xdf\x53\x57\x02\xf0\x92\xe6\xe4\x44\x4f\x5f\x60\x87\xc6\x0b\x9a\x05\x98\xcc\x2e\x1d\x62\x31\x6e\x32\xf7\x38\xce\x46\x91\x82\xe5\xa5\xc7\x08\x13\xfb\x23\xbd\xb8\x33\x90\xb7\xb3\xbf\x01\x5e\x15\xb7\x47\x2c\x38\x8b\x4a\x51\xe8\xe6\x85\x0c\xae\x08\x34\xb1\x0d\xb3\x21\xed\xa7\x37\x1e\x1f\x70\xaf\x51\x69\x9f\xb5\xa6\xf0\xe4\xb5\x8d\x6c\x54\xda\xb9\x3b\x9f\x71\x04\x27\x70\x44\xae\x43\x7e\xe1\x74\x9d\x10\x47\x0a\xe3\xa7\x93\x45\x41\x2d\xbe\xbc\xa9\x03\xfc\x1d\xf7\x2c\xaf\x45\xa8\x89\x42\xa5\xfa\x7b\xcf\xc4\x05\x48\xf3\xf9\x5e\x60\x3e\xf6\xb3\xbb\x65\xe2\x7f\x05\x9d\xac\x76\xeb\x87\x04\xac\x68\x05\xd6\x9c\x82\x43\x27\xcc\xb0\xb9\x41\xe0\x7b\x9d\x6e\x48\x4a\x40\xfb\x21\xff\x0d\xb4\x04\xee\xe4\x50\x19\x0d\xe6\x62\xbc\x55\x7b\x62\xe9\x06\xe2\x86\xca\x2c\xdb\x9f\x4d\x4e\xbc\x25\xd0\x22\x4f\x76\x29\xc4\xc3\x62\xc7\x80\xf4\x1b\x2a\xa6\xa8\xb1\x1e\x17\x4c\xa1\x4e\x3e\xb4\x79\xb8\x11\xbb\x7a\xba\x1f\x42\xfc\x33\x77\xd3\xbc\xfc\x9f\x52\xf2\x5b\x46\xbe\x0d\x2e\x92\xf0\x48\x4f\x4b\x25\x2f\xce\x8b\x85\xda\x89\x53\x59\x9d\xc5\x35\xf2\xd1\x9b\xbb\x0a\xa3\xbc\x24\xb3\x23\xa9\x74\xa8\x38\x6f\x10\x9e\xa2\x48\x24\x05\x32\xcb\xe8\x1a\x62\x91\x80\xc9\x46\x49\x2e\x3b\xcc\xac\xc1\x81\x02\x94\xca\xdf\xc6\x2e\x3a\xc1\xe1\x71\xe1\x5e\x63\x43\xed\x6f\x8a\x06\xd5\xc0\x1e\x91\x27\x26\x1f\xc3\xf4\xfe\xfb\x07\xa8\xe4\xf4\x6d\xf3\xed\x09\x7d\xdd\xed\x3a\x7c\x9a\xfa\x2d\x1f\x2c\xa1\x09\xd7\x21\x54\x09\x39\xfa\x9c\xd3\x6e\x93\x42\x89\xd1\x4f\x8a\xf7\x4d\xa5\x5c\xae\x73\xdf\x28\xf3\x30\xb1\x7f\xfa\x75\x49\x96\x1a\x90\x69\x41\x66\xdc\x12\x8b\x53\x31\x17\x2a\x69\xea\x76\x38\xc0\x7c\x38\xde\x32\x73\xc7\x46\x78\x89\x25\xbb\x4a\x72\xaa\xb9\x28\x27\xae\x56\x59\x83\x0e\x44\x47\x24\x9f\x97\x67\xfe\x1c\x3d\x52\x0d\x54\xe6\xcf\x5a\x59\x11\x96\xcd\x88\xf9\x78\x42\x20\x98\xb5\x91\x99\xc1\x28\x51\x6a\x83\x2c\xfd\x9a\x4c\x39\xc5\xe8\x05\xde\xf2\x30\x9a\xf9\xc4\xe2\x92\xcf\x07\xcd\x7e\x02\x69\x13\xed\x3d\x75\x79\xc5\x53\x03\x8e\x27\xe8\xee\x74\x30\xd4\xdc\xc9\x93\x02\xe4\x61\xdf\x50\x7c\x2e\x1b\x59\x1e\xc5\x55\xf7\x9d\xcf\x91\xab\x7a\x88\x66\x23\x57\x49\x4c\xb7\xff\x5b\x4c\x8a\xdb\xee\x6f\xc1\xa1\xea\xc4\xdb\x86\x86\x70\x91\xe1\x49\x92\x4f\x51\x8c\x90\x70\xa8\x36\xe9\x92\x53\x7e\x51\x7c\xfa\x51\x15\xa4\x80\xcb\x91\xcf\x05\xad\x89\xe8\x49\x7a\x38\x90\xcb\x76\x6f\xad\x6e\x3c\x9e\x33\x36\x7d\x01\x54\xd0\x18\x88\x66\x4b\x9f\xd5\x04\xfe\x5f\x13\xac\xb2\xc3\xdc\x42\x08\x4e\xa1\xce\xad\xd4\x76\x17\xd3\x0f\x51\xd7\x4a\x42\x07\x39\xe5\x22\x68\xf6\xa8\x5b\xee\x52\x2f\x10\xbf\x87\xee\x1c\x70\xb4\x69\xc1\xc1\xa8\x6d\x74\x2c\x0f\xb8\xee\xb1\xbc\x66\x80\x9d\x95\x7d\xba\x70\xaa\xd9\xd6\x79\x87\x0d\x70\x6c\x54\xd2\xc4\xf9\xf8\x19\x9b\x13\xea\x69\xe9\x5e\x56\xa1\x76\xc0\x8a\xa8\x63\xbd\xea\xe0\x7b\xfc\xf7\x86\x3d\x46\xa8\xf1\xaa\xc8\xd8\x99\xd6\x00\xc0\xf8\x38\xb4\x34\x2b\xd9\x2d\x04\xbb\xd9\xd5\x78\xf2\x7e\x58\x0e\x40\x9f\x07\x54\x15\xae\xfc\x97\x88\x89\x2b\x7b\x5d\x25\xde\x02\x55\x10\x26\x2c\x2f\xfa\xb7\x43\x65\x74\x2d\xad\x67\x34\xd6\x94\x75\x93\xa6\x98\x17\xfb\xc7\xdd\x62\xa8\x09\xa0\xf9\xdb\x5b\x44\x59\xa0\x3b\x9e\xd3\x76\x78\xdd\x3c\xe1\xa0\x2f\x85\x28\x88\xac\x01\x36\x70\xfc\xd4\xbc\x34\x9e\x42\xdd\xcb\xb2\xab\x88\x3c\x6b\x12\x3c\x9a\x66\xc5\xe6\xbd\x09\xdf\x56\x50\x58\xc8\x83\x71\x8e\x07\x61\x25\xbd\xe0\x9d\x6f\x63\x71\xa1\x02\xba\x35\x6c\x99\xb1\x13\x48\x9a\x7c\x22\xa2\x03\x33\xbc\xcc\x6d\xe0\x0d\xba\x26\x41\xf9\x05\xf5\xf3\xaf\x0d\x72\xa3\x24\x42\xf8\x9a\xd3\x88\x70\x5d\x9b\x8f\x26\xb7\xf8\x3b\xe8\x25\x4f\x23\x8e\xe1\x38\x37\x9d\x66\x95\x62\xeb\x67\x04\x9f\xa5\x12\xd2\xde\xb3\x0e\xfc\xfd\x65\xb1\xae\x8e\x5b\xd8\x06\x46\xfe\x36\x77\x35\x43\x8b\x70\x08\x7e\x02\x34\x32\x07\x0a\xd6\xa8\x40\xd9\xd0\x39\xf1\x46\x86\x46\x46\xcc\xd0\x3e\x9c\xe1\x8b\x37\x3a\xbc\x75\x7d\xfa\x73\x29\x93\xe2\x8a\x1f\x40\xba\xd7\xde\x68\xe5\x65\xfe\x86\x6a\x2e\x7d\x96\x6d\x3a\xc7\xce\xb6\x78\x92\x80\x6b\x65\xd5\x92\xb4\xa0\xfa\xed\xdf\x39\xbb\x94\x0b\x23\xc7\x6e\x63\xff\x53\x46\xd0\x22\x1e\x4f\x2d\xcc\xed\x68\x93\x38\x06\x94\xa9\x72\xe0\x1f\xa4\xbb\xe4\x9e\x8b\xba\x15\xe1\x64\x58\x44\x59\x63\xa2\xb9\x9e\x35\xa9\xe5\x45\x67\x4a\x5b\xbb\x0c\x30\xbd\xd2\x45\x39\x87\x1c\xd1\x31\x4e\x50\x34\xde\x52\x9d\xe8\x5f\x3e\x6b\xde\x77\xf9\x7a\x34\xad\x84\x6c\xf7\xe3\x05\x12\xcc\x3d\x84\xcd\x35\x77\xbe\xda\x93\x5d\x4b\x6c\xb0\x8e\xd5\x95\x68\x97\x00\x11\x20\x83\xf1\xe5\x34\x42\x89\x62\x7c\x35\x71\x9a\x30\x2c\x8a\x5f\x9f\xd8\x76\x5e\xdf\x78\x33\xfa\xbf\x9c\x3f\x3b\x30\x89\xf0\x53\x77\xdf\xfd\x50\xcf\x51\x41\xed\x0b\xa3\x70\x15\x5e\x14\xb8\x04\x04\x0f\x73\xb5\xed\x73\x23\x3a\xac\xc8\xa7\xe8\x47\x25\x12\x44\xc6\xc3\x13\xbf\xe5\x30\xcc\xfd\x13\x24\xec\x06\xf4\xcd\xb1\x96\xef\xf7\x9e\x63\x4e\x5b\x44\xe5\x90\xb9\x30\x00\x0b\x56\x29\x1b\xeb\x7e\x02\x08\x04\x48\x38\xf9\xf1\xc8\x7d\x6d\xc3\xd2\x80\x46\x56\xae\x15\x6e\x6d\x28\xc4\x88\x9a\x16\xe4\x59\xa5\xe7\x81\x61\x3c\x39\x1c\x88\x29\xad\x36\x06\xd6\xeb\xd8\xc1\x0e\x67\xab\x55\x7f\xb8\x74\x50\x5d\xb5\x71\x85\xd0\x53\x5d\x30\xc4\x5e\xd4\x80\xd3\x9b\x76\x95\x1a\xa2\xbd\x6b\xa1\x49\xfa\x7c\x3c\x79\x98\xf4\x7e\x1b\xee\x05\x02\x37\xa2\xbb\xe5\xaa\x87\x5e\x13\x6c\x0f\x80\x1c\xb6\xe2\x4d\x73\x76\x7f\xde\x97\xa4\x56\x28\xcb\xcd\x41\xa2\xb0\x05\x19\x7a\x28\xde\x0d\xa3\x30\x47\xc5\x58\xb3\x92\x6e\x03\x7b\x37\xe4\x50\xf5\x6a\x08\x4f\x11\x2c\x17\x07\xd1\x14\x39\x6c\x6f\x9a\x50\xce\xf3\x26\x2c\xdd\x7a\x38\x83\x0d\x67\xe1\xec\x81\x65\xbd\x00\xe9\x56\xf0\x82\x2a\x6f\x06\x9f\xfc\xc2\x98\x91\xb8\x54\x86\xf8\x1e\x92\x9c\x76\x60\xf6\xf1\xc9\x17\x32\x48\x27\x52\x3c\x02\x81\x80\xff\xd8\x53\x8f\x3e\x18\x3d\x7a\xda\x04\xff\x68\x30\xb4\xc1\x9d\x80\x54\x79\xca\x99\x0c\xd9\xe1\x12\x33\xd0\xed\xa3\x47\xed\x3e\x67\x98\xfb\x60\xa6\xbe\x04\x41\x4e\x0c\x0c\xd0\x4e\xa5\x1a\x64\x17\xad\xb3\x3d\x8b\x1b\x86\x11\xc4\xd4\x6b\x20\xf9\x60\x98\xa1\x1d\x83\xc7\xde\x96\xa3\x01\xca\x7c\x2e\xf9\x2d\x4f\xa8\x4b\x6f\xe8\x12\x03\x5f\x3b\xeb\xcd\x72\x60\x72\xdf\xf3\xe9\x7b\xf0\x0e\x09\x40\xb1\x35\xe5\x36\xa6\x0a\x10\x9d\x23\x69\x86\x8b\x5c\xab\x6a\x62\xe5\xd4\x6c\x6b\x4d\xc4\x29\x13\x07\x51\x67\x52\x96\x27\x5e\x5a\xb2\xd7\x36\x7f\xe2\xb9\x08\xcb\xa5\xd2\xb7\x4a\xd0\xb9\x20\x8b\xab\x3b\x6e\xd6\x7c\x02\x87\x13\x22\xd9\xcd\x4e\x55\xdf\x4c\x89\x7d\xe9\x87\xb5\xe9\x23\x40\x9f\xa4\x4a\x3d\x92\x34\xdd\xc0\x9d\x0a\x62\x68\xb6\xe4\x11\x00\xaa\x36\x26\x08\xae\x8b\x84\xa9\xa5\x75\x7b\xdd\xf8\x16\x7b\xd1\x45\x13\xd9\x69\x50\xca\x99\xf0\xef\x58\xe8\x89\xcc\xc1\x23\x2b\x99\x83\x9c\x6b\xc3\xe0\x20\xf1\x12\x76\x59\xa9\x67\xa1\x16\x46\x6e\x76\x95\xf3\x45\xdd\xa4\xa5\x3b\x8f\x0d\xe5\x84\xe7\x04\x55\x06\xf1\xf5\x5b\x0e\x24\x2d\xc8\x78\xe2\xdd\xaa\x52\xad\xd6\x47\xf0\x1b\x6d\x8c\xc4\x1e\x52\xb1\x4e\x29\x88\x6d\x91\xb5\x26\xd9\x18\x6f\xdd\xe0\x29\x2f\xf5\x4b\x04\xc1\x71\xad\x9f\x1f\xa6\x1e\x96\x01\x05\x64\x61\x21\x80\x9b\xb3\x05\xac\xef\x7c\x53\x6d\xd9\x4f\x1d\x2c\x53\x3f\x8b\x4f\xa6\xa1\x10\x30\x73\xfd\xb5\xb7\x3e\x4e\x33\x0b\xf9\x70\xbf\x77\x1a\x51\x7e\x86\x7b\xd6\xde\x32\x54\x6c\x81\x70\x0d\x4d\xf8\x1a\xc1\x29\xff\x0e\x03\xac\x01\x2b\x86\x18\x77\xe4\x02\x5c\x30\xde\x82\x2d\x7a\x5e\xfd\x8c\x1e\xed\x30\x23\xe2\xe9\x2d\x9a\x4a\x41\xdb\x36\x5f\xf8\xf9\x59\x72\x41\x91\xda\xa9\xf6\x48\x05\xb6\xe5\x82\xa3\x3f\x42\x90\x67\x7f\xed\x0f\x32\xe7\x91\x51\xb9\x52\xd4\x02\x58\x85\x9d\x04\xeb\x43\x3f\xd4\x08\x59\x78\x87\xe2\xbd\xc2\x08\x10\x11\x18\x00\x6c\x0e\x8e\x0b\xc1\x01\xe0\x83\x59\x1a\x5d\x8b\xf7\xa3\xe0\x4d\x41\x78\xf3\x79\xac\xff\xb5\xdf\x7d\xff\xe9\x39\x1a\x2a\x45\xce\x3b\x28\xdb\xda\xa5\xc6\xe6\x74\xe0\xe6\xe4\x3c\xad\x5b\xfa\x31\x83\x49\xfe\x9c\xc3\x8d\x01\xb7\x59\xc8\xe3\x58\x94\xcd\x5b\x04\x30\xc5\xb4\x83\x55\xee\x93\x4c\xd6\x92\x51\x1b\x25\x19\x26\xb2\x3b\xac\xb2\xd2\x96\xa9\xa2\xfb\x74\x89\x4c\x0c\xd5\x1b\x12\x25\x70\xaa\x61\x69\xb5\xf3\x96\xa4\x70\x14\x13\xbc\xba\x9d\x3a\xb4\x85\x98\x87\x3b\x12\x84\xdf\x77\x30\xf8\x23\x1c\x77\xe1\x3b\xaa\x31\xac\x86\x88\x0b\x18\x66\xc3\x65\x4b\x78\x71\x1d\xdd\x74\xb2\x8f\x78\x16\x05\x6b\x07\x72\xb2\x4c\x5e\x1e\xeb\x1d\x01\x07\x22\x3d\x14\xe8\xff\x66\xa1\x70\x0d\x7a\xf0\xbe\x50\x6e\xe0\xbc\x9e\xb8\x51\xb8\x36\x54\xd5\xb1\x25\xce\xea\x78\x6e\x3b\xf4\x98\x1b\xdc\x8d\x13\x5e\x57\x06\x1a\x2c\xf0\x9b\x98\x77\x7d\x8d\x20\x1c\x02\xce\x6c\xf9\x3d\xf3\x30\x8f\x47\xfe\x62\xef\x8f\x74\xeb\x13\x7f\x6a\x36\x16\xfc\xfb\xa3\x57\xe1\xa7\xd4\x69\x4a\x81\xd6\xe6\x92\x32\xfc\x1b\x09\x5f\x36\x39\x9c\x29\x3b\xe7\x06\xb8\xc0\x88\xd1\x5d\xa3\xb1\xb4\xfb\x42\xf3\x78\xf1\xc7\x02\xba\x45\xf6\x4e\xa6\x76\x1f\x2c\x2f\x2b\x87\x6c\xdf\x05\x85\xc0\x70\xcb\x10\x4c\x9a\x05\xa1\x06\x80\xfd\x66\x08\x76\xa5\x5e\x43\xec\xf1\x61\xc5\xb0\xf4\x30\xa6\x80\x78\x7e\x30\x45\x99\x06\x70\xe7\xe9\xc9\xd0\xad\x86\xd1\x11\xbe\x9c\x5b\x50\x0c\x39\x15\x6c\xd5\x7d\x55\x11\xee\x54\x05\x54\x28\x9f\x2b\x26\x80\xb3\x53\xee\x26\x88\x82\xdd\x97\x4c\xad\x5d\x08\xbd\xb2\x50\x87\xf8\x32\xf1\x81\x50\xf9\x0a\x3c\xec\x7b\xa7\x7c\x8f\x5d\xe7\x6e\x0a\x05\x03\x14\xa2\x26\x07\x76\xa8\xc3\x20\xbe\xaf\xef\xa2\x58\x51\xea\x35\x92\xd1\x8b\xa3\x4b\x47\xf2\xf5\xff\xa1\x0b\xab\xa1\x0a\xf1\xb3\x00\x2b\xc2\xf8\x9a\x93\xce\x1c\xf7\x61\x62\x81\xd6\x7a\x26\x97\xce\xfb\xab\x5a\xd0\x13\x5c\xd8\x1b\xd3\x2d\x35\x2c\xcd\xa2\x0c\x79\xf6\x4e\x4d\x54\xdf\x2b\xd1\xa5\x32\xb5\xdb\x54\xc4\x36\x7d\x30\xad\xa1\x38\x3a\x83\xab\xaa\x5f\x5c\x6b\x7c\x4d\x70\x36\x4c\x7c\x2a\x7d\x9c\x70\x6f\xa7\xbb\x17\x69\x47\x70\x1b\x97\xa5\x03\xff\xbf\xe7\xe8\xc9\x36\xa8\x85\x49\x07\xf5\x13\x16\x58\xc1\x25\xe7\xd0\xfc\xad\xc4\xc4\x86\x68\x9c\x79\x6d\x83\x32\xb6\xeb\x65\xe6\x14\xbb\x6d\x8a\xfd\xe4\xbc\x29\x99\xfe\x9e\x24\x57\x73\xf4\x7d\x18\x43\x83\x6c\x94\xa7\x42\x0e\x18\x59\x22\xb7\x21\xe1\xbc\x1f\x69\xc4\x69\xbe\xdc\x97\x7c\xb0\x77\x46\x6c\xbe\x5b\x28\x01\x83\x2e\x81\xc9\x45\x9e\x04\x63\x8e\x11\xca\x38\x83\x1a\x9c\x5f\xf5\x84\xed\xb4\x14\xec\x5a\xd9\x6a\x36\x24\x3e\x0e\xce\x41\x25\x7e\xed\x7d\xc1\x1f\x7d\x5f\xc7\x55\x09\x22\x85\x41\xde\x3e\x4a\x92\x06\xd5\xc3\x55\x8a\xc6\x59\x5d\xbd\x9d\x2f\x50\x70\x31\x4c\x1c\xc7\x1f\x35\x33\x17\xc6\x21\x6e\x63\x04\x3d\xcd\x53\x46\xb3\x5f\x0f\xd4\xaa\x51\x74\x44\x87\xae\xc0\x66\x49\x6b\x3c\xa9\x7e\x03\xed\xd6\xbc\x69\x00\xcb\x48\xe3\x93\xed\xe2\x3e\xf2\x26\x16\xcc\x27\xde\xfd\xa5\x4d\x65\x65\xc6\x99\x5c\xd7\x0a\x22\x86\xfc\xb3\xe1\x20\x1b\x05\x31\x7d\x12\xcc\xb1\x77\x9d\x49\x40\x89\x5c\xa9\xb3\xab\xd3\xe6\xdb\x1a\x3e\x56\x84\xaa\xe6\xd4\x77\xe0\xad\x5e\x6b\x57\xd3\xe4\xc1\x0c\xb7\xc2\xc6\x20\xd1\xc7\xc5\xe1\x54\x29\xf0\xdc\x0c\x15\x86\x75\x13\xc3\x89\x1c\x93\xce\x39\x82\xc2\x04\x07\xe1\x25\xfc\xb2\x36\x0e\x26\xba\x15\x70\x04\xd5\xa8\x2f\x06\xa4\x6f\xb5\xfe\x7d\xfa\xda\x3e\x4e\x9f\x3b\x6e\xaa\x25\x26\x59\x7e\x30\x97\xfa\x9d\x5c\x3b\xc3\x44\xc5\xee\x3a\xbd\xce\xf1\x81\x9d\x34\x45\x52\xd9\x8e\xe4\x35\x3f\xa8\xa1\x20\x1a\x10\x70\x30\x0a\x7d\x44\xd4\xf4\xf2\x93\x78\x54\xce\x27\x14\x93\xc5\x72\x83\x5a\x15\x14\xfb\x41\xb9\x0d\xc3\xc4\x4b\x66\x61\xbe\x01\xa2\x17\xb6\x0d\xbf\x12\xb8\x9e\x0f\xd4\xad\x2a\x9d\x2f\xd5\xd1\xfb\x6b\x74\x3c\x24\x38\x3f\xaa\x8f\xf3\xdd\x75\x02\x8b\xc6\x9e\xaf\x16\xa2\x53\x70\xc9\xf7\x91\x46\x56\xc4\xc6\x13\xd4\xae\xb4\x1d\x3d\x7e\x8c\xd0\x2a\x63\xbe\x46\x9a\xec\x94\x49\xd7\xd4\xc3\x2d\x9c\x28\xdf\x81\x30\x22\x85\x03\x23\x0a\x11\x73\x82\x80\xa9\x7e\xfc\x58\xfe\xc5\x10\x6f\x55\xf3\xe7\x0f\xb9\x6e\x96\x92\xe0\x4c\x9e\x4f\x05\x75\x4a\x52\xaa\x6d\x22\x78\xea\xe3\xcf\x3d\x14\x07\x4d\xac\xeb\x5c\x07\x81\xd8\xf9\xa1\x2a\x99\xe5\xa8\x4f\x44\x9e\xfe\xcf\xbb\x21\x7c\xaa\xfc\xd8\xed\x45\x27\x02\x37\xbe\xad\x72\x7f\xea\x0f\xa3\x1b\xd7\xb6\x0b\x58\xce\x71\xc1\xdb\xb8\x79\xe2\x80\xec\xe9\x76\x9f\xe3\xa3\x6c\x74\x26\x0b\xf2\x0e\xf4\xd0\x51\xbd\xb0\x61\xb1\x38\x58\x8b\x51\xe2\x53\xef\x42\x3d\xa6\xe1\x22\x25\x54\xf2\xc3\x94\x29\x4f\xa0\x0c\xf4\x2a\xf4\xff\xa4\x28\x55\xd4\xfb\xb7\x6b\x1b\xa6\x47\xbc\x98\x2e\xc0\x13\x5f\x70\x09\x4b\x1b\xfe\x3a\xa4\xb5\xf9\x95\xa5\x4d\x7d\xaf\xc3\x38\xc5\x1e\x10\x30\x17\xf2\x47\x7a\x7d\x79\x3c\x9b\x6e\x68\xe5\x7f\xd5\xb9\xac\x42\x7f\x07\xd9\xd9\x82\xaa\x56\x87\x30\x48\x7d\x1d\x4c\x23\xe7\xb7\xd2\x23\x97\xbc\xf6\x74\xc8\xa9\xd3\x4c\x4e\xf5\xa3\xc9\x4e\x13\xae\xf8\xa9\xb8\xdf\x81\xb9\xa8\x4c\xff\x2d\x23\x6c\x82\xbe\x18\xdb\x0c\x11\x4c\x60\x74\x41\xbe\x9c\x30\x85\x6e\xfc\xaf\x37\x4c\xbf\x47\xd1\x6e\x2f\xc7\x4c\x58\x65\x25\x17\x63\x73\x33\xb8\xb2\x8a\xdd\xf4\x6e\x8b\xfc\xf0\x39\x48\x48\x1f\x42\xc4\xa6\x27\x6c\x7a\x1a\x1e\x42\x70\x37\xab\xfc\x0a\x95\xfa\x4d\xd5\xdc\x72\x53\x74\x12\x5b\x00\x10\xac\x07\x2b\xbf\xa8\x3a\x53\x01\x89\x31\xce\x6c\xe2\x1f\x74\xcd\xa2\x46\x5d\xa6\x68\x66\x39\xee\x02\xa3\xad\xd2\x79\x0c\x95\xc0\x31\xab\x99\x54\x8f\x93\x3e\xe0\x3d\xb0\x60\x55\xa6\x78\xa4\xe6\x1f\x9a\x9f\x46\xb0\xb0\xb3\x02\xcf\x46\x0a\x5e\xea\x8f\xc3\x04\x48\x69\x05\xd0\xfd\x16\x15\x94\xf1\x83\x32\xde\xcb\x66\xe3\xb5\x6a\x58\x02\x59\xf1\x39\x83\xc7\x02\x8b\xd5\xd1\x28\xd8\x9f\xaf\x67\xa5\x25\xb6\xda\xfe\x6c\xe0\x52\x86\xc1\x2b\xce\x9b\x2c\x27\x5d\x09\x82\xb8\x00\x87\xd9\x41\xc5\x33\x3c\xf8\x0b\x4f\x2b\x2b\x0d\x58\x2f\x69\x11\x7e\xfd\xbb\x87\x23\x17\x12\x3c\xef\xf9\xb1\x8c\xa0\xf6\xb0\xde\x6c\xba\x28\x05\xbf\x51\xb2\x35\x05\x57\xd4\x5c\xe8\xa4\x27\x6c\xb7\x28\x43\x73\x7c\x66\xe7\x6a\x1d\x35\x18\x31\x38\x0c\x6e\xc1\x86\x0b\xc3\x95\x4b\xec\x48\xf4\x4a\x83\x46\xc3\xb7\xf8\x50\xed\x1f\x48\x34\xdd\xb2\xc8\x96\x1f\xe0\x06\x3e\xf3\xec\x95\x8c\xc4\x45\x18\x34\x6e\x33\x91\x61\xd4\x43\x12\x27\x3c\x8a\x11\xa3\xcb\x87\xd6\x65\x16\x4a\x6f\xc0\x49\xef\xac\x0d\x9a\xd1\x9e\x64\xe6\x77\xf4\x13\xbf\x11\x9c\xa9\x9e\x52\x5e\xec\xff\x2a\x88\x72\x0c\x20\xc0\xec\x84\xf3\x15\xa6\xe4\xdb\x52\x91\x57\x03\xcb\xf1\xd2\x7d\xe9\x08\x1f\xc7\xb0\x5b\x3c\x0c\x83\x33\x14\x3d\x33\xf1\xef\x3f\x3b\xfc\x1c\x9e\xcc\x8d\x54\xaa\x2e\x1b\xc4\x55\xb5\xaa\xc7\x11\x14\xe8\x5f\x39\x08\x5f\x1b\xb7\xe7\xf9\xda\x07\xa9\x58\xb5\x46\x42\x94\x4e\x6e\x95\x0f\xd3\x34\xe1\x6e\x71\x6b\xe2\xf0\xb4\xcd\x53\x2a\x9c\x3e\x30\x1e\x3b\xd2\xe7\xbc\xaf\x0c\x83\x9c\x3f\x99\x88\xc7\x66\x01\x5b\x90\xf2\xa4\x82\x9c\x88\x55\xeb\x4c\xb9\x12\xbc\x19\x53\xd2\x71\xd0\xcf\xe9\x73\xe3\x33\xb6\xd7\xf3\x7a\xdb\x40\x52\x24\x45\x1f\x25\x6e\xaa\x33\xce\x97\x81\x7f\x3a\x5c\x1f\x73\xcd\x0c\x45\xd3\x78\xc4\x75\x48\x85\x02\x6e\xf3\xe6\xf3\x1c\x12\x9c\x4a\x2b\x14\x43\x76\xca\x2f\xa6\x74\x69\xdd", 4092);
	syscall(__NR_write, r[0], 0x20000000ul, 0x1007ul);
	return 0;
}