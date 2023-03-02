import os
import shutil
import os.path


src_dir_path = '../../code'        # 源文件夹,need change

def clean():
    with open('./static_testcases.txt','w') as f:
        f.truncate(0)
    new_str = ""
    with open("../kernel/src/testcases.rs","w") as f:
        f.truncate(0)
    path = r"./build"
    files = os.listdir(path)
    for i, f in enumerate(files):
        if f.find("test") >= 0:
            path2 = os.path.join(path, f)
            os.remove(path2)
    path = r"../oscomp_testcases/busybox"
    files = os.listdir(path)
    for i, f in enumerate(files):
        if f.find("test") >= 0:
            path2 = os.path.join(path, f)
            os.remove(path2)


def run_test(patch_num):
    
    tests = os.listdir(src_dir_path)
    f = open('./static_testcases.txt','a')
    str = []
    id=1
    fstr = ""
    for test in tests:
        if not test.endswith("c"):
            continue
        str.append(src_dir_path+"/"+test.removesuffix('c')+"out")
        fstr += src_dir_path+"/"+test.removesuffix('c')+"out\n"
        if id%patch_num == 0:
            clean()
            f.write(fstr)
            fstr = ""
            os.system("make -i -j8")
            for sstr in str:
                if os.path.exists(sstr):
                    shutil.copy(sstr,"../oscomp_testcases/busybox/"+os.path.basename(sstr))
            str=[]
            os.system("python3 ../kernel/run_test.py")
        id = id + 1

if __name__=='__main__':
    run_test(1)