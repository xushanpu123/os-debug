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
    if not os.path.exists("./output"):
        os.makedirs("./output")
    tests = os.listdir(src_dir_path)
    
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
            f = open('./static_testcases.txt','a')
            f.write(fstr)
            f.close()
            fstr = ""
            os.system("make  -j8")
            for sstr in str:
                if os.path.exists(sstr):
                    shutil.copy(sstr,"../oscomp_testcases/busybox/"+os.path.basename(sstr))
            str=[]
            outputnum=id/patch_num
            outputfilename="./output/output%d.txt" %outputnum
            os.system("python3 ../kernel/run_test.py > "+outputfilename)
        id = id + 1

if __name__=='__main__':
    run_test(1)