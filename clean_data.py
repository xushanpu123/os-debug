import os
import sys
import os.path
import numpy as np
import pandas as pd
import openpyxl as op

path="."
Nproc_per_case=1250


def clean_data():
	arr=[]
	for file_name in os.listdir(path):
		if( file_name=="clean_data.py" or file_name=="res.xlsx"):
			continue
		case_id=file_name.split("output")
		case_id=case_id[1].split(".txt")
		case_id=case_id[0].split("-")
		proc_id=int(case_id[0])
		case_id=proc_id*Nproc_per_case+int(case_id[1])-1

		res_str=""
		with open(file_name,"r") as f:
			data=f.read()
			data=data.split('\n')

			if(data[53]==" --------------- all test ended, passed 0 / 0 --------------- "):
				res_str="complier error"
			elif(data[55]==" --------------- test passed --------------- "):
				res_str="succ"
			else:
				res_str=data[55]

			res_array=[case_id,res_str]
			arr.append(res_array)
	df=pd.DataFrame(arr)
	#print(df)
	#df.to_csv(df,"./res.csv")
	wb=op.Workbook()
	ws=wb.active
	i=1
	r=1
	for line in arr:
		for col in range(1,len(line)+1):
			ws.cell(row=r,column=col).value=line[col-1]
		i+=1
		r+=1
	wb.save("./res.xlsx")


if __name__ =="__main__":
	clean_data()
