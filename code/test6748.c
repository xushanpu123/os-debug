// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#define USLEEP_FORKED_CHILD (3 * 50 *1000)

static long handle_clone_ret(long ret)
{
	if (ret != 0) {
		return ret;
	}
	usleep(USLEEP_FORKED_CHILD);
	syscall(__NR_exit, 0);
	while (1) {
	}
}

static long syz_clone(volatile long flags, volatile long stack, volatile long stack_len,
		      volatile long ptid, volatile long ctid, volatile long tls)
{
	long sp = (stack + stack_len) & ~15;
	long ret = (long)syscall(__NR_clone, flags & ~CLONE_VM, sp, ptid, ctid, tls);
	return handle_clone_ret(ret);
}

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000940, "\x24\x89\x88\x8c\xa8\xf7\x18\x9d\x25\xe2\x7e\xb8\x1a\x1d\xe3\xb1\xbb\xaf\xed\x1e\x90\x70\x5d\x85\xdf\xa6\xfd\xe6\xf9\x25\x45\x7b\x28\x97\x9a\x58\x7b\x57\x63\x92\xf2\xe4\x30\x5b\x29\xb3\x52\xf0\xf1\xc6\x86\x13\x44\x56\xcb\x41\x38\x7c\xae\x50\x7b\x2a\x3c\x34\xfa\x36\x34\x29\x2c\x16\x2e\xf3\xc3\xa3\x25\x09\x09\x64\x0a\x20\x64\x93\x3d\xc8\x5a\x9f\x3a\xe5\x54\x32\xe2\x7b\xb8\xfd\x96\xcc\xc8\x25\xcc\x91\x5d\xb1\xfb\xe7\xc0\x0d\xd4\x42\x72\xbb\x9b\x3b\xee\x4f\x2a\xb6\xdc\x2b\x77\x1a\xbc\x65\xc7\x31\x65\xe2\xf3\xde\x89\x16\x3b\xa0\x40\x0f\x2c\x91\xa4\x3e\xec\x70\xf4\x30\x5b\x08\xfd\xde\x87\x61\xac\x78\x54\x1d\xe6\xbf\x59\x6e\x5d\xf8\xf4\x0b\x6e\x4e\xc4\x6c\xe1\xce\xd0\xa9\x6c\x68\xc6\xc9\x39\x22\x38\xa6\xb9\x85\x7f\x30\xd7\x2d\xf1\x85\xe7\x30\xfd\xaf\x10\x93\x7b\x55\xe8\xd1\x3c\xa3\x9d\x69\x76\x3a\x4e\x99\x47\xd5\xc4\xc5\x75\x56\x50\x50\xc6\x10\x14\x4e\x4e\xc4\x28\xd4\xb6\x54\x1a\xdd\x26\x8c\x46\x94\x1e\x54\x80\xae\xa4\x37\x29\x3d\x75\x2b\x0e\xbc\xe7\x6c\xbb\x51\x3a\xa8\x76\x91\x32\x68\xed\xc2\x5e\x0e\x8a\xd1\xd5\x3e\xd3\x1c\x49\x7f\x25\x74\xd1\x13\xd6\x6a\x0e\xc4\x32\xc1\x71\xed\xde\xd5\x6b\x62\xe1\x34\xcb\x1b\x1b\x33\xdf\x79\x9d\xaf\x1c\x2c\x76\xcd\xe3\x99\x56\x11\xd8\x8d\x11\x20\xfb\xa3\xbe\x90\xed\x48\x77\xe6\x4c\x7f\x9b\xa1\xb7\x1f\x2a\xad\x5b\x6c\xde\x11\xd3\x22\xdf\x8a\x79\xc1\x53\x1f\x5d\xf2\xf4\xb6\x48\x53\x28\xce\xf6\x94\x26\xab\x16\x98\x53\xc3\x57\xe4\xbf\x9d\x2d\xdf\xdf\x18\xec\x08\x24\x0e\x30\x34\xdf\xba\x2b\xe8\x8f\xbd\x1f\x89\xaf\x97\xa6\xb1\x62\xc7\xf6\xb8\xa2\x31\x07\x33\xd2\x15\x21\x45\xf8\xa6\xd1\x85\x6b\x03\x07\xcc\xec\x2d\x2d\x04\xb8\x35\x40\x20\x2c\xe5\x9d\x1e\xd7\xdd\xe5\xc3\xda\xcc\x0c\xc7\x8c\x57\x99\x1c\x69\xf8\x81\x9a\x9d\x77\x18\x2f\x78\xd3\x8e\xb8\x37\x8c\x0b\xad\x78\x43\x6a\xae\x52\xaa\x8a\xe9\x4c\xb6\x9b\xc0\xcf\x2d\x64\x53\xe0\x4a\xb8\x87\xa2\x89\x6b\x70\xcd\x6c\x0a\x77\xc6\xef\xdf\xe5\xfc\x01\xba\xf0\xf0\xf3\xef\x82\x2e\x57\x10\xf2\xd7\xc9\x03\x58\x7d\xae\x2a\x96\x40\xfc\x0f\xc1\x2f\xf8\xb4\x67\x6b\xc3\xde\x79\xb7\x91\xea\x43\xae\xcf\x1c\x05\x54\x61\x64\x36\x54\x6f\x0d\xdf\xfa\x85\x4c\x81\x06\xa2\x4c\x06\xb2\x4a\xba\xc2\xf6\x2e\x6d\xed\x2d\xf6\xe4\x99\x69\x08\xdf\x9e\x79\xed\xe9\x40\x9b\x11\x7e\x08\x02\xa3\x69\x18\xca\xce\x50\x80\x36\xf3\x72\xa5\xf1\x2a\x27\xf9\x6a\x27\x6e\xcd\xfc\x82\xf5\xac\x26\xbb\x3a\xee\xe9\x90\x73\xeb\x29\xa6\x45\x5e\x9e\xaf\xfa\xee\xb5\xee\x0a\xb9\x61\x3c\x22\xe4\x5b\x50\xce\x54\x11\xc2\x8d\x29\x1d\xd7\xa9\x02\x9e\xa7\x23\x43\xb6\x15\x75\x1a\x1e\xaf\x38\xbe\x90\x6c\x60\x7d\xc7\x3d\x56\x48\xfd\xc3\xc9\xa8\xb8\x11\x2c\xc0\xa5\x3d\x3f\x0a\x8f\x8d\xa4\x19\xaf\xf4\x12\xce\x49\xfd\x1f\x71\x10\x05\xc3\xf9\x18\x03\x70\x4a\xf8\x4b\x96\xc3\x4b\xf2\x17\x4b\x23\xb8\x6f\x65\x80\x67\x86\xbc\x4a\x69\x19\x97\x55\x0b\x07\x11\xda\x08\xc0\xd0\x6b\xb2\x61\xa2\x80\x74\x19\xe6\x2e\xdb\x3f\x72\xcf\xb3\xb8\xe3\xeb\x1a\x07\xc3\xaa\x0e\x0f\x33\xd3\x1e\x3c\xe8\x9a\x48\x9e\x5b\xcd\xa4\x70\xd7\x0e\x7c\x85\xa7\xd7\xcc\x3f\x47\x9b\x45\x86\xc7\xdc\x8d\x21\x44\xc7\xf0\xe0\x43\x07\x2b\x94\x2f\x91\x5a\xe9\xb4\x31\xc4\x3a\xf7\x88\xd9\xb6\x28\x74\xc7\x5d\xbb\x3a\x83\x16\x9a\x27\xc4\x31\x3c\x71\xab\x9c\x58\x91\x73\x3b\xfd\xd3\x25\x0a\xd1\x9e\x1b\x38\x47\x01\x32\x2b\x06\x06\x86\xd2\x24\x34\xa4\xcf\xa1\xf3\xf3\xde\x7e\x81\xa9\x4b\xcc\x6a\xa6\xac\x7d\x08\xf0\x27\x37\xda\xe3\xe7\x42\xcd\x78\xf9\xb9\x68\x90\xdf\x64\xcf\x85\xb7\x9a\x79\xa8\x7e\x41\xd7\x90\xb4\xb4\x61\x1a\xd6\x75\x5a\xcb\xf2\x64\x2c\x5f\xbb\x81\xa7\x11\x12\x01\xaf\xd9\x57\x71\x7f\xe7\x57\xf8\x7c\xbf\x4b\xac\xb6\x31\x8e\xa2\x70\x5b\x42\xb2\x9e\xee\xea\x80\x6d\xad\x6c\x55\x04\x27\x03\x53\xf0\x89\x12\x1a\xf2\x5b\x87\x7c\xb0\xa6\xb6\xf3\xf7\x19\xf0\x3f\x75\x9c\xab\x83\xd2\x7d\xcb\x51\x2b\x8a\x30\x62\xaa\x9c\x3d\x89\xb4\x95\x7c\xba\x12\xc8\x25\xee\xa7\x73\x6f\x4e\x5b\xcc\x6e\x75\x4d\xc5\xb3\x6a\x6b\x81\xaa\x63\x1b\xc8\xbb\xae\x8a\x41\xfe\x40\x43\x6b\xa4\x5b\xd5\x32\xed\x7f\x6d\x99\x92\x41\xba\x6d\x7c\x3d\xf4\x5e\x10\x1f\x2d\xfb\x9b\x48\xa0\x0a\xa3\xb6\x5b\x51\xc0\x71\xfa\xca\xd7\xde\x1a\xa2\x7b\x70\x71\xef\xe9\x68\x7d\xe0\x01\xf0\xaa\xde\x99\x2c\x75\xc8\x49\x3f\xfd\x1d\xae\x4d\x29\x65\x0e\xb8\x21\xec\xef\x6e\xfc\x9e\x22\x75\x0b\xca\xe0\xa3\xf0\x0a\x74\x54\x9f\x8d\xf7\xd6\x8e\xc8\x3c\x4d\x27\x32\x72\xaa\x7f\xdc\x5a\xee\x03\x1c\x5c\x88\xb4\x6f\xe5\xda\xff\x02\x6e\x19\x91\xb9\xba\xce\x8f\x71\xf6\xa0\x90\x3e\x1b\x96\x91\xd2\xd9\xdb\x7f\x3b\x9a\x3b\xbf\x59\x28\xda\xd4\x19\xe3\xfe\x01\xdd\x3c\x65\xf0\xf8\x0f\x39\xb6\x77\x51\x0e\x5c\x83\xed\x23\x5d\x58\x21\x36\xd3\xc1\xd3\x62\x84\x7e\x1f\x2b\xd6\xbf\x01\x47\xd3\x39\x3e\xb5\x07\xf4\x92\x19\xa3\xfc\xe0\x0a\xbc\x3a\xaa\x4d\x26\xea\xad\x79\xa2\x9b\xca\xf7\xaa\x50\xfa\xbc\x9f\x87\x2f\x86\x92\xeb\xb5\x6f\xf8\x6e\x3f\xcd\x22\x40\x0a\x49\x0d\x64\x01\x79\xa7\xd7\xa0\x20\x1b\x65\xe6\xec\xc1\x6a\x48\xd1\x3e\x0d\x6b\xb5\xe2\x9e\x75\x5a\x08\xef\xfb\xdc\x38\xaf\x84\x31\xa9\x1d\x82\x86\x2b\xc9\x58\xca\x9f\x29\x20\x7f\x38\xda\xef\xd0\x41\x15\x84\x49\x0b\x3e\x0c\x71\xc3\xff\x5c\x1c\xef\x7c\x29\x34\xc7\x35\xaf\xb5\xbd\xc4\xe1\x8f\x04\x84\x15\x34\x4f\x21\x1f\xb5\x5c\x6d\x05\x2a\xd5\x44\x23\x53\xab\x6e\x1f\x0a\x6e\x1a\x3b\xe8\xe4\xde\x9c\x94\x73\xe1\x39\xe1\xb3\x14\xa4\x4d\xe2\xc1\x2a\xbd\xe5\xe4\x2e\xca\xa6\x83\xd9\xf8\xb6\x43\xfd\x63\xc3\x28\xfd\xc9\x77\xbc\x6e\x8d\x27\x6d\x6d\x61\x18\x09\xf0\xa2\x2f\xdf\x00\xc7\x89\x47\xac\x27\x68\x2e\xf6\x1d\xb9\x8f\x0f\x2e\x0d\x3f\x05\xf6\xd1\x52\xcb\xb3\x7e\x6f\xd9\x7d\x96\x17\x61\x91\x9b\xcf\xb9\x92\xe5\x16\x06\xf7\x23\xb2\x17\xa1\xcb\x5f\x7f\xa1\x66\x53\x89\xba\x35\xbd\xcd\x14\xc2\x3c\xd5\xc5\x3e\xa7\x20\x84\x01\x14\x33\x8b\x92\x72\x1e\x15\xe8\x8f\x94\x92\xe1\x6f\x1a\x65\xd5\xc0\x7c\xf3\x50\xe1\x90\x9f\x62\x0b\x80\x3f\xe8\x33\xfa\x98\x9f\x76\x20\x14\xae\x8c\xdc\x9d\x41\x05\x68\x2f\x23\xed\x67\x35\x9e\x56\xcd\x03\xac\xc6\xbf\x09\x69\x79\x2e\x82\xe8\xf2\x27\xa7\x5d\x01\xa5\xd9\xcf\xc5\xff\x7b\x21\x26\x19\x78\xb1\xcf\x1a\x48\x06\x98\xe0\xa3\x9d\x31\x71\x97\x14\x9e\x20\x1d\x6b\x1b\xf1\xaa\xb5\x90\x21\x03\x19\x00\x15\xfe\x46\x76\x76\x0f\xfc\x2d\xcb\x91\xdb\x7a\x8d\x8e\xbf\x2b\x95\xf1\xf6\x77\x94\x11\x98\xc7\x53\x4d\xa5\x02\x96\x1c\x90\x4f\xb2\x5f\x5c\x73\xb7\xd8\xa9\xf4\xc4\x8b\xd1\xfa\xa5\xf2\x33\x28\xbf\x31\xb4\x06\xa7\xcd\xf0\xe8\xf7\xd4\xa0\xeb\xd5\x4e\xb0\x09\xcd\x43\x08\xe2\x30\x94\xad\x21\x8a\xf2\x13\x96\x2b\x95\x3e\x90\x47\x4a\x93\x61\x32\x64\x3a\xb4\x83\x40\xce\x68\x83\xd2\xfb\x65\x3b\xdc\x27\xb9\xae\x28\xce\x94\x47\xe5\x01\x40\xff\x2d\xc2\x25\x90\x4c\x32\x0b\xe5\x52\x6f\x7a\x00\x09\xf8\xe4\x1d\x1f\x99\x4d\xc3\x3c\xa2\x67\xd7\x57\x5e\x98\x08\x0b\x6f\x34\xfc\x2e\x5b\x2f\x56\x04\x15\xd1\x00\x40\x06\xda\x17\xa0\x8e\x55\xc2\x85\x58\x58\x33\xd9\xdf\xa3\xdf\xc5\xcf\xb3\xfc\xc0\x11\xf9\xea\xc2\x54\xce\xc0\x46\x48\x5a\x3a\x14\x6e\x3b\x5e\x1d\x81\x32\x49\x30\x63\x35\xbb\x8f\xa2\xd1\x24\x11\xf9\xa3\x01\x8a\x0a\x96\x16\xb0\x53\xca\x22\x6e\x6f\x1a\xe0\xe7\x6b\xbd\x29\x27\x8f\xc6\x31\xa1\x1c\x90\xc5\xc0\xe7\xa5\xde\x1f\x7b\xf7\x2b\xdd\x1f\xaf\x0f\x01\x5d\xbc\xe8\x5d\xd3\x42\x5c\xec\x39\x85\x32\x9e\xc6\x26\xc3\xb7\x62\x9f\x79\x44\xd1\x52\x54\x28\x11\xfe\x34\x95\xa6", 1729);
	res = -1;
res = syz_clone(0, 0, 0, 0, 0, 0x20000940);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001ac0 = 0;
*(uint64_t*)0x20001ac8 = 0;
*(uint64_t*)0x20001ad0 = 0x20001980;
*(uint64_t*)0x20001ad8 = 0xbb;
*(uint64_t*)0x20001ae0 = 0x20001a40;
*(uint64_t*)0x20001ae8 = 0x76;
*(uint64_t*)0x20001d80 = 0x20001b00;
*(uint64_t*)0x20001d88 = 0xfc;
*(uint64_t*)0x20001d90 = 0x20001c00;
*(uint64_t*)0x20001d98 = 0x74;
*(uint64_t*)0x20001da0 = 0;
*(uint64_t*)0x20001da8 = 0;
	syscall(__NR_process_vm_readv, r[0], 0x20001ac0ul, 3ul, 0x20001d80ul, 3ul, 0ul);
	return 0;
}