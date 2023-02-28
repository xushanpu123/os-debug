import os
import shutil
import os.path

def clean():
    with open('/home/xsp/mylab/maturin/libc/static_testcases.txt','w') as f:
        f.truncate(0)
    new_str = ""
    with open("/home/xsp/mylab/maturin/kernel/src/testcases.rs","w") as f:
        f.truncate(0)
    path = r"/home/xsp/mylab/maturin/libc/build"
    files = os.listdir(path)
    for i, f in enumerate(files):
        if f.find("test") >= 0:
            path2 = os.path.join(path, f)
            os.remove(path2)
    path = r"/home/xsp/mylab/maturin/oscomp_testcases/busybox"
    files = os.listdir(path)
    for i, f in enumerate(files):
        if f.find("test") >= 0:
            path2 = os.path.join(path, f)
            os.remove(path2)

src_dir_path = '/home/xsp/syzkaller/syzkaller/code'        # 源文件夹
to_dir_path = '/home/xsp/mylab/maturin/oscomp_testcases/busybox'         # 存放复制文件的文件夹
key = '.out'                 # 源文件夹中的文件包含字符key则复制到to_dir_path文件夹中
tests = os.listdir("/home/xsp/syzkaller/syzkaller/code")
id = 1
f = open('/home/xsp/mylab/maturin/libc/static_testcases.txt','a')
str = []
fstr = ""
for test in tests:
    if not test.endswith("c"):
        continue
    str.append("/home/xsp/syzkaller/syzkaller/code/"+test.removesuffix('c')+"out")
    fstr += "/home/xsp/syzkaller/syzkaller/code/"+test.removesuffix('c')+"out\n"
    if id%50 == 0:

        f.write(fstr)
        fstr = ""

        clean()
        os.system("make -i -j8")
        for sstr in str:
            if os.path.exists(sstr):
                shutil.copy(sstr,"/home/xsp/mylab/maturin/oscomp_testcases/busybox/"+os.path.basename(sstr))
        str=[]
        os.system("python3 /home/xsp/mylab/maturin/kernel/run_test.py")
    id = id + 1