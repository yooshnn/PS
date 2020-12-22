import sys; input = sys.stdin.readline

N = int(input())
b = [*map(int, input().split())]
g = [(x, i) for i, x in enumerate(map(int, input().split()))]
g.sort()

r = 0
for i in range(N):
    r += g[i][0]*(i) + b[g[i][1]]
print(r)
