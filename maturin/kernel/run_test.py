import os
import subprocess

pwd=os.getcwd()
os.chdir("../kernel/")
tests = os.listdir("../oscomp_testcases/busybox/")
with open("./src/testcases.rs","w") as f:

    s = ''
    s += "\n#[allow(dead_code)]\npub const TESTCASES: &[&str] = &[\n"
    for test in tests:
        if test.startswith("test"):
            s += f'"{test}",\n'
    s += "];\n"
    #print(s)
    f.write(s)

os.system("DISK_DIR=busybox make testcases-img")
subprocess.run(['make','run'],timeout = 180)
os.chdir("../libc/")
