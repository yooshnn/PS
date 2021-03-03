import sys; input = sys.stdin.readline


N = int(input())
col = []
for _ in range(N): col.append([*map(int, input().split())])
gomduri = [*map(int, input().split())]
res = 100000000

def solve(c, n, p, r, g, b):
    global N, gomduri, res
    if c==n:
        temp = abs(r//n-gomduri[0])+abs(g//n-gomduri[1])+abs(b//n-gomduri[2])
        res = min(res, temp)
        return
    for i in range(p, N):
        solve(c+1, n, i+1, r+col[i][0], g+col[i][1], b+col[i][2])

for x in range(2, min(8, N+1)):
    solve(0, x, 0, 0, 0, 0)

print(res)