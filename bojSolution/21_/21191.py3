import sys; input = sys.stdin.readline

def escape():
    print(0)
    sys.exit(0)

n = int(input())
board = [input().rstrip() for r in range(n)]

for i in range(n):
    r, c = board[i].count("B"), sum([1 if board[j][i]=="B" else 0 for j in range(n)])
    if r*2!=n or c*2!=n: escape()

for i in range(1, n-1):
    for j in range(1, n-1):
        if board[i][j]=="B":
            if board[i-1][j]=="B" and board[i+1][j]=="B": escape()
            if board[i][j-1]=="B" and board[i][j+1]=="B": escape()
        if board[i][j]=="W":
            if board[i-1][j]=="W" and board[i+1][j]=="W": escape()
            if board[i][j-1]=="W" and board[i][j+1]=="W": escape()

print(1)