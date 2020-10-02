from sys import stdin
def input(): return stdin.readline().rstrip()
N,M=map(int,input().split())
res=1
s=list(map(int,input().split()))
for i in range(N):
    res*=s[i]
    res%=M
print(res)