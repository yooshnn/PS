import sys; input = sys.stdin.readline
from collections import deque

N, T, W = map(int, input().split())
que = deque([[*map(int, input().split())] for i in range(N)])
M = int(input())
late = [[*map(int, input().split())] for i in range(M)]
late.sort(key=lambda x : -x[2])

total_time = 0
cid, cti = 0, 0

while total_time < W:
    cid, cti = que.popleft()

    for i in range(min(T, cti)):
        print(cid)
        total_time += 1
        cti -= 1
        if (len(late) != 0) and (late[-1][2] == total_time):
            que.append([late[-1][0], late[-1][1]])
            late.pop()
        if total_time >= W: break

    if cti!=0:
        que.append([cid, cti])

    cid, cti = 0, 0