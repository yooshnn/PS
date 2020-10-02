from sys import stdin
x,k=map(int,stdin.readline().split())
res=0
if k*7 <= x:
    res=k*7
elif k*3.5 <= x:
    res=k*3.5
elif k*1.75 <= x:
    res=k*1.75
print(int(res*1000))
