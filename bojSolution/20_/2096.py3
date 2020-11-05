import sys
input = sys.stdin.readline

dpM, dpm = [[0, 0, 0], [0, 0, 0]], [[0, 0, 0], [0, 0, 0]]

n = int(input())
for i in range(n):
    li = [*map(int, input().split())]
    dpM[1][0] = max(dpM[0][0], dpM[0][1]) + li[0]
    dpM[1][1] = max(dpM[0][0], dpM[0][1], dpM[0][2]) + li[1]
    dpM[1][2] = max(dpM[0][1], dpM[0][2]) + li[2]

    dpm[1][0] = min(dpm[0][0], dpm[0][1]) + li[0]
    dpm[1][1] = min(dpm[0][0], dpm[0][1], dpm[0][2]) + li[1]
    dpm[1][2] = min(dpm[0][1], dpm[0][2]) + li[2]

    for i in range(3):
        dpM[0][i] = dpM[1][i]
        dpm[0][i] = dpm[1][i]

print(max(dpM[0]), min(dpm[0]))
