import sys; input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
p = [s[0]]
res = 210000000000000

for i in range(1, n):
    p.append(p[i-1]+s[i])

for i in range(n-1):
    res = min(res, abs(p[i] - (p[n-1]-p[i])))

print(res)
