##########################################################
#功能: 对列表中的数据并行调用同一函数进行处理
#      multiprocessing.dummy为线程并行, 适用于IO密集型任务
#      multiprocessing为进程并行, 适用于CPU密集型任务
##########################################################
#from multiprocessing.dummy import Pool as ThreadPool 
from multiprocessing import Pool as ThreadPool 

def fib(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

pool = ThreadPool(4) 
results = pool.map(fib, [35,35,35,35])
pool.close() 
pool.join()
for e in results:
    print e
