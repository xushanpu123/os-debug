import os
import shutil
import os.path
import sys


src_dir_path = '../../../code'        # 源文件夹,need change

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


def run_test(test_num):
    test="test%d.c" %test_num
    fstr = ""
    if not os.path.exists(src_dir_path+"/"+test):
        print("file not exist!\n")
        return
    fstr += src_dir_path+"/"+test.removesuffix('c')+"out"
    clean()
    f = open('./static_testcases.txt','a')
    f.write(fstr)
    f.close()
    os.system("make  -j8")
    if os.path.exists(fstr):
        shutil.copy(fstr,"../oscomp_testcases/busybox/"+os.path.basename(fstr))
        os.system("python3 ../kernel/run_test.py")

if __name__=='__main__':
    test_num=int(sys.argv[1])
    print("test%d:\n"%test_num)
    run_test(test_num)