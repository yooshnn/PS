import sys
input = sys.stdin.readline

n = int(input())
s = input().rstrip()
board = [["." for c in range(n)] for r in range(220)]
m, M, h = 220, 0, 110
for i, c in enumerate(s):
    if c=="+":
        board[h][i] = "/"
        h -= 1
    if c=="-":
        h += 1
        board[h][i] = "\\"
    if c=="=":
        board[h][i] = "_"
    m = min(m, h)
    M = max(M, h)

for r in range(0, 220):
    if "_" in board[r] or "/" in board[r] or "\\" in board[r]:
        for c in range(n):
            print(board[r][c], end="")
        print()
