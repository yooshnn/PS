import sys; input = sys.stdin.readline
import queue

def puts(s :str):
    print(s, end="")
dir4 = [[0, -1, 0, 1], [1, 0, -1, 0]]

for TEST in range(int(input())):
    R, C = map(int, input().split())
    board, dup = [['O' for c in range(C)] for r in range(R)], [[False for c in range(C)] for r in range(R)]

    for r in range(R):
        line = input().rstrip()
        for c in range(C):
            board[r][c] = line[c]

    que = queue.Queue()
    if board[0][0]=="O":
        que.put((0, 0)); dup[0][0] = True
    while not que.empty():
        cr, cc = que.get()
        for i in range(4):
            nr, nc = cr + dir4[0][i], cc + dir4[1][i]
            if nr==-1 or nc==-1 or nr==R or nc==C or board[nr][nc]=='X' or dup[nr][nc]: continue
            dup[nr][nc] = True
            que.put((nr, nc))

    print("Case: %d"%(TEST+1))
    for r in range(R*2):
        puts("|" if r&1 else "+")
        for c in range(C*4):
            if r&1==0:
                puts("-" if (c+1)%4 else "+")
            else:
                if (c+1)%4==0: puts("|")
                elif (c+1)%4==2:
                    if dup[r//2][c//4]: puts("M")
                    elif board[r//2][c//4]=='X': puts("X")
                    else: puts(" ")
                else: puts(" ")
        print()
    puts("+")
    for c in range(C*4):
        puts("-" if (c+1)%4 else "+")
    print()
    print("Minions %s cross the room"%(["cannot", "can"][dup[R-1][C-1]]))