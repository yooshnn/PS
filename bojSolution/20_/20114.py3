import sys
input = sys.stdin.readline

n, R, C = map(int, input().split())
paper = []
res = ["?" for i in range(n)]

for r in range(R):
    paper.append(input().rstrip())

for t in range(0, n*C, C):
    for c in range(t, t+C):
        for r in range(R):
            if paper[r][c]!="?":
                res[c//C] = paper[r][c]

print(*res, sep="")
