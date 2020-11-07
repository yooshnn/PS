import sys
input = sys.stdin.readline

res = 0
N, M = map(int, input().split())
w = [[*map(int, input().split())] for i in range(N)]

for i in range(M-2):
    for j in range(i+1, M-1):
        for k in range(j+1, M):
            temp = 0
            for l in range(N):
                temp += max(w[l][i], w[l][j], w[l][k])
            res = max(res, temp)
print(res)