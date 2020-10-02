from sys import stdin
def input(): return stdin.readline().rstrip()
s=[]
n,m=map(int,input().split())
for i in range(n):
    s.append(input())
for i in range(m):
    for j in range(n-1,-1,-1):
        print(s[j][i],end="")
    print()