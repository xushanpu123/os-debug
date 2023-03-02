import os
import subprocess


tests = os.listdir("/home/xsp/mylab/maturin/oscomp_testcases/busybox")
with open("/home/xsp/mylab/maturin/kernel/src/testcases.rs","w") as f:

    s = ''
    s += "\n#[allow(dead_code)]\npub const TESTCASES: &[&str] = &[\n"
    for test in tests:
        if test.startswith("test"):
            s += f'"{test}",\n'
    s += "];\n"
   # print(s)
    f.write(s)
os.chdir("/home/xsp/mylab/maturin/kernel")


os.system("DISK_DIR=busybox make testcases-img")
subprocess.run(['make','run'],timeout = 180)
os.chdir("/home/xsp/mylab/maturin/libc")
