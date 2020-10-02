#n,m=input().split()
#print(int(n)*int(m)-1)

from sys import stdin

N=int(stdin.readline())
M=int(stdin.readline())
x = [int(i) for i in stdin.readline().split()]

for i in range(M):
    if i == 0:
        res = 0
    else:
        res = max(x[i]-x[i-1], res)

if res%2 == 1:
    res += 1
res /= 2

res = max(res, x[0])
res = max(res, N-x[M-1])

print(int(res))