from sys import stdin
l=[0]*2000001
s=[]
N,C=map(int,stdin.readline().split())
for _ in range(N):
    s.append(int(stdin.readline()))
for i in range(N):
    for j in range(s[i],C+1,s[i]):
        l[j]=1
print(sum(l))