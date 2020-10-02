from sys import stdin
N,K=map(int,stdin.readline().split())
M=0
t=list(map(int,stdin.readline().split()))
for i in range(K):
    if t[i]==1:
        M+=1
    else:
        M+=(t[i]-1)//2+1
print(["NO","YES"][M>=N])