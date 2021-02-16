import sys; input = sys.stdin.readline

N = int(input())
x, y = 0, 0
for _ in range(N):
    s = [*map(int, input().split())]
    x += s[0]
    y += s[1]
print((y-x)/N)