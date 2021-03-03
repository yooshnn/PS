import sys; input = sys.stdin.readline

def oob(r, c):
    global R, C
    return (r<0 or c<0 or r>=R or c>=C)

R, C = map(int, input().split())
board = [[False for c in range(C)] for r in range(R)]
res = [['#' for c in range(C)] for r in range(R)]
s = input().rstrip()

cnt = 0
dp45 = 3
r, c = 0, 0
while cnt < len(s):
    if board[r][c] == False:
        board[r][c] = True
        cnt += 1

    if dp45==0:
        if oob(r-1, c+1):
            if r-1<0:
                r, c = r+1, c+1
                dp45 = 3
            elif c+1>=C:
                r, c = r-1, c-1
                dp45 = 1
        else: r, c = r-1, c+1
    elif dp45==1:
        if oob(r-1, c-1):
            if r-1<0:
                r, c = r+1, c-1
                dp45 = 2
            elif c-1<0:
                r, c = r-1, c+1
                dp45 = 0
        else: r, c = r-1, c-1
    elif dp45==2:
        if oob(r+1, c-1):
            if r+1>=R:
                r, c = r-1, c-1
                dp45 = 1
            elif c-1<0:
                r, c = r+1, c+1
                dp45 = 3
        else: r, c = r+1, c-1
    elif dp45==3:
        if oob(r+1, c+1):
            if r+1>=R:
                r, c = r-1, c+1
                dp45 = 0
            elif c+1>=C:
                r, c = r+1, c-1
                dp45 = 2
        else: r, c = r+1, c+1

cnt = 0
for r in range(R):
    for c in range(C):
        if board[r][c]==True and res[r][c]=='#':
            res[r][c] = s[cnt]
            cnt += 1

cnt = 0
dp45 = 3
r, c = 0, 0
while cnt < len(s):
    if res[r][c]!='#':
        print(res[r][c], end="")
        res[r][c] = '#'
        cnt += 1

    if dp45==0:
        if oob(r-1, c+1):
            if r-1<0:
                r, c = r+1, c+1
                dp45 = 3
            elif c+1>=C:
                r, c = r-1, c-1
                dp45 = 1
        else: r, c = r-1, c+1
    elif dp45==1:
        if oob(r-1, c-1):
            if r-1<0:
                r, c = r+1, c-1
                dp45 = 2
            elif c-1<0:
                r, c = r-1, c+1
                dp45 = 0
        else: r, c = r-1, c-1
    elif dp45==2:
        if oob(r+1, c-1):
            if r+1>=R:
                r, c = r-1, c-1
                dp45 = 1
            elif c-1<0:
                r, c = r+1, c+1
                dp45 = 3
        else: r, c = r+1, c-1
    elif dp45==3:
        if oob(r+1, c+1):
            if r+1>=R:
                r, c = r-1, c+1
                dp45 = 0
            elif c+1>=C:
                r, c = r+1, c-1
                dp45 = 2
        else: r, c = r+1, c+1