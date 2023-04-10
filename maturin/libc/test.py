import os
import shutil
import os.path
import sys


src_dir_path = '../../code'        # 源文件夹,need change
outdir = '../../output'

def clean():
    with open('./static_testcases.txt','w') as f:
        f.truncate(0)
    new_str = ""
    with open("../kernel/src/testcases.rs","w") as f:
        f.truncate(0)
    path = "./build"
    if not os.path.exists(path):
        os.makedirs(path)
    files = os.listdir(path)
    for i, f in enumerate(files):
        if f.find("test") >= 0:
            path2 = os.path.join(path, f)
            os.remove(path2)
    path = "../oscomp_testcases/busybox"
    if not os.path.exists(path):
        os.makedirs(path)
    files = os.listdir(path)
    for i, f in enumerate(files):
        if f.find("test") >= 0:
            path2 = os.path.join(path, f)
            os.remove(path2)


def run_test(patch_num):
    if not os.path.exists(outdir):
        os.makedirs(outdir)
    os.system("rm %s/*"%(outdir))
    str = []
    id=1
    fstr = ""
    tests = os.listdir(src_dir_path)
    for test in tests:
        if not test.endswith(".c"):
            continue
        if not os.path.exists(src_dir_path+"/"+test):
            continue
        str.append(src_dir_path+"/"+test.removesuffix('c')+"out")
        fstr += src_dir_path+"/"+test.removesuffix('c')+"out\n"
        if id%patch_num == 0:
            clean()
            f = open('./static_testcases.txt','a')
            f.write(fstr)
            f.close()
            fstr = ""
            os.system("make  -j8")
            for sstr in str:
                if os.path.exists(sstr):
                    shutil.copy(sstr,"../oscomp_testcases/busybox/"+os.path.basename(sstr))
            str=[]
            outputnum=test.removeprefix("test").removesuffix(".c")
            outputfilename=outdir + "/output%s.txt" %(outputnum)
            os.system("python3 ../kernel/run_test.py > "+outputfilename)
        id = id + 1

if __name__=='__main__':
    patch_num=int(sys.argv[1])
    print("patch_num",patch_num)
    run_test(patch_num)