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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000000, "dns_resolver\000", 13);
memcpy((void*)0x20000100, "\x6e\xba\x23\xda\x17\xbd\x70\x70\x1f\xdb\x68\x97\x97\x07\x42\x6d\xbb\x04\xae\x0e\x09\xd2\xa2\x77\xce\x0a\xfd\x40\x56\x36\x7d\x97\xde\xa2\xa6\x96\xf3\x57\x2b\x58\x52\xfa\xca\xb9\x38\x08\x00\x00\x00\x00\x00\x00\x10\x6b\xcb\x99\x2b\xaa\x28\xf3\xca\xff\x50\xa7\xfe\xe5\xe5\x8a\x52\xa0\x6a\xdc\xe6\x68\xe1\x92\x09\x82\x1e\x94\x65\xdd\x1b\xbf\x38\x71\x0f\x24\xc7\x85\xda\x91\xed\xdf\x2a\x72\x14\xe2\x98\xf2\x73\x96\x70\x02\x5b\x62\xe5\x2a\xdc\x9f\x7e\x6b\x40\x97\x5f\x8a\x36\xae\x9b\xc7\x9b\xab\xa1\xe1\x7d\x38\x22\x0f\x98\x80\x9b\xaa\x82\xe2\xe6\x43\x7f\x19\x4b\x00\x58\x78\x3d\x2b\xcb\x40\x0b\x1c\xc3\x5f\x5c\x55\x74\xa2\x49\x62\x0f\xdc\xd8\xa9\xf8\x86\x89\x2b\x9b\xd5\x44\xc4\xa5\x4d\x1b\xf2\x10\x00\x63\xfb\x1a\x4b\x3d\xb7\xb2\x6d\xf1\x9c\xbe\xc3\x87\x88\x0a\x79\x81\x8c\xb8\xe1\x7d\x84\x5c\x56\x72\xdb\x3d\x7b\x7d\xab\x38\xad\x23\x3f\x81\x45\xb8\x4f\x2f\x7f\x82\x00", 216);
	syscall(__NR_add_key, 0x20000000ul, 0ul, 0x20000100ul, 0xd8ul, 0xfffffffc);
	return 0;
}
