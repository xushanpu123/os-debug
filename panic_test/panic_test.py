import pandas as pd
import os
import os.path
src_path = r'./code'
file_path = r'./res-onlypanic.xlsx'   # r对路径进行转义，windows需要
raw_data = pd.read_excel(file_path, header=0)  # header=0表示第一行是表头，就自动去除了
data = raw_data.values     # 只提取表中信息
exist_panic = []
panic_test_num = [[0]]
for test in data:
     test_id = test[0]
     src = src_path + "/test%d.c"%test_id
     panic_info = test[1]
     if test[1].startswith("[cpu"):
          panic_info = test[1][:4]+test[1][6:]
     if panic_info in exist_panic:
          panic_id = exist_panic.index(panic_info)
          des = "panic_type%d"%panic_id
          panic_test_num[panic_id].append(test_id)
          os.system("cp %s %s"%(src,des))
     else:
          panic_id = len(exist_panic)
          des = "panic_type%d"%panic_id
          exist_panic.append(panic_info)
          panic_test_num.append([])
          panic_test_num[panic_id].append(test_id)
          os.mkdir(des)  
          with open(des + "/note.txt","w") as f:
               f.write(panic_info+'\n')
          os.system("cp %s %s"%(src,des))
for id in range(0,len(panic_test_num)):
     with open("panic_type%d/panic_test_num"%id,"w") as f:
          panic_test_num[id].sort()
          f.write(str(panic_test_num[id]))