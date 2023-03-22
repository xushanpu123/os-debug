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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 0x8b, 0x200001c0ul);
	if (res != -1)
r[0] = *(uint64_t*)0x200001c0;
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20001880 = 0x20000180;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint16_t*)0x20000190 = 1;
*(uint16_t*)0x20000192 = 0;
*(uint32_t*)0x20000194 = r[1];
*(uint64_t*)0x20000198 = 0x20000200;
memcpy((void*)0x20000200, "\x36\x4e\xed\xee\x61\x06\x8f\x12\x1f\x60\x4d\x35\x15\xbf\xc6\x0f\x7c\x81\x94\xd3\xdb\xb1\x07\x6c\x3d\x90\xef\xa8\x11\x17\x73\xb6\x8f\x07\xeb\x1b\x5c\x13\xc5\xc8\x9d\xf3\x78\x83\xb0\x93\x67\x6b\xac\x13\x58\x36\xb1\x09\x37\x33\x2c\xfa\xb7\x5f\xb3\xb8\x34\x5f\xa8\x43\xdf\x2f\x89\x52\x3b\x97\x1f\x46\xe1\x2c\x14\xaf\x9d\x81\x9d\x32\xe8\xad\xa5\x3a\xef\x8a\x36\xcb\x03\xc2\x3f\x5b\xd9\x8b\xc7\x0f\x12\x0b\xd0\xbd\x78\x84\x40\xdb\x5d\x8b\x65\x0f\x49\x44\x71\x2b\x00\xb0\x4b\x44\x4a\x96\x51\xeb\x63\x26\xc5\x12\x6b\x28\x8c\x5e\x84\x88\x6e\xe6\x88\xf6\x72\x50\x1b\xbf\xa6\xa3\x27\xbe\xe3\x25\x72\xa0\xaa\xc1\xc3\x1e\x04\xf5\xbb\x16\x08\x9d\x7f\x6f\x68\x7a\x9d\x45\x13\x6b\x0d\x86\x27\x9b\x1f\xb0\x82\x2c\x47\xac\xb0\x4a\x80\x67\xb7\xdb\xa9\x8c\x18\xd0\xc8\x9d\x31\x93\x46\xa8\x86\x33\xe1\x47\x8f\x71\x16\x7f\x7e\x05\x96\x96\x68\x53\x31\x14\xe6\xb2\x34\x38\xc3\x70\xa4\x76\x8e\x9c\xcd\xbd\x7f\x0f\x07\x4c\x42\xca\x0c\x9e\xcc\xbc\x01\x53\x67\x5a\x73\x71\xaf\x36\x0c\x3d\x9a\x05\x7b\xc8\xf0\xfc\xc8\x9a\x63\x53\x4d\xcd\xac\x78\x59\x1d\x6a\xfa\xf1\xfd\x41\xea\xaa\xaf\x5e\xd3\x11\xaa\x1b\x75\x05\xb6\x02\xb8\xb4\x14\xdb\x9b\x7e\x8c\xe8\x1d\xd5\x64\x6c\x26\x86\xf9\x1d\x3f\xd9\xc4\xeb\x40\xf8\x08\x3e\x52\x1a\xa3\xb0\x83\x29\x8f\xff\x6a\xba\x79\x69\xf3\x27\xd3\x2d\x2b\x48\x8d\x33\x32\x63\x22\x23\x26\x87\x32\x84\x29\x7b\x60\x1d\x09\x8a\xec\x25\x45\x2c\x70\x6c\x00\x57\xd9\xfb\xb7\xb1\xd8\x87\xbd\x85\xe7\xa8\xb8\xbf\xdf\x81\x2b\x2b\x51\xcd\xae\xbc\xef\x24\x2f\x2a\xae\x21\x8e\x7e\x8a\xb8\xad\x18\x16\x8f\xfa\x9e\x0a\x9a\x38\xeb\x7d\xc7\x34\x69\x0d\x69\x76\x14\x1c\xe5\x5e\x30\xad\xa7\x8e\xf9\x36\xe5\xa3\x30\xaf\x30\x5d\x5e\x5a\x2d\x6a\x09\x99\xe7\xe7\xb4\x23\x2a\x8d\x9c\x03\xba\xf4\xa4\xbf\xbc\xd0\xd9\x4e\x41\x1d\x47\x45\x47\xda\xb2\x6b\x0a\x75\x90\xfd\xd6\x55\xf8\x8d\xe3\xc7\xd1\x51\x6b\x13\x28\x95\xfd\x78\xaf\x48\xf1\x96\xf3\xe7\x88\xf5\x50\x69\x37\xc9\x35\x9f\x46\x35\xd7\x8e\xcf\x03\x65\xaf\xb4\x1c\x51\xf8\xd4\x2a\x91\xaa\x91\xf5\xb4\x16\x3a\xf1\xf4\x59\xfa\x4a\xeb\xac\xa0\x15\x9d\x91\x03\x69\x83\xee\x63\x6f\xb3\x3d\x5b\x20\x76\x8b\xf1\xdc\xa6\x9e\x1b\xbe\xb0\x85\xc1\x6d\x69\x7a\xc0\x6b\xa7\x6f\x74\x11\xe5\x64\x2e\x67\x46\xd7\xdd\x3c\xf0\x22\x0f\x82\xd0\x3f\xfa\xf0\x6d\xfe\xb6\x38\xd7\x87\xe1\xbe\xd2\x52\xfd\x21\xae\x55\x5d\xd5\xf0\x41\xbb\x18\x42\xdf\xdd\xe8\x58\xe4\x07\xc6\xf6\xa3\xec\x7c\x20\x39\x2c\x77\xe3\xdd\xc0\xca\xb6\x01\x71\xae\x9f\x4a\x30\x53\x73\x28\x79\x46\xe2\x04\xd7\xa0\xe7\x3f\xf1\x99\x9c\xaa\xf3\x13\x58\x63\xbe\x59\xef\xb8\xe0\x8a\xca\xd0\x38\xd5\xf2\x9a\xa6\x6f\xc8\x3b\x60\x15\xfe\x06\x03\xd5\x1a\xfa\x80\x14\xd7\x3b\xc5\x95\x44\x0e\x91\xa4\xc8\x75\x2a\x55\xc2\x3b\xfe\x13\xbc\x9c\x10\x2f\xa0\x16\x20\xc1\xad\xc5\x25\x1d\x92\x5c\xa7\x5e\xed\xad\xef\x1a\x03\xd8\xf3\x0f\x8d\xe7\xac\x68\x01\x28\xe0\xc8\x14\xc8\xd2\xc8\x0f\x3a\x36\xa2\xa2\x49\xfa\xac\x5b\x10\x1a\x44\xdf\x86\xa0\x21\x65\x79\x7b\x1d\x81\x61\xba\x4e\xda\x38\x68\x40\x53\x37\x60\xb5\x57\x99\xc1\xfe\x29\xfa\x8d\x3c\x2d\x44\xd2\xec\x1b\x16\x7b\xa2\xf1\xc1\xfe\xcb\xbd\x46\x74\x58\xfa\xd7\xff\xcf\xdc\xf7\x9c\xfb\xe9\x75\xcf\x03\x95\x5e\xd7\xfe\x0f\xf9\x4e\xb5\x60\xf4\x4a\x20\x84\x06\x0b\xa0\xae\x97\x5a\x70\xf6\xda\xd9\x7a\xd0\xf8\xb8\x38\x89\x57\xe8\x9b\x26\x67\x61\x6a\xf9\x81\x4a\x88\x08\xd8\x02\xba\xba\x6b\x97\x10\xae\xd5\x49\xf3\xbb\x6f\x28\xa5\x19\x38\x92\x2c\x04\x53\xb0\xeb\x70\x9a\xf8\x85\x34\x60\xef\xca\xdf\x2d\x64\x65\x21\x32\x0c\xc8\xb6\x0f\x9c\xde\x3b\xbf\x3e\x7a\x38\xa6\xd9\xf9\xba\xba\x3f\xa8\x40\xd4\xd9\x89\x65\x19\x55\xbf\x7b\x4b\xc3\x89\x71\xdd\x22\x6b\x43\x23\xef\x82\x50\x46\x13\x03\x44\xb7\x20\xf9\xca\x5a\x1c\x73\x6e\xca\x54\x5f\x17\xb2\xee\x0e\x39\x5e\xc1\x2c\x68\xe5\x7b\x39\xd9\xea\x47\xfb\xdd\x58\x4c\x9b\xb7\x88\xbf\xef\x24\x43\x78\x4b\x1d\x32\x68\x51\x29\xf0\x67\x46\xa0\xf0\xce\x73\x51\xc3\x3c\xa8\xf3\x32\xef\xa1\x7d\xaf\x66\x31\x4b\x12\xf2\x1c\x8a\x6f\xd9\x4a\xe9\x88\x9f\x5d\x41\x88\xe6\x65\xb0\xbd\x80\x91\xa7\x90\x65\x61\xf4\x6f\xf7\xb6\x9b\x80\x3f\x44\xf2\x01\x15\x1f\xab\x1e\x26\x93\x34\x10\x5c\x58\x58\x75\x71\x54\xbe\x1a\x6c\xca\xc2\xc0\x10\xd5\x1a\x0e\x59\xbd\xe9\xd4\xd3\xcb\x22\x00\xb9\xab\x52\x22\x1f\x5c\x25\xea\xb0\x7d\xf2\xe2\xbf\xb3\xf2\x07\x84\x39\xff\xa3\x69\x74\xc3\x51\x2f\xb1\x4c\x50\x16\x96\xfa\xa8\xce\xfc\x8b\x8f\x7c\x9c\x9e\x84\xed\x52\xfe\xd9\xa2\xaa\xcb\x3c\x0b\xe0\xce\x86\xcf\x97\xe3\x18\xfe\x54\x51\x82\x76\x9b\xf2\x40\xa1\x37\x5a\x00\xa1\x6f\x9e\x7e\xd9\xae\xa3\x6f\x8c\x79\x9e\xed\x63\x24\xd6\x95\x49\x64\x01\xaa\x8b\xec\xdf\x2e\xaa\xda\x76\x7f\x43\x02\xf6\x24\x9b\x8f\xb6\x19\x7f\x4f\x1c\x97\xdf\xb5\x06\x29\x83\x80\x97\xd5\x78\xef\x2e\x01\x41\x42\x03\x25\x85\xfc\x2e\xef\x5c\xa8\xee\xa0\x44\x69\x42\x20\x60\xdf\xa5\x5f\xc8\xe3\x42\x3f\xa8\x8d\xf7\x80\x93\xf3\xfa\x50\x89\x26\xb1\x14\xd3\x9d\x63\x97\x34\xb1\x6e\x24\xfd\xbd\x19\xb7\xd2\x9f\xe0\xe4\x1f\x43\x3e\xa4\x05\xdf\x29\x51\xba\x5c\x29\xdd\xfc\x1e\x53\x9b\x9e\x06\x91\xd0\x43\x42\x9b\xca\x0a\x1e\xac\xcb\xd2\xd6\xe0\x6f\x49\x02\xdc\x3f\x26\x4b\x7f\x49\xc9\xc9\x02\xc9\x13\x69\x2e\x79\x5e\xd9\x00\x56\x2c\x48\xcd\x08\xa6\x64\x68\xf7\x45\x11\xb1\x1c\x94\x17\x80\xb7\x96\x59\x2d\x3d\xc2\xef\x08\x5e\x66\x1f\x94\x57\x88\x2d\xf1\xce\x4a\x0c\xe0\xe3\x81\xbe\x9b\x40\x2c\xeb\x1a\x90\x33\xc1\x78\x12\x1a\xbc\x84\x45\x32\xac\x43\xd1\x53\xb1\xa6\xd3\xab\xd3\x7b\xc5\xcf\x93\x73\x36\x46\x0c\xbd\xbd\xfd\x8b\xc1\x67\x94\xf5\x1d\x9a\xc9\x33\x76\x07\xac\xfd\xfe\x58\xd3\xc7\x8a\x67\x1a\xf6\xe1\x2c\xf1\x63\x7a\x8f\x85\xf9\x92\x71\x54\x2b\x98\x24\x6e\x91\xb2\x6d\xe2\x93\xf9\x58\xcc\x5f\xb5\x13\xd7\xd4\x86\xa2\x3f\x68\x70\x3a\xe9\x4c\x99\xa6\x99\xde\xc3\xd9\xa8\x9b\xe5\x2d\xe4\x0b\xce\xc0\x9f\xc7\x09\x02\xc4\x4a\x26\x11\x8a\x75\x2a\xf5\x11\xb0\xae\xbe\x61\x0c\xd7\x80\x71\x9f\x57\x8f\x6c\x3b\xc4\x4e\xae\x8d\xd5\x31\xaa\x17\x14\x85\xb0\xf3\x3f\x8c\x14\x1b\x4e\xcd\x05\xe2\x1b\xd4\x6b\xac\xe1\xa8\x6b\x03\x8e\xf2\xd6\xbd\x87\xa1\xde\xb2\xca\xc8\xfc\x55\xe4\x7a\xec\xb4\xcc\xb5\x95\x0e\x5e\x1f\x5f\x57\xea\x17\x9d\xbf\x99\x68\xf9\xfb\x30\x03\x67\x61\x38\xa8\x5a\x1a\x52\x54\x5a\xb4\x1f\xbe\x36\x4d\x42\x9c\x4d\x23\x1c\xf3\x72\x8d\xba\xfc\x38\xf0\xa6\x9b\xbc\x38\x93\x57\x28\x2a\x1b\x1d\x87\x98\x38\xc2\x83\x95\x2e\x48\x42\x7f\x4f\xaf\xf3\x22\x6a\xfd\xb7\x4b\x9f\x3f\xa6\xba\x9c\xa6\x89\xdf\x21\x70\xaf\x90\x0f\xfb\x9d\x28\x1e\xc0\x42\x9b\xd0\x1d\x8b\x75\xf0\x8a\xe1\xaa\x9b\x81\xc2\x7e\xd4\x6b\x2e\xa5\x2c\x5e\x90\x1b\x35\xe2\x2f\x94\x3a\x8c\x39\x5b\x90\xfc\x57\x76\x24\xd9\x97\x3a\x7c\xb5\x74\x99\x0b\x00\xab\x86\xf6\x32\xb9\x75\x51\x9d\x9a\xe0\x0e\x5b\xb1\x2b\x3c\xfc\xbb\xd8\x11\x4d\xf6\xb4\x24\x8b\x65\x9f\x08\xeb\x2f\x3d\xff\x6c\xef\x91\x92\x6b\x19\x35\xb5\x19\xb4\xf1\x4a\x65\x91\xc9\xb6\x45\x56\x32\x6f\xf5\x74\xe9\xf0\x03\x1a\x5c\x30\xf3\x8a\xf5\xeb\xfb\xc3\xde\xb3\x9d\xbc\x2b\x57\x85\x9f\x62\xce\x13\x63\x89\x4e\xcd\xa0\xdd\xec\xba\x9f\x2f\x93\xa7\x17\x54\xb7\x55\xe4\xbd\xbd\x3b\xea\xa1\xcd\x77\x68\x04\x17\xb5\xf4\x4f\x71\x19\x3a\xb7\x8b\xdb\x46\xa4\xcf\x7f\xf8\x42\x42\x2a\x0d\x6d\xae\x1a\xde\xb5\xec\x31\x7b\x55\x32\x0d\xcb\xf2\x79\x80\x09\xa3\xce\x4b\x04\xb1\xa5\x3e\xd4\x66\x81\x6d\x97\x34\x95\x12\x58\x27\xfc\x71\x45\x6a\x87\xbd\xa4\x89\x0a\xaf\xfc\x48\x55\x64\x28\x79\x6e\xa2\x7b\xf2\x82\xe5\xd7\xb5\xcc\x62\x8a\x30\x70\x39\x8f\xb6\x88\x1d\x7d\xda\x3f\xef\xba\xeb\x30\x6c\x73\xf1\xba\x2c\x06\x5b\x36\x22\x4f\xd4\x07\x8a\x41\xf5\xef\xa4\x1f\xd0\x0b\x57\x02\xb2\xbd\x1e\x8f\x02\x2b\xae\x02\x2e\xf9\x61\x02\xde\x65\xda\x3c\x38\x40\xc3\x61\xc2\x19\xe4\x84\x9e\xbe\xfa\xb7\xad\xee\xf6\x27\x92\xe5\x48\x4c\x5d\x0e\x98\x66\x3a\xb2\xbd\x45\x24\x7e\xca\x3e\x00\x32\xc1\xc7\x25\xb6\x9f\x18\x2c\x3e\x8c\x8b\xe7\xb3\x13\x8c\xa3\x3e\x74\x7a\x45\x82\xc4\x2a\xad\xa7\x5b\x5a\xd7\x97\xa6\x4a\x01\xe0\x34\xd6\x49\xcd\x32\x2d\x68\xa3\xad\x28\x9e\x7b\xe8\xc5\xf8\xc3\x9d\x16\x37\x9c\x62\x19\xd1\xf7\x3f\x89\xe7\x1f\x36\x0f\xd8\x19\x2e\x7f\x4b\x5c\x7f\xf1\xe0\x78\x7d\xd0\x32\x32\x04\x82\x9d\xbb\xa1\xdb\xed\xf0\x69\xc3\x81\x09\xde\x1d\x1a\xbf\x18\xa0\xa9\xc6\x0b\x80\x7d\xe2\x2b\xcc\x9c\x0f\xb0\x0a\x62\x5d\xe4\x14\xaa\x63\x49\xed\xc1\x5a\xca\x44\xb7\xdf\xb9\xcc\x92\xe8\xdb\x09\xd1\x46\x57\xb5\xc4\xe3\xd0\x3d\x4a\x15\xd2\xd5\xd4\xf5\x3e\xca\x30\xb4\x59\xc1\x2f\xa7\xb7\xef\x82\x24\xe2\x79\x6f\xb5\x06\xb1\xaf\xb6\x69\xad\x0a\xb9\x35\x4b\x79\xba\xb4\xc6\x10\xce\x06\x58\x67\x05\x83\xbe\xca\xc0\x88\xc7\xf3\x8a\x38\x0f\x6c\xd8\xdc\x3d\x1e\xa8\x5e\xda\x04\x7b\x1d\xa2\x84\xb4\x2c\xc1\x58\x6c\xa6\xe0\xd2\x10\xcc\x30\xae\xf3\x66\xe1\x2c\x0d\x8d\x64\xb8\x38\x04\x53\x32\xb5\x24\x7f\xc7\xaa\x86\xc8\x54\x82\x54\x16\x22\x9c\x9c\x28\x7e\xd4\x8e\xe6\x7d\xb6\x8c\x71\x3e\x9b\xf6\xea\x5d\x49\xab\x2e\xbb\xe9\x0e\x73\x67\x7b\x95\x31\x9e\xfc\x35\x53\x73\x6d\xc0\x4a\x8e\xaf\x25\xe3\x31\x23\x6d\xeb\xb8\x6c\xe4\x47\x28\x8d\x3c\xf3\xae\x14\xee\x04\x89\x40\x20\xed\x48\x6d\xe9\xf6\x2a\xf4\x23\x1b\x3b\x8b\xc2\xdf\x71\xcb\x8f\xb1\x01\xd4\xd2\x52\x55\xfc\x0b\x03\xfa\xdb\xf2\x32\x50\xc4\xd5\xbd\xaa\xcd\x4e\xb5\xad\xc1\xb7\x71\x8b\x8d\x8e\xc8\x8a\x4c\x08\x06\xe8\x13\x32\xf3\x21\xd0\xcd\xe4\x90\xf8\x6c\xcd\x17\xe9\xac\x41\xd5\xcf\x00\x92\x42\xa6\x25\xb7\xa9\x94\xf5\x48\x80\xe9\xd2\xbd\x5f\x08\x28\xe6\xc0\x7b\x12\xd5\x5e\x0f\xf4\x12\xa4\x06\xb0\xfc\xb4\xac\x53\xa2\xbc\x95\x03\x37\x39\xc5\xd0\x4d\xa1\xc0\xa6\xaf\xf1\xe8\xd2\xfe\x2d\x5a\x94\xa1\x99\x44\x18\xe2\x10\xfc\x47\x94\xdb\x3d\xc4\x12\x0c\x16\xcc\x5b\x69\x04\x9b\x26\x6a\x45\xa3\xd7\x18\xf0\x22\xb9\xdd\xc6\xc3\x55\xca\x80\x3f\x3a\x49\xa5\x06\x2c\x97\x72\x83\x7a\x51\x96\xe5\x4a\xec\x38\x87\x14\xc7\x36\xf7\x72\xd4\x92\x7f\x1f\x3b\xd8\x76\x4a\xae\x1e\x15\x7e\xd6\xec\xc8\xcc\x63\x99\xa5\xc2\xf9\xcb\x90\x2c\x50\xa4\xfb\x8f\x06\x84\x4f\x0f\xd2\x03\x7f\x9c\x6b\x87\xc5\x15\x96\x21\x50\x80\x69\x63\x8d\x41\x3e\xa1\x25\x26\x5b\x97\xd9\x61\xb7\xd8\x67\xe9\xb2\x56\x35\x81\x61\x0a\x70\x27\x0d\x9f\x73\x1c\x81\xb0\xfe\xf9\xea\xbb\x65\x63\xdb\x5d\x8b\xb5\x52\x80\x8f\xef\xb0\xcc\xa3\xf0\x30\x37\x43\x4e\xe7\xa9\x70\xc7\x5c\x04\x31\x5c\x5c\xff\xed\x84\xf8\x56\x4f\x2d\x6f\xfb\x8b\x80\x41\x4b\x23\x9e\xe9\x43\x27\x50\x41\xe9\x2a\x10\x6f\x67\x12\x72\x34\x77\x00\xb7\xa3\x4c\x54\xb3\x7e\x2a\x65\x35\x44\x74\x9f\x19\xa6\x35\x5c\x71\x23\x05\x73\xb2\x50\xdc\x13\x59\xe8\x30\x29\xd8\x29\xe8\xf0\x26\x98\xdd\x6b\x3f\x15\xb2\x16\x3a\x60\x0d\x30\xc7\x62\xa8\x40\x0b\x98\xfc\x25\x2b\xaf\x06\x20\x81\xf3\xf3\x35\x3b\xc1\xf3\xa4\xdb\x51\x68\x44\x1c\xaa\x21\xb2\x87\x27\x6f\xb8\x05\x31\x31\xdc\x32\x5c\x3a\x1f\x06\xd2\x79\xc0\xc8\x9e\xb9\x5a\xde\xd2\x24\xb7\x76\x21\x74\x85\x18\x09\x96\x12\x40\xe6\xc9\xfb\x85\x17\xc1\xda\x6d\xb8\x13\x6e\x01\x94\x13\xe9\xbd\x0b\x50\x3e\x15\x63\x2c\xa0\xb7\x90\x44\xee\x4c\xf7\x98\x73\x42\x88\xa7\x68\x54\x14\x79\xa3\xa6\xff\x07\xdf\x45\x25\x8e\xdb\x4b\xf1\x46\x13\x14\x77\xff\x7d\x40\xe3\xb9\x52\x06\x48\x3c\xcf\xc8\xc9\x87\xc9\x90\x6b\x71\xdf\x2c\x1a\x1a\xdf\x1b\x40\xf2\x2b\x80\xcb\x76\xb0\x91\xff\x38\xd5\xf7\x0a\x15\xb3\x6c\x65\xcf\xf9\xba\x35\x8e\xcb\xc8\x93\xb4\x7f\x45\x2d\x4d\xe1\xac\xed\x51\x9d\x91\x70\x68\xc1\x43\xed\x57\xd3\xc2\xa4\xd5\x4c\x6b\x9a\xb6\x00\x97\xd1\x3b\xc0\x93\x64\xf8\x2c\xb0\x31\xea\xe6\x6a\x3b\x85\xc8\x8e\xc9\x66\xe5\xe8\xc9\xec\x7a\xde\x88\xf8\xb6\x8f\xcb\xd7\x1a\xc8\x0c\xa5\xba\x86\xe0\xf5\xc2\x8e\x66\xc8\x2f\x86\xd7\xeb\x16\x1d\xa1\x29\xbc\xc8\xa6\xe3\x28\x0b\x85\x11\x0a\xfd\xf3\x70\xca\x5c\xc7\xd2\x27\x53\xcd\x4d\x04\x2c\xb2\x5a\xbc\xdd\x0a\xa5\x64\x17\x0f\x33\x60\x86\xc3\x6d\xac\x3b\xe6\x8b\x2e\x76\xef\x85\xc4\xca\x4f\x42\xa9\xe3\xfc\x78\x64\x2f\x69\xdf\x30\xcf\x68\xb2\x27\x9a\x9b\x5a\x62\xda\xd5\xff\x16\x6d\x2b\xc9\x08\x37\xf0\x7e\xbb\x95\x98\x9f\x4b\x9c\x85\xf8\xdc\x61\x0b\x16\xbc\x05\x01\xdb\x54\x71\x48\x0f\xb0\xbb\x00\x29\x97\x38\x7c\xad\x25\x13\x07\x44\x10\x9d\x6a\x5f\xf2\xfb\xaa\x66\x64\xda\x7c\x61\x91\x8f\x0d\x9e\x47\x65\x2a\x5b\xa5\x95\xae\xa9\x1a\x3c\xeb\x17\xe9\xef\x41\x6c\x23\xb7\x88\xb5\x58\x20\x2b\x43\x5a\xe6\x45\x7e\xe0\xbd\x4b\xec\x13\xe8\xb9\xec\x41\xa7\x56\x2e\xc7\xa9\xad\x5a\x54\x28\xc0\x47\x1e\xc2\xf3\x4e\xf1\x02\x28\xe5\x82\xc1\x2f\x92\x29\x7b\xa3\x5c\x42\xcd\x4c\xb5\xad\x07\xa1\x0a\xfe\x2e\x64\x43\xcb\xb8\x99\xb5\x1e\x01\x2b\x16\x2a\xbb\x0f\x7e\x84\x23\x67\xa0\x64\x53\xf0\xea\xc6\xd3\x9a\x51\xd8\x2c\x1a\x29\x0e\xc3\xd1\x81\x6a\x4f\xce\xc8\xc7\x06\x2f\xee\x8d\x41\x80\xa2\x4e\x31\xb7\xf0\xe1\x69\xe6\x00\x58\x7c\xd3\x7c\xcd\xc7\x26\x53\x12\x43\x3f\x65\xc2\x1a\x42\x3c\x4f\xf1\x7a\x2c\xde\x0f\x48\x35\xd2\xd9\xd8\x29\x02\x3a\x35\x36\xbf\xb2\x05\x38\x9a\x84\x58\xfe\xa9\x60\x2b\x9f\xdf\xb5\x33\x59\xd3\xd4\x12\x9a\xb3\xa1\xd2\xe7\x0c\x95\x7e\x0e\xdb\x70\x5f\x1a\x95\x34\x31\x62\xb5\xdd\x5b\xfd\x2f\x07\x7c\xbd\x93\xae\xfa\xcd\xe7\x6b\x0f\x3a\x73\x09\x10\x32\x70\x39\x72\x9e\x7c\x58\x14\x04\xd8\xa3\xc6\xc2\x77\x75\x85\x75\x1e\x75\x3e\x77\x55\xd2\xb8\x17\x16\xb4\x7f\x79\xd6\x12\x63\x41\x34\x30\x35\xa2\xd8\xd5\x1a\x28\xc6\x04\x91\x9f\x9a\xb4\xee\x4f\x42\xb5\x42\xc0\x7d\x3b\xb0\xbf\x25\x6f\xd4\xe3\x60\xd6\xc6\x8b\xdb\x77\x77\x0a\x1e\xbc\x69\x02\x35\xc2\x71\xe3\x94\x2b\x45\xe3\xba\x7b\x5a\xca\x96\xe9\x53\x5d\x2d\xfa\xb2\xb5\x72\x58\x69\x31\x9b\x80\xbc\x1b\x5b\xe9\x3c\xaa\x05\x2a\x13\x31\x64\x54\x2f\xc9\x9c\x12\x05\x1e\xde\x20\x13\x16\x9f\xcb\x74\xb5\x0a\xc2\x80\x45\xb0\xfe\x35\x43\x88\xf1\x46\x75\x00\x10\x47\x3e\x2b\xa1\xba\x8c\xbf\x67\xdc\xb9\xa6\xad\x90\xc0\xb2\x90\x5a\x63\xe1\x43\x9d\xfa\x56\x29\xdd\xb0\x9c\xab\x41\xf9\x48\x93\x7d\xe0\x80\x8c\x79\x55\x99\x58\x47\x6a\x5c\x46\x38\xdf\xba\x8d\x0a\x9e\x45\x60\x7b\xa5\x98\x3f\x91\x20\x12\xaf\x6c\xe0\xce\xbf\x59\x3b\x70\xcc\x66\x1c\xf8\x77\xae\x24\x94\x9d\xf1\x35\xcd\x91\xee\xc6\xcb\xfe\x7c\x85\xae\xda\x4a\x11\x0a\x1a\x3b\xfc\xe7\x9c\x3a\xf8\x83\x7c\x8e\x4d\xc5\x94\x8e\x35\x9d\xa6\x47\x7a\xe2\xa1\xd9\xec\xe9\x95\xd3\x1d\x8c\x96\xcf\xac\x44\x6a\x9a\x10\xeb\x88\x94\xcb\x02\x19\xed\x39\x3d\xf5\x4b\x7c\x9b\x6f\xc9\xde\x60\x9f\x75\xee\x15\x44\xc2\x89\xa1\xd1\xcf\xfb\x54\x5f\x78\x1c\x2f\x25\xe8\xdf\xff\x99\x80\x10\x7d\x1b\xbb\x64\x18\xc8\x5b\xde\xf2\x16\x46\x3a\x82\x97\x2c\x52\x7e\xab\x95\x72\x90\xe6\xee\xd8\x5a\xc1\xc9\x37\xbd\x36\xd5\xdc\xf8\x06\x41\x7f\x42\x0e\x3a\x24\x97\xcd\x61\xbd\x80\x19\x23\x21\x44\xc6\x91\x17\xcf\x98\xc4\xa7\xcf\x75\x09\x63\x70\x72\x81\x00\x6a\x17\x2d\xe2\x2f\x63\x2e\x4c\x48\x6f\x89\x05\x2c\x0e\xbb\x94\xa3\x18\x73\x97\xae\xec\xbe\x5b\x7c\xca\x26\x1a\x4a\xb8\x6c\x9b\x81\x9c\x16\x1f\x33\xc9\x5d\x69\x2d\x89\xc6\xa0\x5e\x57\xe5\x15\x72\x04\xe5\xbc\x76\xf1\x99\xa3\xa9\x6c\x7d\x9b\x0b\x38\x72\x65\xa3\x03\x83\x32\xd9", 3508);
*(uint64_t*)0x200001a0 = 0xdb4;
*(uint64_t*)0x200001a8 = 6;
*(uint64_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b8 = 0;
*(uint32_t*)0x200001bc = -1;
*(uint64_t*)0x20001888 = 0;
	syscall(__NR_io_submit, r[0], 2ul, 0x20001880ul);
	return 0;
}
