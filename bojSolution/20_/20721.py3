import sys; input = sys.stdin.readline

safe = [[1 for c in range(8)] for r in range(8)]

for r in range(8):
    t = input().rstrip()
    free = True
    for c in range(8):
        if t[c]=='R':
            free = False
            for i in range(8): safe[i][c] = 0
    if not free:
        for i in range(8): safe[r][i] = 0

res = 0
for r in range(8):
    res += sum(safe[r])

print(res)