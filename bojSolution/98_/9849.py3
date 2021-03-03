import sys; input = sys.stdin.readline

N = int(input())

x1, x2, y1, y2 = -1, 10001, -1, 10001
for i in range(N):
    s = [*map(int, input().split())]
    x1 = max(x1, s[0])
    x2 = min(x2, s[1])
    y1 = max(y1, s[2])
    y2 = min(y2, s[3])

print(max(0, x2-x1) * max(0, y2-y1))