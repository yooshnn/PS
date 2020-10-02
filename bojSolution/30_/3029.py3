from sys import stdin

a=list(stdin.readline().split(":"))
b=list(stdin.readline().split(":"))

p=int(a[2])+60*int(a[1])+3600*int(a[0])
q=int(b[2])+60*int(b[1])+3600*int(b[0])
if q-p<=0:
    q+=3600*24
a=q-p
res=""
res+=str("%02d"%(a//3600))
res+=":"
a-=3600*(a//3600)
res+=str("%02d"%(a//60))
res+=":"
a-=60*(a//60)
res+=str("%02d"%a)
print(res)