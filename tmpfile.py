############################################
#功能: 将文件保存于内存之中, 
#      可用于需频繁保存的临时文件
############################################
import tempfile
temp = tempfile.NamedTemporaryFile()
temp.write('hello maymay')
temp.flush()
f = open(temp.name)
print f.read()
f.close()
