from sys import stdin
N,M=map(int,stdin.readline().split())
board = [[0 for j in range(M)] for i in range(N)]
for i in range(N):
    s = list(stdin.readline()[:M])
    for j in range(M):
        board[i][j] = s[j]
PR,PC=map(int,stdin.readline().split())

direction=["R","U","L","D"]

def solve(r, c, d):
    ret = 1
    visit[r][c] = direction[d]
    while True:
        if d==0: c+=1
        if d==1: r-=1
        if d==2: c-=1
        if d==3: r+=1
        if r<0 or c<0 or r>=N or c>=M:
            return ret
        if board[r][c]=="C":
            return ret
        if visit[r][c] == direction[d]:
            return 141592653589793141592653589793
        if board[r][c] == "\\":
            d=3-d
        elif board[r][c] == "/":
            if d<=1:
                d=1-d
            else:
                d=2+int(d==2)
        ret += 1
        visit[r][c] = direction[d]

tmax = -2
tmax_ = []
for i in range(4):
    val = []
    visit = [["0" for j in range(M)] for i in range(N)]
    t=solve(PR-1, PC-1, i)
    val.append(t)
    if t>=tmax:
        if t>tmax:
            del tmax_[:]
        tmax=t
        tmax_.append(direction[i])
if tmax==141592653589793141592653589793:
    print(tmax_[0])
    print("Voyager")
else:
    if "U" in tmax_:
        print("U")
        print(tmax)
    elif "R" in tmax_:
        print("R")
        print(tmax)
    elif "D" in tmax_:
        print("D")
        print(tmax)
    elif "L" in tmax_:
        print("L")
        print(tmax)
