from sys import stdin
def input(): return stdin.readline().rstrip()
a,b=input().split()
r=0
p=q=0
for _ in range(len(a)):
    p+=int(a[_])
for _ in range(len(b)):
    q+=int(b[_])
print(p*q)