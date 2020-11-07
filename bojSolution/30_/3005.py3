import sys
input = sys.stdin.readline

R, C = map(int, input().split())
board = []
word = []

for i in range(R):
    board.append(input().rstrip())

for r in range(R):
    for c in range(C):
        if board[r][c] == "#": continue
        tempW = ""
        rr, cc = r, c
        if c<1 or board[r][c-1]=="#":
            while cc<C and board[r][cc]!="#":
                tempW += board[r][cc]
                cc += 1
            if len(tempW)>1:
                word.append(tempW)
        tempW = ""
        rr, cc = r, c
        if r<1 or board[r-1][c]=="#":
            while rr<R and board[rr][c]!="#":
                tempW += board[rr][c]
                rr += 1
            if len(tempW)>1:
                word.append(tempW)

print(sorted(word)[0])