import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    N = int(input())
    N *= N
    board = []
    valid = True
    for r in range(N):
        board.append([*map(int, input().split())])
    for r in range(N):
        dup = [0 for i in range(10)]
        good = True
        for c in board[r]:
            if c>9 or c<1:
                good = 0
                break
            if dup[c]: good = 0
            else: dup[c] = 1
        if sum(dup) != 9: good = 0
        if not good: valid = False

    for c in range(N):
        dup = [0 for i in range(10)]
        good = True
        for r in range(N):
            if board[r][c]>9 or board[r][c]<1:
                good = 0
                break
            if dup[board[r][c]]: good = 0
            else: dup[board[r][c]] = 1
        if sum(dup) != 9: good = 0
        if not good: valid = False

    for i in range(0, N, 3):
        for j in range(0, N, 3):
            dup = [0 for i in range(10)]
            good = True
            for r in range(3):
                for c in range(3):
                    if board[r][c]>9 or board[r][c]<1:
                        good = 0
                        break
                    if dup[board[r][c]]: good = 0
                    else: dup[board[r][c]] = 1
            if sum(dup) != 9: good = 0
            if not good: valid = False

    print("Case #%d: %s"%(TEST+1, "Yes" if valid else "No"))
