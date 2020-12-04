import sys
import collections
input = sys.stdin.readline
deque = collections.deque

N, M = map(int, input().split())
s = [*map(int, input().split())]
que = deque([i for i in range(1, N+1)])
res = 0

for c in s:
    r1, r2 = 0, len(que)
    pp = 0
    while que[pp]!=c:
        r1 += 1
        pp = (pp+1)%len(que)
    r2 -= r1
    if r1<r2:
        que.rotate(-r1)
        que.popleft()
    else:
        que.rotate(r2)
        que.popleft()
    res += min(r1, r2)

print(res)