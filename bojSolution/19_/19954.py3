from sys import stdin
input = stdin.readline

maxBanana, minMove = 0, 1000000001
R, C, X = map(int, input().split())
IGRUS = dict()

for i in range(X):
    r, c, d = input().split(); r = int(r)-1
    pos = int(c) + r%(C*2) * int(d)
    if pos<1 : pos = -pos + 1

    if ((pos-1)//C)%2: pos = C - ((pos-1)%C)
    else: pos = 1 + ((pos-1)%C)

    try:
        IGRUS[pos][0] += 1
        IGRUS[pos][1] = max(IGRUS[pos][1], r)
    except:
        IGRUS[pos] = [1, r]

    if IGRUS[pos][0] >= maxBanana:
        minMove = IGRUS[pos][1] if IGRUS[pos][0]>maxBanana else min(minMove, IGRUS[pos][1])
        maxBanana = IGRUS[pos][0]

print(maxBanana, minMove)