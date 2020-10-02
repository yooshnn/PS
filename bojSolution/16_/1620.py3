from sys import stdin
def input(): return stdin.readline().rstrip()
d={}
e={}
n,m=map(int,input().split())
for _ in range(n):
    s=input()
    d[_+1]=s
    e[s]=_+1

for _ in range(m):
    s=input()
    if s.isdigit():
        print(d[int(s)])
    else:
        print(e[s])
