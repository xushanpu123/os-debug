import os
import shutil
import os.path
import sys


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


def run_test(proc_id,patch_num,cases_per_proc):
    if not os.path.exists("./output"):
        os.makedirs("./output")
    str = []
    id=1
    fstr = ""
    case_start=proc_id*cases_per_proc
    case_end=(proc_id+1)*cases_per_proc-1
    for case_id in range(case_start,case_end):
        test="test%d.c" %case_id
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
            outputnum=id/patch_num
            outputfilename="./output/output%d-%d.txt" %(proc_id ,outputnum)
            os.system("python3 ../kernel/run_test.py > "+outputfilename)
        id = id + 1

if __name__=='__main__':
    proc_id=int(sys.argv[1])
    patch_num=int(sys.argv[2])
    cases_per_proc=int(sys.argv[3])
    print("proc_id",proc_id)
    print("patch_num",patch_num)
    print("cases_per_proc",cases_per_proc)
    run_test(proc_id,patch_num,cases_per_proc)