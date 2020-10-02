from sys import stdin
#from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

res=0
a=[[0 for j in range(201)] for i in range(201)]
n,m=map(int,input().split())
for _ in range(m):
    p,q=sorted(map(int,input().split()))
    a[p][q]=True
for i in range(1,n-1):
    for j in range(i+1,n):
        for k in range(j+1,n+1):
            if a[i][j] or a[i][k] or a[j][k]: continue
            res+=1

print(res)