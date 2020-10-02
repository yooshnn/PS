from sys import stdin
n,m=map(int,stdin.readline().split())
a=[0]*m
b=[0]*n
s=0
for _ in range(n):
    t=list(map(str,stdin.readline().split()))
    for i in range(m):
        a[i]+=t[i].count("9")
        b[_]+=t[i].count("9")
print(sum(a)-max(max(a),max(b)))