import sys
input = sys.stdin.readline

board = []

N = int(input())
for _ in range(N):
    board.append(input().rstrip())

good = True
for i in range(N):
    for j in range(N):
        if board[i][j] != board[j][i]:
            good = False

print("YES" if good else "NO")
