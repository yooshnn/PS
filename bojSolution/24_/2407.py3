from sys import stdin
def input(): return stdin.readline().rstrip()

f=[1,1]
for i in range(2,101):
    f.append(f[i-1]*i)

n,m=map(int,input().split())
print(f[n]//(f[n-m]*f[m]))