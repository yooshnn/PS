import sys; input = sys.stdin.readline

while 1:
    msg = input().rstrip()
    if not msg: break
    seq = input().split()
    order = {}
    p, seq = int(seq[0]), [*map(int, seq[1:])]
    h = (len(msg)-1)//p+1
    for i in range(p): order[seq[i]] = i
    board = [['\0' for x in range(p)] for x in range(h)]

    col, row = 0, 0
    for c in msg:
        board[row][col] = c
        col += 1
        if col==p: col, row = 0, row+1

    res = []

    for i in range(p):
        row, col = 0, order[i+1]
        while row<h:
            if board[row][col]!='\0':
                res.append(board[row][col])
            row += 1

    print("".join(res))
