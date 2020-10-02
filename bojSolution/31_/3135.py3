from sys import stdin
def input(): return stdin.readline().rstrip()
a,b=map(int,input().split())
res=abs(b-a)
for _ in range(int(input())):
    s=int(input())
    res=min(res,abs(s-b)+1)
print(res)