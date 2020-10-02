from sys import stdin
C,K,P=map(int,stdin.readline().split())
res=0
for n in range(C+1):
    res+=K*n+P*n*n
print(res)