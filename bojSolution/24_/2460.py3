import sys; input = sys.stdin.readline

c, r = 0, 0
for i in range(10):
    a, b = map(int, input().split())
    c += -a + b
    r = max(r, c)
print(r)
