import sys; input = sys.stdin.readline

n, a, d = map(int, input().split())
s = [*map(int, input().split())]
res = 0

for c in s:
    if c==a:
        res += 1
        a += d

print(res)