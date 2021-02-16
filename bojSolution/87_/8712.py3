import sys; input = sys.stdin.readline

n = int(input())
res = [[0 for c in range(n)] for r in range(n)]

c = 1
for i in range(n):
    if i&1:
        for j in range(n):
            res[i][n-1-j] = c
            c += 1
    else:
        for j in range(n):
            res[i][j] = c
            c += 1

for r in res: print(*r)
