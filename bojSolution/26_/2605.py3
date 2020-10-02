from sys import stdin
def input(): return stdin.readline().rstrip()

n=int(input())
s=[i for i in range(1,n+1)]
r=[]
p=list(map(int,input().split()))
for i in range(n):
    r.insert(i-p[i],s[i])
print(*r)