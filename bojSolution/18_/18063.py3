from sys import stdin
def input(): return stdin.readline().rstrip()

m=[]
s=[]
x,y=map(int,input().split())
for i in range(x):
    a,b=map(int,input().split(":"))
    m.append(a)
    s.append(b)
    if i<x-1:
        s.append(-y)

h=0
m=sum(m)
s=sum(s)
s+=m*60
m=0
if s>=60:
    m+=s//60
    s%=60
if m>=60:
    h+=m//60
    m%=60
print("%02d"%h,"%02d"%m,"%02d"%s,sep=":")
