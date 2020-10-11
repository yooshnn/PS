import sys
input = sys.stdin.readline

n = int(input())
s = sorted(list(map(int, input().split())))
res = 10000000000

for i in range(n):
    res = min(res, s[i] + s[-1-i])
print(res)