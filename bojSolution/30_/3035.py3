from sys import stdin
def input(): return stdin.readline().rstrip()
r,c,zr,zc=map(int,input().split())
s=[]
for _ in range(r):
    s.append(input())

for i in range(r*zr):
    for j in range(c*zc):
        print(s[i//zr][j//zc],end="")
    print()