import sys; input = sys.stdin.readline

a, b, c, m = map(int, input().split())
x, res = 0, 0

for i in range(24):
    if x+a <= m:
        res += b
        x += a
    else:
        x -= c
        x = max(x, 0)
print(res)