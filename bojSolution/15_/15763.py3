import sys; input = sys.stdin.readline

res1, res2 = 0, 0
board = [input().rstrip() for r in range(3)]
line = [set() for i in range(8)]

for r in range(3):
    for c in range(3):
        line[r].add(board[r][c])
        line[3+r].add(board[c][r])
for i in range(3):
    line[6].add(board[i][i])
    line[7].add(board[i][2-i])

res = set(tuple(i) for i in line)
for i in res:
    if len(i)==1:
        res1 += 1
    if len(i)==2:
        res2 += 1

print(res1, res2, sep="\n")