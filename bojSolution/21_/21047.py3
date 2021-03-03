import sys; input = sys.stdin.readline
from collections import *

res = []

n = int(input())
s = [-1]
s.extend([*map(int, input().split())])
s.append(int(1e18))

for i in range(1, n+1):
    t = str(s[i])
    t = int("9" + t[1:])
    if not s[i-1]<=t<=s[i+1]:
        for j in range(1, i):
            res.append(s[j])
        res.append(t)
        for j in range(i+1, n+1):
            res.append(s[j])
        print(*res)
        sys.exit(0)
for i in range(1, n+1):
    if s[i]<10: t = 0
    else: t = int("1" + str(s[i])[1:])
    if not s[i-1]<=t<=s[i+1]:
        for j in range(1, i):
            res.append(s[j])
        res.append(t)
        for j in range(i+1, n+1):
            res.append(s[j])
        print(*res)
        sys.exit(0)

print("impossible")