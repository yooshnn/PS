from sys import stdin,setrecursionlimit
def input(): return stdin.readline().rstrip()

a,b=input().split()
res=100
for i in range(len(b)-len(a)+1):
    cnt=0
    for j in range(len(a)):
        if a[j]!=b[i+j]:
            cnt+=1
    res=min(res,cnt)
print(res)