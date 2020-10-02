from sys import stdin
def input(): return stdin.readline().rstrip()
n,t=map(int,input().split())
c=0
s=list(map(int,input().split()))
for i in range(n):
    c+=s[i]
    if c>t:
        c=i
        break
    if i==n-1:
        c=n
print(c)
