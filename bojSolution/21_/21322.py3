import sys; input = sys.stdin.readline

def w(x: int, y: int):
    global N, board, rot
    rx, ry = x - 1, y - 1
    dx, dy = x - N//2, y - N//2
    dx, dy = dx - (dx > 0), dy - (dy > 0)
    M = max(abs(dx), abs(dy))
    delta = N//2 - M - 1
    togo = rot[delta]

    if rx == delta: dire = 0
    if ry == delta: dire = 1
    if rx == N-delta-1: dire = 2
    if ry == N-delta-1 and rx != delta: dire = 3

    #print("x: %d, y: %d, dire: %d, delta: %d"%(x, y, dire, delta))

    while togo != 0:
        if dire==0:
            d = ry - delta
            ry -= min(togo, d)
            togo -= min(togo, d)
        if dire==1:
            d = N - delta - rx - 1
            rx += min(togo, d)
            togo -= min(togo, d)
        if dire==2:
            d = N - delta - ry - 1
            ry += min(togo, d)
            togo -= min(togo, d)
        if dire==3:
            d = rx - delta
            rx -= min(togo, d)
            togo -= min(togo, d)

        dire = (dire + 1) % 4

    return (rx, ry)

N, M = map(int, input().split())
board = []
rot = [0 for i in range(N//2)]
rmod = [((N//2 - i - 1)*2+1)*4 for i in range(N//2)]

for i in range(N):
    board.append([*map(int, input().split())])

for i in range(M):
    o, x, y = map(int, input().split())
    if o==1:
        rot[x-1] += y
        rot[x-1] %= rmod[x-1]
    if o==2:
        p0, p1, p2, p3 = w(x, y), w(x, y+1), w(x+1, y+1), w(x+1, y)
        temp = board[p0[0]][p0[1]]
        board[p0[0]][p0[1]] = board[p3[0]][p3[1]]
        board[p3[0]][p3[1]] = board[p2[0]][p2[1]]
        board[p2[0]][p2[1]] = board[p1[0]][p1[1]]
        board[p1[0]][p1[1]] = temp
    if o==3:
        temp = w(x, y)
        print(board[temp[0]][temp[1]])

    # print()
    # for row in range(N):
    #     for col in range(N):
    #         temp = w(row+1, col+1)
    #         print(board[temp[0]][temp[1]], end=" ")
    #     print()
