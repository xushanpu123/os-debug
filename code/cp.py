import os


id = 0
for i in range(0,4):
    os.system("rm ../os-debug%i/code/*" %i)
tests = os.listdir()
for test in tests:
    if test.endswith(".c") == False:
       continue
    if  (id >=5000*0 and id < 5000*1):
        os.system("cp %s ../os-debug0/code/%s" 
                  %(test,test)
                  )
        print("cp %s ../os-debug0/code/%s" 
                  %(test,test))
    if  (id >=5000*1 and id < 5000*2):
        os.system("cp %s ../os-debug1/code/%s" 
                  %(test,test)
                  )
    if  (id >=5000*2 and id < 5000*3):
        os.system("cp %s ../os-debug2/code/%s" 
                  %(test,test)
                  )
    if  (id >=5000*3 and id < 5000*4):
        os.system("cp %s ../os-debug3/code/%s" 
                  %(test,test)
                  )
    id = id +1