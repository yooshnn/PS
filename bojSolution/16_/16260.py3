import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    R, C = map(int, input().split())
    res = [[0 for c in range(C)] for r in range(R)]
    lp = [0, 0]
    cur = [0, 0]
    for i in range(R*C):
        res[cur[0]][cur[1]] = R*C-i
        cur = [cur[0]-1, cur[1]+1]
        if cur[0]==-1 or cur[1]==C:
            if lp[0]==R-1:
                lp[1] += 1
            else:
                lp[0] += 1
            cur = lp
    for rr in res:
        print(*rr)