import sys
input = sys.stdin.readline

R, C = map(int, input().split())
board = [input().rstrip() for r in range(R)]

r1, c1, r2, c2 = -1, -1, -1, -1
for i, s in enumerate(board):
    for j, c in enumerate(s):
        if c==".": continue
        if r1+c1 == -2:
            r1, c1 = i, j
        r2, c2 = i, j

if board[r1][c1 + (c2-c1)//2] == ".": print("UP")
if board[r2][c1 + (c2-c1)//2] == ".": print("DOWN")
if board[r1 + (r2-r1)//2][c1] == ".": print("LEFT")
if board[r1 + (r2-r1)//2][c2] == ".": print("RIGHT")
