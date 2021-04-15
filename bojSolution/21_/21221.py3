import sys; input = sys.stdin.readline

def sharp(r, c):
    global board

    if board[r][c]=="#": return True
    if r==0 or c==0: return False
    return (board[r-1][c]=="#" or board[r-1][c-1]=="#" or board[r][c-1]=="#")

r, c = map(int, input().split())
board = []

for i in range(r):
    board.append(input().rstrip())

for i in range(r):
    for j in range(c):
        print("#" if sharp(i, j) else ".", end="")
    print()